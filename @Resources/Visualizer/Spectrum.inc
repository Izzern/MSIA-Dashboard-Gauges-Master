[Variables]
@includeVariablesUser=#@#Visualizer\Settings\VariablesUser.inc
@includeVariables=#@#Visualizer\Settings\VariablesVisualizer.inc
@includeCalcs=#@#Visualizer\Settings\CalcBands.inc
@includeMeasures=#@#Visualizer\Settings\MeasureBands.inc

UnitWidth=((#BarWidth# + #BarSpacingX#) * #ScaleVis#)
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
TransformationMatrix=1;0;0;1;0;0
Shape=Rectangle 0, ((#BarHeight# * #ScaleVis#) - ([CalcBand1] * #Jump#)), #UnitWidth#, (Neg([CalcBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers

Disabled=0
LeftMouseUpAction=[!ToggleConfig "#Path#\Settings" "Settings.ini"]
RightMouseUpAction=[!CommandMeasure CreateSpectrum "Run"]

SpectrumModifiers=Fill Color 0,0,0,1 | StrokeWidth #StrokeWidth# | Stroke Color 0,0,0,1
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#

[Spectrum]
Meter=Shape
TransformationMatrix=1;0;0;1;0;0
DynamicVariables=1

; Spectrum and Reflection for Band 1
Shape=Rectangle 0, ((#BarHeight# * #ScaleVis#) - ([CalcBand1] * #Jump#)), #UnitWidth#, (Neg([CalcBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape2=Rectangle 0, (#UnitStartY# + ([CalcBand1] * #Jump#)), #UnitWidth#, (([CalcBand1] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=0

; Spectrum and Reflection for Band 2
Shape3=Rectangle (#UnitStartX# * 1),  ((#BarHeight# * #ScaleVis#) - ([CalcBand2] * #Jump#)), #UnitWidth#, (Neg([CalcBand2] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape4=Rectangle (#UnitStartX# * 1), (#UnitStartY# + ([CalcBand2] * #Jump#)), #UnitWidth#, (([CalcBand2] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 2)

; Spectrum and Reflection for Band 3
Shape5=Rectangle (#UnitStartX# * 2), ((#BarHeight# * #ScaleVis#) - ([CalcBand3] * #Jump#)), #UnitWidth#, (Neg([CalcBand3] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape6=Rectangle (#UnitStartX# * 2), (#UnitStartY# + ([CalcBand3] * #Jump#)), #UnitWidth#, (([CalcBand3] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 3)

; Spectrum and Reflection for Band 4
Shape7=Rectangle (#UnitStartX# * 3),  ((#BarHeight# * #ScaleVis#) - ([CalcBand4] * #Jump#)), #UnitWidth#, (Neg([CalcBand4] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape8=Rectangle (#UnitStartX# * 3), (#UnitStartY# + ([CalcBand4] * #Jump#)), #UnitWidth#, (([CalcBand4] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 3)

; Spectrum and Reflection for Band 5
Shape9=Rectangle (#UnitStartX# * 4),  ((#BarHeight# * #ScaleVis#) - ([CalcBand5] * #Jump#)), #UnitWidth#, (Neg([CalcBand5] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape10=Rectangle (#UnitStartX# * 4), (#UnitStartY# + ([CalcBand5] * #Jump#)), #UnitWidth#, (([CalcBand5] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 4)

; Spectrum and Reflection for Band 6
Shape11=Rectangle (#UnitStartX# * 5), ((#BarHeight# * #ScaleVis#) - ([CalcBand6] * #Jump#)), #UnitWidth#, (Neg([CalcBand6] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape12=Rectangle (#UnitStartX# * 5), (#UnitStartY# + ([CalcBand6] * #Jump#)), #UnitWidth#, (([CalcBand6] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 6)

; Spectrum and Reflection for Band 7
Shape13=Rectangle (#UnitStartX# * 6), ((#BarHeight# * #ScaleVis#) - ([CalcBand7] * #Jump#)), #UnitWidth#, (Neg([CalcBand7] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape14=Rectangle (#UnitStartX# * 6), (#UnitStartY# + ([CalcBand7] * #Jump#)), #UnitWidth#, (([CalcBand7] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 7)

; Spectrum and Reflection for Band 8
Shape15=Rectangle (#UnitStartX# * 7), ((#BarHeight# * #ScaleVis#) - ([CalcBand8] * #Jump#)), #UnitWidth#, (Neg([CalcBand8] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape16=Rectangle (#UnitStartX# * 7), (#UnitStartY# + ([CalcBand8] * #Jump#)), #UnitWidth#, (([CalcBand8] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 8)

; Spectrum and Reflection for Band 9
Shape17=Rectangle (#UnitStartX# * 8), ((#BarHeight# * #ScaleVis#) - ([CalcBand9] * #Jump#)), #UnitWidth#, (Neg([CalcBand9] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape18=Rectangle (#UnitStartX# * 8), (#UnitStartY# + ([CalcBand9] * #Jump#)), #UnitWidth#, (([CalcBand9] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 9)

; Spectrum and Reflection for Band 10
Shape19=Rectangle (#UnitStartX# * 9), ((#BarHeight# * #ScaleVis#) - ([CalcBand10] * #Jump#)), #UnitWidth#, (Neg([CalcBand10] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape20=Rectangle (#UnitStartX# * 9), (#UnitStartY# + ([CalcBand10] * #Jump#)), #UnitWidth#, (([CalcBand10] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 10)

; Spectrum and Reflection for Band 11
Shape21=Rectangle (#UnitStartX# * 10), ((#BarHeight# * #ScaleVis#) - ([CalcBand11] * #Jump#)), #UnitWidth#, (Neg([CalcBand11] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape22=Rectangle (#UnitStartX# * 10), (#UnitStartY# + ([CalcBand11] * #Jump#)), #UnitWidth#, (([CalcBand11] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 11)

; Spectrum and Reflection for Band 12
Shape23=Rectangle (#UnitStartX# * 11), ((#BarHeight# * #ScaleVis#) - ([CalcBand12] * #Jump#)), #UnitWidth#, (Neg([CalcBand12] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape24=Rectangle (#UnitStartX# * 11), (#UnitStartY# + ([CalcBand12] * #Jump#)), #UnitWidth#, (([CalcBand12] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 12)

; Spectrum and Reflection for Band 13
Shape25=Rectangle (#UnitStartX# * 12), ((#BarHeight# * #ScaleVis#) - ([CalcBand13] * #Jump#)), #UnitWidth#, (Neg([CalcBand13] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape26=Rectangle (#UnitStartX# * 12), (#UnitStartY# + ([CalcBand13] * #Jump#)), #UnitWidth#, (([CalcBand13] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 13)

; Spectrum and Reflection for Band 14
Shape27=Rectangle (#UnitStartX# * 13), ((#BarHeight# * #ScaleVis#) - ([CalcBand14] * #Jump#)), #UnitWidth#, (Neg([CalcBand14] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape28=Rectangle (#UnitStartX# * 13), (#UnitStartY# + ([CalcBand14] * #Jump#)), #UnitWidth#, (([CalcBand14] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 14)

; Spectrum and Reflection for Band 15
Shape29=Rectangle (#UnitStartX# * 14), ((#BarHeight# * #ScaleVis#) - ([CalcBand15] * #Jump#)), #UnitWidth#, (Neg([CalcBand15] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape30=Rectangle (#UnitStartX# * 14), (#UnitStartY# + ([CalcBand15] * #Jump#)), #UnitWidth#, (([CalcBand15] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 15)

; Spectrum and Reflection for Band 16
Shape31=Rectangle (#UnitStartX# * 15), ((#BarHeight# * #ScaleVis#) - ([CalcBand16] * #Jump#)), #UnitWidth#, (Neg([CalcBand16] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape32=Rectangle (#UnitStartX# * 15), (#UnitStartY# + ([CalcBand16] * #Jump#)), #UnitWidth#, (([CalcBand16] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 16)

; Spectrum and Reflection for Band 17
Shape33=Rectangle (#UnitStartX# * 16), ((#BarHeight# * #ScaleVis#) - ([CalcBand17] * #Jump#)), #UnitWidth#, (Neg([CalcBand17] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape34=Rectangle (#UnitStartX# * 16), (#UnitStartY# + ([CalcBand17] * #Jump#)), #UnitWidth#, (([CalcBand17] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 17)

; Spectrum and Reflection for Band 18
Shape35=Rectangle (#UnitStartX# * 17), ((#BarHeight# * #ScaleVis#) - ([CalcBand18] * #Jump#)), #UnitWidth#, (Neg([CalcBand18] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape36=Rectangle (#UnitStartX# * 17), (#UnitStartY# + ([CalcBand18] * #Jump#)), #UnitWidth#, (([CalcBand18] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 18)

; Spectrum and Reflection for Band 19
Shape37=Rectangle (#UnitStartX# * 18), ((#BarHeight# * #ScaleVis#) - ([CalcBand19] * #Jump#)), #UnitWidth#, (Neg([CalcBand19] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape38=Rectangle (#UnitStartX# * 18), (#UnitStartY# + ([CalcBand19] * #Jump#)), #UnitWidth#, (([CalcBand19] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 19)

; Spectrum and Reflection for Band 20
Shape39=Rectangle (#UnitStartX# * 19), ((#BarHeight# * #ScaleVis#) - ([CalcBand20] * #Jump#)), #UnitWidth#, (Neg([CalcBand20] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape40=Rectangle (#UnitStartX# * 19), (#UnitStartY# + ([CalcBand20] * #Jump#)), #UnitWidth#, (([CalcBand20] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 20)

; Spectrum and Reflection for Band 21
Shape41=Rectangle (#UnitStartX# * 20), ((#BarHeight# * #ScaleVis#) - ([CalcBand21] * #Jump#)), #UnitWidth#, (Neg([CalcBand21] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape42=Rectangle (#UnitStartX# * 20), (#UnitStartY# + ([CalcBand21] * #Jump#)), #UnitWidth#, (([CalcBand21] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 21)

; Spectrum and Reflection for Band 22
Shape43=Rectangle (#UnitStartX# * 21), ((#BarHeight# * #ScaleVis#) - ([CalcBand22] * #Jump#)), #UnitWidth#, (Neg([CalcBand22] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape44=Rectangle (#UnitStartX# * 21), (#UnitStartY# + ([CalcBand22] * #Jump#)), #UnitWidth#, (([CalcBand22] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 22)

; Spectrum and Reflection for Band 23
Shape45=Rectangle (#UnitStartX# * 22), ((#BarHeight# * #ScaleVis#) - ([CalcBand23] * #Jump#)), #UnitWidth#, (Neg([CalcBand23] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape46=Rectangle (#UnitStartX# * 22), (#UnitStartY# + ([CalcBand23] * #Jump#)), #UnitWidth#, (([CalcBand23] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 23)

; Spectrum and Reflection for Band 24
Shape47=Rectangle (#UnitStartX# * 23), ((#BarHeight# * #ScaleVis#) - ([CalcBand24] * #Jump#)), #UnitWidth#, (Neg([CalcBand24] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape48=Rectangle (#UnitStartX# * 23), (#UnitStartY# + ([CalcBand24] * #Jump#)), #UnitWidth#, (([CalcBand24] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 24)

; Spectrum and Reflection for Band 25
Shape49=Rectangle (#UnitStartX# * 24), ((#BarHeight# * #ScaleVis#) - ([CalcBand25] * #Jump#)), #UnitWidth#, (Neg([CalcBand25] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape50=Rectangle (#UnitStartX# * 24), (#UnitStartY# + ([CalcBand25] * #Jump#)), #UnitWidth#, (([CalcBand25] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 25)

; Spectrum and Reflection for Band 26
Shape51=Rectangle (#UnitStartX# * 25), ((#BarHeight# * #ScaleVis#) - ([CalcBand26] * #Jump#)), #UnitWidth#, (Neg([CalcBand26] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape52=Rectangle (#UnitStartX# * 25), (#UnitStartY# + ([CalcBand26] * #Jump#)), #UnitWidth#, (([CalcBand26] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 26)

; Spectrum and Reflection for Band 27
Shape53=Rectangle (#UnitStartX# * 26), ((#BarHeight# * #ScaleVis#) - ([CalcBand27] * #Jump#)), #UnitWidth#, (Neg([CalcBand27] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape54=Rectangle (#UnitStartX# * 26), (#UnitStartY# + ([CalcBand27] * #Jump#)), #UnitWidth#, (([CalcBand27] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 27)

; Spectrum and Reflection for Band 28
Shape55=Rectangle (#UnitStartX# * 27), ((#BarHeight# * #ScaleVis#) - ([CalcBand28] * #Jump#)), #UnitWidth#, (Neg([CalcBand28] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape56=Rectangle (#UnitStartX# * 27), (#UnitStartY# + ([CalcBand28] * #Jump#)), #UnitWidth#, (([CalcBand28] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 28)

; Spectrum and Reflection for Band 29
Shape57=Rectangle (#UnitStartX# * 28), ((#BarHeight# * #ScaleVis#) - ([CalcBand29] * #Jump#)), #UnitWidth#, (Neg([CalcBand29] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape58=Rectangle (#UnitStartX# * 28), (#UnitStartY# + ([CalcBand29] * #Jump#)), #UnitWidth#, (([CalcBand29] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 29)

; Spectrum and Reflection for Band 30
Shape59=Rectangle (#UnitStartX# * 29), ((#BarHeight# * #ScaleVis#) - ([CalcBand30] * #Jump#)), #UnitWidth#, (Neg([CalcBand30] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape60=Rectangle (#UnitStartX# * 29), (#UnitStartY# + ([CalcBand30] * #Jump#)), #UnitWidth#, (([CalcBand30] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 30)

; Spectrum and Reflection for Band 31
Shape61=Rectangle (#UnitStartX# * 30), ((#BarHeight# * #ScaleVis#) - ([CalcBand31] * #Jump#)), #UnitWidth#, (Neg([CalcBand31] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape62=Rectangle (#UnitStartX# * 30), (#UnitStartY# + ([CalcBand31] * #Jump#)), #UnitWidth#, (([CalcBand31] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 31)

; Spectrum and Reflection for Band 32
Shape63=Rectangle (#UnitStartX# * 31), ((#BarHeight# * #ScaleVis#) - ([CalcBand32] * #Jump#)), #UnitWidth#, (Neg([CalcBand32] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape64=Rectangle (#UnitStartX# * 31), (#UnitStartY# + ([CalcBand32] * #Jump#)), #UnitWidth#, (([CalcBand32] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 32)

; Spectrum and Reflection for Band 33
Shape65=Rectangle (#UnitStartX# * 32), ((#BarHeight# * #ScaleVis#) - ([CalcBand33] * #Jump#)), #UnitWidth#, (Neg([CalcBand33] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape66=Rectangle (#UnitStartX# * 32), (#UnitStartY# + ([CalcBand33] * #Jump#)), #UnitWidth#, (([CalcBand33] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 33)

; Spectrum and Reflection for Band 34
Shape67=Rectangle (#UnitStartX# * 33), ((#BarHeight# * #ScaleVis#) - ([CalcBand34] * #Jump#)), #UnitWidth#, (Neg([CalcBand34] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape68=Rectangle (#UnitStartX# * 33), (#UnitStartY# + ([CalcBand34] * #Jump#)), #UnitWidth#, (([CalcBand34] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 34)

; Spectrum and Reflection for Band 35
Shape69=Rectangle (#UnitStartX# * 34), ((#BarHeight# * #ScaleVis#) - ([CalcBand35] * #Jump#)), #UnitWidth#, (Neg([CalcBand35] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape70=Rectangle (#UnitStartX# * 34), (#UnitStartY# + ([CalcBand35] * #Jump#)), #UnitWidth#, (([CalcBand35] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 35)

; Spectrum and Reflection for Band 36
Shape71=Rectangle (#UnitStartX# * 35), ((#BarHeight# * #ScaleVis#) - ([CalcBand36] * #Jump#)), #UnitWidth#, (Neg([CalcBand36] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape72=Rectangle (#UnitStartX# * 35), (#UnitStartY# + ([CalcBand36] * #Jump#)), #UnitWidth#, (([CalcBand36] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 36)

; Spectrum and Reflection for Band 37
Shape73=Rectangle (#UnitStartX# * 36), ((#BarHeight# * #ScaleVis#) - ([CalcBand37] * #Jump#)), #UnitWidth#, (Neg([CalcBand37] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape74=Rectangle (#UnitStartX# * 36), (#UnitStartY# + ([CalcBand37] * #Jump#)), #UnitWidth#, (([CalcBand37] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 37)

; Spectrum and Reflection for Band 38
Shape75=Rectangle (#UnitStartX# * 37), ((#BarHeight# * #ScaleVis#) - ([CalcBand38] * #Jump#)), #UnitWidth#, (Neg([CalcBand38] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape76=Rectangle (#UnitStartX# * 37), (#UnitStartY# + ([CalcBand38] * #Jump#)), #UnitWidth#, (([CalcBand38] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 38)

; Spectrum and Reflection for Band 39
Shape77=Rectangle (#UnitStartX# * 38), ((#BarHeight# * #ScaleVis#) - ([CalcBand39] * #Jump#)), #UnitWidth#, (Neg([CalcBand39] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape78=Rectangle (#UnitStartX# * 38), (#UnitStartY# + ([CalcBand39] * #Jump#)), #UnitWidth#, (([CalcBand39] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 39)

; Spectrum and Reflection for Band 40
Shape79=Rectangle (#UnitStartX# * 39), ((#BarHeight# * #ScaleVis#) - ([CalcBand40] * #Jump#)), #UnitWidth#, (Neg([CalcBand40] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape80=Rectangle (#UnitStartX# * 39), (#UnitStartY# + ([CalcBand40] * #Jump#)), #UnitWidth#, (([CalcBand40] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 40)

; Spectrum and Reflection for Band 41
Shape81=Rectangle (#UnitStartX# * 40), ((#BarHeight# * #ScaleVis#) - ([CalcBand41] * #Jump#)), #UnitWidth#, (Neg([CalcBand41] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape82=Rectangle (#UnitStartX# * 40), (#UnitStartY# + ([CalcBand41] * #Jump#)), #UnitWidth#, (([CalcBand41] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 41)

; Spectrum and Reflection for Band 42
Shape83=Rectangle (#UnitStartX# * 41), ((#BarHeight# * #ScaleVis#) - ([CalcBand42] * #Jump#)), #UnitWidth#, (Neg([CalcBand42] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape84=Rectangle (#UnitStartX# * 41), (#UnitStartY# + ([CalcBand42] * #Jump#)), #UnitWidth#, (([CalcBand42] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 42)

; Spectrum and Reflection for Band 43
Shape85=Rectangle (#UnitStartX# * 42), ((#BarHeight# * #ScaleVis#) - ([CalcBand43] * #Jump#)), #UnitWidth#, (Neg([CalcBand43] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape86=Rectangle (#UnitStartX# * 42), (#UnitStartY# + ([CalcBand43] * #Jump#)), #UnitWidth#, (([CalcBand43] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 43)

; Spectrum and Reflection for Band 44
Shape87=Rectangle (#UnitStartX# * 43), ((#BarHeight# * #ScaleVis#) - ([CalcBand44] * #Jump#)), #UnitWidth#, (Neg([CalcBand44] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape88=Rectangle (#UnitStartX# * 43), (#UnitStartY# + ([CalcBand44] * #Jump#)), #UnitWidth#, (([CalcBand44] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 44)

; Spectrum and Reflection for Band 45
Shape89=Rectangle (#UnitStartX# * 44), ((#BarHeight# * #ScaleVis#) - ([CalcBand45] * #Jump#)), #UnitWidth#, (Neg([CalcBand45] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape90=Rectangle (#UnitStartX# * 44), (#UnitStartY# + ([CalcBand45] * #Jump#)), #UnitWidth#, (([CalcBand45] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 45)

; Spectrum and Reflection for Band 46
Shape91=Rectangle (#UnitStartX# * 45), ((#BarHeight# * #ScaleVis#) - ([CalcBand46] * #Jump#)), #UnitWidth#, (Neg([CalcBand46] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape92=Rectangle (#UnitStartX# * 45), (#UnitStartY# + ([CalcBand46] * #Jump#)), #UnitWidth#, (([CalcBand46] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 46)

; Spectrum and Reflection for Band 47
Shape93=Rectangle (#UnitStartX# * 46), ((#BarHeight# * #ScaleVis#) - ([CalcBand47] * #Jump#)), #UnitWidth#, (Neg([CalcBand47] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape94=Rectangle (#UnitStartX# * 46), (#UnitStartY# + ([CalcBand47] * #Jump#)), #UnitWidth#, (([CalcBand47] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 47)

; Spectrum and Reflection for Band 48
Shape95=Rectangle (#UnitStartX# * 47), ((#BarHeight# * #ScaleVis#) - ([CalcBand48] * #Jump#)), #UnitWidth#, (Neg([CalcBand48] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape96=Rectangle (#UnitStartX# * 47), (#UnitStartY# + ([CalcBand48] * #Jump#)), #UnitWidth#, (([CalcBand48] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 48)

; Spectrum and Reflection for Band 49
Shape97=Rectangle (#UnitStartX# * 48), ((#BarHeight# * #ScaleVis#) - ([CalcBand49] * #Jump#)), #UnitWidth#, (Neg([CalcBand49] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape98=Rectangle (#UnitStartX# * 48), (#UnitStartY# + ([CalcBand49] * #Jump#)), #UnitWidth#, (([CalcBand49] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 49)

; Spectrum and Reflection for Band 41
Shape81=Rectangle (#UnitStartX# * 40), ((#BarHeight# * #ScaleVis#) - ([CalcBand41] * #Jump#)), #UnitWidth#, (Neg([CalcBand41] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape82=Rectangle (#UnitStartX# * 40), (#UnitStartY# + ([CalcBand41] * #Jump#)), #UnitWidth#, (([CalcBand41] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 41)

; Spectrum and Reflection for Band 42
Shape83=Rectangle (#UnitStartX# * 41), ((#BarHeight# * #ScaleVis#) - ([CalcBand42] * #Jump#)), #UnitWidth#, (Neg([CalcBand42] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape84=Rectangle (#UnitStartX# * 41), (#UnitStartY# + ([CalcBand42] * #Jump#)), #UnitWidth#, (([CalcBand42] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 42)

; Spectrum and Reflection for Band 43
Shape85=Rectangle (#UnitStartX# * 42), ((#BarHeight# * #ScaleVis#) - ([CalcBand43] * #Jump#)), #UnitWidth#, (Neg([CalcBand43] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape86=Rectangle (#UnitStartX# * 42), (#UnitStartY# + ([CalcBand43] * #Jump#)), #UnitWidth#, (([CalcBand43] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 43)

; Spectrum and Reflection for Band 44
Shape87=Rectangle (#UnitStartX# * 43), ((#BarHeight# * #ScaleVis#) - ([CalcBand44] * #Jump#)), #UnitWidth#, (Neg([CalcBand44] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape88=Rectangle (#UnitStartX# * 43), (#UnitStartY# + ([CalcBand44] * #Jump#)), #UnitWidth#, (([CalcBand44] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 44)

; Spectrum and Reflection for Band 45
Shape89=Rectangle (#UnitStartX# * 44), ((#BarHeight# * #ScaleVis#) - ([CalcBand45] * #Jump#)), #UnitWidth#, (Neg([CalcBand45] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape90=Rectangle (#UnitStartX# * 44), (#UnitStartY# + ([CalcBand45] * #Jump#)), #UnitWidth#, (([CalcBand45] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 45)

; Spectrum and Reflection for Band 46
Shape91=Rectangle (#UnitStartX# * 45), ((#BarHeight# * #ScaleVis#) - ([CalcBand46] * #Jump#)), #UnitWidth#, (Neg([CalcBand46] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape92=Rectangle (#UnitStartX# * 45), (#UnitStartY# + ([CalcBand46] * #Jump#)), #UnitWidth#, (([CalcBand46] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 46)

; Spectrum and Reflection for Band 47
Shape93=Rectangle (#UnitStartX# * 46), ((#BarHeight# * #ScaleVis#) - ([CalcBand47] * #Jump#)), #UnitWidth#, (Neg([CalcBand47] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape94=Rectangle (#UnitStartX# * 46), (#UnitStartY# + ([CalcBand47] * #Jump#)), #UnitWidth#, (([CalcBand47] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 47)

; Spectrum and Reflection for Band 48
Shape95=Rectangle (#UnitStartX# * 47), ((#BarHeight# * #ScaleVis#) - ([CalcBand48] * #Jump#)), #UnitWidth#, (Neg([CalcBand48] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape96=Rectangle (#UnitStartX# * 47), (#UnitStartY# + ([CalcBand48] * #Jump#)), #UnitWidth#, (([CalcBand48] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 48)

; Spectrum and Reflection for Band 49
Shape97=Rectangle (#UnitStartX# * 48), ((#BarHeight# * #ScaleVis#) - ([CalcBand49] * #Jump#)), #UnitWidth#, (Neg([CalcBand49] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape98=Rectangle (#UnitStartX# * 48), (#UnitStartY# + ([CalcBand49] * #Jump#)), #UnitWidth#, (([CalcBand49] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 49)

; Spectrum and Reflection for Band 50
Shape99=Rectangle (#UnitStartX# * 49), ((#BarHeight# * #ScaleVis#) - ([CalcBand50] * #Jump#)), #UnitWidth#, (Neg([CalcBand50] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape100=Rectangle (#UnitStartX# * 49), (#UnitStartY# + ([CalcBand50] * #Jump#)), #UnitWidth#, (([CalcBand50] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 50)

; Spectrum and Reflection for Band 51
Shape101=Rectangle (#UnitStartX# * 50), ((#BarHeight# * #ScaleVis#) - ([CalcBand51] * #Jump#)), #UnitWidth#, (Neg([CalcBand51] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape102=Rectangle (#UnitStartX# * 50), (#UnitStartY# + ([CalcBand51] * #Jump#)), #UnitWidth#, (([CalcBand51] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 51)

; Spectrum and Reflection for Band 52
Shape103=Rectangle (#UnitStartX# * 51), ((#BarHeight# * #ScaleVis#) - ([CalcBand52] * #Jump#)), #UnitWidth#, (Neg([CalcBand52] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape104=Rectangle (#UnitStartX# * 51), (#UnitStartY# + ([CalcBand52] * #Jump#)), #UnitWidth#, (([CalcBand52] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 52)

; Spectrum and Reflection for Band 53
Shape105=Rectangle (#UnitStartX# * 52), ((#BarHeight# * #ScaleVis#) - ([CalcBand53] * #Jump#)), #UnitWidth#, (Neg([CalcBand53] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape106=Rectangle (#UnitStartX# * 52), (#UnitStartY# + ([CalcBand53] * #Jump#)), #UnitWidth#, (([CalcBand53] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 53)

; Spectrum and Reflection for Band 54
Shape107=Rectangle (#UnitStartX# * 53), ((#BarHeight# * #ScaleVis#) - ([CalcBand54] * #Jump#)), #UnitWidth#, (Neg([CalcBand54] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape108=Rectangle (#UnitStartX# * 53), (#UnitStartY# + ([CalcBand54] * #Jump#)), #UnitWidth#, (([CalcBand54] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 54)

; Spectrum and Reflection for Band 55
Shape109=Rectangle (#UnitStartX# * 54), ((#BarHeight# * #ScaleVis#) - ([CalcBand55] * #Jump#)), #UnitWidth#, (Neg([CalcBand55] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape110=Rectangle (#UnitStartX# * 54), (#UnitStartY# + ([CalcBand55] * #Jump#)), #UnitWidth#, (([CalcBand55] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 55)

; Spectrum and Reflection for Band 56
Shape111=Rectangle (#UnitStartX# * 55), ((#BarHeight# * #ScaleVis#) - ([CalcBand56] * #Jump#)), #UnitWidth#, (Neg([CalcBand56] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape112=Rectangle (#UnitStartX# * 55), (#UnitStartY# + ([CalcBand56] * #Jump#)), #UnitWidth#, (([CalcBand56] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 56)

; Spectrum and Reflection for Band 57
Shape113=Rectangle (#UnitStartX# * 56), ((#BarHeight# * #ScaleVis#) - ([CalcBand57] * #Jump#)), #UnitWidth#, (Neg([CalcBand57] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape114=Rectangle (#UnitStartX# * 56), (#UnitStartY# + ([CalcBand57] * #Jump#)), #UnitWidth#, (([CalcBand57] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 57)

; Spectrum and Reflection for Band 58
Shape115=Rectangle (#UnitStartX# * 57), ((#BarHeight# * #ScaleVis#) - ([CalcBand58] * #Jump#)), #UnitWidth#, (Neg([CalcBand58] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape116=Rectangle (#UnitStartX# * 57), (#UnitStartY# + ([CalcBand58] * #Jump#)), #UnitWidth#, (([CalcBand58] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 58)

; Spectrum and Reflection for Band 59
Shape117=Rectangle (#UnitStartX# * 58), ((#BarHeight# * #ScaleVis#) - ([CalcBand59] * #Jump#)), #UnitWidth#, (Neg([CalcBand59] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape118=Rectangle (#UnitStartX# * 58), (#UnitStartY# + ([CalcBand59] * #Jump#)), #UnitWidth#, (([CalcBand59] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 59)

; Spectrum and Reflection for Band 60
Shape119=Rectangle (#UnitStartX# * 59), ((#BarHeight# * #ScaleVis#) - ([CalcBand60] * #Jump#)), #UnitWidth#, (Neg([CalcBand60] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape120=Rectangle (#UnitStartX# * 59), (#UnitStartY# + ([CalcBand60] * #Jump#)), #UnitWidth#, (([CalcBand60] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 60)

; Spectrum and Reflection for Band 61
Shape121=Rectangle (#UnitStartX# * 60), ((#BarHeight# * #ScaleVis#) - ([CalcBand61] * #Jump#)), #UnitWidth#, (Neg([CalcBand61] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape122=Rectangle (#UnitStartX# * 60), (#UnitStartY# + ([CalcBand61] * #Jump#)), #UnitWidth#, (([CalcBand61] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 61)

; Spectrum and Reflection for Band 62
Shape123=Rectangle (#UnitStartX# * 61), ((#BarHeight# * #ScaleVis#) - ([CalcBand62] * #Jump#)), #UnitWidth#, (Neg([CalcBand62] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape124=Rectangle (#UnitStartX# * 61), (#UnitStartY# + ([CalcBand62] * #Jump#)), #UnitWidth#, (([CalcBand62] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 62)

; Spectrum and Reflection for Band 63
Shape125=Rectangle (#UnitStartX# * 62), ((#BarHeight# * #ScaleVis#) - ([CalcBand63] * #Jump#)), #UnitWidth#, (Neg([CalcBand63] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape126=Rectangle (#UnitStartX# * 62), (#UnitStartY# + ([CalcBand63] * #Jump#)), #UnitWidth#, (([CalcBand63] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 63)

; Spectrum and Reflection for Band 64
Shape127=Rectangle (#UnitStartX# * 63), ((#BarHeight# * #ScaleVis#) - ([CalcBand64] * #Jump#)), #UnitWidth#, (Neg([CalcBand64] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient
Shape128=Rectangle (#UnitStartX# * 63), (#UnitStartY# + ([CalcBand64] * #Jump#)), #UnitWidth#, (([CalcBand64] * #Gain#)), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 64)


SpectrumModifiers=Fill Color #BarColor# | StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#
ReflectionModifiers=StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#,#Alpha#
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#
;SpectrumGradient=90 | 0,255,0,#Alpha# ; #SpectrumStart# | 255,255,0,#Alpha# ; #SpectrumMid# | 255,0,0,1 ; #SpectrumEnd#
ReflectionGradient=270 | #BarColor#,#Alpha# ; #ReflectionStart# | #BarColor#,0 ; #ReflectionEnd#
;ReflectionGradient=270 | 0,255,0,#Alpha# ; #ReflectionStart# | 255,255,0,#Alpha# ; #ReflectionMid# | 255,0,0,1 ; #ReflectionEnd#




