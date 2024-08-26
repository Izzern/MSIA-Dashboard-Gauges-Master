[Variables]
@include=#@#VariablesVisualizer.inc
@include2=#@#Visualizer\MeasureBands.inc

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
Formula=MeasureBand4
IfCondition=(MeasureBand4 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand4 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand4 Formula "MeasureBand4"]

[CalcBand5]
Measure=Calc
Formula=MeasureBand5
IfCondition=(MeasureBand5 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand5 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand5 Formula "MeasureBand5"]

[CalcBand6]
Measure=Calc
Formula=MeasureBand5
IfCondition=(MeasureBand5 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand5 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand5 Formula "MeasureBand5"]

[CalcBand7]
Measure=Calc
Formula=MeasureBand6
IfCondition=(MeasureBand6 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand6 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand6 Formula "MeasureBand6"]

[CalcBand8]
Measure=Calc
Formula=MeasureBand7
IfCondition=(MeasureBand7 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand7 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand7 Formula "MeasureBand7"]

[CalcBand9]
Measure=Calc
Formula=MeasureBand8
IfCondition=(MeasureBand8 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand8 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand8 Formula "MeasureBand8"]

[CalcBand10]
Measure=Calc
Formula=MeasureBand9
IfCondition=(MeasureBand9 <= #Threshold#)
IfTrueAction=[!SetOption CalcBand9 Formula "(#Visibility# / #Gain#)"]
IfFalseAction=[!SetOption CalcBand9 Formula "MeasureBand9"]