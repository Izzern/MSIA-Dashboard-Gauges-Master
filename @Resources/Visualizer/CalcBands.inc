[Variables]
@includeVariablesVisualizer=#@#VariablesVisualizer.inc

[CalcBand1]
Measure=Calc
Formula=MeasureBand1
IfCondition=(MeasureBand1 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand1 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand1 Formula "MeasureBand1"]

[CalcBand2]
Measure=Calc
Formula=((MeasureBand1 + MeasureBand2) / 2)
IfCondition=(MeasureBand1 = 0) && (MeasureBand2 = 0)
IfTrueAction=[!SetOption CalcBand2 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand2 Formula "((MeasureBand1 + MeasureBand2) / 2)"]
DynamicVariables=1

[CalcBand3]
Measure=Calc
Formula=MeasureBand2
IfCondition=(MeasureBand2 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand3 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand3 Formula "MeasureBand2"]

[CalcBand4]
Measure=Calc
Formula=((MeasureBand2 + MeasureBand3) / 2)
IfCondition=(MeasureBand2 = 0) && (MeasureBand3 = 0)
IfTrueAction=[!SetOption CalcBand4 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand4 Formula "((MeasureBand2 + MeasureBand3) / 2)"]
DynamicVariables=1

[CalcBand5]
Measure=Calc
Formula=MeasureBand3
IfCondition=(MeasureBand3 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand5 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand5 Formula "MeasureBand3"]

[CalcBand6]
Measure=Calc
Formula=((MeasureBand3 + MeasureBand4) / 2)
IfCondition=(MeasureBand3 = 0) && (MeasureBand4 = 0)
IfTrueAction=[!SetOption CalcBand6 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand6 Formula "((MeasureBand3 + MeasureBand4) / 2)"]
DynamicVariables=1

[CalcBand7]
Measure=Calc
Formula=MeasureBand4
IfCondition=(MeasureBand4 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand7 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand7 Formula "MeasureBand4"]

[CalcBand8]
Measure=Calc
Formula=((MeasureBand4 + MeasureBand5) / 2)
IfCondition=(MeasureBand4 = 0) && (MeasureBand5 = 0)
IfTrueAction=[!SetOption CalcBand8 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand8 Formula "((MeasureBand4 + MeasureBand5) / 2)"]
DynamicVariables=1

[CalcBand9]
Measure=Calc
Formula=MeasureBand5
IfCondition=(MeasureBand5 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand9 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand9 Formula "MeasureBand5"]

[CalcBand10]
Measure=Calc
Formula=((MeasureBand5 + MeasureBand6) / 2)
IfCondition=(MeasureBand5 = 0) && (MeasureBand6 = 0)
IfTrueAction=[!SetOption CalcBand10 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand10 Formula "((MeasureBand5 + MeasureBand6) / 2)"]
DynamicVariables=1

[CalcBand11]
Measure=Calc
Formula=MeasureBand6
IfCondition=(MeasureBand6 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand11 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand11 Formula "MeasureBand6"]

[CalcBand12]
Measure=Calc
Formula=((MeasureBand6 + MeasureBand7) / 2)
IfCondition=(MeasureBand6 = 0) && (MeasureBand7 = 0)
IfTrueAction=[!SetOption CalcBand12 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand12 Formula "((MeasureBand6 + MeasureBand7) / 2)"]
DynamicVariables=1

[CalcBand13]
Measure=Calc
Formula=MeasureBand7
IfCondition=(MeasureBand7 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand13 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand13 Formula "MeasureBand7"]

[CalcBand14]
Measure=Calc
Formula=((MeasureBand7 + MeasureBand8) / 2)
IfCondition=(MeasureBand7 = 0) && (MeasureBand8 = 0)
IfTrueAction=[!SetOption CalcBand14 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand14 Formula "((MeasureBand7 + MeasureBand8) / 2)"]
DynamicVariables=1

[CalcBand15]
Measure=Calc
Formula=MeasureBand8
IfCondition=(MeasureBand8 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand15 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand15 Formula "MeasureBand8"]

[CalcBand16]
Measure=Calc
Formula=((MeasureBand8 + MeasureBand9) / 2)
IfCondition=(MeasureBand8 = 0) && (MeasureBand9 = 0)
IfTrueAction=[!SetOption CalcBand16 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand16 Formula "((MeasureBand8 + MeasureBand9) / 2)"]
DynamicVariables=1

[CalcBand17]
Measure=Calc
Formula=MeasureBand9
IfCondition=(MeasureBand9 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand17 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand17 Formula "MeasureBand9"]

[CalcBand18]
Measure=Calc
Formula=((MeasureBand9 + MeasureBand10) / 2)
IfCondition=(MeasureBand9 = 0) && (MeasureBand10 = 0)
IfTrueAction=[!SetOption CalcBand18 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand18 Formula "((MeasureBand9 + MeasureBand10) / 2)"]
DynamicVariables=1

[CalcBand19]
Measure=Calc
Formula=MeasureBand10
IfCondition=(MeasureBand10 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand19 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand19 Formula "MeasureBand10"]

[CalcBand20]
Measure=Calc
Formula=((MeasureBand10 + MeasureBand11) / 2)
IfCondition=(MeasureBand10 = 0) && (MeasureBand11 = 0)
IfTrueAction=[!SetOption CalcBand20 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand20 Formula "((MeasureBand10 + MeasureBand11) / 2)"]
DynamicVariables=1

[CalcBand21]
Measure=Calc
Formula=MeasureBand11
IfCondition=(MeasureBand11 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand21 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand21 Formula "MeasureBand11"]

[CalcBand22]
Measure=Calc
Formula=((MeasureBand11 + MeasureBand12) / 2)
IfCondition=(MeasureBand11 = 0) && (MeasureBand12 = 0)
IfTrueAction=[!SetOption CalcBand22 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand22 Formula "((MeasureBand11 + MeasureBand12) / 2)"]
DynamicVariables=1

[CalcBand23]
Measure=Calc
Formula=MeasureBand12
IfCondition=(MeasureBand12 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand23 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand23 Formula "MeasureBand12"]

[CalcBand24]
Measure=Calc
Formula=((MeasureBand12 + MeasureBand13) / 2)
IfCondition=(MeasureBand12 = 0) && (MeasureBand13 = 0)
IfTrueAction=[!SetOption CalcBand24 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand24 Formula "((MeasureBand12 + MeasureBand13) / 2)"]
DynamicVariables=1

[CalcBand25]
Measure=Calc
Formula=MeasureBand13
IfCondition=(MeasureBand13 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand25 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand25 Formula "MeasureBand13"]

[CalcBand26]
Measure=Calc
Formula=((MeasureBand13 + MeasureBand14) / 2)
IfCondition=(MeasureBand13 = 0) && (MeasureBand14 = 0)
IfTrueAction=[!SetOption CalcBand26 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand26 Formula "((MeasureBand13 + MeasureBand14) / 2)"]
DynamicVariables=1

[CalcBand27]
Measure=Calc
Formula=MeasureBand14
IfCondition=(MeasureBand14 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand27 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand27 Formula "MeasureBand14"]

[CalcBand28]
Measure=Calc
Formula=((MeasureBand14 + MeasureBand15) / 2)
IfCondition=(MeasureBand14 = 0) && (MeasureBand15 = 0)
IfTrueAction=[!SetOption CalcBand28 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand28 Formula "((MeasureBand14 + MeasureBand15) / 2)"]
DynamicVariables=1

[CalcBand29]
Measure=Calc
Formula=MeasureBand15
IfCondition=(MeasureBand15 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand29 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand29 Formula "MeasureBand15"]

[CalcBand30]
Measure=Calc
Formula=((MeasureBand15 + MeasureBand16) / 2)
IfCondition=(MeasureBand15 = 0) && (MeasureBand16 = 0)
IfTrueAction=[!SetOption CalcBand30 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand30 Formula "((MeasureBand15 + MeasureBand16) / 2)"]
DynamicVariables=1

[CalcBand31]
Measure=Calc
Formula=MeasureBand16
IfCondition=(MeasureBand16 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand31 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand31 Formula "MeasureBand16"]

[CalcBand32]
Measure=Calc
Formula=((MeasureBand16 + MeasureBand17) / 2)
IfCondition=(MeasureBand16 = 0) && (MeasureBand17 = 0)
IfTrueAction=[!SetOption CalcBand32 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand32 Formula "((MeasureBand16 + MeasureBand17) / 2)"]
DynamicVariables=1

[CalcBand33]
Measure=Calc
Formula=MeasureBand17
IfCondition=(MeasureBand17 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand33 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand33 Formula "MeasureBand17"]

[CalcBand34]
Measure=Calc
Formula=((MeasureBand17 + MeasureBand18) / 2)
IfCondition=(MeasureBand17 = 0) && (MeasureBand18 = 0)
IfTrueAction=[!SetOption CalcBand34 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand34 Formula "((MeasureBand17 + MeasureBand18) / 2)"]
DynamicVariables=1

[CalcBand35]
Measure=Calc
Formula=MeasureBand18
IfCondition=(MeasureBand18 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand35 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand35 Formula "MeasureBand18"]

[CalcBand36]
Measure=Calc
Formula=((MeasureBand18 + MeasureBand19) / 2)
IfCondition=(MeasureBand18 = 0) && (MeasureBand19 = 0)
IfTrueAction=[!SetOption CalcBand36 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand36 Formula "((MeasureBand18 + MeasureBand19) / 2)"]
DynamicVariables=1

[CalcBand37]
Measure=Calc
Formula=MeasureBand19
IfCondition=(MeasureBand19 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand37 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand37 Formula "MeasureBand19"]

[CalcBand38]
Measure=Calc
Formula=((MeasureBand19 + MeasureBand20) / 2)
IfCondition=(MeasureBand19 = 0) && (MeasureBand20 = 0)
IfTrueAction=[!SetOption CalcBand38 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand38 Formula "((MeasureBand19 + MeasureBand20) / 2)"]
DynamicVariables=1

[CalcBand39]
Measure=Calc
Formula=MeasureBand20
IfCondition=(MeasureBand20 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand39 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand39 Formula "MeasureBand20"]

[CalcBand40]
Measure=Calc
Formula=((MeasureBand20 + MeasureBand21) / 2)
IfCondition=(MeasureBand20 = 0) && (MeasureBand21 = 0)
IfTrueAction=[!SetOption CalcBand40 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand40 Formula "((MeasureBand20 + MeasureBand21) / 2)"]
DynamicVariables=1

[CalcBand41]
Measure=Calc
Formula=MeasureBand21
IfCondition=(MeasureBand21 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand41 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand41 Formula "MeasureBand21"]

[CalcBand42]
Measure=Calc
Formula=((MeasureBand21 + MeasureBand22) / 2)
IfCondition=(MeasureBand21 = 0) && (MeasureBand22 = 0)
IfTrueAction=[!SetOption CalcBand42 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand42 Formula "((MeasureBand21 + MeasureBand22) / 2)"]
DynamicVariables=1

[CalcBand43]
Measure=Calc
Formula=MeasureBand22
IfCondition=(MeasureBand22 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand43 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand43 Formula "MeasureBand22"]

[CalcBand44]
Measure=Calc
Formula=((MeasureBand22 + MeasureBand23) / 2)
IfCondition=(MeasureBand22 = 0) && (MeasureBand23 = 0)
IfTrueAction=[!SetOption CalcBand44 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand44 Formula "((MeasureBand22 + MeasureBand23) / 2)"]
DynamicVariables=1

[CalcBand45]
Measure=Calc
Formula=MeasureBand23
IfCondition=(MeasureBand23 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand45 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand45 Formula "MeasureBand23"]

[CalcBand46]
Measure=Calc
Formula=((MeasureBand23 + MeasureBand24) / 2)
IfCondition=(MeasureBand23 = 0) && (MeasureBand24 = 0)
IfTrueAction=[!SetOption CalcBand46 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand46 Formula "((MeasureBand23 + MeasureBand24) / 2)"]
DynamicVariables=1

[CalcBand47]
Measure=Calc
Formula=MeasureBand24
IfCondition=(MeasureBand24 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand47 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand47 Formula "MeasureBand24"]

[CalcBand48]
Measure=Calc
Formula=((MeasureBand24 + MeasureBand25) / 2)
IfCondition=(MeasureBand24 = 0) && (MeasureBand25 = 0)
IfTrueAction=[!SetOption CalcBand48 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand48 Formula "((MeasureBand24 + MeasureBand25) / 2)"]
DynamicVariables=1

[CalcBand49]
Measure=Calc
Formula=MeasureBand25
IfCondition=(MeasureBand25 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand49 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand49 Formula "MeasureBand25"]

[CalcBand50]
Measure=Calc
Formula=((MeasureBand25 + MeasureBand26) / 2)
IfCondition=(MeasureBand25 = 0) && (MeasureBand26 = 0)
IfTrueAction=[!SetOption CalcBand50 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand50 Formula "((MeasureBand25 + MeasureBand26) / 2)"]
DynamicVariables=1

[CalcBand51]
Measure=Calc
Formula=MeasureBand26
IfCondition=(MeasureBand26 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand51 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand51 Formula "MeasureBand26"]

[CalcBand52]
Measure=Calc
Formula=((MeasureBand26 + MeasureBand27) / 2)
IfCondition=(MeasureBand26 = 0) && (MeasureBand27 = 0)
IfTrueAction=[!SetOption CalcBand52 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand52 Formula "((MeasureBand26 + MeasureBand27) / 2)"]
DynamicVariables=1

[CalcBand53]
Measure=Calc
Formula=MeasureBand27
IfCondition=(MeasureBand27 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand53 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand53 Formula "MeasureBand27"]

[CalcBand54]
Measure=Calc
Formula=((MeasureBand27 + MeasureBand28) / 2)
IfCondition=(MeasureBand27 = 0) && (MeasureBand28 = 0)
IfTrueAction=[!SetOption CalcBand54 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand54 Formula "((MeasureBand27 + MeasureBand28) / 2)"]
DynamicVariables=1

[CalcBand55]
Measure=Calc
Formula=MeasureBand28
IfCondition=(MeasureBand28 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand55 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand55 Formula "MeasureBand28"]

[CalcBand56]
Measure=Calc
Formula=((MeasureBand28 + MeasureBand29) / 2)
IfCondition=(MeasureBand28 = 0) && (MeasureBand29 = 0)
IfTrueAction=[!SetOption CalcBand56 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand56 Formula "((MeasureBand28 + MeasureBand29) / 2)"]
DynamicVariables=1

[CalcBand57]
Measure=Calc
Formula=MeasureBand29
IfCondition=(MeasureBand29 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand57 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand57 Formula "MeasureBand29"]

[CalcBand58]
Measure=Calc
Formula=((MeasureBand29 + MeasureBand30) / 2)
IfCondition=(MeasureBand29 = 0) && (MeasureBand30 = 0)
IfTrueAction=[!SetOption CalcBand58 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand58 Formula "((MeasureBand29 + MeasureBand30) / 2)"]
DynamicVariables=1

[CalcBand59]
Measure=Calc
Formula=MeasureBand30
IfCondition=(MeasureBand30 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand59 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand59 Formula "MeasureBand30"]

[CalcBand60]
Measure=Calc
Formula=((MeasureBand30 + MeasureBand31) / 2)
IfCondition=(MeasureBand30 = 0) && (MeasureBand31 = 0)
IfTrueAction=[!SetOption CalcBand60 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand60 Formula "((MeasureBand30 + MeasureBand31) / 2)"]
DynamicVariables=1

[CalcBand61]
Measure=Calc
Formula=MeasureBand31
IfCondition=(MeasureBand31 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand61 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand61 Formula "MeasureBand31"]

[CalcBand62]
Measure=Calc
Formula=((MeasureBand31 + MeasureBand32) / 2)
IfCondition=(MeasureBand31 = 0) && (MeasureBand32 = 0)
IfTrueAction=[!SetOption CalcBand62 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand62 Formula "((MeasureBand31 + MeasureBand32) / 2)"]
DynamicVariables=1

[CalcBand63]
Measure=Calc
Formula=MeasureBand32
IfCondition=(MeasureBand32 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand63 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand63 Formula "MeasureBand32"]

[CalcBand64]
Measure=Calc
Formula=MeasureBand32
IfCondition=(MeasureBand32 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand63 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand63 Formula "MeasureBand32"]
