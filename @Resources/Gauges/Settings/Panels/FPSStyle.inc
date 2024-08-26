[Variables]
@includeGaugeVars=#@#Gauges\Settings\VariablesGauges.inc
@includeHardware=#@#Gauges\Settings\VariablesHardware.inc
@includeUserVars=#@#Gauges\Settings\VariablesUser.inc
@includeMeasures=#@#Gauges\Settings\Measures.inc
@includeSettingsStyle=#@#Gauges\Styles\DefaultStyle.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc

[SelectionFrame]
Meter=Image
ImageName=#@#\Gauges\Settings\Panels\Index_2-3.png
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
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSPosition" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabStyle]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\FPSStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;--------------------------- Font Face ---------------------------
;=================================================================
[FontContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,(80 * #SettingsScale#) | Fill Color 180,180,50,255 | Stroke Color 0,0,0,0 | Extend Odd

Odd=#Odd#

[FontFaceFPSText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Font Face:"
AntiAlias=1

[MeterFontFaceFPS]
Meter=Shape
Container=ContainerSelection
X=(85 * #SettingsScale#)r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontFaceFPS" "ExecuteBatch 1"]

[MeterFontFaceFPSValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(58 * #SettingsScale#)r
Y=#BoxValueLgSpacingY#r
Text="#FontFaceFPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontFaceFPS]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontFaceFPS:X]
Y=[MeterFontFaceFPSValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontFaceFPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#FontFaceFPS#

[InstructionFont]
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=(70 * #SettingsScale#)r
Y=0r
Text="Type the desired font and press the Enter key."
AntiAlias=1

[];===============================================================
;---------------------------- Colors -----------------------------
;=================================================================
[ColorContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle #Spacing1#,0,#ContainerSelectionW#,(600 * #SettingsScale#) | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
Y=(50 * #SettingsScale#)

Even=#Even#

[ColorText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Colors:"
AntiAlias=1

[InstructionColor]
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=(75 * #SettingsScale#)
Y=#Spacing3#r
Text="Type the desired value formated as R, G, B (range 0-255) and press Enter."
AntiAlias=1

[];========================= Column 1 ============================

;----------------------------- %1 --------------------------------
[Percent1Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel1FPS#
X=#Column1X#
Y=#ColumnY#
Text="Percent Level 1"
AntiAlias=1

[MeterPercent1]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputPercent1" "ExecuteBatch 1"]

[MeterPercent1Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#PercentLevel1FPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputPercent1]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterPercent1:X]
Y=[MeterPercent1Value:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables PercentLevel1FPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#PercentLevel1FPS#

;----------------------------- %2 --------------------------------
[Percent2Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel2FPS#
X=#Column1X#
Y=#BoxValueLgSpacingX#r
Text="Percent Level 2"
AntiAlias=1

[MeterPercent2]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputPercent2" "ExecuteBatch 1"]

[MeterPercent2Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#PercentLevel2FPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputPercent2]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=([MeterPercent2:X])
Y=([MeterPercent2Value:Y])
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables PercentLevel2FPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#PercentLevel2FPS#

;----------------------------- %3 --------------------------------
[Percent3Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel3FPS#
;StringStyle=Bold
X=#Column1X#
Y=#BoxValueLgSpacingX#r
Text="Percent Level 3"
AntiAlias=1

[MeterPercent3]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputPercent3" "ExecuteBatch 1"]

[MeterPercent3Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#PercentLevel3FPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputPercent3]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=([MeterPercent3:X])
Y=([MeterPercent3Value:Y])
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables PercentLevel3FPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#PercentLevel3FPS#

;----------------------------- %4 --------------------------------
[Percent4Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel4FPS#
;StringStyle=Bold
X=#Column1X#
Y=#BoxValueLgSpacingX#r
Text="Percent Level 4"
AntiAlias=1

[MeterPercent4]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputPercent4" "ExecuteBatch 1"]

[MeterPercent4Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#PercentLevel4FPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputPercent4]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=([MeterPercent4:X])
Y=([MeterPercent4Value:Y])
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables PercentLevel4FPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#PercentLevel4FPS#

[];========================= Column 2 ============================
;----------------------- Background Color ------------------------
[BackgroundColorText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#BGColorFPS#
X=#Column2X#
Y=#ColumnY#
Text="Background Color"
AntiAlias=1

[MeterBackgroundColor]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #BGColorFPS#,30 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputBackgroundColor" "ExecuteBatch 1"]

[MeterBackgroundColorValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=(5 * #SettingsScale#)r
Text="#BGColorFPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputBackgroundColor]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=([MeterBackgroundColor:X])
Y=([MeterBackgroundColorValue:Y])
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables BGColorFPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#BGColorFPS#

;--------------------------- Gear Tint ---------------------------
[GearTintText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#GearTint#
;StringStyle=Bold
X=#Column2X#
Y=#BoxValueLgSpacingX#r
Text="Gear"
AntiAlias=1

[MeterGearTint]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputGearTint" "ExecuteBatch 1"]

[MeterGearTintValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#GearTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputGearTint]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=([MeterGearTint:X])
Y=([MeterGearTintValue:Y])
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables GearTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#GearTint#

;-------------------------- Icon Color ---------------------------
[IconColorText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FPSIconTint#
;StringStyle=Bold
X=#Column2X#
Y=#BoxValueLgSpacingX#r
Text="Icon"
AntiAlias=1

[MeterIconColor]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputIconColor" "ExecuteBatch 1"]

[MeterIconColorValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FPSIconTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputIconColor]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=([MeterIconColor:X])
Y=([MeterIconColorValue:Y])
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FPSIconTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#FPSIconTint#

;----------------------- FPS Border Color ------------------------
[FPSBorderColorText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#BorderColorFPS#
X=#Column2X#
Y=#BoxValueLgSpacingX#r
Text="Text Border Color"
AntiAlias=1

[FPSBorderColor]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #BorderColorFPS#
LeftMouseUpAction=[!CommandMeasure "MeterInputFPSBorderColor" "ExecuteBatch 1"]

[MeterFPSBorderColorValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#BorderColorFPS#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFPSBorderColor]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[FPSBorderColor:X]
Y=[MeterFPSBorderColorValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables BorderColorFPS "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\fps Counter"]
DefaultValue=#BorderColorFPS#