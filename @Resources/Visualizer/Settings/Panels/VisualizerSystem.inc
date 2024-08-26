[Variables]
@includeHardware=#@#Gauges\Settings\VariablesHardware.inc
@includeUserVars=#@#Visualizer\Settings\VariablesUser.inc
@includeSettingsVars=#@#Settings\SettingsVariables.inc
@includeDefaults=#SKINSPATH##PATH#\Settings\Defaults\Default.inc

[SelectionFrame]
Meter=Image
ImageName=#@#Visualizer\Settings\Panels\Index_4-1.png
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
;LeftMouseUpAction=[!WriteKeyValue Variables Selection "Visualizer\Settings\Panels\VisualizerSystem" "#CURRENTPATH#Settings.ini"][!Refresh]

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
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Visualizer\Settings\Panels\VisualizerStyle" "#CURRENTPATH#Settings.ini"][!Refresh]

SideTab=#SideTab#

[];===============================================================
;------------------------- GPU Selection -------------------------
;=================================================================
[VisualizerContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,(165 * #SettingsScale#) | Fill Color 100,100,255,255 | Stroke Color 0,0,0,0 | Extend Odd
Y=0
Odd=#Odd#

[VisualizerSelectionText]
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=#Spacing3#r
Text="Visualizer Selection:"
AntiAlias=1

[MeasureVisualizerState]
Meter=String
MeasureName=#Selection#
UpdateDivider=-1
IfMatch=Spectrum
IfMatchAction=[!SetOption MeterToggleSpectrum Text "#Checked#"][!SetOption MeterToggleSpectrogram Text "#Unchecked#"][!SetOption MeterToggleWave Text "#Unchecked#"][!SetOption MeterTogglePeaks Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfMatch2=Spectrogram
IfMatchAction2=[!SetOption MeterToggleSpectrum Text "#Unchecked#"][!SetOption MeterToggleSpectrogram Text "#Checked#"][!SetOption MeterToggleWave Text "#Unchecked#"][!SetOption MeterTogglePeaks Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfMatch3=Wave
IfMatchAction3=[!SetOption MeterToggleSpectrum Text "#Unchecked#"][!SetOption MeterToggleSpectrogram Text "#Unchecked#"][!SetOption MeterToggleWave Text "#Checked#"][!SetOption MeterTogglePeaks Text "#Unchecked#"][!UpdateMeter *][!Redraw]
IfMatch4=Peaks
IfMatchAction4=[!SetOption MeterToggleSpectrum Text "#Unchecked#"][!SetOption MeterToggleSpectrogram Text "#Unchecked#"][!SetOption MeterToggleWave Text "#Unchecked#"][!SetOption MeterTogglePeaks Text "#Checked#"][!UpdateMeter *][!Redraw]

[SpectrumScript]
Measure=Script
ScriptFile=#@#Visualizer\Scripts\CreateSpectrum.lua
BandsCount=#Bands#
UpdateDivider=-1
DynamicVariables=1

[MeterToggleSpectrum]
Meter=String
Container=ContainerSelection
MeasureName=MeasureVisualizerState
MeterStyle=ButtonStyle
X=([VisualizerSelectionText:X] + (70 * #SettingsScale#))
Y=([VisualizerSelectionText:Y] - (118 * #SettingsScale#))
H=#BoxCheckSize#
W=#BoxCheckSize#
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure SpectrumScript "Initialize()"][!WriteKeyValue Variables Selection "Spectrum" "#@#Visualizer\Settings\VariablesUser.inc"][!WriteKeyValue Variables BGImage "#@#Visualizer\Images\radio-volume-gradient.png" "#@#Visualizer\Settings\VariablesUser.inc"][!UpdateMeter MeterToggleSpectrum][!UpdateMeter MeterToggleSpectrogram][!UpdateMeter MeterToggleWave][!UpdateMeter MeterTogglePeaks][!Refresh][!Refresh "#PATH#\visualizer"]

[SpectrumText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleSpectrum:X] - (80 * #SettingsScale#))
Y=([MeterToggleSpectrum:Y] - (127 * #SettingsScale#))
Text="Spectrum"
AntiAlias=1
ClipString=1

[MeterToggleSpectrogram]
Meter=String
Container=ContainerSelection
MeasureName=MeasureVisualizerState
MeterStyle=ButtonStyle
X=([VisualizerSelectionText:X] + (270 * #SettingsScale#))
Y=([VisualizerSelectionText:Y] - (118 * #SettingsScale#))
H=#BoxCheckSize#
W=#BoxCheckSize#
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Spectrogram" "#@#Visualizer\Settings\VariablesUser.inc"][!WriteKeyValue Variables BGImage "#@#Visualizer\Images\record-player.png" "#@#Visualizer\Settings\VariablesUser.inc"][!UpdateMeter MeterToggleSpectrum][!UpdateMeter MeterToggleSpectrogram][!UpdateMeter MeterToggleWave][!UpdateMeter MeterTogglePeaks][!Refresh][!Refresh "#PATH#\visualizer"]

[SpectrogramText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleSpectrogram:X] - (80 * #SettingsScale#))
Y=([MeterToggleSpectrogram:Y] - (127 * #SettingsScale#))
Text="Spectrogram"
AntiAlias=1
ClipString=1

[MeterToggleWave]
Meter=String
Container=ContainerSelection
MeasureName=MeasureVisualizerState
MeterStyle=ButtonStyle
X=([VisualizerSelectionText:X] + (70 * #SettingsScale#))
Y=#RowSpacing#
H=#BoxCheckSize#
W=#BoxCheckSize#
Text=
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Wave" "#@#Visualizer\Settings\VariablesUser.inc"][!WriteKeyValue Variables BGImage "#@#Visualizer\Images\record-player.png" "#@#Visualizer\Settings\VariablesUser.inc"][!UpdateMeter MeterToggleSpectrum][!UpdateMeter MeterToggleSpectrogram][!UpdateMeter MeterToggleWave][!UpdateMeter MeterTogglePeaks][!Refresh][!Refresh "#PATH#\visualizer"]

[WaveText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterToggleWave:X] - (80 * #SettingsScale#))
Y=([MeterToggleWave:Y] - (127 * #SettingsScale#))
Text="Wave"
AntiAlias=1
ClipString=1

[PeaksScript]
Measure=Script
ScriptFile=#@#Visualizer\Scripts\CreatePeaks.lua
BandsCount=#Bands#
UpdateDivider=-1
DynamicVariables=1

[MeterTogglePeaks]
Meter=String
Container=ContainerSelection
MeasureName=MeasureVisualizerState
MeterStyle=ButtonStyle
X=([VisualizerSelectionText:X] + (270 * #SettingsScale#))
Y=(7 * #SettingsScale#)r
H=#BoxCheckSize#
W=#BoxCheckSize#
AntiAlias=1
Text=
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure PeaksScript "Initialize()"][!WriteKeyValue Variables BGImage "#@#Visualizer\Images\record-player.png" "#@#Visualizer\Settings\VariablesUser.inc"][!WriteKeyValue Variables Selection "Peaks" "#@#Visualizer\Settings\VariablesUser.inc"][!UpdateMeter MeterToggleSpectrum][!UpdateMeter MeterToggleSpectrogram][!UpdateMeter MeterToggleWave][!UpdateMeter MeterTogglePeaks][!Refresh][!Refresh "#PATH#\visualizer"]

[PeaksText]
Meter=String
Container=ContainerSelection
MeterStyle=ButtonTextStyle
H=#BoxInputSmH#
W=#GPUTextW#
X=([MeterTogglePeaks:X] - (80 * #SettingsScale#))
Y=([MeterTogglePeaks:Y] - (127 * #SettingsScale#))
Text="Peaks"
AntiAlias=1
ClipString=1

[];===============================================================
;----------------------------- Scale -----------------------------
;=================================================================
[ScaleContainer]
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

[ScaleText] ;Scale Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(30 * #SettingsScale#)r
Text="Scale:"
AntiAlias=1

[MeterScale] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputScale" "ExecuteBatch 1"]

[MeterScaleValue] ;Current Scale
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#ScaleVis#"
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
Command1=[!WriteKeyValue Variables ScaleVis "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#ScaleVis#

[];===============================================================
;----------------------------- Bands -----------------------------
;=================================================================
[BandsContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd
X=0
Y=(40 * #SettingsScale#)r

Odd=#Odd#

[BandsText] ;Bands Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(25 * #SettingsScale#)r
Text="Bands (1-64):"
AntiAlias=1

[MeterBands] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputBands" "ExecuteBatch 1"]

[MeterBandsValue] ;Current Bands
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#Bands#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputBands] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterBands:X]
Y=[MeterBandsValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables Bands "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#Bands#

[];===============================================================
;----------------------------- FqMin -----------------------------
;=================================================================
[FreqMinContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
X=0
Y=(50 * #SettingsScale#)r

Even=#Even#

[FreqMinText] ;FreqMin Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(24 * #SettingsScale#)r
Text="FreqMin (Hz):"
AntiAlias=1

[MeterFreqMin] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFreqMin" "ExecuteBatch 1"]

[MeterFreqMinValue] ;Current FreqMin
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#FreqMin#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFreqMin] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFreqMin:X]
Y=[MeterFreqMinValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables FreqMin "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#FreqMin#

[];===============================================================
;----------------------------- FqMax -----------------------------
;=================================================================
[FreqMaxContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Odd
X=0
Y=(50 * #SettingsScale#)r

Odd=#Odd#

[FreqMaxText] ;FreqMax Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(22 * #SettingsScale#)r
Text="FreqMax (Hz):"
AntiAlias=1

[MeterFreqMax] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputFreqMax" "ExecuteBatch 1"]

[MeterFreqMaxValue] ;Current FreqMax
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#FreqMax#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputFreqMax] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterFreqMax:X]
Y=[MeterFreqMaxValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables FreqMax "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#FreqMax#

[];===============================================================
;----------------------------- Gain ------------------------------
;=================================================================
[GainUserContainer]
Meter=Shape
Container=ContainerSelection
Shape=Rectangle 0,0,#ContainerSelectionW#,#ContainerScaleH# | Fill Color 255,100,100,255 | Stroke Color 0,0,0,0 | Extend Even
X=0
Y=(45 * #SettingsScale#)r

Even=#Even#

[GainUserText] ;GainUser Title
Meter=String
Container=ContainerSelection
MeterStyle=TitleStyle
X=#TitleX#
Y=(24 * #SettingsScale#)r
Text="Gain (1-10):"
AntiAlias=1

[MeterGainUser] ;Input Box
Meter=Shape
Container=ContainerSelection
X=(200 * #SettingsScale#)r
Y=(-5 * #SettingsScale#)r
Shape=Rectangle 0,0,#BoxValueMdW#,#BoxValueMdH#,#BoxValueMdR# | Fill Color #FontColor#,20 | Stroke Color #ColorTint#
LeftMouseUpAction=[!CommandMeasure "MeterInputGainUser" "ExecuteBatch 1"]

[MeterGainUserValue] ;Current GainUser
Meter=String
Container=ContainerSelection
MeterStyle=DisplayStyle
X=(31 * #SettingsScale#)r
Y=#BoxValueMdSpacingY#r
Text="#GainUser#"
AntiAlias=1
ToolTipType=1
ToolTipText="Click to insert value."

[MeterInputGainUser] ;Input Box
Measure=Plugin
Plugin=InputText
Container=ContainerSelection
MeterStyle=InputStyle
FontSize=(12 * #SettingsScale#)
StringAlign=CENTER
SolidColor=215,215,215,255
X=[MeterGainUser:X]
Y=[MeterGainUserValue:Y]
W=#BoxInputMdW#
H=#BoxInputMdH#
FocusDismiss=1
Command1=[!WriteKeyValue Variables GainUser "$UserInput$" "#@#\Visualizer\Settings\VariablesUser.inc"][!Refresh][!Refresh "#PATH#\visualizer"]
DefaultValue=#GainUser#

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
;LeftMouseUpAction=[!CommandMeasure HardwareScript "Run"][!EnableMeasure "MeasureCountdown"][!ShowMeterGroup LoadingAnimation][!Redraw]
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
LeftMouseDownAction=[!CommandMeasure Defaults "ExecuteBatch 3"]
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
IfEqualAction=[!HideMeterGroup LoadingAnimation][!Refresh "#PATH#\visualizer"][!Refresh]
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