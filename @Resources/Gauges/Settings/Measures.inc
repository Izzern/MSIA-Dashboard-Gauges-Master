[RainMeter]
Update=250

;=================================================================
;------------------ Gauges Measures Config File ------------------
;=================================================================
[Variables]
@IncludeVars=#@#Gauges\Settings\VariablesGauges.inc
@IncludeVarsUser=#@#Gauges\Settings\VariablesUser.inc

[];===============================================================
;-------------------------- System Info --------------------------
;=================================================================
[HardwareScript] ;Gather Hardware Information for VariablesHarware.ini
Measure=Plugin
Plugin=RunCommand
Program=PowerShell
Parameter=-NoProfile -ExecutionPolicy Bypass -Command "& '#@#Gauges\Scripts\Hardware.ps1'"
OutputType=ANSI
UpdateDivider=-1
DynamicVariables=1

[];===============================================================
;--------------------------- Defaults ----------------------------
;=================================================================
[DefaultScript] ;Restores default settings for VariablesUser.ini
Measure=Plugin
Plugin=RunCommand
Program=PowerShell
Parameter=-NoProfile -ExecutionPolicy Bypass -Command "& '#@#Gauges\Scripts\GaugeDefaults.ps1'"
OutputType=ANSI
UpdateDivider=-1

[DefaultFPSScript] ;Restores default FPS settings for VariablesUser.ini
Measure=Plugin
Plugin=RunCommand
Program=PowerShell
Parameter=-NoProfile -ExecutionPolicy Bypass -Command "& '#@#Gauges\Scripts\FPSDefaults.ps1'"
OutputType=ANSI
UpdateDivider=-1

[];===============================================================
;------------------------------ FPS ------------------------------
;=================================================================
[MeasureFPS] ;Only with Riva Statistics Tuner
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=Framerate
MinValue=0
MaxValue=244

[];===============================================================
;----------------------------- Load ------------------------------
;=================================================================
[CPUCoreLoadMSIA] ;CPU
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=CPU usage

[GPUCoreLoadMSIA] ;GPU
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=GPU usage

[];===============================================================
;---------------------------- Network ----------------------------
;=================================================================
[MeasureNetIn] ;Download
Measure=NetIn
Interface=Best
MinValue=0
AverageSize=3

[MeasureInDelay] ;Download Calc
Measure=Calc
Formula=(MeasureNetIn * 10)

[MeasureNetOut] ;Upload
Measure=NetOut
Interface=Best
MinValue=0
AverageSize=5

[MeasureOutDelay] ;Upload Calc
Measure=Calc
Formula=(MeasureNetOut * 10)

[MeasurePing] ;Ping
Measure=Plugin
Interface=Best
Plugin=PingPlugin
DestAddress=www.google.com

[];===============================================================
;------------------------------ RAM ------------------------------
;=================================================================
[MeasurePhysMemUsed]
Measure=PhysicalMemory
OnUpdateAction=[!SetVariable UsedPercent "(Round((([MeasurePhysMemUsed:]/[MeasurePhysMemUsed:MaxValue])*100)))"]
DynamicVariables=1

[];===============================================================
;----------------------------- Temp ------------------------------
;=================================================================
[CPUCoreTempMSIA] ;CPU
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=CPU temperature
MinValue=20
MaxValue=140

[GPUCoreTempMSIA] ;GPU
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=GPU temperature
MinValue=20
MaxValue=140

[];===============================================================
;--------------------------- VRAM/Proc ---------------------------
;=================================================================
[VRAMProcMSIA] 
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=GPU dedicated memory usage \ process

[];===============================================================
;----------------------------- WiFi ------------------------------
;=================================================================
[measureWifiSignal] ;Signal Strength
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=Quality

[MeasureSSID] ;SSID
Measure=Plugin
Plugin=WifiStatus
WifiInfoType=SSID
Meter=String

[MeasurePHY] ;Connection Type
Measure=Plugin
Plugin=WifiStatus
WifiInfoType=PHY
Meter=String

[MeasureRXRate] ;Current Network Speed
Measure=Plugin
Plugin=WifiStatus
WifiInfoType=RXRate
Meter=String
