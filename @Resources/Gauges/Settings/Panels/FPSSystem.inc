[Variables]
@includeGaugeVars=#@#Gauges\Settings\VariablesGauges.inc
@includeHardware=#@#Gauges\Settings\VariablesHardware.inc
@includeUserVars=#@#Gauges\Settings\VariablesUser.inc
@includeMeasures=#@#Gauges\Settings\Measures.inc
@includeSettingsStyle=#@#Gauges\Styles\DefaultStyle.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc
@includeDefaults=#SKINSPATH##PATH#\Settings\Defaults\Default.inc

[SelectionFrame]
Meter=Image
ImageName=#@#\Gauges\Settings\Panels\Index_2-1.png
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
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabPosition]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSPosition" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabStyle]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;----------------------------- Scale -----------------------------
;=================================================================
[ScaleContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd

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
Y=#BoxInputMdSpacingY#r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputScale" "ExecuteBatch 1"]

[MeterScaleValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxInputMdSpacingY#r
Text="#ScaleFPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputScale] ;Input Box
Measure=Plugin
Plugin=InputText
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterScale:X]
Y=[MeterScaleValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables ScaleFPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#ScaleFPS#

[];===============================================================
;---------------------------- Buttons ----------------------------
;=================================================================
[ButtonContainer]
Meter=Image
SolidColor=#ColorTint#,12
X=#ContainerSelectionX#
Y=(685 * #SettingsScale#)
W=#ContainerSelectionW#
H=#ContainerScaleH#

[ContainerDefaults]
Meter=Shape
Shape=Rectangle 0,0,#ButtonBottomW#,#ButtonBottomH#,#BoxValueMdR# | Fill Color 204,0,0,255 | Stroke Color 0,0,0,0
X=(([ButtonContainer:W] - #ButtonBottomW#) / 2)r
Y=(([ButtonContainer:H] - #ButtonBottomH#) / 2)r

;------------------------ Default Button -------------------------
[DefaultButton]
Meter=String
Container=ContainerDefaults
FontColor=255,255,255
FontSize=#FontSizeTitle#
StringAlign=CENTERCENTER
StringEffect=BORDER
StringEffectColor=0,0,0,255
SolidColor=204,0,0
X=(#ButtonBottomW# / 2)r
Y=#Spacing15#r
W=#ButtonBottomW#
H=#ButtonBottomH#
Text="Restore Default Settings"
AntiAlias=1
MouseOverAction=[!ShowMeter DefaultButtonActive][!HideMeter DefaultButton][!Redraw]

[DefaultButtonActive]
Meter=String
Container=ContainerDefaults
FontColor=255,255,255
FontSize=#FontSizeButton#
StringAlign=CENTERCENTER
StringStyle=BOLD
StringEffect=BORDER
StringEffectColor=0,0,0,255
SolidColor=204,0,0
X=r
Y=r
W=(220 * #SettingsScale#)
H=(33 * #SettingsScale#)
Text="Restore Default Settings"
AntiAlias=1
Hidden=1
ToolTipType=1
ToolTipText="Reset all FPS settings to their defaults."
LeftMouseDownAction=[!ToggleMeterGroup Reset][!ShowMeter ResetButton][!UpdateMeterGroup Reset][!Redraw]
LeftMouseUpAction=[!ShowMeter "DefaultButton"][!HideMeter "DefaultButtonActive"][!Redraw]
MouseLeaveAction=[!ShowMeter "DefaultButton"][!HideMeter "DefaultButtonActive"][!Redraw]

;=================================================================
;------------------------- Reset Window --------------------------
;=================================================================
[ContainerResetBG]
Meter=Shape
Group=Reset
Shape=Rectangle 0,1,#BGW#,#BGH#,(25 * #SettingsScale#) | FillColor 0,0,0,255
X=0
Y=0
Hidden=1

[ResetBG]
Meter=Image
Group=Reset
ImageName=#@#\Settings\Images\ResetBG.png
H=(215 * #SettingsScale#)
W=(500 * #SettingsScale#)
X=((#BGW#-(500 * #SettingsScale#)) / 2)
Y=((#BGH#-(215 * #SettingsScale#)) / 2)
Hidden=1

[InstructionReset] ;Instruction Text
Meter=String
Group=Reset
StringAlign=CENTER
StringStyle=BOLD
StringEffect=BORDER
StringEffectColor=255,0,0,255
StringCase=UPPER
FontFace=#FontFace#
FontColor=#fff
FontSize=(11 * #SettingsScale#)
X=((#BGW#-[ResetBG:W]) / 2)
Y=(80 * #SettingsScale#)r
Text="You are about to reset FPS settings to their default values.#CRLF#TO ACCEPT CLICK RESET."
AntiAlias=1
Hidden=1

;------------------------- Reset Button --------------------------
[ContainerResetButton]
Meter=Shape
Group=Reset
Shape=Rectangle 0,0,#ButtonBottomW#,(#ButtonBottomH# * 2),#BoxValueMdR# | StrokeWidth 0 | FillColor 204,0,0
X=(((#BGW# - #ButtonBottomW#) / 2))
Y=(60 * #SettingsScale#)r
Hidden=1

[ResetButton]
Meter=String
Container=ContainerResetButton
FontColor=255,255,255
FontSize=(24 * #SettingsScale#)
StringAlign=CENTERCENTER
StringEffect=BORDER
StringEffectColor=0,0,0,255
SolidColor=204,0,0
X=(#ButtonBottomW# / 2)r
Y=(#Spacing15# * 2)r
W=#ButtonBottomW#
H=(#ButtonBottomH# * 2)
Text="Reset"
AntiAlias=1
MouseOverAction=[!ShowMeter ResetButtonActive][!HideMeter ResetButton][!Redraw]
Hidden=1

[ResetButtonActive]
Meter=String
Container=ContainerResetButton
FontColor=255,255,255
FontSize=(30 * #SettingsScale#)
StringAlign=CENTERCENTER
StringEffect=BORDER
StringEffectColor=0,0,0,255
StringStyle=BOLD
SolidColor=204,0,0
X=r
Y=#ButtonBottomH#
W=#ButtonBottomW#
H=(#ButtonBottomH# * 2)
Text="Reset"
AntiAlias=1
Hidden=1
LeftMouseDownAction=[!CommandMeasure Defaults "ExecuteBatch 2"]
LeftMouseUpAction=[!HideMeterGroup Reset][!UpdateMeterGroup Reset][!Redraw]
MouseLeaveAction=[!ShowMeter ResetButton][!HideMeter ResetButtonActive][!Redraw]

[Defaults]
@includeDefaults=#SKINSPATH##PATH#\Settings\Defaults\Default.inc

;------------------------- Close Button --------------------------
[ContainerResetClose]
Meter=Shape
Group=Reset
Shape=Rectangle 0,0,#ButtonCloseSize#,#ButtonCloseSize#,#ButtonCloseR# | StrokeWidth 0 | FillColor 204,0,0
X=(615 * #SettingsScale#)
Y=(280 * #SettingsScale#)
Hidden=1

[CloseButtonReset]
Meter=String
Container=ContainerResetClose
StringAlign=Centercenter
FontColor=#fff
FontSize=#FontSizeText#
X=#Spacing10#r
Y=#Spacing10#r
W=#ButtonCloseSize#
H=#ButtonCloseSize#
Text="X"
SolidColor=204,0,0
AntiAlias=1
MouseOverAction=[!ShowMeter CloseButtonResetActive][!HideMeter CloseButtonReset][!Redraw]

[CloseButtonResetActive]
Meter=String
Container=ContainerResetClose
StringAlign=CenterTop
FontColor=255,255,255
FontSize=#FontSizeButton#
StringStyle=BOLD
StringAlign=CENTERCENTER
X=0r
Y=#Spacing-10#r
W=#ButtonCloseSize#
H=#ButtonCloseSize#
Text="X"
SolidColor=204,0,0
AntiAlias=1
Hidden=1
ToolTipText="Close"
LeftMouseUpAction=[!HideMeterGroup Reset][!UpdateMeterGroup Reset][!Redraw]
MouseLeaveAction=[!ShowMeter CloseButtonReset][!HideMeter CloseButtonResetActive][!Redraw]