[Metadata]
Name=Compact Analog Clock
Author=Izzern, Special thanks to jsmorley for all the forum posts.
Information=Rainmeter minimalist analog clock skin with day/night & day/date.
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0
Version=1.0

[BG]
Meter=Shape
Shape=Ellipse #AnalogR#,#AnalogR#,#AnalogR# | FillColor #AnalogPrimaryColor#,100 | StrokeWidth #CompactStrokeW# | StrokeColor #AnalogSecondaryColor#,150
X=#Spacing1#
Y=#Spacing1#

[ClockFace]
Meter=Image
ImageName=#@#Clock\Images\Chronometer-#modeclock#.png
;ImageTint=#PercentLevel2#
H=#AnalogD#
W=#AnalogD#
X=#Spacing1#
Y=#Spacing1#

[MeterDayDate]
Meter=String
MeterStyle=StringStyleDate
MeasureName=MeasureDayAnalog
MeasureName2=MeasureDateAnalog
FontSize=#FontSizeXS#
StringAlign=CENTERCENTER
H=#DayDateH#
W=#DayDateW#
X=#AnalogR#
Y=#DayDateY#
Text="%1 %2"
ClipString=0
DynamicVariables=1

[ContainerDayNight] ;Image Container Gauge
Meter=ROUNDLINE
X=#Spacing1#
Y=#Spacing1#
W=#AnalogD#
H=#AnalogD#
LineStart=#DayNightLineStart#
LineLength=#DayNightLineLength#
LineColor="#BGColorClock#,255"
Solid=1
StartAngle=#DayNightStartAngle#
RotationAngle=#DayNightRotationAngle#

[MeterDayNightImage]
Meter=Image
Container=ContainerDayNight
ImageName=#@#Clock\Images\Day-night.png
W=#DayNightW#
H=#DayNightH#
X=#DayNightOffSetX#
Y=#DayNightOffSetY#
TransformationMatrix=(Cos(Rad([MeasureRotate])));(Sin(Rad([MeasureRotate])));(-Sin(Rad([MeasureRotate])));(Cos(Rad([MeasureRotate])));(([#CURRENTSECTION#:X] + [#CURRENTSECTION#:W] / 2) - ([#CURRENTSECTION#:X] + [#CURRENTSECTION#:W] / 2) * Cos(Rad([MeasureRotate])) + ([#CURRENTSECTION#:Y] + [#CURRENTSECTION#:H] / 2) * Sin(Rad([MeasureRotate])));(([#CURRENTSECTION#:Y] + [#CURRENTSECTION#:H] / 2) - ([#CURRENTSECTION#:X] + [#CURRENTSECTION#:W] / 2) * Sin(Rad([MeasureRotate])) - ([#CURRENTSECTION#:Y] + [#CURRENTSECTION#:H] / 2) * Cos(Rad([MeasureRotate])))
;AntiAlias=1
DynamicVariables=1

[MeterClockHands]
Meter=Shape
X=#AnalogR1#
Y=#ClockHandY#

Shape=Line 0,#LineStartY#,0,#LineMinuteEndY# | StrokeWidth #HandBGW# | Stroke Color #AnalogSecondaryColor#,#HandBGAlpha# | StrokeStartCap Round | StrokeEndCap Triangle | Rotate [MeasureMinuteAngle],#HandRotateBGX#,#HandMinuteRotateY#
Shape2=Line 0,#LineStartY#,0,#LineMinuteEndY# | StrokeWidth #HandW# | Stroke Color #HandColorMinute#,#HandAlpha# | StrokeStartCap Round | StrokeEndCap Triangle | Rotate [MeasureMinuteAngle],#HandRotateX#,#HandMinuteRotateY#

Shape3=Line 0,#LineStartY#,0,#LineSencondEndY# | StrokeWidth #HandBGW# | Stroke Color #AnalogSecondaryColor#,#HandBGAlpha# | StrokeStartCap Round | StrokeEndCap Triangle | Rotate [MeasureSecondAngle],#HandRotateBGX#,#HandSecondRotateY#
Shape4=Line 0,#LineStartY#,0,#LineSencondEndY# | StrokeWidth #HandW# | Stroke Color #HandColorSecond#,#HandAlpha# | StrokeStartCap Round | StrokeEndCap Triangle | Rotate [MeasureSecondAngle],#HandRotateX#,#HandSecondRotateY#

Shape5=Line 0,#LineStartY#,0,#LineHourEndY# | StrokeWidth #HandBGW# | Stroke Color #AnalogSecondaryColor#,#HandBGAlpha# | StrokeStartCap Round | StrokeEndCap Triangle | Rotate [MeasureHourAngle],#HandRotateBGX#,#HandHourRotateY#
Shape6=Line 0,#LineStartY#,0,#LineHourEndY# | StrokeWidth #HandW# | Stroke Color #HandColorHour#,#HandAlpha# | StrokeStartCap Round | StrokeEndCap Triangle | Rotate [MeasureHourAngle],#HandRotateX#,#HandHourRotateY#

Shape7=Ellipse 0,#CircleY#,#CircleR# | Fill Color #AnalogPrimaryColor# | StrokeWidth #CircleStrokeWidth# | StrokeColor #AnalogSecondaryColor#,#HandBGAlpha#

Shape8=Ellipse 0,#CircleY#,#CircleButtonR# | Fill Color 0,0,0,0 | StrokeWidth #CircleStrokeWidth# | StrokeColor 0,0,0,0

LeftMouseUpAction=[!WriteKeyValue Variables Selection "Clock\Settings\Panels\ClockSystem" "#SKINSPATH##PATH#\Settings\Settings.ini"][!ToggleConfig "#Path#\Settings" "Settings.ini"]
DynamicVariables=1
AntiAlias=1