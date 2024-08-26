[Variables]
@includeVariables=#@#VariablesVisualizer.inc
@includeCalcs=#@#Visualizer\CalcBands.inc
@includeMeasures=#@#Visualizer\MeasureBands.inc

[MeterWave]
Meter=Image
ImageName=wave-AUTO.bmp
x=0
y=350
H=#BarHeight#
W=((#BarWidth# + #BarSpacingX#) * #Bands# - #BarSpacingX#)
DynamicVariables=1