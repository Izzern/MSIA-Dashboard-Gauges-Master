;=================================================================
;------------------------ Net Gauge Style ------------------------
;=================================================================
[Variables]
BGSize=(60 * #ScaleGauge#)

IconWideX=(9 * #ScaleGauge#)
IconWideY=(26 * #ScaleGauge#)

IconSquareX=(15 * #ScaleGauge#)
IconSquareY=(31.67 * #ScaleGauge#)

;===============================================================
;--------------------------- HoneyComb Style -------------------
;===============================================================
[Variables]
BGSize=(60 * #ScaleGauge#)

IconWideX=(9 * #ScaleGauge#)
IconWideY=(26 * #ScaleGauge#)

IconSquareX=(15 * #ScaleGauge#)
IconSquareY=(31.67 * #ScaleGauge#)

[BG]
Meter=Image
ImageName=#@#Gauges\Images\background.png
H=#BGSize#
AutoScale=1
AntiAlias=1
ImageTint=[MeasureColor]
DynamicVariables=1

[Icon]
Meter=Image
ImageName=#@#Gauges\Icons\interneticon.png
Grayscale=1
ImageTint=#NetIconTint#
H=(40 * #ScaleGauge#)
X=(4 * #ScaleGauge#)
Y=(10 * #ScaleGauge#)
LeftMouseDownAction=[!ToggleConfig "#Path#\Settings" "Settings.ini"]

ToolTipTitle=Network Adapter Information
ToolTipType=1
ToolTipWidth=250
ToolTipText=#NetAdapterNameSelection##CRLF#Connection: #NetAdapterConnSelection##CRLF#DNS: #NetAdapterDNSSelection##CRLF#IP: #NetAdapterIPSelection##CRLF#Current Download Speed: [NetInCalc] Kbps#CRLF#Current Upload Speed: [NetOutCalc] Kbps

[MeterNetOutText]
MeasureName=MeasureOutDelay
Meter=String
StringAlign=RIGHTCENTER
StringStyle=BOLD
StringEffect=BORDER
FontColor=#FontColorUp#
FontEffectColor=#FontEffectTemp#
FontFace=#FontFaceTemp#
FontSize=(8.5 * #ScaleGauge#)
AntiAlias=1
AutoScale=1
UpdateRate=1
DynamicVariables=1
NumOfDecimals=1
X=(48 * #ScaleGauge#)
Y=(19 * #ScaleGauge#)
Text="%1B"

[MeterPing]
Meter=String
MeasureName=MeasurePing
StringAlign=CENTERCENTER
StringStyle=BOLD
StringEffect=BORDER
FontColor=#FontColorPing#
FontEffectColor=#FontEffectTemp#
FontFace=#FontFaceTemp#
FontSize=(8 * #ScaleGauge#)
AntiAlias=1
AutoScale=1
UpdateRate=1
DynamicVariables=1
NumOfDecimals=0
X=(25 * #ScaleGauge#)
Y=(12.5 * #ScaleGauge#)r
Text="%1ms"

[MeterNetInText]
MeasureName=MeasureInDelay
Meter=String
StringAlign=RIGHTCENTER
StringStyle=BOLD
StringEffect=BORDER
FontColor=#FontColorDn#
FontEffectColor=#FontEffectTemp#
FontFace=#FontFaceTemp#
FontSize=(8.5 * #ScaleGauge#)
AntiAlias=1
AutoScale=1
UpdateRate=1
DynamicVariables=1
NumOfDecimals=1
X=(48 * #ScaleGauge#)
Y=(12.5 * #ScaleGauge#)r
Text="%1B"