[Variables]
@includeGaugeVars=#@#Gauges\Settings\VariablesGauges.inc
@includeHardware=#@#Gauges\Settings\VariablesHardware.inc
@includeUserVars=#@#Gauges\Settings\VariablesUser.inc
@includeMeasures=#@#Gauges\Settings\Measures.inc
@includeSettingsStyle=#@#Gauges\Styles\DefaultStyle.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc

[SelectionFrame]
Meter=Image
ImageName=#@#\Gauges\Settings\Panels\Index_2-2.png
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
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabPosition]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSPosition" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabStyle]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;----------------------------- Text ------------------------------
;=================================================================
[TextOffsetContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,(90 * #SettingsScale#) | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd
X=0
Y=0

Odd=#Odd#

[GaugeTitle] ;Gauge Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Gauge:"
AntiAlias=1

[InstructionTextOffset] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=(20 * #SettingsScale#)r
Y=(30 * #SettingsScale#)r
Text="Type the desired value and press the Enter key. (Use a leading zero for values <1 i.e. 0.5)"
AntiAlias=1

;--------------------------- X Offset ----------------------------
[TextOffsetXText] ;Position Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#Column1X#
Y=(40 * #SettingsScale#)r
Text="Text Offset X:"
AntiAlias=1

[MeterTextOffsetX] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(145 * #SettingsScale#)r
Y=(-3 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputTextOffsetX" "ExecuteBatch 1"]

[MeterTextOffsetXValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxInputMdSpacingY#r
Text="#TextFPSX#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputTextOffsetX] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
StringAlign=Center
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
SolidColor=215,215,215,255
X=[MeterTextOffsetX:X]
Y=[MeterTextOffsetXValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables TextFPSX "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
DefaultValue=#TextFPSX#

;--------------------------- Y Offset ----------------------------
[TextOffsetYText] ;Position Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#Column2X#
Y=(-3 * #SettingsScale#)r
Text="Text Offset Y:"
AntiAlias=1

[MeterTextOffsetY] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(145 * #SettingsScale#)r
Y=(-3 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputTextOffsetY" "ExecuteBatch 1"]

[MeterTextOffsetYValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxInputMdSpacingY#r
Text="#TextFPSY#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputTextOffsetY] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=ButtonStyle
StringAlign=center
SolidColor=215,215,215,255
X=[MeterTextOffsetY:X]
Y=[MeterTextOffsetYValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables TextFPSY "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
DefaultValue=#TextFPSY#

;---------------------------- Overlay ----------------------------
[OverlayContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerSelectionH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
X=0
Y=(125 * #SettingsScale#)

Even=#Even#

[OverlayTitle] ;Overlay Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Overlay:"
AntiAlias=1

[InstructionOverlayOffset] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=(20 * #SettingsScale#)r
Y=(30 * #SettingsScale#)r
Text="Type the desired value and press the Enter key. (Use a leading zero for values <1 i.e. 0.5)"
AntiAlias=1

;----------------------- X Offset Overlay ------------------------
[OverlayOffsetXText] ;Position Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#Column1X#
Y=(40 * #SettingsScale#)r
Text="Overlay Offset X:"
AntiAlias=1

[MeterOverlayOffsetX] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(145 * #SettingsScale#)r
Y=(-3 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputOverlayOffsetX" "ExecuteBatch 1"]

[MeterOverlayOffsetXValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxInputMdSpacingY#r
Text="#OverlayOffsetX#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputOverlayOffsetX] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
StringAlign=Center
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
SolidColor=215,215,215,255
X=[MeterOverlayOffsetX:X]
Y=[MeterOverlayOffsetXValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables OverlayOffsetX "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
DefaultValue=#OverlayOffsetX#

;----------------------- Y Offset Overlay ------------------------
[OverlayOffsetYText] ;Position Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#Column2X#
Y=0r
Text="Overlay Offset Y:"
AntiAlias=1

[MeterOverlayOffsetY] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(145 * #SettingsScale#)r
Y=(-3 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputOverlayOffsetY" "ExecuteBatch 1"]

[MeterOverlayOffsetYValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxInputMdSpacingY#r
Text="#OverlayOffsetY#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputOverlayOffsetY] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=ButtonStyle
StringAlign=center
SolidColor=215,215,215,255
X=[MeterOverlayOffsetY:X]
Y=[MeterOverlayOffsetYValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables OverlayOffsetY "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
DefaultValue=#OverlayOffsetY#

;------------------------- Overlay Width -------------------------
[OverlayWText] ;Position Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#Column1X#
Y=(50 * #SettingsScale#)r
Text="Overlay Width:"
AntiAlias=1

[MeterOverlayW] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(145 * #SettingsScale#)r
Y=(-3 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputOverlayW" "ExecuteBatch 1"]

[MeterOverlayWValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxInputMdSpacingY#r
Text="#OverlayW#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputOverlayW] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
StringAlign=Center
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
SolidColor=215,215,215,255
X=[MeterOverlayW:X]
Y=[MeterOverlayWValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables OverlayW "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
DefaultValue=#OverlayW#

;------------------------ Overlay Height -------------------------
[OverlayHText] ;Position Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#Column2X#
Y=0r
Text="Overlay Height:"
AntiAlias=1

[MeterOverlayH] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(145 * #SettingsScale#)r
Y=(-3 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputOverlayH" "ExecuteBatch 1"]

[MeterOverlayHValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxInputMdSpacingY#r
Text="#OverlayH#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputOverlayH] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=ButtonStyle
StringAlign=center
SolidColor=215,215,215,255
X=[MeterOverlayH:X]
Y=[MeterOverlayHValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables OverlayH "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
DefaultValue=#OverlayH#