#### Get Paths ####
$parentFolderPath = Split-Path -Parent $MyInvocation.MyCommand.Definition
$scriptFolderPath = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Definition)
$greatgrandparentFolderPath = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Definition)))
$variableFilePath = Join-Path -Path $greatgrandparentFolderPath -ChildPath '@Resources\Gauges\Settings\VariablesHardware.inc'
$settingsFilePath = Join-Path -Path $parentFolderPath -ChildPath 'settings.ini'

#### Get System Info ####
#=== CPU Info ===#
$cpuName = (Get-CimInstance -ClassName Win32_Processor).Name.Trim()
$cpuSpeed = (Get-CimInstance -ClassName Win32_Processor).MaxClockSpeed

#=== GPU Info ===#
$gpus = Get-CimInstance -ClassName Win32_VideoController | Where-Object { $_.Name -like "*Nvidia*" -or $_.Name -like "*AMD*" -or $_.Name -like "*Intel*" }

# GPU Names
$gpuNames = $gpus | ForEach-Object {
    $_.Name
}

$gpuName = $gpuNames

$GPU1Name = "N/A"
$GPU2Name = "N/A"
$GPU3Name = "N/A"

if ($gpus.Count -ge 1) {
    $GPU1Name = $gpus[0].Name
}

if ($gpus.Count -ge 2) {
    $GPU2Name = $gpus[1].Name
}

if ($gpus.Count -ge 3) {
    $GPU3Name = $gpus[2].Name
}

# VRAM Info
$vramPath = "HKLM:\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0*"
$vramValues = Get-ItemProperty -Path $vramPath -Name HardwareInformation.qwMemorySize -ErrorAction SilentlyContinue
$VRAM = $vramValues | ForEach-Object { $_."HardwareInformation.qwMemorySize" }
$VRAM = $VRAM | Where-Object { $_ -ne $null }
$VRAM = $VRAM | ForEach-Object { $_ / 1GB }  # Convert VRAM values to GB

$VRAM = $VRAM | ForEach-Object {
    # Round to two decimal places if the VRAM is less than 1GB
    if ($_ -lt 1) {
        $_.ToString("N2")
    } else {
        [math]::Round($_, 0).ToString()
    }
}

# Separate VRAM into VRAM1, VRAM2, and VRAM3 based on the number of GPUs
$VRAM1 = "N/A"
$VRAM2 = "N/A"
$VRAM3 = "N/A"

if ($VRAM.Count -ge 1) {
    $VRAM1 = $VRAM[0]
}

if ($VRAM.Count -ge 2) {
    $VRAM2 = $VRAM[1]
}

if ($VRAM.Count -ge 3) {
    $VRAM3 = $VRAM[2]
}

#=== Network Info ===#
# Retrieve active Ethernet devices
$ethernetDevices = Get-NetAdapter | Where-Object { $_.Name -like "*Ethernet*" }

# Initialize variables for Ethernet adapters
$ethernetNames = @()
$ethernetIPs = @()
$ethernetConns = @()
$ethernetDnsServers = @()

# Retrieve Ethernet adapter information
foreach ($ethernetDevice in $ethernetDevices) {
    $ethernetNames += $ethernetDevice.InterfaceDescription
    $ethernetIPs += (Get-NetIPAddress -AddressFamily IPv4 -InterfaceAlias $ethernetDevice.Name).IPAddress
    $ethernetConns += $ethernetDevice.MediaConnectionState
    $ethernetDns = (Get-DnsClientServerAddress -InterfaceAlias $ethernetDevice.Name).ServerAddresses
    $ethernetDnsServers += $ethernetDns -join '  |  '
}

# Retrieve active Wi-Fi devices
$wifiDevices = Get-NetAdapter | Where-Object { $_.Name -like "*Wi-Fi*" }

# Initialize variables for Wi-Fi adapters
$wifiNames = @()
$wifiIPs = @()
$wifiConns = @()
$wifiDnsServers = @()

# Retrieve Wi-Fi adapter information
foreach ($wifiDevice in $wifiDevices) {
    $wifiNames += $wifiDevice.InterfaceDescription
    $wifiIPs += (Get-NetIPAddress -AddressFamily IPv4 -InterfaceAlias $wifiDevice.Name).IPAddress
    $wifiConns += $wifiDevice.MediaConnectionState
    $wifiDns = (Get-DnsClientServerAddress -InterfaceAlias $wifiDevice.Name).ServerAddresses
    $wifiDnsServers += $wifiDns -join '  |  '
}

# IP and Connection Info
$wifiIP = $wifiIPs -join "  |  "
$ethernetIP = $ethernetIPs -join "  |  "

$wifiConn = $wifiConns -join "  |  "
$ethernetConn = $ethernetConns -join "  |  "

#=== Ram Info ===#
$ramCap = (Get-CimInstance -ClassName Win32_PhysicalMemory | Measure-Object -Property Capacity -Sum).Sum
$ramMan = (Get-CimInstance -ClassName Win32_PhysicalMemory | Select-Object -First 1).Manufacturer
$ramModel = (Get-CimInstance -ClassName Win32_PhysicalMemory | Select-Object -First 1).PartNumber
$ramSpeed = (Get-CimInstance -ClassName Win32_PhysicalMemory | Select-Object -First 1).Speed
$ramWidth = (Get-CimInstance -ClassName Win32_PhysicalMemory | Select-Object -First 1).TotalWidth
$totalRAM = $ramCap / 1GB

#### Script Output ####
# Get the last folder name from the greatgrandparentFolderPath
$scriptFolderName = Split-Path -Leaf $greatgrandparentFolderPath

# Check if VariablesHardware.inc exists
if (Test-Path $variableFilePath) {
    # Read the existing content of VariablesHardware.inc
    $existingContent = Get-Content -Path $variableFilePath -Raw

    # Remove existing variables from the content
    $existingContent = $existingContent -replace '(?m)^(CPUName=|CPUSpeed=|GPUName=|GPU1Name=|GPU2Name=|GPU3Name=|WifiName=|WifiIP=|WifiConn=|EthernetName=|EthernetIP=|EthernetConn=|RAMCap=|RAMMan=|RAMModel=|RAMSpeed=|TotalRAM=|Path=|DNSName=|WifiDns=|EthernetDns=|VRAM=|VRAM1=|VRAM2=|VRAM3=).*\r?\n?'

    # Trim leading and trailing whitespaces
    $existingContent = $existingContent.Trim()

    # Append the new variables and existing GPU-related variables to the existing content
    $variableContent = @"
$existingContent
CPUName=$cpuName
CPUSpeed=$cpuSpeed
EthernetName=$($ethernetNames -join ' | ')
EthernetIP=$ethernetIP
EthernetConn=$ethernetConn
EthernetDns=$($ethernetDnsServers -join ' | ')
GPUName=$gpuName
GPU1Name=$GPU1Name
GPU2Name=$GPU2Name
GPU3Name=$GPU3Name
RAMCap=$ramCap
RAMMan=$ramMan
RAMModel=$ramModel
RAMSpeed=$ramSpeed
TotalRAM=$totalRAM
VRAM=$VRAM
VRAM1=$VRAM1
VRAM2=$VRAM2
VRAM3=$VRAM3
WifiName=$($wifiNames -join ' | ')
WifiIP=$wifiIP
WifiConn=$wifiConn
WifiDns=$($wifiDnsServers -join ' | ')
Path=$scriptFolderName
"@

    $variableContent | Out-File -FilePath $variableFilePath -Encoding UTF8
}