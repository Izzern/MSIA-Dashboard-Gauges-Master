[BGImage]
Meter=Image
Container=Spectrogram
ImageName=#BGImage#
W=#SpectrogramW#
H=#BarHeight#
PreserveAspectRatio=2
UpdateDivider=-1

[Spectrogram]
Meter=Image
MeasureName=MeasureSpectrogram
ImageName=#@#Visualizer\Images\Main-Spectrogram-a.bmp
W=#SpectrogramW#
H=#BarHeight#
DynamicVariables=1

[SettingsGear]
Meter=Image
ImageName=#@#Visualizer\Icons\Gears
GrayScale=1
ImageTint=#StrokeColor#
H=(20 * #ScaleVis#)
X=0
Y=(#BarHeight# - (22 * #ScaleVis#))
LeftMouseUpAction=[!ToggleConfig "#Path#\Settings" "Settings.ini"]

;[SpectrogramReflection]
;@includeSpectrogramReflection=#@#Visualizer\Styles\SpectrogramReflection.inc