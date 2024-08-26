[BGRoundlineMeter] ;Image Container Gauge
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

[GrayArcs] ;Gray BG Arcs
Meter=Image
ImageName=#@#Gauges\Images\ArcDark.png
Container=BGRoundlineMeter
W=#RoundLineID#
H=#RoundLineID#
X=#Spacing1#
Y=#Spacing2#