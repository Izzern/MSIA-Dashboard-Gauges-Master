[Variables]
@includeGaugeVars=#@#Gauges\Settings\VariablesGauges.inc
@includeHardware=#@#Gauges\Settings\VariablesHardware.inc
@includeUserVars=#@#Gauges\Settings\VariablesUser.inc
@includeMeasures=#@#Gauges\Settings\Measures.inc
@includeSettingsStyle=#@#Gauges\Styles\DefaultStyle.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc

[SelectionFrame]
Meter=Image
ImageName=#@#\Gauges\Settings\Panels\Index_1-3.png
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
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\GaugesSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabPosition]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\GaugesPosition" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabStyle]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\GaugesStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;----------------------------- Fonts -----------------------------
;=================================================================
[FontContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle #Spacing1#,0,#ContainerSelectionW#,(80 * #SettingsScale#) | Fill Color 180,180,50,255 | Stroke Color 0,0,0,0 | Extend Odd

Odd=#Odd#

[FontText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Fonts:"
AntiAlias=1

[InstructionFonts] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=#BoxValueLgSpacingX#r
Y=#Spacing3#r
Text="Type the desired font and press the Enter key."
AntiAlias=1

;------------------------ Font Face Perct ------------------------
[FontFacePerctText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontFacePerct#
X=#Column1X#
Y=(30 * #SettingsScale#)r
Text="Percent Font"
AntiAlias=1

[MeterFontFacePerct]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
LeftMouseUpAction=[!CommandMeasure "MeterInputFontFacePerct" "ExecuteBatch 1"]

[MeterFontFacePerctValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontFacePerct#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontFacePerct]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontFacePerct:X]
Y=[MeterFontFacePerctValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontFacePerct "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#FontFacePerct#

;----------------------- Font Face Temp --------------------------
[FontFaceTempText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontFaceTemp#
X=#Column2X# 
Y=0r
Text="Temp Font"
AntiAlias=1

[MeterFontFaceTemp]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontFaceTemp" "ExecuteBatch 1"]

[MeterFontFaceTempValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontFaceTemp#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontFaceTemp]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontFaceTemp:X]
Y=[MeterFontFaceTempValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontFaceTemp "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\network usage"]
DefaultValue=#FontFaceTemp#


[];===============================================================
;---------------------------- Colors -----------------------------
;=================================================================
[ColorContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle #Spacing1#,0,#ContainerSelectionW#,(550 * #SettingsScale#) | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
Y=(80 * #SettingsScale#)

Even=#Even#

[ColorText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#TitleY#r
Text="Colors:"
AntiAlias=1

[InstructionsColor]
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=#BoxValueLgSpacingX#r
Y=#Spacing3#r
Text="Type the desired value formated as R, G, B (range 0-255) and press the Enter key."
AntiAlias=1

;========================== Column 1 =============================
;---------------------- Font Color Perct -------------------------
[FontColorPerctText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontColorPerct#
X=#Column1X#
Y=#ColumnY#
Text="Percent Font"
AntiAlias=1

[MeterFontColorPerct]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontColorPerct" "ExecuteBatch 1"]

[MeterFontColorPerctValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontColorPerct#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontColorPerct]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontColorPerct:X]
Y=[MeterFontColorPerctValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontColorPerct "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#FontColorPerct#

;----------------------- Font Border Perct -----------------------
[FontEffectPerctText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontEffectPerct#
X=#Column1X#
Y=#RowSpacing#
Text="Percent Border"
AntiAlias=1

[MeterFontEffectPerct]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #FontEffectPerct#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontEffectPerct" "ExecuteBatch 1"]

[MeterFontEffectPerctValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontEffectPerct#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontEffectPerct]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontEffectPerct:X]
Y=[MeterFontEffectPerctValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontEffectPerct "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#FontEffectPerct#

;----------------------------- %1 --------------------------------
[Percent1Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel1#
X=#Column1X#
Y=#RowSpacing#
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
Text="#PercentLevel1#"
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
Command1=[!WriteKeyValue Variables PercentLevel1 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#PercentLevel1#

;----------------------------- %2 --------------------------------
[Percent2Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel2#
X=#Column1X#
Y=#RowSpacing#
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
Text="#PercentLevel2#"
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
Command1=[!WriteKeyValue Variables PercentLevel2 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#PercentLevel2#

;----------------------------- %3 --------------------------------
[Percent3Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel3#
X=#Column1X#
Y=#RowSpacing#
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
Text="#PercentLevel3#"
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
X=[MeterPercent3:X]
Y=[MeterPercent3Value:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables PercentLevel3 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#PercentLevel3#

;----------------------------- %4 --------------------------------
[Percent4Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#PercentLevel4#
X=#Column1X#
Y=#RowSpacing#
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
Text="#PercentLevel4#"
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
X=[MeterPercent4:X]
Y=[MeterPercent4Value:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables PercentLevel4 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#PercentLevel4#

;---------------------  Font Color Net Dn ------------------------
[FontColorDnText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontColorDn#
X=#Column1X#
Y=#RowSpacing#
Text="Net Download"
AntiAlias=1

[MeterFontColorDn]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontColorDn" "ExecuteBatch 1"]

[MeterFontColorDnValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontColorDn#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontColorDn]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontColorDn:X]
Y=[MeterFontColorDnValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontColorDn "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\network usage"]
DefaultValue=#FontColorDn#

;------------------- Background Color --------------------
[BGColorText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#BGColor#
X=#Column1X#
Y=#RowSpacing#
Text="Background"
AntiAlias=1

[MeterBGColor]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #BGColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputBGColor" "ExecuteBatch 1"]

[MeterBGColorValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#BGColor#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputBGColor]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterBGColor:X]
Y=[MeterBGColorValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables BGColor "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!redraw][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#BGColor#

;-------------------------- CPU Tint -----------------------------
[CPUTintText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#CPUIconTint#
X=#Column1X#
Y=#RowSpacing#
Text="CPU Icon"
AntiAlias=1

[MeterCPUTint]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputCPUTint" "ExecuteBatch 1"]

[MeterCPUTintValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#CPUIconTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputCPUTint]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterCPUTint:X]
Y=[MeterCPUTintValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables CPUIconTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\cpu temp"]
DefaultValue=#CPUIconTint#

;-------------------------- GPU Tint -----------------------------
[GPUTintText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#GPUIconTint#
X=#Column1X#
Y=#RowSpacing#
Text="GPU Icon"
AntiAlias=1

[MeterGPUTint]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputGPUTint" "ExecuteBatch 1"]

[MeterGPUTintValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#GPUIconTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputGPUTint]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterGPUTint:X]
Y=[MeterGPUTintValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables GPUIconTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"]
DefaultValue=#GPUIconTint#

[];========================= Column 2 ============================
;----------------------- Font Color Temp -------------------------
[FontColorTempText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontColorTemp#
X=#Column2X# 
Y=#ColumnY#
Text="Temp Font"
AntiAlias=1

[MeterFontColorTemp]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontColorTemp" "ExecuteBatch 1"]

[MeterFontColorTempValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontColorTemp#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontColorTemp]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontColorTemp:X]
Y=[MeterFontColorTempValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontColorTemp "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\network usage"]
DefaultValue=#FontColorTemp#

;------------------------ Font Border Temp -----------------------
[FontEffectTempText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontEffectTemp#
X=#Column2X# 
Y=#RowSpacing#
Text="Temp Border"
AntiAlias=1

[MeterFontEffectTemp]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #FontEffectTemp#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontEffectTemp" "ExecuteBatch 1"]

[MeterFontEffectTempValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontEffectTemp#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontEffectTemp]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontEffectTemp:X]
Y=[MeterFontEffectTempValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontEffectTemp "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\network usage"]
DefaultValue=#FontEffectTemp#

;----------------------------- T1 --------------------------------
[Temp1Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#TempLevel1#
X=#Column2X# 
Y=#RowSpacing#
Text="Temp Level 1"
AntiAlias=1

[MeterTemp1]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputTemp1" "ExecuteBatch 1"]

[MeterTemp1Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#TempLevel1#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputTemp1]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterTemp1:X]
Y=[MeterTemp1Value:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables TempLevel1 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\network usage"]
DefaultValue=#TempLevel1#

;----------------------------- T2 --------------------------------
[Temp2Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#TempLevel2#
X=#Column2X# 
Y=#RowSpacing#
Text="Temp Level 2"
AntiAlias=1

[MeterTemp2]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputTemp2" "ExecuteBatch 1"]

[MeterTemp2Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#TempLevel2#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputTemp2]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterTemp2:X]
Y=[MeterTemp2Value:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables TempLevel2 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\network usage"]
DefaultValue=#TempLevel2#

;----------------------------- T3 --------------------------------
[Temp3Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#TempLevel3#
X=#Column2X# 
Y=#RowSpacing#
Text="Temp Level 3"
AntiAlias=1

[MeterTemp3]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputTemp3" "ExecuteBatch 1"]

[MeterTemp3Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#TempLevel3#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputTemp3]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterTemp3:X]
Y=[MeterTemp3Value:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables TempLevel3 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\network usage"]
DefaultValue=#TempLevel3#

;----------------------------- T4 --------------------------------
[Temp4Text]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#TempLevel4#
X=#Column2X# 
Y=#RowSpacing#
Text="Temp Level 4"
AntiAlias=1

[MeterTemp4]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputTemp4" "ExecuteBatch 1"]

[MeterTemp4Value]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#TempLevel4#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputTemp4]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterTemp4:X]
Y=[MeterTemp4Value:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables TempLevel4 "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\network usage"]
DefaultValue=#TempLevel4#

;---------------------  Font Color Net Up ------------------------
[FontColorUpText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#FontColorUp#
X=#Column2X# 
Y=#RowSpacing#
Text="Net Upload"
AntiAlias=1

[MeterFontColorUp]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFontColorUp" "ExecuteBatch 1"]

[MeterFontColorUpValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#FontColorUp#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFontColorUp]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFontColorUp:X]
Y=[MeterFontColorUpValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables FontColorUp "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\network usage"]
DefaultValue=#FontColorUp#

;-------------------------- RAM Tint -----------------------------
[RAMTintText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#RamIconTint#
X=#Column2X# 
Y=#RowSpacing#
Text="RAM Icon"
AntiAlias=1

[MeterRAMTint]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputRAMTint" "ExecuteBatch 1"]

[MeterRAMTintValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#RAMIconTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputRAMTint]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterRAMTint:X]
Y=[MeterRAMTintValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables RAMIconTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\memory usage"]
DefaultValue=#RAMIconTint#

;------------------- Network Icon Color --------------------
[NetIconText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#NetIconTint#
X=#Column2X# 
Y=#RowSpacing#
Text="Net Icon"
AntiAlias=1

[MeterNetIcon]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputNetIcon" "ExecuteBatch 1"]

[MeterNetIconValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#NetIconTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputNetIcon]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterNetIcon:X]
Y=[MeterNetIconValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables NetIconTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\network usage"]
DefaultValue=#NetIconTint#

[MeterRAMTint]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputRAMTint" "ExecuteBatch 1"]

[MeterRAMTintValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#RAMIconTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputRAMTint]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterRAMTint:X]
Y=[MeterRAMTintValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables RAMIconTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\memory usage"]
DefaultValue=#RAMIconTint#

;--------------------- Wifi Signal Bar Color ---------------------
[WifiIconColorText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
FontColor=#WifiIconTint#
X=#Column2X# 
Y=#RowSpacing#
Text="Wifi Icon"
AntiAlias=1

[MeterWifiIconColor]
Meter=Shape
Container=ContainerSelection
X=#MeterInputLgSpacingX#r
Y=#MeterInputLgSpacingY#r
Shape=Rectangle 0,0,#BoxValueLgW#,#BoxValueLgH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputWifiIconColor" "ExecuteBatch 1"]

[MeterWifiIconColorValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueLgSpacingX#r
Y=#BoxValueLgSpacingY#r
Text="#WifiIconTint#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputWifiIconColor]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterWifiIconColor:X]
Y=[MeterWifiIconColorValue:Y]
W=#BoxValueLgW#
H=#BoxInputLgH#
Command1=[!WriteKeyValue Variables WifiIconTint "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#WifiIconTint#