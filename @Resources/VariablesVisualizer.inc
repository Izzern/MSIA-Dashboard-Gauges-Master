[Variables]
Scale=1.0
;Change to "ReflectionAlpha"
AlphaUser=0.5
Alpha=(#AlphaUser# * 255)
Type=Spectrum

;AnalyzerPort=DefaultOutput
Attack=10
;AudioDevice=#AudioDevice#

Bands=26
BarColor=255,0,0
;BarsGab=0.2
BarHeight=120
BarSpacingX=2
BarSpacingY=5
BarWidth=12
BinWidth=15
BlurRadius=2

CascadesCount=1
Channel=Auto

Decay=250

;FFTAttack=10
;FFTDecay=250
;FFTSize=4096

FreqMin=300
FreqMax=12000

GainUser=5
Gain=((40 * #GainUser#) * #Scale#)

Jump=((#BarSpacingY# * 2))

MaxHeight=100
MinHeight=10

OverlapBoost=6

;PeakAttack=15
;PeakDecay=250
PercentBottom=80
PercentTop=100

Reflection=1
ReflectionStart=(0.4 * (#PercentBottom# / 100))
ReflectionMid=(0.8 * (#PercentBottom# / 100))
ReflectionEnd=(#PercentBottom# / 100)

SpectrumStart=(0.45 * (#PercentTop# / 100))
SpectrumMid=(0.85 * (#PercentTop# / 100))
SpectrumEnd=(#PercentTop# / 100)

SpectrogramLength=((((#BarWidth# + #BarSpacingX#) * #Bands#) - #BarSpacingX#) * #Scale#)

;RMSAttack=15
;RMSDecay=500
;RMSGain=120.0

MaxSensitivity=60
MinSensitivity=1
;LowSensitivity=10
;HighSensitivity=50

;Sensitivity=51
BGSpectrum=#@#Visualizer\Images\radio-volume-gradient.png
StrokeColor=#fff
StrokeWidth=0

Threshold=0.01

UnitWidth=(#BarWidth# * #Scale#)
UnitHeight=((#BarHeight# + #BarSpacingY#) * #Scale#)
UnitRounding=((#BarWidth# / 2) * #Scale#)
UnitStartX=((#BarWidth# + #BarSpacingX#) * #Scale#)
UnitStartY=((#BarHeight# + #BarSpacingY# + #Jump#) * #Scale#)

Visibility=((#BarWidth# + 1) * #Scale#)

WindowFunction=Hann