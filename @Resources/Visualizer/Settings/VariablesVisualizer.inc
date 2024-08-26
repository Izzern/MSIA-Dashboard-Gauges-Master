[Variables]
@includeVariablesUser=#@#Visualizer\Settings\VariablesUser.inc

;=================================================================
;---------------------------- System -----------------------------
;=================================================================
Alpha=((#AlphaUser# / 100) * 255)

Attack=5

;BarColor=50,0,255
BarSpacingY=5
BarWidth=12
BinWidth=15
BlurRadius=2

CascadesCount=1
Channel=Auto

Decay=100

MaxHeight=(#BarHeight# * 0.4)
MinHeight=0.01

OverlapBoost=6

PercentTop=100

MaxSensitivity=60
MinSensitivity=1
StrokeColor=255,255,255
StrokeWidth=0

Threshold=0.01

WindowFunction=Hann

;=================================================================
;----------------------------- Calcs -----------------------------
;=================================================================
Gain=((40 * #GainUser#) * #ScaleVis#)

Jump=((#BarSpacingY# * 2))

ReflectionStart=(0.4 * (#PercentBottom# / 100))
ReflectionMid=(0.8 * (#PercentBottom# / 100))
ReflectionEnd=(#PercentBottom# / 100)

SpectrumH=(((#BarHeight# * 2) + #BarSpacingY#) * #ScaleVis#)
SpectrumW=(((#BarWidth# + #BarSpacingX#) * #Bands#) * #ScaleVis#)

SpectrumStart=(0.45 * (#PercentTop# / 100))
SpectrumMid=(0.85 * (#PercentTop# / 100))
SpectrumEnd=(#PercentTop# / 100)

SpectrogramW=((((#BarWidth# + #BarSpacingX#) * #Bands#) - #BarSpacingX#) * #ScaleVis#)

UnitWidth=(#BarWidth# * #ScaleVis#)
UnitHeight=((#BarHeight# + #BarSpacingY#) * #ScaleVis#)
UnitRounding=((#BarWidth# / 2) * #ScaleVis#)
UnitStartX=((#BarWidth# + #BarSpacingX#) * #ScaleVis#)
UnitStartY=((#BarHeight# + #BarSpacingY# + #Jump#) * #ScaleVis#)

Visibility=((#BarWidth# + 1) * #ScaleVis#)
