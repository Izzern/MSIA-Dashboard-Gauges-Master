[Variables]
@includeUserVars=#@#Gauges\Settings\VariablesUser.inc
@includeClockVars=#@#Clock\Settings\VariablesClock.inc
@includeClockUserVars=#@#Clock\Settings\VariablesUser.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc

[SelectionFrame]
Meter=Image
ImageName=#@#\Clock\Settings\Panels\Index_3-1.png
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
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Clock\Settings\Panels\ClockSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

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
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Clock\Settings\Panels\ClockStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;----------------------------- Scale -----------------------------
;=================================================================
[ScaleContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd
X=0
Y=0

Odd=#Odd#

[ScaleText] ;Scale Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Scale:"
AntiAlias=1

[InstructionScale] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=(55 * #SettingsScale#)r
Y=#Spacing3#r
Text="Type the desired value and press the Enter key. (Use a leading zero#CRLF#for values <1 i.e. 0.5)"
AntiAlias=1

[MeterScale] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(480 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputScale" "ExecuteBatch 1"]

[MeterScaleValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#Scale#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputScale] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterScale:X]
Y=[MeterScaleValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables Scale "$UserInput$" "#@#Clock\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\Clock"]
DefaultValue=#Scale#