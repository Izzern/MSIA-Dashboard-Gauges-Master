[Variables]
@includeVariables=#@#VariablesVisualizer.inc
@includeCalcs=#@#Visualizer\CalcBands.inc
@includeMeasures=#@#Visualizer\MeasureBands.inc

[MeterSpectrogram]
Meter=Image
ImageName=spectrogram-AUTO.bmp
x=0
y=200
H=#BarHeight#
W=((#BarWidth# + #BarSpacingX#) * #Bands# - #BarSpacingX#)
DynamicVariables=1