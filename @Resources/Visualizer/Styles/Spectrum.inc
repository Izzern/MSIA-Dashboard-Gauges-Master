[Variables]
@includeVariablesUser=#@#Visualizer\Settings\VariablesUser.inc
@includeVariables=#@#Visualizer\Settings\VariablesVisualizer.inc
@includeMeasures=#@#Visualizer\Settings\MeasureBands.inc

[SpectrumReflection]
@includeSpectrumReflection=#@#Visualizer\Styles\SpectrumReflection.inc

[VisualizerBGImage]
Meter=Image
Container=#Selection#
ImageName=#BGImage#
W=#SpectrumW#
H=#SpectrumH#
X=0
Y=0
UpdateDivider=-1

[Settings]
Meter=Shape
DynamicVariables=1
Shape=Rectangle 0, ((#BarHeight# * #ScaleVis#) - ([MeasureBand1] * #Jump#)), #UnitWidth#, (Neg([MeasureBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers

Disabled=0
LeftMouseUpAction=[!WriteKeyValue Variables Selection "Visualizer\Settings\Panels\VisualizerSystem" "#SKINSPATH##PATH#\Settings\Settings.ini"][!ToggleConfig "#Path#\Settings" "Settings.ini"]
SpectrumModifiers=Fill Color 0,0,0,1 | StrokeWidth #StrokeWidth# | Stroke Color 0,0,0,1
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#

[Spectrum]
Meter=Shape
DynamicVariables=1

; Spectrum Band 1
Shape=Rectangle (#UnitStartX# * 0), ((#BarHeight# * #ScaleVis#) - ([MeasureBand0] * #Jump#)), #UnitWidth#, (Neg([MeasureBand0] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 2
Shape2=Rectangle (#UnitStartX# * 1), ((#BarHeight# * #ScaleVis#) - ([MeasureBand1] * #Jump#)), #UnitWidth#, (Neg([MeasureBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 3
Shape3=Rectangle (#UnitStartX# * 2), ((#BarHeight# * #ScaleVis#) - ([MeasureBand2] * #Jump#)), #UnitWidth#, (Neg([MeasureBand2] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 4
Shape4=Rectangle (#UnitStartX# * 3), ((#BarHeight# * #ScaleVis#) - ([MeasureBand3] * #Jump#)), #UnitWidth#, (Neg([MeasureBand3] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 5
Shape5=Rectangle (#UnitStartX# * 4), ((#BarHeight# * #ScaleVis#) - ([MeasureBand4] * #Jump#)), #UnitWidth#, (Neg([MeasureBand4] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 6
Shape6=Rectangle (#UnitStartX# * 5), ((#BarHeight# * #ScaleVis#) - ([MeasureBand5] * #Jump#)), #UnitWidth#, (Neg([MeasureBand5] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 7
Shape7=Rectangle (#UnitStartX# * 6), ((#BarHeight# * #ScaleVis#) - ([MeasureBand6] * #Jump#)), #UnitWidth#, (Neg([MeasureBand6] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 8
Shape8=Rectangle (#UnitStartX# * 7), ((#BarHeight# * #ScaleVis#) - ([MeasureBand7] * #Jump#)), #UnitWidth#, (Neg([MeasureBand7] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 9
Shape9=Rectangle (#UnitStartX# * 8), ((#BarHeight# * #ScaleVis#) - ([MeasureBand8] * #Jump#)), #UnitWidth#, (Neg([MeasureBand8] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 10
Shape10=Rectangle (#UnitStartX# * 9), ((#BarHeight# * #ScaleVis#) - ([MeasureBand9] * #Jump#)), #UnitWidth#, (Neg([MeasureBand9] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 11
Shape11=Rectangle (#UnitStartX# * 10), ((#BarHeight# * #ScaleVis#) - ([MeasureBand10] * #Jump#)), #UnitWidth#, (Neg([MeasureBand10] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 12
Shape12=Rectangle (#UnitStartX# * 11), ((#BarHeight# * #ScaleVis#) - ([MeasureBand11] * #Jump#)), #UnitWidth#, (Neg([MeasureBand11] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 13
Shape13=Rectangle (#UnitStartX# * 12), ((#BarHeight# * #ScaleVis#) - ([MeasureBand12] * #Jump#)), #UnitWidth#, (Neg([MeasureBand12] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 14
Shape14=Rectangle (#UnitStartX# * 13), ((#BarHeight# * #ScaleVis#) - ([MeasureBand13] * #Jump#)), #UnitWidth#, (Neg([MeasureBand13] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 15
Shape15=Rectangle (#UnitStartX# * 14), ((#BarHeight# * #ScaleVis#) - ([MeasureBand14] * #Jump#)), #UnitWidth#, (Neg([MeasureBand14] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 16
Shape16=Rectangle (#UnitStartX# * 15), ((#BarHeight# * #ScaleVis#) - ([MeasureBand15] * #Jump#)), #UnitWidth#, (Neg([MeasureBand15] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 17
Shape17=Rectangle (#UnitStartX# * 16), ((#BarHeight# * #ScaleVis#) - ([MeasureBand16] * #Jump#)), #UnitWidth#, (Neg([MeasureBand16] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 18
Shape18=Rectangle (#UnitStartX# * 17), ((#BarHeight# * #ScaleVis#) - ([MeasureBand17] * #Jump#)), #UnitWidth#, (Neg([MeasureBand17] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 19
Shape19=Rectangle (#UnitStartX# * 18), ((#BarHeight# * #ScaleVis#) - ([MeasureBand18] * #Jump#)), #UnitWidth#, (Neg([MeasureBand18] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 20
Shape20=Rectangle (#UnitStartX# * 19), ((#BarHeight# * #ScaleVis#) - ([MeasureBand19] * #Jump#)), #UnitWidth#, (Neg([MeasureBand19] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 21
Shape21=Rectangle (#UnitStartX# * 20), ((#BarHeight# * #ScaleVis#) - ([MeasureBand20] * #Jump#)), #UnitWidth#, (Neg([MeasureBand20] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 22
Shape22=Rectangle (#UnitStartX# * 21), ((#BarHeight# * #ScaleVis#) - ([MeasureBand21] * #Jump#)), #UnitWidth#, (Neg([MeasureBand21] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 23
Shape23=Rectangle (#UnitStartX# * 22), ((#BarHeight# * #ScaleVis#) - ([MeasureBand22] * #Jump#)), #UnitWidth#, (Neg([MeasureBand22] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 24
Shape24=Rectangle (#UnitStartX# * 23), ((#BarHeight# * #ScaleVis#) - ([MeasureBand23] * #Jump#)), #UnitWidth#, (Neg([MeasureBand23] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 25
Shape25=Rectangle (#UnitStartX# * 24), ((#BarHeight# * #ScaleVis#) - ([MeasureBand24] * #Jump#)), #UnitWidth#, (Neg([MeasureBand24] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

; Spectrum Band 26
Shape26=Rectangle (#UnitStartX# * 25), ((#BarHeight# * #ScaleVis#) - ([MeasureBand25] * #Jump#)), #UnitWidth#, (Neg([MeasureBand25] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient

SpectrumModifiers=Fill Color #BarColor# | StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#
;SpectrumGradient=90 | 0,255,0,#Alpha# ; #SpectrumStart# | 255,255,0,#Alpha# ; #SpectrumMid# | 255,0,0,1 ; #SpectrumEnd#
