[Variables]
@includeVariables=#@#VariablesVisualizer.inc
@includeCalcs=#@#Visualizer\CalcBands.inc
@includeMeasures=#@#Visualizer\MeasureBands.inc

UnitWidth=(#BarWidth# * #Scale#)
UnitHeight=((#BarHeight# + #BarSpacingY#) * #Scale#)
UnitRounding=((#BarWidth# / 2) * #Scale#)
UnitStartX=((#BarWidth# + #BarSpacingX#) * #Scale#)
UnitStartY=((#BarHeight# + #BarSpacingY# + #Jump#) * #Scale#)

[Reflection]
Meter=Shape
;TransformationMatrix=1;0;0;-1;0;(((#UnitHeight# + #Jump#) * 2) * #Scale#)
DynamicVariables=1

; Reflection of Band 1
Shape=Rectangle 0, ((#UnitHeight# * #Scale#) + ([CalcBand1] * #Jump#)), #UnitWidth#, ([CalcBand1] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=0

; Reflection of Band 2
Shape2=Rectangle (#UnitStartX# * 1),  ((#UnitHeight# * #Scale#) + ([CalcBand2] * #Jump#)), #UnitWidth#, ([CalcBand2] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 2)

; Reflection of Band 3
Shape3=Rectangle (#UnitStartX# * 2), ((#UnitHeight# * #Scale#) + ([CalcBand3] * #Jump#)), #UnitWidth#, ([CalcBand3] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 3)

; Reflection of Band 4
Shape4=Rectangle (#UnitStartX# * 3),  ((#UnitHeight# * #Scale#) + ([CalcBand4] * #Jump#)), #UnitWidth#, ([CalcBand4] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 4)

; Reflection of Band 5
Shape5=Rectangle (#UnitStartX# * 4),  ((#UnitHeight# * #Scale#) + ([CalcBand5] * #Jump#)), #UnitWidth#, ([CalcBand5] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 5)

; Reflection of Band 6
Shape6=Rectangle (#UnitStartX# * 5), ((#UnitHeight# * #Scale#) + ([CalcBand6] * #Jump#)), #UnitWidth#, ([CalcBand6] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 6)

; Reflection of Band 7
Shape7=Rectangle (#UnitStartX# * 6), ((#UnitHeight# * #Scale#) + ([CalcBand7] * #Jump#)), #UnitWidth#, ([CalcBand7] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 7)

; Reflection of Band 8
Shape8=Rectangle (#UnitStartX# * 7), ((#UnitHeight# * #Scale#) + ([CalcBand8] * #Jump#)), #UnitWidth#, ([CalcBand8] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 8)

; Reflection of Band 9
Shape9=Rectangle (#UnitStartX# * 8), ((#UnitHeight# * #Scale#) + ([CalcBand9] * #Jump#)), #UnitWidth#, ([CalcBand9] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 9)

; Reflection of Band 10
Shape10=Rectangle (#UnitStartX# * 9), ((#UnitHeight# * #Scale#) + ([CalcBand10] * #Jump#)), #UnitWidth#, ([CalcBand10] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 10)

; Reflection of Band 11
Shape11=Rectangle (#UnitStartX# * 10), ((#UnitHeight# * #Scale#) + ([CalcBand11] * #Jump#)), #UnitWidth#, ([CalcBand11] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 11)

; Reflection of Band 12
Shape12=Rectangle (#UnitStartX# * 11), ((#UnitHeight# * #Scale#) + ([CalcBand12] * #Jump#)), #UnitWidth#, ([CalcBand12] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 12)

; Reflection of Band 13
Shape13=Rectangle (#UnitStartX# * 12), ((#UnitHeight# * #Scale#) + ([CalcBand13] * #Jump#)), #UnitWidth#, ([CalcBand13] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 13)

; Reflection of Band 14
Shape14=Rectangle (#UnitStartX# * 13), ((#UnitHeight# * #Scale#) + ([CalcBand14] * #Jump#)), #UnitWidth#, ([CalcBand14] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 14)

; Reflection of Band 15
Shape15=Rectangle (#UnitStartX# * 14), ((#UnitHeight# * #Scale#) + ([CalcBand15] * #Jump#)), #UnitWidth#, ([CalcBand15] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 15)

; Reflection of Band 16
Shape16=Rectangle (#UnitStartX# * 15), ((#UnitHeight# * #Scale#) + ([CalcBand16] * #Jump#)), #UnitWidth#, ([CalcBand16] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 16)

; Reflection of Band 17
Shape17=Rectangle (#UnitStartX# * 16), ((#UnitHeight# * #Scale#) + ([CalcBand17] * #Jump#)), #UnitWidth#, ([CalcBand17] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 17)

; Reflection of Band 18
Shape18=Rectangle (#UnitStartX# * 17), ((#UnitHeight# * #Scale#) + ([CalcBand18] * #Jump#)), #UnitWidth#, ([CalcBand18] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 18)

; Reflection of Band 19
Shape19=Rectangle (#UnitStartX# * 18), ((#UnitHeight# * #Scale#) + ([CalcBand19] * #Jump#)), #UnitWidth#, ([CalcBand19] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 19)

; Reflection of Band 20
Shape20=Rectangle (#UnitStartX# * 19), ((#UnitHeight# * #Scale#) + ([CalcBand20] * #Jump#)), #UnitWidth#, ([CalcBand20] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 20)

; Reflection of Band 21
Shape21=Rectangle (#UnitStartX# * 20), ((#UnitHeight# * #Scale#) + ([CalcBand21] * #Jump#)), #UnitWidth#, ([CalcBand21] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 21)

; Reflection of Band 22
Shape22=Rectangle (#UnitStartX# * 21), ((#UnitHeight# * #Scale#) + ([CalcBand22] * #Jump#)), #UnitWidth#, ([CalcBand22] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 22)

; Reflection of Band 23
Shape23=Rectangle (#UnitStartX# * 22), ((#UnitHeight# * #Scale#) + ([CalcBand23] * #Jump#)), #UnitWidth#, ([CalcBand23] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 23)

; Reflection of Band 24
Shape24=Rectangle (#UnitStartX# * 23), ((#UnitHeight# * #Scale#) + ([CalcBand24] * #Jump#)), #UnitWidth#, ([CalcBand24] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 24)

; Reflection of Band 25
Shape25=Rectangle (#UnitStartX# * 24), ((#UnitHeight# * #Scale#) + ([CalcBand25] * #Jump#)), #UnitWidth#, ([CalcBand25] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 25)

; Reflection of Band 26
Shape26=Rectangle (#UnitStartX# * 25), ((#UnitHeight# * #Scale#) + ([CalcBand26] * #Jump#)), #UnitWidth#, ([CalcBand26] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 26)

; Reflection of Band 27
Shape27=Rectangle (#UnitStartX# * 26), ((#UnitHeight# * #Scale#) + ([CalcBand27] * #Jump#)), #UnitWidth#, ([CalcBand27] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 27)

; Reflection of Band 28
Shape28=Rectangle (#UnitStartX# * 27), ((#UnitHeight# * #Scale#) + ([CalcBand28] * #Jump#)), #UnitWidth#, ([CalcBand28] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 28)

; Reflection of Band 29
Shape29=Rectangle (#UnitStartX# * 28), ((#UnitHeight# * #Scale#) + ([CalcBand29] * #Jump#)), #UnitWidth#, ([CalcBand29] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 29)

; Reflection of Band 30
Shape30=Rectangle (#UnitStartX# * 29), ((#UnitHeight# * #Scale#) + ([CalcBand30] * #Jump#)), #UnitWidth#, ([CalcBand30] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 30)

; Reflection of Band 31
Shape31=Rectangle (#UnitStartX# * 30), ((#UnitHeight# * #Scale#) + ([CalcBand31] * #Jump#)), #UnitWidth#, ([CalcBand31] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 31)

; Reflection of Band 32
Shape32=Rectangle (#UnitStartX# * 31), ((#UnitHeight# * #Scale#) + ([CalcBand32] * #Jump#)), #UnitWidth#, ([CalcBand32] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 32)

; Reflection of Band 33
Shape33=Rectangle (#UnitStartX# * 32), ((#UnitHeight# * #Scale#) + ([CalcBand33] * #Jump#)), #UnitWidth#, ([CalcBand33] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 33)

; Reflection of Band 34
Shape34=Rectangle (#UnitStartX# * 33), ((#UnitHeight# * #Scale#) + ([CalcBand34] * #Jump#)), #UnitWidth#, ([CalcBand34] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 34)

; Reflection of Band 35
Shape35=Rectangle (#UnitStartX# * 34), ((#UnitHeight# * #Scale#) + ([CalcBand35] * #Jump#)), #UnitWidth#, ([CalcBand35] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 35)

; Reflection of Band 36
Shape36=Rectangle (#UnitStartX# * 35), ((#UnitHeight# * #Scale#) + ([CalcBand36] * #Jump#)), #UnitWidth#, ([CalcBand36] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 36)

; Reflection of Band 37
Shape37=Rectangle (#UnitStartX# * 36), ((#UnitHeight# * #Scale#) + ([CalcBand37] * #Jump#)), #UnitWidth#, ([CalcBand37] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 37)

; Reflection of Band 38
Shape38=Rectangle (#UnitStartX# * 37), ((#UnitHeight# * #Scale#) + ([CalcBand38] * #Jump#)), #UnitWidth#, ([CalcBand38] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 38)

; Reflection of Band 39
Shape39=Rectangle (#UnitStartX# * 38), ((#UnitHeight# * #Scale#) + ([CalcBand39] * #Jump#)), #UnitWidth#, ([CalcBand39] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 39)

; Reflection of Band 40
Shape40=Rectangle (#UnitStartX# * 39), ((#UnitHeight# * #Scale#) + ([CalcBand40] * #Jump#)), #UnitWidth#, ([CalcBand40] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 40)

; Reflection of Band 41
Shape41=Rectangle (#UnitStartX# * 40), ((#UnitHeight# * #Scale#) + ([CalcBand41] * #Jump#)), #UnitWidth#, ([CalcBand41] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 41)

; Reflection of Band 42
Shape42=Rectangle (#UnitStartX# * 41), ((#UnitHeight# * #Scale#) + ([CalcBand42] * #Jump#)), #UnitWidth#, ([CalcBand42] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 42)

; Reflection of Band 43
Shape43=Rectangle (#UnitStartX# * 42), ((#UnitHeight# * #Scale#) + ([CalcBand43] * #Jump#)), #UnitWidth#, ([CalcBand43] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 43)

; Reflection of Band 44
Shape44=Rectangle (#UnitStartX# * 43), ((#UnitHeight# * #Scale#) + ([CalcBand44] * #Jump#)), #UnitWidth#, ([CalcBand44] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 44)

; Reflection of Band 45
Shape45=Rectangle (#UnitStartX# * 44), ((#UnitHeight# * #Scale#) + ([CalcBand45] * #Jump#)), #UnitWidth#, ([CalcBand45] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 45)

; Reflection of Band 46
Shape46=Rectangle (#UnitStartX# * 45), ((#UnitHeight# * #Scale#) + ([CalcBand46] * #Jump#)), #UnitWidth#, ([CalcBand46] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 46)

; Reflection of Band 47
Shape47=Rectangle (#UnitStartX# * 46), ((#UnitHeight# * #Scale#) + ([CalcBand47] * #Jump#)), #UnitWidth#, ([CalcBand47] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 47)

; Reflection of Band 48
Shape48=Rectangle (#UnitStartX# * 47), ((#UnitHeight# * #Scale#) + ([CalcBand48] * #Jump#)), #UnitWidth#, ([CalcBand48] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 48)

; Reflection of Band 49
Shape49=Rectangle (#UnitStartX# * 48), ((#UnitHeight# * #Scale#) + ([CalcBand49] * #Jump#)), #UnitWidth#, ([CalcBand49] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 49)

; Reflection of Band 50
Shape50=Rectangle (#UnitStartX# * 49), ((#UnitHeight# * #Scale#) + ([CalcBand50] * #Jump#)), #UnitWidth#, ([CalcBand50] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 50)

; Reflection of Band 51
Shape51=Rectangle (#UnitStartX# * 50), ((#UnitHeight# * #Scale#) + ([CalcBand51] * #Jump#)), #UnitWidth#, ([CalcBand51] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 51)

; Reflection of Band 52
Shape52=Rectangle (#UnitStartX# * 51), ((#UnitHeight# * #Scale#) + ([CalcBand52] * #Jump#)), #UnitWidth#, ([CalcBand52] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 52)

; Reflection of Band 53
Shape53=Rectangle (#UnitStartX# * 52), ((#UnitHeight# * #Scale#) + ([CalcBand53] * #Jump#)), #UnitWidth#, ([CalcBand53] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 53)

; Reflection of Band 54
Shape54=Rectangle (#UnitStartX# * 53), ((#UnitHeight# * #Scale#) + ([CalcBand54] * #Jump#)), #UnitWidth#, ([CalcBand54] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 54)

; Reflection of Band 55
Shape55=Rectangle (#UnitStartX# * 54), ((#UnitHeight# * #Scale#) + ([CalcBand55] * #Jump#)), #UnitWidth#, ([CalcBand55] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 55)

; Reflection of Band 56
Shape56=Rectangle (#UnitStartX# * 55), ((#UnitHeight# * #Scale#) + ([CalcBand56] * #Jump#)), #UnitWidth#, ([CalcBand56] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 56)

; Reflection of Band 57
Shape57=Rectangle (#UnitStartX# * 56), ((#UnitHeight# * #Scale#) + ([CalcBand57] * #Jump#)), #UnitWidth#, ([CalcBand57] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 57)

; Reflection of Band 58
Shape58=Rectangle (#UnitStartX# * 57), ((#UnitHeight# * #Scale#) + ([CalcBand58] * #Jump#)), #UnitWidth#, ([CalcBand58] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 58)

; Reflection of Band 59
Shape59=Rectangle (#UnitStartX# * 58), ((#UnitHeight# * #Scale#) + ([CalcBand59] * #Jump#)), #UnitWidth#, ([CalcBand59] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 59)

; Reflection of Band 60
Shape60=Rectangle (#UnitStartX# * 59), ((#UnitHeight# * #Scale#) + ([CalcBand60] * #Jump#)), #UnitWidth#, ([CalcBand60] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 60)

; Reflection of Band 61
Shape61=Rectangle (#UnitStartX# * 60), ((#UnitHeight# * #Scale#) + ([CalcBand61] * #Jump#)), #UnitWidth#, ([CalcBand61] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 61)

; Reflection of Band 62
Shape62=Rectangle (#UnitStartX# * 61), ((#UnitHeight# * #Scale#) + ([CalcBand62] * #Jump#)), #UnitWidth#, ([CalcBand62] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 62)

; Reflection of Band 63
Shape63=Rectangle (#UnitStartX# * 62), ((#UnitHeight# * #Scale#) + ([CalcBand63] * #Jump#)), #UnitWidth#, ([CalcBand63] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 63)

; Reflection of Band 64
Shape64=Rectangle (#UnitStartX# * 63), ((#UnitHeight# * #Scale#) + ([CalcBand64] * #Jump#)), #UnitWidth#, ([CalcBand64] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient
Disabled=(#Bands# < 64)

SpectrumModifiers=Fill Color #BarColor# | StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#
ReflectionModifiers=StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#,#Alpha#
SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#
;SpectrumGradient=90 | 0,255,0,#Alpha# ; #SpectrumStart# | 255,255,0,#Alpha# ; #SpectrumMid# | 255,0,0,1 ; #SpectrumEnd#
;ReflectionGradient=90 | #BarColor#,#Alpha# ; #ReflectionStart# | #BarColor#,0 ; #ReflectionEnd#
ReflectionGradient=270 | 0,255,0,#Alpha# ; #ReflectionStart# | 255,255,0,#Alpha# ; #ReflectionMid# | 255,0,0,1 ; #ReflectionEnd#