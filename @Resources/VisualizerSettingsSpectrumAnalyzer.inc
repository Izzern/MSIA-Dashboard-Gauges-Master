[Variables]
@includeVariables=#@#VariablesVisualizer.inc
@includeCalcs=#@#Visualizer\CalcBands.inc
@includeMeasures=#@#Visualizer\MeasureBands.inc

UnitWidth=(#BarWidth# * #ScaleVis#)
UnitHeight=((#BarHeight# + #BarSpacingY#) * #ScaleVis#)
UnitRounding=((#BarWidth# / 2) * #ScaleVis#)
UnitStartX=((#BarWidth# + #BarSpacingX#) * #ScaleVis#)
UnitStartY=((#BarHeight# + #BarSpacingY# + #Jump#) * #ScaleVis#)

[CreateSpectrum]
Measure=Script
ScriptFile=#@#Scripts\CreateSpectrumBars.lua
Disabled=1

[Settings]
Meter=Shape
DynamicVariables=1
Shape=Rectangle 0, ((#BarHeight# * #ScaleVis#) - ([CalcBand1] * #Jump#)), #UnitWidth#, (Neg([CalcBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers

Disabled=0
LeftMouseUpAction=[!ToggleConfig "#Path#\Settings" "Settings.ini"]
RightMouseUpAction=[!CommandMeasure CreateSpectrum "Run"]

SpectrumModifiers=Fill Color 0,0,0,1 | StrokeWidth #StrokeWidth# | Stroke Color 0,0,0,1
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#

[Spectrum]
Meter=Shape
DynamicVariables=1

; Spectrum Band 1
Shape=Rectangle (#UnitStartX# * 0), ((#BarHeight# * #ScaleVis#) - ([CalcBand1] * #Jump#)), #UnitWidth#, (Neg([CalcBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 1)

; Spectrum Band 2
Shape2=Rectangle (#UnitStartX# * 1), ((#BarHeight# * #ScaleVis#) - ([CalcBand2] * #Jump#)), #UnitWidth#, (Neg([CalcBand2] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 2)

; Spectrum Band 3
Shape3=Rectangle (#UnitStartX# * 2), ((#BarHeight# * #ScaleVis#) - ([CalcBand3] * #Jump#)), #UnitWidth#, (Neg([CalcBand3] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 3)

; Spectrum Band 4
Shape4=Rectangle (#UnitStartX# * 3), ((#BarHeight# * #ScaleVis#) - ([CalcBand4] * #Jump#)), #UnitWidth#, (Neg([CalcBand4] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 4)

; Spectrum Band 5
Shape5=Rectangle (#UnitStartX# * 4), ((#BarHeight# * #ScaleVis#) - ([CalcBand5] * #Jump#)), #UnitWidth#, (Neg([CalcBand5] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 5)

; Spectrum Band 6
Shape6=Rectangle (#UnitStartX# * 5), ((#BarHeight# * #ScaleVis#) - ([CalcBand6] * #Jump#)), #UnitWidth#, (Neg([CalcBand6] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 6)

; Spectrum Band 7
Shape7=Rectangle (#UnitStartX# * 6), ((#BarHeight# * #ScaleVis#) - ([CalcBand7] * #Jump#)), #UnitWidth#, (Neg([CalcBand7] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 7)

; Spectrum Band 8
Shape8=Rectangle (#UnitStartX# * 7), ((#BarHeight# * #ScaleVis#) - ([CalcBand8] * #Jump#)), #UnitWidth#, (Neg([CalcBand8] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 8)

; Spectrum Band 9
Shape9=Rectangle (#UnitStartX# * 8), ((#BarHeight# * #ScaleVis#) - ([CalcBand9] * #Jump#)), #UnitWidth#, (Neg([CalcBand9] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 9)

; Spectrum Band 10
Shape10=Rectangle (#UnitStartX# * 9), ((#BarHeight# * #ScaleVis#) - ([CalcBand10] * #Jump#)), #UnitWidth#, (Neg([CalcBand10] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 10)

; Spectrum Band 11
Shape11=Rectangle (#UnitStartX# * 10), ((#BarHeight# * #ScaleVis#) - ([CalcBand11] * #Jump#)), #UnitWidth#, (Neg([CalcBand11] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 11)

; Spectrum Band 12
Shape12=Rectangle (#UnitStartX# * 11), ((#BarHeight# * #ScaleVis#) - ([CalcBand12] * #Jump#)), #UnitWidth#, (Neg([CalcBand12] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 12)

; Spectrum Band 13
Shape13=Rectangle (#UnitStartX# * 12), ((#BarHeight# * #ScaleVis#) - ([CalcBand13] * #Jump#)), #UnitWidth#, (Neg([CalcBand13] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 13)

; Spectrum Band 14
Shape14=Rectangle (#UnitStartX# * 13), ((#BarHeight# * #ScaleVis#) - ([CalcBand14] * #Jump#)), #UnitWidth#, (Neg([CalcBand14] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 14)

; Spectrum Band 15
Shape15=Rectangle (#UnitStartX# * 14), ((#BarHeight# * #ScaleVis#) - ([CalcBand15] * #Jump#)), #UnitWidth#, (Neg([CalcBand15] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 15)

; Spectrum Band 16
Shape16=Rectangle (#UnitStartX# * 15), ((#BarHeight# * #ScaleVis#) - ([CalcBand16] * #Jump#)), #UnitWidth#, (Neg([CalcBand16] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 16)

; Spectrum Band 17
Shape17=Rectangle (#UnitStartX# * 16), ((#BarHeight# * #ScaleVis#) - ([CalcBand17] * #Jump#)), #UnitWidth#, (Neg([CalcBand17] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 17)

; Spectrum Band 18
Shape18=Rectangle (#UnitStartX# * 17), ((#BarHeight# * #ScaleVis#) - ([CalcBand18] * #Jump#)), #UnitWidth#, (Neg([CalcBand18] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 18)

; Spectrum Band 19
Shape19=Rectangle (#UnitStartX# * 18), ((#BarHeight# * #ScaleVis#) - ([CalcBand19] * #Jump#)), #UnitWidth#, (Neg([CalcBand19] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 19)

; Spectrum Band 20
Shape20=Rectangle (#UnitStartX# * 19), ((#BarHeight# * #ScaleVis#) - ([CalcBand20] * #Jump#)), #UnitWidth#, (Neg([CalcBand20] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 20)

; Spectrum Band 21
Shape21=Rectangle (#UnitStartX# * 20), ((#BarHeight# * #ScaleVis#) - ([CalcBand21] * #Jump#)), #UnitWidth#, (Neg([CalcBand21] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 21)

; Spectrum Band 22
Shape22=Rectangle (#UnitStartX# * 21), ((#BarHeight# * #ScaleVis#) - ([CalcBand22] * #Jump#)), #UnitWidth#, (Neg([CalcBand22] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 22)

; Spectrum Band 23
Shape23=Rectangle (#UnitStartX# * 22), ((#BarHeight# * #ScaleVis#) - ([CalcBand23] * #Jump#)), #UnitWidth#, (Neg([CalcBand23] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 23)

; Spectrum Band 24
Shape24=Rectangle (#UnitStartX# * 23), ((#BarHeight# * #ScaleVis#) - ([CalcBand24] * #Jump#)), #UnitWidth#, (Neg([CalcBand24] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 24)

; Spectrum Band 25
Shape25=Rectangle (#UnitStartX# * 24), ((#BarHeight# * #ScaleVis#) - ([CalcBand25] * #Jump#)), #UnitWidth#, (Neg([CalcBand25] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 25)

; Spectrum Band 26
Shape26=Rectangle (#UnitStartX# * 25), ((#BarHeight# * #ScaleVis#) - ([CalcBand26] * #Jump#)), #UnitWidth#, (Neg([CalcBand26] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 26)

SpectrumModifiers=Fill Color #BarColor# | StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#
ReflectionModifiers=StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#,#Alpha#
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#
;SpectrumGradient=90 | 0,255,0,#Alpha# ; #SpectrumStart# | 255,255,0,#Alpha# ; #SpectrumMid# | 255,0,0,1 ; #SpectrumEnd#
ReflectionGradient=270 | #BarColor#,#Alpha# ; #ReflectionStart# | #BarColor#,0 ; #ReflectionEnd#
;ReflectionGradient=270 | 0,255,0,#Alpha# ; #ReflectionStart# | 255,255,0,#Alpha# ; #ReflectionMid# | 255,0,0,1 ; #ReflectionEnd#
