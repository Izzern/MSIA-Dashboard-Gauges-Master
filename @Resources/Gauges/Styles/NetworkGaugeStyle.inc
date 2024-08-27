;=================================================================
;------------------------ Net Gauge Style ------------------------
;=================================================================
[Variables]
BGSize=(30 * #ScaleGauge#)

IconWideX=(13 * #ScaleGauge#)
IconWideY=(33 * #ScaleGauge#)

IconSquareX=#IconSquareH#
IconSquareY=(38 * #ScaleGauge#)

[BG]
Meter=Shape
Shape=Ellipse #BGSize#,#BGSize#,#BGSize# | Fill Color #BGColor#,10 | StrokeWidth #Spacing1# | StrokeColor 100,100,100,10

[Icon]
Meter=Image
ImageName=#@#Gauges\Icons\interneticon.png
Grayscale=1
ImageTint=#NetIconTint#
H=#IconSquareH#
x=#IconSquareX#
y=(17 * #ScaleGauge#)
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\GaugesSystem" "#SKINSPATH##PATH#\Settings\Settings.ini"][!ToggleConfig "#Path#\Settings" "Settings.ini"]

ToolTipType=1
ToolTipTitle="Network Adapter Information"
ToolTipText="#NetAdapterNameSelection##CRLF#Connection: #NetAdapterConnSelection##CRLF#DNS: #NetAdapterDNSSelection##CRLF#IP: #NetAdapterIPSelection##CRLF#Current Download Speed: [NetInCalc] Kbps#CRLF#Current Upload Speed: [NetOutCalc] Kbps"
DynamicVariables=1

[];===============================================================
;-------------------------- Text Meter ---------------------------
;=================================================================
[MeterPing]
Meter=String
MeasureName=MeasurePing
MeterStyle=StylePing
AntiAlias=1
AutoScale=1
UpdateRate=1
DynamicVariables=1
NumOfDecimals=0
X=(#TextGaugeX# * #ScaleGauge#)
Y=(48 * #ScaleGauge#)
Text="%1ms"

;-------------------------- In/Download --------------------------
[BGRoundlineMeterNetIn] ;Image Container Gauge
Meter=ROUNDLINE
MeasureName=
X=0
Y=#Spacing-1#
W=#RoundLineOD#
H=#RoundLineOD#
LineStart=0
LineLength=#RoundLineOD#
LineColor="255,255,255,230"
Solid=1
StartAngle=#BGRoundlineMeterStart#
RotationAngle=#BGRoundlineMeterAngle#

[GrayArcsNetIn] ;Gray BG Arcs
Meter=Image
ImageName=#@#Gauges\Images\ArcDark
Container=BGRoundlineMeterNetIn
W=#RoundLineID#
H=#RoundLineID#
X=#Spacing1#
Y=#Spacing2#

[RoundlineMeterNetIn] ;Image Container Gauge
Meter=ROUNDLINE
MeasureName=RoundlineAngleIn
X=0
Y=#Spacing-1#
W=#RoundLineOD#
H=#RoundLineOD#
LineStart=0
LineLength=#RoundLineOD#
LineColor="255,255,255,255"
Solid=1
StartAngle=#BGRoundlineMeterStart#
RotationAngle=#RoundlineMeterAngle#
DynamicVariables=1
AntiAlias=1

[ArcImageNetIn] ;Image
Meter=Image
Container=RoundlineMeterNetIn
ImageName=#@#Gauges\Images\ArcLight.png
ImageTint=#FontColorDn#
W=#RoundLineID#
H=#RoundLineID#
X=#Spacing1#
Y=#Spacing2#
AntiAlias=1
DynamicVariables=1

[RoundlineEndBGNetIn] ;End Point Indicator
Meter=ROUNDLINE
MeasureName=RoundlineAngleIn
X=0
Y=0
H=#RoundLineOD#
W=#RoundLineOD#
LineStart=(#RoundlineEndBGStart# + (0.5 * #ScaleGauge#))
LineLength=(#RoundlineEndBGLength# + (#Spacing1#))
LineWidth=#RoundlineEndBGWidth#
LineColor=255,255,255,#EndPointAlpha#
StartAngle=#RoundlineEndBGStartAngle#
RotationAngle=#RoundlineEndBGRotationAngle#
DynamicVariables=1
AntiAlias=1

;-------------------------- Out/Upload ---------------------------
[BGRoundlineMeterNetOut] ;Image Container Gauge
Meter=ROUNDLINE
MeasureName=
X=0
Y=0
W=#RoundLineOD#
H=#RoundLineOD#
LineStart=0
LineLength=#BGRoundlineMeterNetOutLength#
LineColor="255,255,255,255"
Solid=1
StartAngle=#BGRoundlineMeterNetOutStart#
RotationAngle=#BGRoundlineMeterNetOutRotation#

[GrayArcsNetOut] ;Gray BG Arcs
Meter=Image
ImageName=#@#Gauges\Images\ArcDark
Container=BGRoundlineMeterNetOut
X=#RoundlineMeterNetOutPosition#
Y=#RoundlineMeterNetOutPosition#
W=#RoundlineMeterNetOutSize#
H=#RoundlineMeterNetOutSize#

[RoundlineMeterNetOut] ;Image Container Gauge
Meter=ROUNDLINE
MeasureName=RoundlineAngleOut
X=0
Y=0
W=#RoundLineOD#
H=#RoundLineOD#
LineStart=0
LineLength=#BGRoundlineMeterNetOutLength#
LineColor="255,255,255,255"
Solid=1
StartAngle=#BGRoundlineMeterNetOutStart#
RotationAngle=(Rad(234.5))
DynamicVariables=1
AntiAlias=1

[ArcImageNetOut] ;Image
Meter=Image
Container=RoundlineMeterNetOut
ImageName=#@#Gauges\Images\ArcLight.png
ImageTint=#FontColorUp#
X=#RoundlineMeterNetOutPosition#
Y=#RoundlineMeterNetOutPosition#
W=#RoundlineMeterNetOutSize#
H=#RoundlineMeterNetOutSize#
AntiAlias=1
DynamicVariables=1

[RoundlineEndBGNetOut] ;End Point Indicator
Meter=ROUNDLINE
MeasureName=RoundlineAngleOut
X=0
Y=0
H=#RoundLineOD#
W=#RoundLineOD#
LineStart=(#ScaleGauge#*17.25)
LineLength=(#ScaleGauge#*21.75)
LineWidth=(#ScaleGauge#*2)
LineColor=255,255,255,(#EndPointAlpha# + 20)
StartAngle=#RoundlineEndBGStartAngle#
RotationAngle=#RoundlineEndRotationAngle#
DynamicVariables=1
AntiAlias=1
