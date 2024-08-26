[Variables]
;@includeVars=#@#\Gauges\VariablesGauges.inc
@includeSettingsVars=#@#SettingsVariables.inc

[SelectionFrame]
Meter=Image
ImageName=#@#\SettingsPages\Images\Index_1-1.png
GrayScale=1
ImageTint=#ColorTint#,#FrameAlpha#
Y=#Spacing1#
H=#SelectionFrameH#
W=#SelectionFrameW#
AntiAlias=1

[TabSystem] 
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=#SideTabX#
Y=#SideTabY#
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "GaugesSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabPosition]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
LeftMouseUpAction=[!WriteKeyValue Variables Selection "GaugesPosition" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[TabStyle]
Meter=Shape
Shape=Rectangle 0,0,#SideTabW#,#SideTabH# | Extend SideTab
X=0r
Y=#SideTabH#r
LeftMouseUpAction=[!WriteKeyValue Variables Selection "GaugesStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

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
Text=Scale:
AntiAlias=1

[InstructionScale] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=(55 * #SettingsScale#)r
Y=#Spacing3#r
Text=Type the desired value and press the "Enter" key. (Use a leading zero#CRLF#for values <1 i.e. "0.5")
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
Text=#ScaleGauge#
AntiAlias=1
ToolTipType=1
ToolTipText=Click to insert value.

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
AntiAlias=1
FocusDismiss=1
Command1=[!WriteKeyValue Variables ScaleGauge "$UserInput$" "#@#\Gauges\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
DefaultValue=#ScaleGauge#

[];===============================================================
;------------------------ Network Adapter ------------------------
;=================================================================
[NetworkContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,(155 * #SettingsScale#) | Fill Color 180,180,50,255 | Stroke Color 0,0,0,0 | Extend Even
Y=#ContainerScaleH#

Even=#Even#

[NetworkText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(80 * #SettingsScale#)
Text=Network Adapter:
AntiAlias=1

[MeasureToggleWifi]
Measure=Calc
Meter=String
Formula=#NetState#
UpdateDivider=-1
DynamicVariables=1
IfCondition=MeasureToggleWifi = 0
IfTrueAction=[!SetOption MeterToggleWifi Text "#Checked#"][!SetOption MeterToggleEthernet Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfFalseAction=[!SetOption MeterToggleWifi Text "#Unchecked#"][!UpdateMeter *][!Redraw]

[MeterToggleWifi]
Meter=String
MeasureName=MeasureToggleWifi
Container=ContainerSelection
MeterStyle=ButtonStyle
X=(170 * #SettingsScale#)r
Y=#Spacing10#r
H=#BoxCheckSize#
W=#BoxCheckSize#
AntiAlias=1
Text=
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables NetState "0" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterNameSelection "#WifiName#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterIPSelection "#WifiIP#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterConnSelection "#WifiConn#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterDNSSelection "#WifiDNS#" "#@#\Gauges\VariablesUser.inc"][!UpdateMeasure MeasureToggleWifi][!UpdateMeasure MeasureToggleEthernet][!Refresh][!Refresh "#PATH#\network usage"]

[WifiText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(300 * #SettingsScale#)
X=([MeterToggleWifi:X] - (80 * #SettingsScale#))
Y=([MeterToggleWifi:Y] - (127 * #SettingsScale#))
Text=#WifiName#
AntiAlias=1
ClipString=1

[MeasureToggleEthernet]
Measure=Calc
Meter=String
Formula=#NetState#
UpdateDivider=-1
DynamicVariables=1
IfCondition=MeasureToggleEthernet = 1
IfTrueAction=[!SetOption MeterToggleEthernet Text "#Checked#"][!SetOption MeterToggleWifi Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfFalseAction=[!SetOption MeterToggleEthernet Text "#Unchecked#"][!UpdateMeter *][!Redraw]

[MeterToggleEthernet]
Meter=String
MeasureName=MeasureToggleEthernet
Container=ContainerSelection
MeterStyle=ButtonStyle
X=(-23 * #SettingsScale#)r
Y=#RowSpacing#
H=#BoxCheckSize#
W=#BoxCheckSize#
AntiAlias=1
Text=
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables NetState "1" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterNameSelection "#EthernetName#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterIPSelection "#EthernetIP#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterConnSelection "#EthernetConn#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterDNSSelection "#EthernetDNS#" "#@#\Gauges\VariablesUser.inc"][!UpdateMeasure MeasureToggleWifi][!UpdateMeasure MeasureToggleEthernet][!Refresh][!Refresh "#PATH#\network usage"]

[EthernetText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(300 * #SettingsScale#)
X=([MeterToggleEthernet:X] - (80 * #SettingsScale#))
Y=([MeterToggleEthernet:Y] - (127 * #SettingsScale#))
Text=#EthernetName#
AntiAlias=1
ClipString=1

[InstructionMaxAdapterSpeed] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=([NetworkText:X] - (100 * #SettingsScale#))
Y=(50 * #SettingsScale#)r
Text=Input the network adapter's max speed in Mbps for network gauges and#CRLF#press the "Enter" key.
AntiAlias=1

[MeterMaxAdapterSpeed]
Meter=Shape
Container=ContainerSelection
X=(520 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputMaxAdapterSpeed" "ExecuteBatch 1"]

[MeterMaxAdapterSpeedValue]
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=#BoxValueMdH#r
Y=#BoxValueMdSpacingY#r
Text=#MaxAdapterSpeed#
AntiAlias=1
ToolTipType=1
ToolTipText=Click to insert value.

[MeterInputMaxAdapterSpeed]
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterMaxAdapterSpeed:X]
Y=[MeterMaxAdapterSpeedValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
AntiAlias=1
FocusDismiss=1
Command1=[!WriteKeyValue Variables MaxAdapterSpeed "$UserInput$" "#@#\Gauges\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"]
DefaultValue=#MaxAdapterSpeed#

[];===============================================================
;------------------------- GPU Selection -------------------------
;=================================================================
[GPUContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,(165 * #SettingsScale#) | Fill Color 100,100,255,255 | Stroke Color 0,0,0,0 | Extend Odd
Y=(225 * #SettingsScale#)
Odd=#Odd#

[GPUSelectionText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(15 * #SettingsScale#)r
Text=GPU Selection:
AntiAlias=1

[MeasureGPUState]
Measure=Calc
Meter=String
Formula=#GPUState#
UpdateDivider=-1
DynamicVariables=1
IfCondition=MeasureGPUState = 0
IfTrueAction=[!SetOption MeterToggleGPU0 Text "#Checked#"][!SetOption MeterToggleGPU1 Text "#Unchecked#"][!SetOption MeterToggleGPU2 Text "#Unchecked#"][!SetOption MeterToggleGPU3 Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfCondition2=MeasureGPUState = 1
IfTrueAction2=[!SetOption MeterToggleGPU0 Text "#Unchecked#"][!SetOption MeterToggleGPU1 Text "#Checked#"][!SetOption MeterToggleGPU2 Text "#Unchecked#"][!SetOption MeterToggleGPU3 Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfCondition3=MeasureGPUState = 2
IfTrueAction3=[!SetOption MeterToggleGPU0 Text "#Unchecked#"][!SetOption MeterToggleGPU1 Text "#Unchecked#"][!SetOption MeterToggleGPU2 Text "#Checked#"][!SetOption MeterToggleGPU3 Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfCondition4=MeasureGPUState = 3
IfTrueAction4=[!SetOption MeterToggleGPU0 Text "#Unchecked#"][!SetOption MeterToggleGPU1 Text "#Unchecked#"][!SetOption MeterToggleGPU2 Text "#Unchecked#"][!SetOption MeterToggleGPU3 Text "#Checked#"][!UpdateMeter *][!Redraw]

[MeterToggleGPU0]
Meter=String
Container=ContainerSelection
MeasureName=MeasureGPUState
MeterStyle=ButtonStyle
X=([GPUSelectionText:X] + (40 * #SettingsScale#))
Y=([GPUSelectionText:Y] - (118 * #SettingsScale#))
H=#BoxCheckSize#
W=#BoxCheckSize#
AntiAlias=1
Text=
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "0" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPUName#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU temperature" "#@#\Gauges\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU usage" "#@#\Gauges\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU dedicated memory usage \ process" "#@#\Gauges\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU0Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(260 * #SettingsScale#)
X=([MeterToggleGPU0:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU0:Y] - (127 * #SettingsScale#))
Text=#GPUName#
AntiAlias=1
ClipString=1

[MeterToggleGPU1]
Meter=String
Container=ContainerSelection
MeasureName=MeasureGPUState
MeterStyle=ButtonStyle
X=([GPUSelectionText:X] + (40 * #SettingsScale#))
Y=#RowSpacing#
H=#BoxCheckSize#
W=#BoxCheckSize#
AntiAlias=1
Text=
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "1" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPU1Name#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM1#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU1 temperature" "#@#\Gauges\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU1 usage" "#@#\Gauges\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU1 dedicated memory usage \ process" "#@#\Gauges\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU1Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(260 * #SettingsScale#)
X=([MeterToggleGPU1:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU1:Y] - (127 * #SettingsScale#))
Text=#GPU1Name#
AntiAlias=1
ClipString=1

[MeterToggleGPU2]
Meter=String
Container=ContainerSelection
MeasureName=MeasureGPUState
MeterStyle=ButtonStyle
X=([GPUSelectionText:X] + (40 * #SettingsScale#))
Y=#RowSpacing#
H=#BoxCheckSize#
W=#BoxCheckSize#
AntiAlias=1
Text=
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "2" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPU2Name#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM2#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU2 temperature" "#@#\Gauges\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU2 usage" "#@#\Gauges\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU2 dedicated memory usage \ process" "#@#\Gauges\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU2Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(260 * #SettingsScale#)
X=([MeterToggleGPU2:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU2:Y] - (127 * #SettingsScale#))
Text=#GPU2Name#
AntiAlias=1
ClipString=1

[MeterToggleGPU3]
Meter=String
Container=ContainerSelection
MeasureName=MeasureGPUState
MeterStyle=ButtonStyle
X=([GPUSelectionText:X] + (40 * #SettingsScale#))
Y=#RowSpacing#
H=#BoxCheckSize#
W=#BoxCheckSize#
AntiAlias=1
Text=
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "3" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPU3Name#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM3#" "#@#\Gauges\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU3 temperature" "#@#\Gauges\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU3 usage" "#@#\Gauges\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU3 dedicated memory usage \ process" "#@#\Gauges\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU3Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(260 * #SettingsScale#)
X=([MeterToggleGPU3:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU3:Y] - (127 * #SettingsScale#))
Text=#GPU3Name#
AntiAlias=1
ClipString=1

[];===============================================================
;---------------------------- Buttons ----------------------------
;=================================================================
[ButtonContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#SelectionFrameW#,(60 * #SettingsScale#) | Fill Color 255,255,255,20 | Stroke Color 0,0,0,0 | Extend Even
Y=(555 * #SettingsScale#)

Even=#Even#

;------------------------ Default Button -------------------------
[ContainerDefaults]
Meter=Shape
Shape=Rectangle 0,0,#ButtonBottomW#,#ButtonBottomH#,#BoxValueMdR# | Fill Color 204,0,0,255 | Stroke Color 0,0,0,0
X=(170 * #SettingsScale#)r
Y=(470 * #SettingsScale#)r

[DefaultButton]
Meter=String
Container=ContainerDefaults
FontColor=255,255,255
FontEffectColor=0,0,0
FontSize=#FontSizeTitle#
StringAlign=CENTERCENTER
StringEffect=BORDER
SolidColor=204,0,0
X=(#ButtonBottomW# / 2)r
Y=#Spacing15#r
W=#ButtonBottomW#
H=#ButtonBottomH#
Text=Restore Default Settings
AntiAlias=1
MouseOverAction=[!ShowMeter DefaultButtonActive][!HideMeter DefaultButton][!Redraw]

[DefaultButtonActive]
Meter=String
Container=ContainerDefaults
FontColor=255,255,255
FontEffectColor=0,0,0
FontSize=#FontSizeButton#
StringAlign=CENTERCENTER
StringStyle=BOLD
StringEffect=BORDER
SolidColor=204,0,0
X=r
Y=r
W=#ButtonBottomW#
H=(33 * #SettingsScale#)
Text=Restore Default Settings
AntiAlias=1
Hidden=1
ToolTipType=1
ToolTipText=Reset all Gauge settings to their defaults.
LeftMouseUpAction=[!ActivateConfig "#Path#\Settings\Defaults" "Default.ini"]
MouseLeaveAction=[!ShowMeter DefaultButton][!HideMeter DefaultButtonActive][!Redraw]

;------------------------- Script Button -------------------------
[ContainerScript]
Meter=Shape
Shape=Rectangle 0,0,#ButtonBottomW#,#ButtonBottomH#,#BoxValueMdR# | Fill Color 150,150,150,255
X=(300 * #SettingsScale#)r
Y=0r

[ScriptButton]
Meter=String
Container=ContainerScript
FontColor=255,255,255
FontEffectColor=0,0,0
FontSize=#FontSizeTitle#
StringAlign=CENTERCENTER
StringEffect=BORDER
SolidColor=#ColorTint#,200
X=(#ButtonBottomW# / 2)r
Y=#Spacing15#r
W=#ButtonBottomW#
H=#ButtonBottomH#
Text=Set Variables
AntiAlias=1
MouseOverAction=[!ShowMeter ScriptButtonActive][!HideMeter ScriptButton][!Redraw]

[ScriptButtonActive]
Meter=String
Container=ContainerScript
FontColor=255,255,255
FontEffectColor=0,0,0
FontSize=#FontSizeButton#
StringAlign=CENTERCENTER
StringStyle=BOLD
StringEffect=BORDER
X=r
Y=r
W=#ButtonBottomW#
H=(33 * #SettingsScale#)
Text=Set Variables
SolidColor=#ColorTint#,200
AntiAlias=1
Hidden=1
ToolTipType=1
ToolTipText=Sets hardware variables for tooltips and meters.#CRLF#Only use if you do not see devices or if you move/rename the folder.
LeftMouseDownAction=[!CommandMeasure "HardwareScript" "Run"][!Delay 6000][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
MouseLeaveAction=[!ShowMeter ScriptButton][!HideMeter ScriptButtonActive][!Redraw]
