[Variables]
@includeVariablesUser=#@#Visualizer\Settings\VariablesUser.inc

[BGImage]
Meter=Image
;Container=#Selection#
ImageName=#BGImage#
ImageAlpha=#Alpha#
UpdateDivider=-1
W=#SpectrogramW#
H=(#BarHeight#)
PreserveAspectRatio=2

[MeasureWaveform]
measure=plugin
Plugin=AudioAnalyzer
Type=child
Parent=WaveAnalyzer
StringValue=Info
InfoRequest=HandlerInfo, Channel Auto | HandlerName Waveform | Data File

[Wave]
Meter=Image
MeasureName=MeasureWaveform

[SettingsGear]
Meter=Image
ImageName=#@#Visualizer\Icons\Gears
GrayScale=1
ImageTint=#StrokeColor#
H=(20 * #ScaleVis#)
X=0
Y=(#BarHeight# - (22 * #ScaleVis#))
LeftMouseUpAction=[!ToggleConfig "#Path#\Settings" "Settings.ini"]
