[Variables]
@includeGaugeVars=#@#Gauges\Settings\VariablesGauges.inc
@includeHardware=#@#Gauges\Settings\VariablesHardware.inc
@includeUserVars=#@#Gauges\Settings\VariablesUser.inc
@includeMeasures=#@#Gauges\Settings\Measures.inc
@includeSettingsStyle=#@#Gauges\Styles\DefaultStyle.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc
@includeDefaults=#SKINSPATH##PATH#\Settings\Defaults\Default.inc
DefaultWindowPath=

[SelectionFrame]
Meter=Image
ImageName=#@#\Gauges\Settings\Panels\Index_1-1.png
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
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\GaugesSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

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
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Gauges\Settings\Panels\GaugesStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

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
Text="#ScaleGauge#"
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
Command1=[!WriteKeyValue Variables ScaleGauge "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
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
Text="Network Adapter:"
AntiAlias=1

[MeasureToggleWifi]
Measure=Calc
Meter=String
Formula=#NetState#
UpdateDivider=-1
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
LeftMouseUpAction=[!WriteKeyValue Variables NetState "0" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterNameSelection "#WifiName#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterIPSelection "#WifiIP#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterConnSelection "#WifiConn#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterDNSSelection "#WifiDNS#" "#@#\Gauges\Settings\VariablesUser.inc"][!UpdateMeasure MeasureToggleWifi][!UpdateMeasure MeasureToggleEthernet][!Refresh][!Refresh "#PATH#\network usage"]

[WifiText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(300 * #SettingsScale#)
X=([MeterToggleWifi:X] - (80 * #SettingsScale#))
Y=([MeterToggleWifi:Y] - (127 * #SettingsScale#))
Text="#WifiName#"
AntiAlias=1
ClipString=1

[MeasureToggleEthernet]
Measure=Calc
Meter=String
Formula=#NetState#
UpdateDivider=-1
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
LeftMouseUpAction=[!WriteKeyValue Variables NetState "1" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterNameSelection "#EthernetName#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterIPSelection "#EthernetIP#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterConnSelection "#EthernetConn#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables NetAdapterDNSSelection "#EthernetDNS#" "#@#\Gauges\Settings\VariablesUser.inc"][!UpdateMeasure MeasureToggleWifi][!UpdateMeasure MeasureToggleEthernet][!Refresh][!Refresh "#PATH#\network usage"]

[EthernetText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=(300 * #SettingsScale#)
X=([MeterToggleEthernet:X] - (80 * #SettingsScale#))
Y=([MeterToggleEthernet:Y] - (127 * #SettingsScale#))
Text="#EthernetName#"
AntiAlias=1
ClipString=1

[InstructionMaxAdapterSpeed] ;Instruction Text
Meter=String
Container=ContainerSelection
MeterStyle=TextStyle
X=([NetworkText:X] - (100 * #SettingsScale#))
Y=(50 * #SettingsScale#)r
Text="Input the network adapter's max speed in Mbps for network gauges and#CRLF#press the Enter key."
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
Text="#MaxAdapterSpeed#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

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
Command1=[!WriteKeyValue Variables MaxAdapterSpeed "$UserInput$" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"]
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
Text="GPU Selection:"
AntiAlias=1

[MeasureGPUState]
Measure=Calc
Meter=String
Formula=#GPUState#
UpdateDivider=-1
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
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "0" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPUName#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU temperature" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU usage" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU dedicated memory usage \ process" "#@#\Gauges\Settings\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU0Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleGPU0:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU0:Y] - (127 * #SettingsScale#))
Text="#GPUName#"
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
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "1" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPU1Name#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM1#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU1 temperature" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU1 usage" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU1 dedicated memory usage \ process" "#@#\Gauges\Settings\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU1Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleGPU1:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU1:Y] - (127 * #SettingsScale#))
Text="#GPU1Name#"
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
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "2" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPU2Name#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM2#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU2 temperature" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU2 usage" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU2 dedicated memory usage \ process" "#@#\Gauges\Settings\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU2Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleGPU2:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU2:Y] - (127 * #SettingsScale#))
Text="#GPU2Name#"
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
LeftMouseUpAction=[!WriteKeyValue Variables GPUState "3" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables GPUSelection "#GPU3Name#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables VRAMSelection "#VRAM3#" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue GPUCoreTempMSIA DataSource "GPU3 temperature" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue GPUCoreLoadMSIA DataSource "GPU3 usage" "#@#\Gauges\Settings\Measures.inc"][!WriteKeyValue VRAMProcMSIA DataSource "GPU3 dedicated memory usage \ process" "#@#\Gauges\Settings\Measures.inc"][!UpdateMeasure MeasureToggleGPU0][!UpdateMeasure MeasureToggleGPU1][!UpdateMeasure MeasureToggleGPU2][!UpdateMeasure MeasureToggleGPU3][!Refresh][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\FPS Counter"]

[GPU3Text]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleGPU3:X] - (80 * #SettingsScale#))
Y=([MeterToggleGPU3:Y] - (127 * #SettingsScale#))
Text="#GPU3Name#"
AntiAlias=1
ClipString=1

[];===============================================================
;------------------------ Style Selection ------------------------
;=================================================================
[StyleContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,255,#ContainerSelectionW#,(120 * #SettingsScale#) | Fill Color 180,180,50,255 | Stroke Color 0,0,0,0 | Extend Even
Y=#ContainerScaleH#

Even=#Even#

[StyleText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(405 * #SettingsScale#)
Text="Style Selection:"
AntiAlias=1

[DropDownStyle]
Meter=Shape
Shape=Rectangle 0,0,(200 * #SettingsScale#),(30 * #SettingsScale#) | Fill Color 255,255,255,255 | StrokeWidth 2 | Stroke Color #ColorTint#,255
X=([StyleText:X] + (150 * #SettingsScale#))
Y=[StyleText:Y]
DynamicVariables=1
LeftMouseUpAction=[!ToggleMeterGroup "DropDown"][!UpdateMeter *][!Redraw]

[DropDownText]
Meter=String
MeterStyle=DisplayStyle
X=([StyleText:X] + (155 * #SettingsScale#))
Y=10r
FontColor=0,0,0
FontSize=(#FontSizeLG# * #SettingsScale#)
StringAlign=LEFTCENTER
StringStyle=#StringStyleBold#
Text=#ActiveStyle#
AntiAlias=1
DynamicVariables=1

[DropDownCarrot]
Meter=Shape
Shape=Line 0,0,0,5 | StrokeWidth 20 | StrokeEndCap Triangle | Stroke Color 0,0,0,100
X=([DropDownStyle:X] + (180 * #SettingsScale#))
Y=-5r
DynamicVariables=1
LeftMouseUpAction=[!ToggleMeterGroup "DropDown"][!UpdateMeter *][!Redraw]

[DropDownBox]
Meter=Shape
Group=DropDown
X=([StyleText:X] + (150 * #SettingsScale#))
Y=15r
Shape=Rectangle 0,0,(200 * #SettingsScale#),(70 * #SettingsScale#) | Fill Color #FontColor#,200 | StrokeWidth 2 | Stroke Color #ColorTint#,255
Hidden=1
DynamicVariables=1

[DropdownGaugeBox]
Meter=Shape
Container=DropdownBox
X=0r
Y=4r ; Position these below the text meters
DynamicVariables=1

Shape=Rectangle 0,0,(200 * #SettingsScale#),(35 * #SettingsScale#) | StrokeWidth 0
LeftMouseUpAction=[!WriteKeyValue Variables ActiveStyle "Gauge" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeX "30" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeY "24" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorPerct "[MeasureColor]" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorTemp "[MeasureColor]" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"][!HideMeterGroup "DropDown"][!UpdateMeter *][!Redraw]

[DropdownHoneycombBox]
Meter=Shape
Container=DropdownBox
Y=4r ; Position these below the text meters
DynamicVariables=1

Shape=Rectangle 0,(35 * #SettingsScale#),(200 * #SettingsScale#),(35 * #SettingsScale#) | StrokeWidth 0
LeftMouseUpAction=[!WriteKeyValue Variables ActiveStyle "Honeycomb" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeX "25" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeY "20" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorPerct "255,255,255,240" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorTemp "255,255,255,240" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"][!HideMeterGroup "DropDown"][!UpdateMeter *][!Redraw]

[DropdownGauge]
Meter=String
MeterStyle=DisplayStyle
Group=DropDown
X=10r
Y=15r
FontSize=(#FontSizeLG# * #SettingsScale#)
FontColor=#FontEffectColor#
StringAlign=LEFTCENTER
Text="Gauge"
AntiAlias=1
DynamicVariables=1
Hidden=1
LeftMouseUpAction=[!WriteKeyValue Variables ActiveStyle "Gauge" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeX "30" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeY "24" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorPerct "[MeasureColor]" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorTemp "[MeasureColor]" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"][!HideMeterGroup "DropDown"][!UpdateMeter *][!Redraw]

[DropdownHoneycomb]
Meter=String
MeterStyle=DisplayStyle
Group=DropDown
X=0r
Y=30r
FontSize=(#FontSizeLG# * #SettingsScale#)
FontColor=#FontEffectColor#
StringAlign=LEFTCENTER
Text="Honeycomb"
AntiAlias=1
DynamicVariables=1
Hidden=1
LeftMouseUpAction=[!WriteKeyValue Variables ActiveStyle "Honeycomb" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeX "25" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables TextGaugeY "20" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorPerct "255,255,255,240" "#@#\Gauges\Settings\VariablesUser.inc"][!WriteKeyValue Variables FontColorTemp "255,255,255,240" "#@#\Gauges\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"][!HideMeterGroup "DropDown"][!UpdateMeter *][!Redraw]

[];===============================================================
;----------------------- Button Container ------------------------
;=================================================================
[ButtonContainer]
Meter=Image
SolidColor=#ColorTint#,12
X=#ContainerSelectionX#
Y=(685 * #SettingsScale#)
W=#ContainerSelectionW#
H=#ContainerScaleH#

;------------------------ Default Button -------------------------
[ContainerDefault]
Meter=Shape
Shape=Rectangle 0,0,#ButtonBottomW#,#ButtonBottomH#,#BoxValueMdR# | Fill Color 204,0,0,255 | Stroke Color 0,0,0,0
X=(75 * #SettingsScale#)r
Y=(([ButtonContainer:H] - #ButtonBottomH#) / 2)r

[DefaultButton]
Meter=String
Container=ContainerDefault
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
Text="Restore Default Settings"
AntiAlias=1
MouseOverAction=[!ShowMeter DefaultButtonActive][!HideMeter DefaultButton][!Redraw]

[DefaultButtonActive]
Meter=String
Container=ContainerDefault
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
Text="Restore Default Settings"
AntiAlias=1
Hidden=1
ToolTipType=1
ToolTipText="Reset all Gauge settings to their defaults."

LeftMouseDownAction=[!ToggleMeterGroup Reset][!ShowMeter ResetButton][!UpdateMeterGroup Reset][!Redraw]
LeftMouseUpAction=[!ShowMeter "DefaultButton"][!HideMeter "DefaultButtonActive"][!Redraw]
MouseLeaveAction=[!ShowMeter "DefaultButton"][!HideMeter "DefaultButtonActive"][!Redraw]

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
Text="Set Variables"
AntiAlias=1
DynamicVariables=1
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
SolidColor=#ColorTint#,200
X=r
Y=r
W=#ButtonBottomW#
H=(33 * #SettingsScale#)
Text="Set Variables"
AntiAlias=1
DynamicVariables=1
Hidden=1
ToolTipType=1
ToolTipText="Sets hardware variables for tooltips and meters.#CRLF#Only use if you do not see devices or if you move/rename the folder."
LeftMouseUpAction=[!CommandMeasure HardwareScript "Run"][!EnableMeasure "MeasureCountdown"][!ShowMeterGroup LoadingAnimation][!Redraw]
;[!Delay 6000][!Refresh][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"]
MouseLeaveAction=[!ShowMeter ScriptButton][!HideMeter ScriptButtonActive][!Redraw]

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
W=(500 * #SettingsScale#)
H=(215 * #SettingsScale#)
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
Text="You are about to reset Gauges to their default values.#CRLF#TO ACCEPT CLICK RESET."
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
LeftMouseDownAction=[!CommandMeasure Defaults "ExecuteBatch 1"]
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

;=================================================================
;------------------------ Loading Window -------------------------
;=================================================================
[MeasureCountdown]
Measure=Loop
StartValue=9
EndValue=360
Increment=9
LoopCount=1
DynamicVariables=1
Disabled=1
;UpdateRate=25

[MeasureVisibility]
Measure=Calc
Formula=MeasureCountdown
IfEqualValue=360
IfEqualAction=[!HideMeterGroup LoadingAnimation][!Refresh "#PATH#\cpu usage"][!Refresh "#PATH#\gpu usage"][!Refresh "#PATH#\cpu temp"][!Refresh "#PATH#\gpu temp"][!Refresh "#PATH#\memory Usage"][!Refresh "#PATH#\network usage"][!Refresh "#PATH#\wifi connectivity"][!Refresh "#PATH#\fps Counter"][!Refresh]
DynamicVariables=1

[ContainerLoadingBG]
Meter=Shape
Group=LoadingAnimation
Shape=Rectangle 0,1,#BGW#,#BGH#,(25 * #SettingsScale#) | FillColor 0,0,0,255
X=0
Y=0
DynamicVariables=1
Hidden=1

[LoadingBG]
Meter=Image
Group=LoadingAnimation
Container=ContainerLoadingBG
H=#BGH#
W=#BGW#
SolidColor=0,0,0,250
X=0r
Y=0r

[MeterRoundline]
Meter=Roundline
Container=ContainerLoadingBG
X=0
Y=0
W=#BGW#
H=#BGH#
LineColor=196,218,135,255
Solid=1
LineStart=15
LineLength=30
StartAngle=(Rad(0))
RotationAngle=(Rad([MeasureCountdown]))
AntiAlias=1
DynamicVariables=1
