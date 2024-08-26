[Variables]
@includeHardware=#@#Gauges\Settings\VariablesHardware.inc
@includeUserVars=#@#Visualizer\Settings\VariablesUser.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc
@includeDefaults=#SKINSPATH##PATH#\Settings\Defaults\Default.inc

[SelectionFrame]
Meter=Image
ImageName=#@#Visualizer\Settings\Panels\Index_4-3.png
GrayScale=1
ImageTint=#ColorTint#,#FrameAlpha#
Y=#SelectionFrameY#
H=#SelectionFrameH#
W=#SelectionFrameW#
AntiAlias=1

[TabSystem] 
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=#SideTabX#
Y=#SideTabY#
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Visualizer\Settings\Panels\VisualizerSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabPosition]
Meter=Shape
Shape=Rectangle #Spacing3#,Spacing2#,(99 * #SettingsScale#),(47 * #SettingsScale#),(3 * #SettingsScale#) | Fill Color 20,20,20,140 | Extend SideTab
X=#Spacing1#r
Y=(#SideTabH# + (4 * #SettingsScale#))r

;SideTab=#SideTab#

[TabStyle]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=(#SideTabH# -(4 * #SettingsScale#))r
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Visualizer\Settings\Panels\VisualizerStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;------------------------- Vis Selection -------------------------
;=================================================================
[VisualizerContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,(165 * #SettingsScale#) | Fill Color 100,100,255,255 | Stroke Color 0,0,0,0 | Extend Odd
Y=0
Odd=#Odd#

[BGSelectionText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#Spacing3#r
Text="Background:"
AntiAlias=1

[MeasureBGState]
Meter=String
MeasureName=#BGType#
UpdateDivider=-1
IfMatch=Image
IfMatchAction=[!SetOption MeterToggleImage Text "#Checked#"][!SetOption MeterToggleGradient Text "#Unchecked#"][!SetOption MeterToggleColor Text "#Unchecked#"][!SetOption MeterTogglePeaks Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfMatch2=Gradient
IfMatchAction2=[!SetOption MeterToggleImage Text "#Unchecked#"][!SetOption MeterToggleGradient Text "#Checked#"][!SetOption MeterToggleColor Text "#Unchecked#"][!SetOption MeterTogglePeaks Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfMatch3=Color
IfMatchAction3=[!SetOption MeterToggleImage Text "#Unchecked#"][!SetOption MeterToggleGradient Text "#Unchecked#"][!SetOption MeterToggleColor Text "#Checked#"][!SetOption MeterTogglePeaks Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfMatch4=Peaks
IfMatchAction4=[!SetOption MeterToggleImage Text "#Unchecked#"][!SetOption MeterToggleGradient Text "#Unchecked#"][!SetOption MeterToggleColor Text "#Unchecked#"][!SetOption MeterTogglePeaks Text "#Checked#"][!UpdateMeter *][!Redraw]

[MeterToggleImage]
Meter=String
Container=ContainerSelection
MeasureName=MeasureBGState
MeterStyle=ButtonStyle
X=([BGSelectionText:X] + (70 * #SettingsScale#))
Y=([BGSelectionText:Y] - (118 * #SettingsScale#))
H=#BoxCheckSize#
W=#BoxCheckSize#
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables BGType "Image" "#@#\Visualizer\Settings\VariablesUser.inc"][!UpdateMeter MeterToggleImage][!UpdateMeter MeterToggleGradient][!UpdateMeter MeterToggleColor][!UpdateMeter MeterTogglePeaks][!Refresh][!Refresh "#PATH#\visualizer"]

[ImageText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleImage:X] - (80 * #SettingsScale#))
Y=([MeterToggleImage:Y] - (127 * #SettingsScale#))
Text="Image"
AntiAlias=1
ClipString=1

[MeterToggleGradient]
Meter=String
Container=ContainerSelection
MeasureName=MeasureBGState
MeterStyle=ButtonStyle
X=([BGSelectionText:X] + (270 * #SettingsScale#))
Y=([BGSelectionText:Y] - (118 * #SettingsScale#))
H=#BoxCheckSize#
W=#BoxCheckSize#
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables BGType "Gradient" "#@#\Visualizer\Settings\VariablesUser.inc"][!UpdateMeter MeterToggleImage][!UpdateMeter MeterToggleGradient][!UpdateMeter MeterToggleColor][!UpdateMeter MeterTogglePeaks][!Refresh][!Refresh "#PATH#\visualizer"]

[GradientText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleGradient:X] - (80 * #SettingsScale#))
Y=([MeterToggleGradient:Y] - (127 * #SettingsScale#))
Text="Gradient"
AntiAlias=1
ClipString=1

[MeterToggleColor]
Meter=String
Container=ContainerSelection
MeasureName=MeasureBGState
MeterStyle=ButtonStyle
X=([BGSelectionText:X] + (70 * #SettingsScale#))
Y=#RowSpacing#
H=#BoxCheckSize#
W=#BoxCheckSize#
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables BGType "Color" "#@#\Visualizer\Settings\VariablesUser.inc"][!UpdateMeter MeterToggleImage][!UpdateMeter MeterToggleGradient][!UpdateMeter MeterToggleColor][!UpdateMeter MeterTogglePeaks][!Refresh][!Refresh "#PATH#\visualizer"]

[ColorText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleColor:X] - (80 * #SettingsScale#))
Y=([MeterToggleColor:Y] - (127 * #SettingsScale#))
Text="Color"
AntiAlias=1
ClipString=1

[];===============================================================
;----------------------------- Alpha -----------------------------
;=================================================================
[AlphaUserContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
X=0
Y=(40 * #SettingsScale#)r

Even=#Even#

[InstructionText] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=#TitleX#
Y=#Spacing3#r
Text="Type the desired value and press the Enter key. (Use a leading zero for values <1 i.e. 0.5)"
AntiAlias=1

[AlphaUserText] ;AlphaUser Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(30 * #SettingsScale#)r
Text="Alpha (0-100):"
AntiAlias=1

[MeterAlphaUser] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputAlphaUser" "ExecuteBatch 1"]

[MeterAlphaUserValue] ;Current AlphaUser
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#AlphaUser#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputAlphaUser] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterAlphaUser:X]
Y=[MeterAlphaUserValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables AlphaUser "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#AlphaUser#

[];===============================================================
;--------------------------- BarWidth ----------------------------
;=================================================================
[BarWidthContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd
X=0
Y=(40 * #SettingsScale#)r

Odd=#Odd#

[BarWidthText] ;BarWidth Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(25 * #SettingsScale#)r
Text="BarWidth:"
AntiAlias=1

[MeterBarWidth] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputBarWidth" "ExecuteBatch 1"]

[MeterBarWidthValue] ;Current BarWidth
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#BarWidth#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputBarWidth] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterBarWidth:X]
Y=[MeterBarWidthValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables BarWidth "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#BarWidth#

[];===============================================================
;--------------------------- BarHeight ---------------------------
;=================================================================
[BarHeightContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
X=0
Y=(50 * #SettingsScale#)r

Even=#Even#

[BarHeightText] ;BarHeight Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(24 * #SettingsScale#)r
Text="BarHeight:"
AntiAlias=1

[MeterBarHeight] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputBarHeight" "ExecuteBatch 1"]

[MeterBarHeightValue] ;Current BarHeight
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#BarHeight#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputBarHeight] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterBarHeight:X]
Y=[MeterBarHeightValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables BarHeight "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#BarHeight#

[];===============================================================
;-------------------------- BarSpacingX --------------------------
;=================================================================
[BarSpacingXContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd
X=0
Y=(50 * #SettingsScale#)r

Odd=#Odd#

[BarSpacingXText] ;BarSpacingX Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(22 * #SettingsScale#)r
Text="BarSpacingX:"
AntiAlias=1

[MeterBarSpacingX] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputBarSpacingX" "ExecuteBatch 1"]

[MeterBarSpacingXValue] ;Current BarSpacingX
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#BarSpacingX#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputBarSpacingX] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterBarSpacingX:X]
Y=[MeterBarSpacingXValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables BarSpacingX "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#BarSpacingX#

[];===============================================================
;------------------------- PercentBottom -------------------------
;=================================================================
[PercentBottomContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
X=0
Y=(45 * #SettingsScale#)r

Even=#Even#

[PercentBottomText] ;PercentBottom Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(24 * #SettingsScale#)r
Text="Visible % of Reflection:"
AntiAlias=1

[MeterPercentBottom] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputPercentBottom" "ExecuteBatch 1"]

[MeterPercentBottomValue] ;Current PercentBottom
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#PercentBottom#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputPercentBottom] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterPercentBottom:X]
Y=[MeterPercentBottomValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables PercentBottom "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#PercentBottom#