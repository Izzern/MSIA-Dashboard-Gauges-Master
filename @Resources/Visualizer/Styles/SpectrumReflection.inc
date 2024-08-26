[ReflectionBGImage]
Meter=Image
Container=Reflection
ImageName=#BGImage#
W=#SpectrumW#
H=#SpectrumH#
X=0
Y=0
Hidden=(1 - #Reflection#)
UpdateDivider=-1

[Reflection]
Meter=Shape
Hidden=(1 - #Reflection#)
DynamicVariables=1

; Spectrum Band 1
Shape=Rectangle (#UnitStartX# * 0),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand0] * #Jump#)), #UnitWidth#, ([MeasureBand0] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 2
Shape2=Rectangle (#UnitStartX# * 1),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand1] * #Jump#)), #UnitWidth#, ([MeasureBand1] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 3
Shape3=Rectangle (#UnitStartX# * 2),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand2] * #Jump#)), #UnitWidth#, ([MeasureBand2] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 4
Shape4=Rectangle (#UnitStartX# * 3),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand3] * #Jump#)), #UnitWidth#, ([MeasureBand3] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 5
Shape5=Rectangle (#UnitStartX# * 4),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand4] * #Jump#)), #UnitWidth#, ([MeasureBand4] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 6
Shape6=Rectangle (#UnitStartX# * 5),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand5] * #Jump#)), #UnitWidth#, ([MeasureBand5] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 7
Shape7=Rectangle (#UnitStartX# * 6),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand6] * #Jump#)), #UnitWidth#, ([MeasureBand6] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 8
Shape8=Rectangle (#UnitStartX# * 7),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand7] * #Jump#)), #UnitWidth#, ([MeasureBand7] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 9
Shape9=Rectangle (#UnitStartX# * 8),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand8] * #Jump#)), #UnitWidth#, ([MeasureBand8] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 10
Shape10=Rectangle (#UnitStartX# * 9),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand9] * #Jump#)), #UnitWidth#, ([MeasureBand9] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 11
Shape11=Rectangle (#UnitStartX# * 10),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand10] * #Jump#)), #UnitWidth#, ([MeasureBand10] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 12
Shape12=Rectangle (#UnitStartX# * 11),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand11] * #Jump#)), #UnitWidth#, ([MeasureBand11] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 13
Shape13=Rectangle (#UnitStartX# * 12),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand12] * #Jump#)), #UnitWidth#, ([MeasureBand12] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 14
Shape14=Rectangle (#UnitStartX# * 13),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand13] * #Jump#)), #UnitWidth#, ([MeasureBand13] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 15
Shape15=Rectangle (#UnitStartX# * 14),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand14] * #Jump#)), #UnitWidth#, ([MeasureBand14] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 16
Shape16=Rectangle (#UnitStartX# * 15),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand15] * #Jump#)), #UnitWidth#, ([MeasureBand15] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 17
Shape17=Rectangle (#UnitStartX# * 16),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand16] * #Jump#)), #UnitWidth#, ([MeasureBand16] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 18
Shape18=Rectangle (#UnitStartX# * 17),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand17] * #Jump#)), #UnitWidth#, ([MeasureBand17] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 19
Shape19=Rectangle (#UnitStartX# * 18),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand18] * #Jump#)), #UnitWidth#, ([MeasureBand18] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 20
Shape20=Rectangle (#UnitStartX# * 19),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand19] * #Jump#)), #UnitWidth#, ([MeasureBand19] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 21
Shape21=Rectangle (#UnitStartX# * 20),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand20] * #Jump#)), #UnitWidth#, ([MeasureBand20] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 22
Shape22=Rectangle (#UnitStartX# * 21),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand21] * #Jump#)), #UnitWidth#, ([MeasureBand21] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 23
Shape23=Rectangle (#UnitStartX# * 22),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand22] * #Jump#)), #UnitWidth#, ([MeasureBand22] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 24
Shape24=Rectangle (#UnitStartX# * 23),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand23] * #Jump#)), #UnitWidth#, ([MeasureBand23] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 25
Shape25=Rectangle (#UnitStartX# * 24),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand24] * #Jump#)), #UnitWidth#, ([MeasureBand24] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

; Spectrum Band 26
Shape26=Rectangle (#UnitStartX# * 25),  ((#UnitHeight# * #ScaleVis#) + ([MeasureBand25] * #Jump#)), #UnitWidth#, ([MeasureBand25] * #Gain#), #UnitRounding# | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient

ReflectionModifiers=StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#,#Alpha#
ReflectionGradient=270 | #BarColor#,#Alpha# ; #ReflectionStart# | #BarColor#,0 ; #ReflectionEnd#
;ReflectionGradient=270 | 0,255,0,#Alpha# ; #ReflectionStart# | 255,255,0,#Alpha# ; #ReflectionMid# | 255,0,0,1 ; #ReflectionEnd#
