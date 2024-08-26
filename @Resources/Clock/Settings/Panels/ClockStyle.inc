[Variables]
@includeUserVars=#@#Gauges\Settings\VariablesUser.inc
@includeClockVars=#@#Clock\Settings\VariablesClock.inc
@includeClockUserVars=#@#Clock\Settings\VariablesUser.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc

[SelectionFrame]
Meter=Image
ImageName=#@#\Clock\Settings\Panels\Index_3-3.png
GrayScale=1
ImageTint=#ColorTint#,#FrameAlpha#
Y=#SelectionFrameY#
H=#SelectionFrameH#
W=#SelectionFrameW#

[TabSystem] 
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=#SideTabX#
Y=#SideTabY#
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Clock\Settings\Panels\ClockSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabPosition]
Meter=Shape
Shape=Rectangle #Spacing3#,Spacing2#,(99 * #SettingsScale#),(47 * #SettingsScale#),(3 * #SettingsScale#) | Fill Color 20,20,20,140 | Extend SideTab
X=#Spacing1#r
Y=(#SideTabH# + (4 * #SettingsScale#))r
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Clock\Settings\Panels\ClockPosition" "#CURRENTPATH#Settings.ini"][!Refresh]

;SideTab=#SideTab#

[TabStyle]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=(#SideTabH# -(4 * #SettingsScale#))r
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Clock\Settings\Panels\ClockStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;----------------------------- Mode ------------------------------
;=================================================================
[ModeContainerClock]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd
X=0
Y=0

Odd=#Odd#

[ModeTextClock]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Mode:"
AntiAlias=1

[MeasureToggleModeClock]
Meter=String
MeasureName=#ModeClock#
UpdateDivider=-1
IfMatch=Light
IfMatchAction=[!SetOption MeterToggleClockLight Text "#Checked#"][!SetOption MeterToggleClockDark Text "#Unchecked#"][!UpdateMeter *][!Refresh][!Refresh "#PATH#\Clock"][!Redraw]
IfNotMatchAction=[!SetOption MeterToggleClockDark Text "#Checked#"][!SetOption MeterToggleClockLight Text "#Unchecked#"][!UpdateMeter *][!Refresh][!Refresh "#PATH#\Clock"][!Redraw]

[ToggleModeClock]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ButtonToggleW#,#ButtonToggleH#,#ButtonToggleR# | Fill Color #FontColor#,200 | StrokeColor #FontColor# | StrokeWidth #Spacing1#
X=#ButtonToggleX#r
Y=(#ButtonToggleY# + #Spacing1#)r

[IndicatorModeClock]
Meter=Shape
Container=ContainerSelection
Shape=Ellipse 0, 0,(9 * #SettingsScale#) | Fill Color #FontEffectColor#,240 | StrokeColor #FontColor# | StrokeWidth #Spacing2#
X=(#IndicatorPositionClock# * #SettingsScale#)r
Y=#ButtonToggleY#r

[MeterToggleClockLight]
Meter=String
Container=ContainerSelection
MeasureName=MeasureToggleModeClock
MeterStyle=ButtonStyle
FontColor=0,0,0,0
SolidColor=0,0,0,0
X=(82 * #SettingsScale#)
Y=0r
H=#BoxModeSize#
W=#BoxModeSize#
LeftMouseUpAction=[!WriteKeyValue Variables ModeClock "Light" "#@#Clock\Settings\VariablesUser.inc"][!WriteKeyValue Variables AnalogPrimaryColor "255,255,255" "#@#Clock\Settings\VariablesClock.inc"][!WriteKeyValue Variables AnalogSecondaryColor "0,0,0" "#@#Clock\Settings\VariablesClock.inc"][!WriteKeyValue Variables IndicatorPositionClock "6" "#@#Settings\SettingsVariables.inc"][!UpdateMeter MeasureToggleModeClock][!Refresh "#PATH#\Clock"][!Refresh][!Redraw]

ToolTipType=1
ToolTipText="Light"

[MeterToggleClockDark]
Meter=String
Container=ContainerSelection
MeasureName=MeasureToggleModeClock
MeterStyle=ButtonStyle
FontColor=0,0,0,0
SolidColor=0,0,0,0
X=#ButtonToggleH#r
Y=0r
H=#BoxModeSize#
W=#BoxModeSize#
LeftMouseUpAction=[!WriteKeyValue Variables ModeClock "Dark" "#@#Clock\Settings\VariablesUser.inc"][!WriteKeyValue Variables AnalogPrimaryColor "0,0,0" "#@#Clock\Settings\VariablesClock.inc"][!WriteKeyValue Variables AnalogSecondaryColor "255,255,255" "#@#Clock\Settings\VariablesClock.inc"][!WriteKeyValue Variables IndicatorPositionClock "19" "#@#Settings\SettingsVariables.inc"][!UpdateMeter MeasureToggleModeClock][!UpdateMeter MeasureToggleModeClock][!Refresh "#PATH#\Clock"][!Refresh][!Redraw]
ToolTipType=1
ToolTipText="Dark"

[];===============================================================
;---------------------------- Layout -----------------------------
;=================================================================
[ContainerClockSelection]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerSelectionH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
X=0
Y=#ContainerScaleH#

Even=#Even#

[ClockSelectionText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Layout:"
AntiAlias=1

[MeasureLayoutSelection]
Measure=String
String=#Layout#
UpdateDivider=-1
IfMatch=Chronometer
IfMatchAction=[!SetOption ImageChronometer ImageTint "#ColorTint#"][!SetOption ImageChronometer02 ImageTint " "][!SetOption ImageCompactDigital ImageTint " "][!Redraw]
IfMatch2=Chronometer02
IfMatchAction2=[!SetOption ImageChronometer ImageTint " "][!SetOption ImageChronometer02 ImageTint "#ColorTint#"][!SetOption ImageCompactDigital ImageTint " "][!Redraw]
IfMatch3=CompactForecast
IfMatchAction3=[!SetOption ImageChronometer ImageTint " "][!SetOption ImageChronometer02 ImageTint " "][!SetOption ImageCompactDigital ImageTint "#ColorTint#"][!Redraw]

[ImageChronometer]
Meter=Image
Container=ContainerSelection
ImageName=#@#Clock\Settings\Images\Chronometer.png
ImageTint=
Alpha=255
X=(30 * #SettingsScale#)r
Y=(30 * #SettingsScale#)r
H=(60 * #SettingsScale#)
W=(60 * #SettingsScale#)
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables Layout "Chronometer" "#@#Clock\Settings\VariablesUser.inc"][!UpdateMeasure MeasureLayoutSelection][!Refresh "#PATH#\Clock"][!Refresh]

[ImageChronometer02]
Meter=Image
Container=ContainerSelection
ImageName=#@#Clock\Settings\Images\Chronometer02.png
ImageTint=
X=(90 * #SettingsScale#)r
Y=(0 * #SettingsScale#)r
H=(60 * #SettingsScale#)
W=(60 * #SettingsScale#)
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables Layout "Chronometer02" "#@#Clock\Settings\VariablesUser.inc"][!UpdateMeasure MeasureLayoutSelection][!Refresh "#PATH#\Clock"][!Refresh]

[ImageCompactDigital]
Meter=Image
Container=ContainerSelection
ImageName=#@#Clock\Settings\Images\CompactDigital.png
ImageTint=
X=(95 * #SettingsScale#)r
Y=(0 * #SettingsScale#)r
H=(60 * #SettingsScale#)
W=(225 * #SettingsScale#)
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables Layout "CompactForecast" "#@#Clock\Settings\VariablesUser.inc"][!UpdateMeasure MeasureLayoutSelection][!Refresh "#PATH#\Clock"][!Refresh]