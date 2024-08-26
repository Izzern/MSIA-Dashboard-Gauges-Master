[];===============================================================
;-------------------------- Gauge Style --------------------------
;=================================================================
[BG]
Meter=Shape
Shape=Ellipse #BGSize#,#BGSize#,#BGSize# | Fill Color #BGColor#,10 | StrokeWidth #Spacing1# | StrokeColor 100,100,100,10

[];===============================================================
;----------------------------- Gauges ----------------------------
;=================================================================
[ArcBG]
@includeArcBG=#@#Gauges\Styles\ArcBG.inc

[RoundlineMeter] ;Image Container Gauge
Meter=ROUNDLINE
MeasureName=RoundlineAngle
X=0
Y=#Spacing-1#
H=#RoundLineOD#
W=#RoundLineOD#
LineStart=0
LineLength=#RoundLineOD#
LineColor="255,255,255,255"
Solid=1
StartAngle=#BGRoundlineMeterStart#
RotationAngle=#RoundlineMeterAngle#
DynamicVariables=1
AntiAlias=1

[ArcImage] ;Image
Meter=Image
Container=RoundlineMeter
ImageName=#@#Gauges\Images\ArcLight.png
ImageTint="[MeasureColor],255"
W=#RoundLineID#
H=#RoundLineID#
X=#Spacing1#
Y=#Spacing2#
AntiAlias=1
DynamicVariables=1

[RoundlineEnd] ;End Point Indicator transparent bg
Meter=ROUNDLINE
Container=RoundlineMeter
MeasureName=RoundlineAngle
ImageName=#@#Gauges\Images\RoundLineEnd.png
ImageTint=255,255,255
X=0
Y=0
H=#RoundLineOD#
W=#RoundLineOD#
LineStart=#RoundlineEndBGStart#
LineLength=#RoundlineEndBGLength#
LineWidth=#RoundlineEndBGWidth#
LineColor=255,255,255,180
StartAngle=#RoundlineEndBGStartAngle#
RotationAngle=#RoundlineEndBGRotationAngle#
DynamicVariables=1
AntiAlias=1

[RoundlineEndBG] ;End Point Indicator
Meter=ROUNDLINE
MeasureName=RoundlineAngle
X=0
Y=0
H=#RoundLineOD#
W=#RoundLineOD#
LineStart=#RoundlineEndBGStart#
LineLength=#RoundlineEndBGLength#
LineWidth=#RoundlineEndBGWidth#
LineColor=255,255,255,#EndPointAlpha#
StartAngle=#RoundlineEndBGStartAngle#
RotationAngle=#RoundlineEndBGRotationAngle#
DynamicVariables=1
AntiAlias=1