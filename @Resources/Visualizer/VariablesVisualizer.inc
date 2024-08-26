[Variables]

;=================================================================
;---------------------------- System -----------------------------
;=================================================================
Alpha=((#AlphaUser# / 100) * 255)

;AnalyzerPort=DefaultOutput
Attack=10
;AudioDevice=#AudioDevice#

BarColor=255,0,0
;BarsGab=0.2
BarSpacingY=5
BarWidth=12
BinWidth=15
BlurRadius=2

CascadesCount=1
Channel=Auto

Decay=250

Gain=((40 * #GainUser#) * #ScaleVis#)

Jump=((#BarSpacingY# * 2))

MaxHeight=100
MinHeight=10

OverlapBoost=6

MaxSensitivity=60
MinSensitivity=1

Threshold=0.01

WindowFunction=Hann

;----------------------------- Calc ------------------------------
UnitWidth=(#BarWidth# * #ScaleVis#)
UnitHeight=((#BarHeight# + #BarSpacingY#) * #ScaleVis#)
UnitRounding=((#BarWidth# / 2) * #ScaleVis#)
UnitStartX=((#BarWidth# + #BarSpacingX#) * #ScaleVis#)
UnitStartY=((#BarHeight# + #BarSpacingY# + #Jump#) * #ScaleVis#)
SpectrogramLength=((((#BarWidth# + #BarSpacingX#) * #Bands#) - #BarSpacingX#) * #ScaleVis#)

Visibility=((#BarWidth# + 1) * #ScaleVis#)

SpectrumW=(((#BarWidth# + #BarSpacingX#) * #Bands#) * #ScaleVis#)
SpectrumH=(((#BarHeight# * 2) + #BarSpacingY#) * #ScaleVis#)

;=================================================================
;---------------------------- Styles -----------------------------
;=================================================================
StrokeColor=#fff
StrokeWidth=0

;Spectrum Fade
PercentTop=100
SpectrumStart=(0.45 * (#PercentTop# / 100))
SpectrumMid=(0.85 * (#PercentTop# / 100))
SpectrumEnd=(#PercentTop# / 100)

;Reflection Fade
ReflectionStart=(0.4 * (#PercentBottom# / 100))
ReflectionMid=(0.8 * (#PercentBottom# / 100))
ReflectionEnd=(#PercentBottom# / 100)

