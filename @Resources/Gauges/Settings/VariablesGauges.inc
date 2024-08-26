;=================================================================
;------------ Gauges Calculated Variables Config File ------------
;=================================================================
;To customize or restore defaults click on any of the Izzern Gauge Icons (CPU, GPU, RAM, etc.).

[Variables]
;======================================
;---------- Position & Sizes ----------
;======================================
Spacing1=(1 * #ScaleGauge#)
Spacing-1=(-1 * #ScaleGauge#)
Spacing2=(2 * #ScaleGauge#)
Spacing-2=(-2 * #ScaleGauge#)

BGSize=(30 * #ScaleGauge#)
BGSizeHc=(60 * #ScaleGauge#)

IconWideH=(33 * #ScaleGauge#)
IconWideX=(13 * #ScaleGauge#)
IconWideY=(33 * #ScaleGauge#)

IconSquareH=(20 * #ScaleGauge#)
IconSquareX=#IconSquareH#
IconSquareY=(38 * #ScaleGauge#)
IconSquareHcX=(20 / 1.33 * #ScaleGauge#)
IconSquareHcY=(38 / 1.2 * #ScaleGauge#)

RoundLineOD=(60 * #ScaleGauge#)
RoundLineID=(58 * #ScaleGauge#)
BGRoundlineMeterStart=(Rad(151))
BGRoundlineMeterAngle=(Rad(237))
RoundlineMeterAngle=(Rad(239.5))
RoundlineEndBGStart=(#ScaleGauge#*22.4)
RoundlineEndBGLength=(#ScaleGauge#*28.4)
RoundlineEndBGWidth=(#ScaleGauge#*2.5)
RoundlineEndBGStartAngle=(Rad(153))
RoundlineEndBGRotationAngle=(Rad(233))

;RoundlineEndStart=(#ScaleGauge#*24.75)
;RoundlineEndLength=(#ScaleGauge#*27)
;RoundlineEndWidth=(#ScaleGauge#*1.5)
;RoundlineEndStartAngle=(Rad(152.25))
RoundlineEndRotationAngle=(Rad(232.5))

BGRoundlineMeterNetOutLength=(#ScaleGauge#*50)
BGRoundlineMeterNetOutStart=(Rad(154))
BGRoundlineMeterNetOutRotation=(Rad(232))
RoundlineMeterNetOutPosition=(#ScaleGauge#*8)
RoundlineMeterNetOutSize=(#ScaleGauge#*44)

EndPointAlpha=120