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
ImageName=#@#Clock\Images\Chronometer-#ModeClock#.png
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
UpdateDivider=60
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
DynamicVariables=1

[ContainerClockFace]
Meter=Shape
Shape=Ellipse #AnalogR#,#AnalogR#,#AnalogR# | FillColor #AnalogPrimaryColor#,255 | StrokeWidth 0
X=#Spacing1#
Y=#Spacing1#

[MeterMinuteHand]
Meter=Image
Container=ContainerClockFace
ImageName=#@#Clock\Images\HourHand-#ModeClock#.png
ImageTint=#HandColorMinute#
W=#HandImgW#
H=#HandMinuteImgH#
X=(#AnalogR# - ([#CURRENTSECTION#:W] / 2))
Y=(#AnalogR1# - [#CURRENTSECTION#:H])
TransformationMatrix=(Cos(Rad([MeasureMinuteAngle])));(Sin(Rad([MeasureMinuteAngle])));(-Sin(Rad([MeasureMinuteAngle])));(Cos(Rad([MeasureMinuteAngle])));((#AnalogR1#) - ((#AnalogR1#) * Cos(Rad([MeasureMinuteAngle]))) + ((#AnalogR1#) * Sin(Rad([MeasureMinuteAngle]))));((#AnalogR1#) - ((#AnalogR1#) * Sin(Rad([MeasureMinuteAngle]))) - ((#AnalogR1#) * Cos(Rad([MeasureMinuteAngle]))))
DynamicVariables=1

[MeterSecondHand]
Meter=Image
Container=ContainerClockFace
ImageName=#@#Clock\Images\HourHand-#ModeClock#.png
ImageTint=#HandColorSecond#
W=#HandImgW#
H=#HandSecondImgH#
X=(#AnalogR# - ([#CURRENTSECTION#:W] / 2))
Y=(#AnalogR1# - [#CURRENTSECTION#:H])
TransformationMatrix=(Cos(Rad([MeasureSecondAngle])));(Sin(Rad([MeasureSecondAngle])));(-Sin(Rad([MeasureSecondAngle])));(Cos(Rad([MeasureSecondAngle])));((#AnalogR1#) - ((#AnalogR1#) * Cos(Rad([MeasureSecondAngle]))) + ((#AnalogR1#) * Sin(Rad([MeasureSecondAngle]))));((#AnalogR1#) - ((#AnalogR1#) * Sin(Rad([MeasureSecondAngle]))) - ((#AnalogR1#) * Cos(Rad([MeasureSecondAngle]))))
DynamicVariables=1

[MeterHourHand]
Meter=Image
Container=ContainerClockFace
ImageName=#@#Clock\Images\HourHand-#ModeClock#.png
ImageTint=#HandColorHour#
W=#HandImgW#
H=#HandHourImgH#
X=(#AnalogR# - ([#CURRENTSECTION#:W] / 2))
Y=(#AnalogR1# - [#CURRENTSECTION#:H])
TransformationMatrix=(Cos(Rad([MeasureHourAngle])));(Sin(Rad([MeasureHourAngle])));(-Sin(Rad([MeasureHourAngle])));(Cos(Rad([MeasureHourAngle])));((#AnalogR1#) - ((#AnalogR1#) * Cos(Rad([MeasureHourAngle]))) + ((#AnalogR1#) * Sin(Rad([MeasureHourAngle]))));((#AnalogR1#) - ((#AnalogR1#) * Sin(Rad([MeasureHourAngle]))) - ((#AnalogR1#) * Cos(Rad([MeasureHourAngle]))))
DynamicVariables=1

[MeterCircle]
Meter=Shape
X=#AnalogR1#
Y=#ClockHandY#
Shape=Ellipse 0,#CircleY#,#CircleR# | Fill Color #AnalogPrimaryColor# | StrokeWidth #CircleStrokeWidth# | StrokeColor #AnalogSecondaryColor#,#HandBGAlpha#
Shape2=Ellipse 0,#CircleY#,#CircleButtonR# | Fill Color 0,0,0,0 | StrokeWidth #CircleStrokeWidth# | StrokeColor 0,0,0,0
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Clock\Settings\Panels\ClockSystem" "#SKINSPATH##PATH#\Settings\Settings.ini"][!ToggleConfig "#Path#\Settings" "Settings.ini"]