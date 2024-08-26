[Variables]
@includeVariables=#@#VariablesVisualizer.inc
@includeCalcs=#@#Visualizer\Settings\CalcBands.inc
@includeMeasures=#@#Visualizer\Settings\MeasureBands.inc

;[CreateSpectrum]
;Measure=Script
;ScriptFile=#@#Visualizer\Scripts\CreateSpectrumBars.lua
;Disabled=1

[Settings]
Meter=Shape
DynamicVariables=1
Shape=Rectangle 0, ((#BarHeight# * #Scale#) - ([CalcBand1] * #Jump#)), #UnitWidth#, (Neg([CalcBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers

Disabled=0
LeftMouseUpAction=[!ToggleConfig "#Path#\Settings" "Settings.ini"]
RightMouseUpAction=[!CommandMeasure CreateSpectrum "Run"]

SpectrumModifiers=Fill Color 0,0,0,1 | StrokeWidth #StrokeWidth# | Stroke Color 0,0,0,1
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#

[Spectrum]
Meter=Shape
DynamicVariables=1

; Spectrum Band 1
Shape=Rectangle (#UnitStartX# * 0), ((#BarHeight# * #Scale#) - ([CalcBand1] * #Jump#)), #UnitWidth#, (Neg([CalcBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 1)

; Spectrum Band 2
Shape2=Rectangle (#UnitStartX# * 1), ((#BarHeight# * #Scale#) - ([CalcBand2] * #Jump#)), #UnitWidth#, (Neg([CalcBand2] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 2)

; Spectrum Band 3
Shape3=Rectangle (#UnitStartX# * 2), ((#BarHeight# * #Scale#) - ([CalcBand3] * #Jump#)), #UnitWidth#, (Neg([CalcBand3] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 3)

; Spectrum Band 4
Shape4=Rectangle (#UnitStartX# * 3), ((#BarHeight# * #Scale#) - ([CalcBand4] * #Jump#)), #UnitWidth#, (Neg([CalcBand4] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 4)

; Spectrum Band 5
Shape5=Rectangle (#UnitStartX# * 4), ((#BarHeight# * #Scale#) - ([CalcBand5] * #Jump#)), #UnitWidth#, (Neg([CalcBand5] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 5)

; Spectrum Band 6
Shape6=Rectangle (#UnitStartX# * 5), ((#BarHeight# * #Scale#) - ([CalcBand6] * #Jump#)), #UnitWidth#, (Neg([CalcBand6] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 6)

; Spectrum Band 7
Shape7=Rectangle (#UnitStartX# * 6), ((#BarHeight# * #Scale#) - ([CalcBand7] * #Jump#)), #UnitWidth#, (Neg([CalcBand7] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 7)

; Spectrum Band 8
Shape8=Rectangle (#UnitStartX# * 7), ((#BarHeight# * #Scale#) - ([CalcBand8] * #Jump#)), #UnitWidth#, (Neg([CalcBand8] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 8)

; Spectrum Band 9
Shape9=Rectangle (#UnitStartX# * 8), ((#BarHeight# * #Scale#) - ([CalcBand9] * #Jump#)), #UnitWidth#, (Neg([CalcBand9] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 9)

; Spectrum Band 10
Shape10=Rectangle (#UnitStartX# * 9), ((#BarHeight# * #Scale#) - ([CalcBand10] * #Jump#)), #UnitWidth#, (Neg([CalcBand10] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 10)

; Spectrum Band 11
Shape11=Rectangle (#UnitStartX# * 10), ((#BarHeight# * #Scale#) - ([CalcBand11] * #Jump#)), #UnitWidth#, (Neg([CalcBand11] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 11)

; Spectrum Band 12
Shape12=Rectangle (#UnitStartX# * 11), ((#BarHeight# * #Scale#) - ([CalcBand12] * #Jump#)), #UnitWidth#, (Neg([CalcBand12] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 12)

; Spectrum Band 13
Shape13=Rectangle (#UnitStartX# * 12), ((#BarHeight# * #Scale#) - ([CalcBand13] * #Jump#)), #UnitWidth#, (Neg([CalcBand13] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 13)

; Spectrum Band 14
Shape14=Rectangle (#UnitStartX# * 13), ((#BarHeight# * #Scale#) - ([CalcBand14] * #Jump#)), #UnitWidth#, (Neg([CalcBand14] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 14)

; Spectrum Band 15
Shape15=Rectangle (#UnitStartX# * 14), ((#BarHeight# * #Scale#) - ([CalcBand15] * #Jump#)), #UnitWidth#, (Neg([CalcBand15] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 15)

; Spectrum Band 16
Shape16=Rectangle (#UnitStartX# * 15), ((#BarHeight# * #Scale#) - ([CalcBand16] * #Jump#)), #UnitWidth#, (Neg([CalcBand16] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 16)

; Spectrum Band 17
Shape17=Rectangle (#UnitStartX# * 16), ((#BarHeight# * #Scale#) - ([CalcBand17] * #Jump#)), #UnitWidth#, (Neg([CalcBand17] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 17)

; Spectrum Band 18
Shape18=Rectangle (#UnitStartX# * 17), ((#BarHeight# * #Scale#) - ([CalcBand18] * #Jump#)), #UnitWidth#, (Neg([CalcBand18] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 18)

; Spectrum Band 19
Shape19=Rectangle (#UnitStartX# * 18), ((#BarHeight# * #Scale#) - ([CalcBand19] * #Jump#)), #UnitWidth#, (Neg([CalcBand19] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 19)

; Spectrum Band 20
Shape20=Rectangle (#UnitStartX# * 19), ((#BarHeight# * #Scale#) - ([CalcBand20] * #Jump#)), #UnitWidth#, (Neg([CalcBand20] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 20)

; Spectrum Band 21
Shape21=Rectangle (#UnitStartX# * 20), ((#BarHeight# * #Scale#) - ([CalcBand21] * #Jump#)), #UnitWidth#, (Neg([CalcBand21] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 21)

; Spectrum Band 22
Shape22=Rectangle (#UnitStartX# * 21), ((#BarHeight# * #Scale#) - ([CalcBand22] * #Jump#)), #UnitWidth#, (Neg([CalcBand22] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 22)

; Spectrum Band 23
Shape23=Rectangle (#UnitStartX# * 22), ((#BarHeight# * #Scale#) - ([CalcBand23] * #Jump#)), #UnitWidth#, (Neg([CalcBand23] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 23)

; Spectrum Band 24
Shape24=Rectangle (#UnitStartX# * 23), ((#BarHeight# * #Scale#) - ([CalcBand24] * #Jump#)), #UnitWidth#, (Neg([CalcBand24] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 24)

; Spectrum Band 25
Shape25=Rectangle (#UnitStartX# * 24), ((#BarHeight# * #Scale#) - ([CalcBand25] * #Jump#)), #UnitWidth#, (Neg([CalcBand25] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 25)

; Spectrum Band 26
Shape26=Rectangle (#UnitStartX# * 25), ((#BarHeight# * #Scale#) - ([CalcBand26] * #Jump#)), #UnitWidth#, (Neg([CalcBand26] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 26)

; Spectrum Band 27
Shape27=Rectangle (#UnitStartX# * 26), ((#BarHeight# * #Scale#) - ([CalcBand27] * #Jump#)), #UnitWidth#, (Neg([CalcBand27] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 27)

; Spectrum Band 28
Shape28=Rectangle (#UnitStartX# * 27), ((#BarHeight# * #Scale#) - ([CalcBand28] * #Jump#)), #UnitWidth#, (Neg([CalcBand28] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 28)

; Spectrum Band 29
Shape29=Rectangle (#UnitStartX# * 28), ((#BarHeight# * #Scale#) - ([CalcBand29] * #Jump#)), #UnitWidth#, (Neg([CalcBand29] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 29)

; Spectrum Band 30
Shape30=Rectangle (#UnitStartX# * 29), ((#BarHeight# * #Scale#) - ([CalcBand30] * #Jump#)), #UnitWidth#, (Neg([CalcBand30] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 30)

; Spectrum Band 31
Shape31=Rectangle (#UnitStartX# * 30), ((#BarHeight# * #Scale#) - ([CalcBand31] * #Jump#)), #UnitWidth#, (Neg([CalcBand31] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 31)

; Spectrum Band 32
Shape32=Rectangle (#UnitStartX# * 31), ((#BarHeight# * #Scale#) - ([CalcBand32] * #Jump#)), #UnitWidth#, (Neg([CalcBand32] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 32)

; Spectrum Band 33
Shape33=Rectangle (#UnitStartX# * 32), ((#BarHeight# * #Scale#) - ([CalcBand33] * #Jump#)), #UnitWidth#, (Neg([CalcBand33] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 33)

; Spectrum Band 34
Shape34=Rectangle (#UnitStartX# * 33), ((#BarHeight# * #Scale#) - ([CalcBand34] * #Jump#)), #UnitWidth#, (Neg([CalcBand34] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 34)

; Spectrum Band 35
Shape35=Rectangle (#UnitStartX# * 34), ((#BarHeight# * #Scale#) - ([CalcBand35] * #Jump#)), #UnitWidth#, (Neg([CalcBand35] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 35)

; Spectrum Band 36
Shape36=Rectangle (#UnitStartX# * 35), ((#BarHeight# * #Scale#) - ([CalcBand36] * #Jump#)), #UnitWidth#, (Neg([CalcBand36] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 36)

; Spectrum Band 37
Shape37=Rectangle (#UnitStartX# * 36), ((#BarHeight# * #Scale#) - ([CalcBand37] * #Jump#)), #UnitWidth#, (Neg([CalcBand37] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 37)

; Spectrum Band 38
Shape38=Rectangle (#UnitStartX# * 37), ((#BarHeight# * #Scale#) - ([CalcBand38] * #Jump#)), #UnitWidth#, (Neg([CalcBand38] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 38)

; Spectrum Band 39
Shape39=Rectangle (#UnitStartX# * 38), ((#BarHeight# * #Scale#) - ([CalcBand39] * #Jump#)), #UnitWidth#, (Neg([CalcBand39] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 39)

; Spectrum Band 40
Shape40=Rectangle (#UnitStartX# * 39), ((#BarHeight# * #Scale#) - ([CalcBand40] * #Jump#)), #UnitWidth#, (Neg([CalcBand40] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 40)

; Spectrum Band 41
Shape41=Rectangle (#UnitStartX# * 40), ((#BarHeight# * #Scale#) - ([CalcBand41] * #Jump#)), #UnitWidth#, (Neg([CalcBand41] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 41)

; Spectrum Band 42
Shape42=Rectangle (#UnitStartX# * 41), ((#BarHeight# * #Scale#) - ([CalcBand42] * #Jump#)), #UnitWidth#, (Neg([CalcBand42] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 42)

; Spectrum Band 43
Shape43=Rectangle (#UnitStartX# * 42), ((#BarHeight# * #Scale#) - ([CalcBand43] * #Jump#)), #UnitWidth#, (Neg([CalcBand43] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 43)

; Spectrum Band 44
Shape44=Rectangle (#UnitStartX# * 43), ((#BarHeight# * #Scale#) - ([CalcBand44] * #Jump#)), #UnitWidth#, (Neg([CalcBand44] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 44)

; Spectrum Band 45
Shape45=Rectangle (#UnitStartX# * 44), ((#BarHeight# * #Scale#) - ([CalcBand45] * #Jump#)), #UnitWidth#, (Neg([CalcBand45] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 45)

; Spectrum Band 46
Shape46=Rectangle (#UnitStartX# * 45), ((#BarHeight# * #Scale#) - ([CalcBand46] * #Jump#)), #UnitWidth#, (Neg([CalcBand46] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 46)

; Spectrum Band 47
Shape47=Rectangle (#UnitStartX# * 46), ((#BarHeight# * #Scale#) - ([CalcBand47] * #Jump#)), #UnitWidth#, (Neg([CalcBand47] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 47)

; Spectrum Band 48
Shape48=Rectangle (#UnitStartX# * 47), ((#BarHeight# * #Scale#) - ([CalcBand48] * #Jump#)), #UnitWidth#, (Neg([CalcBand48] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 48)

; Spectrum Band 49
Shape49=Rectangle (#UnitStartX# * 48), ((#BarHeight# * #Scale#) - ([CalcBand49] * #Jump#)), #UnitWidth#, (Neg([CalcBand49] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 49)

; Spectrum Band 50
Shape50=Rectangle (#UnitStartX# * 49), ((#BarHeight# * #Scale#) - ([CalcBand50] * #Jump#)), #UnitWidth#, (Neg([CalcBand50] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 50)

; Spectrum Band 51
Shape51=Rectangle (#UnitStartX# * 50), ((#BarHeight# * #Scale#) - ([CalcBand51] * #Jump#)), #UnitWidth#, (Neg([CalcBand51] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 51)

; Spectrum Band 52
Shape52=Rectangle (#UnitStartX# * 51), ((#BarHeight# * #Scale#) - ([CalcBand52] * #Jump#)), #UnitWidth#, (Neg([CalcBand52] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 52)

; Spectrum Band 53
Shape53=Rectangle (#UnitStartX# * 52), ((#BarHeight# * #Scale#) - ([CalcBand53] * #Jump#)), #UnitWidth#, (Neg([CalcBand53] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 53)

; Spectrum Band 54
Shape54=Rectangle (#UnitStartX# * 53), ((#BarHeight# * #Scale#) - ([CalcBand54] * #Jump#)), #UnitWidth#, (Neg([CalcBand54] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 54)

; Spectrum Band 55
Shape55=Rectangle (#UnitStartX# * 54), ((#BarHeight# * #Scale#) - ([CalcBand55] * #Jump#)), #UnitWidth#, (Neg([CalcBand55] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 55)

; Spectrum Band 56
Shape56=Rectangle (#UnitStartX# * 55), ((#BarHeight# * #Scale#) - ([CalcBand56] * #Jump#)), #UnitWidth#, (Neg([CalcBand56] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 56)

; Spectrum Band 57
Shape57=Rectangle (#UnitStartX# * 56), ((#BarHeight# * #Scale#) - ([CalcBand57] * #Jump#)), #UnitWidth#, (Neg([CalcBand57] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 57)

; Spectrum Band 58
Shape58=Rectangle (#UnitStartX# * 57), ((#BarHeight# * #Scale#) - ([CalcBand58] * #Jump#)), #UnitWidth#, (Neg([CalcBand58] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 58)

; Spectrum Band 59
Shape59=Rectangle (#UnitStartX# * 58), ((#BarHeight# * #Scale#) - ([CalcBand59] * #Jump#)), #UnitWidth#, (Neg([CalcBand59] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 59)

; Spectrum Band 60
Shape60=Rectangle (#UnitStartX# * 59), ((#BarHeight# * #Scale#) - ([CalcBand60] * #Jump#)), #UnitWidth#, (Neg([CalcBand60] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 60)

; Spectrum Band 61
Shape61=Rectangle (#UnitStartX# * 60), ((#BarHeight# * #Scale#) - ([CalcBand61] * #Jump#)), #UnitWidth#, (Neg([CalcBand61] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 61)

; Spectrum Band 62
Shape62=Rectangle (#UnitStartX# * 61), ((#BarHeight# * #Scale#) - ([CalcBand62] * #Jump#)), #UnitWidth#, (Neg([CalcBand62] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 62)

; Spectrum Band 63
Shape63=Rectangle (#UnitStartX# * 62), ((#BarHeight# * #Scale#) - ([CalcBand63] * #Jump#)), #UnitWidth#, (Neg([CalcBand63] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 63)

; Spectrum Band 64
Shape64=Rectangle (#UnitStartX# * 63), ((#BarHeight# * #Scale#) - ([CalcBand64] * #Jump#)), #UnitWidth#, (Neg([CalcBand64] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Disabled=(#Bands# < 64)

SpectrumModifiers=Fill Color #BarColor# | StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#
ReflectionModifiers=StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#,#Alpha#
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#
;SpectrumGradient=90 | 0,255,0,#Alpha# ; #SpectrumStart# | 255,255,0,#Alpha# ; #SpectrumMid# | 255,0,0,1 ; #SpectrumEnd#
ReflectionGradient=270 | #BarColor#,#Alpha# ; #ReflectionStart# | #BarColor#,0 ; #ReflectionEnd#
;ReflectionGradient=270 | 0,255,0,#Alpha# ; #ReflectionStart# | 255,255,0,#Alpha# ; #ReflectionMid# | 255,0,0,1 ; #ReflectionEnd#
