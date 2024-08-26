[Variables]
@includeVariablesUser=#@#Visualizer\Settings\VariablesUser.inc
@includeVariables=#@#Visualizer\Settings\VariablesVisualizer.inc
@includeMeasures=#@#Visualizer\Settings\MeasurePeaks.inc

[PeaksReflection]
@includePeaksReflection=#@#Visualizer\Styles\PeaksReflection.inc

[VisualizerBGImage]
Meter=Image
ImageName=#BGImage#
W=#SpectrumW#
H=#BarHeight#
X=0
Y=0
PreserveAspectRatio=2
UpdateDivider=-1

[Settings]
Meter=Image
ImageName=#@#VisualizerIconsGears
GrayScale=1
ImageTint=#StrokeColor#
H=(20 * #ScaleVis#)
Y=(#BarHeight# + (22 * #ScaleVis#))
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Visualizer\Settings\Panels\VisualizerSystem" "#SKINSPATH##PATH#\Settings\Settings.ini"][!ToggleConfig "#Path#\Settings" "Settings.ini"]

[Peaks]
Meter=Shape
DynamicVariables=1

; Peaks 1
Shape=Line (#UnitStartX# * 0), (([MeasureBand0] * #Jump#)), (#UnitStartX# * 1), (([MeasureBand1] * #Jump#)) | Extend PeaksModifiers

; Peaks 2
Shape2=Line (#UnitStartX# * 1), (([MeasureBand1] * #Jump#)), (#UnitStartX# * 2), (([MeasureBand2] * #Jump#)) | Extend PeaksModifiers

; Peaks 3
Shape3=Line (#UnitStartX# * 2), (([MeasureBand2] * #Jump#)), (#UnitStartX# * 3), (([MeasureBand3] * #Jump#)) | Extend PeaksModifiers

; Peaks 4
Shape4=Line (#UnitStartX# * 3), (([MeasureBand3] * #Jump#)), (#UnitStartX# * 4), (([MeasureBand4] * #Jump#)) | Extend PeaksModifiers

; Peaks 5
Shape5=Line (#UnitStartX# * 4), (([MeasureBand4] * #Jump#)), (#UnitStartX# * 5), (([MeasureBand5] * #Jump#)) | Extend PeaksModifiers

; Peaks 6
Shape6=Line (#UnitStartX# * 5), (([MeasureBand5] * #Jump#)), (#UnitStartX# * 6), (([MeasureBand6] * #Jump#)) | Extend PeaksModifiers

; Peaks 7
Shape7=Line (#UnitStartX# * 6), (([MeasureBand6] * #Jump#)), (#UnitStartX# * 7), (([MeasureBand7] * #Jump#)) | Extend PeaksModifiers

; Peaks 8
Shape8=Line (#UnitStartX# * 7), (([MeasureBand7] * #Jump#)), (#UnitStartX# * 8), (([MeasureBand8] * #Jump#)) | Extend PeaksModifiers

; Peaks 9
Shape9=Line (#UnitStartX# * 8), (([MeasureBand8] * #Jump#)), (#UnitStartX# * 9), (([MeasureBand9] * #Jump#)) | Extend PeaksModifiers

; Peaks 10
Shape10=Line (#UnitStartX# * 9), (([MeasureBand9] * #Jump#)), (#UnitStartX# * 10), (([MeasureBand10] * #Jump#)) | Extend PeaksModifiers

; Peaks 11
Shape11=Line (#UnitStartX# * 10), (([MeasureBand10] * #Jump#)), (#UnitStartX# * 11), (([MeasureBand11] * #Jump#)) | Extend PeaksModifiers

; Peaks 12
Shape12=Line (#UnitStartX# * 11), (([MeasureBand11] * #Jump#)), (#UnitStartX# * 12), (([MeasureBand12] * #Jump#)) | Extend PeaksModifiers

; Peaks 13
Shape13=Line (#UnitStartX# * 12), (([MeasureBand12] * #Jump#)), (#UnitStartX# * 13), (([MeasureBand13] * #Jump#)) | Extend PeaksModifiers

; Peaks 14
Shape14=Line (#UnitStartX# * 13), (([MeasureBand13] * #Jump#)), (#UnitStartX# * 14), (([MeasureBand14] * #Jump#)) | Extend PeaksModifiers

; Peaks 15
Shape15=Line (#UnitStartX# * 14), (([MeasureBand14] * #Jump#)), (#UnitStartX# * 15), (([MeasureBand15] * #Jump#)) | Extend PeaksModifiers

; Peaks 16
Shape16=Line (#UnitStartX# * 15), (([MeasureBand15] * #Jump#)), (#UnitStartX# * 16), (([MeasureBand16] * #Jump#)) | Extend PeaksModifiers

; Peaks 17
Shape17=Line (#UnitStartX# * 16), (([MeasureBand16] * #Jump#)), (#UnitStartX# * 17), (([MeasureBand17] * #Jump#)) | Extend PeaksModifiers

; Peaks 18
Shape18=Line (#UnitStartX# * 17), (([MeasureBand17] * #Jump#)), (#UnitStartX# * 18), (([MeasureBand18] * #Jump#)) | Extend PeaksModifiers

; Peaks 19
Shape19=Line (#UnitStartX# * 18), (([MeasureBand18] * #Jump#)), (#UnitStartX# * 19), (([MeasureBand19] * #Jump#)) | Extend PeaksModifiers

; Peaks 20
Shape20=Line (#UnitStartX# * 19), (([MeasureBand19] * #Jump#)), (#UnitStartX# * 20), (([MeasureBand20] * #Jump#)) | Extend PeaksModifiers

; Peaks 21
Shape21=Line (#UnitStartX# * 20), (([MeasureBand20] * #Jump#)), (#UnitStartX# * 21), (([MeasureBand21] * #Jump#)) | Extend PeaksModifiers

; Peaks 22
Shape22=Line (#UnitStartX# * 21), (([MeasureBand21] * #Jump#)), (#UnitStartX# * 22), (([MeasureBand22] * #Jump#)) | Extend PeaksModifiers

; Peaks 23
Shape23=Line (#UnitStartX# * 22), (([MeasureBand22] * #Jump#)), (#UnitStartX# * 23), (([MeasureBand23] * #Jump#)) | Extend PeaksModifiers

; Peaks 24
Shape24=Line (#UnitStartX# * 23), (([MeasureBand23] * #Jump#)), (#UnitStartX# * 24), (([MeasureBand24] * #Jump#)) | Extend PeaksModifiers

; Peaks 25
Shape25=Line (#UnitStartX# * 24), (([MeasureBand24] * #Jump#)), (#UnitStartX# * 25), (([MeasureBand25] * #Jump#)) | Extend PeaksModifiers

; Peaks 26
Shape26=Line (#UnitStartX# * 25), (([MeasureBand25] * #Jump#)), (#UnitStartX# * 26), (([MeasureBand26] * #Jump#)) | Extend PeaksModifiers

PeaksModifiers=StrokeWidth 3 | Stroke Color #StrokeColor#
