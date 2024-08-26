[Variables]
@IncludeVars=#@#Clock\Settings\VariablesClock.inc

[MeasureAmPm]
Measure=Time
Format=#AMPMCompact#

[MeasureDate]
Measure=Time
Format=#DateCompact#

[MeasureTime]
Measure=Time
Format=#TimeCompact#

[MeasureBlink]
Measure=Calc
Formula=Counter % 4 = 2 ? 200 : 0

[MeasureSeconds]
Measure=Time
Format=#SecondCompact#

[MeasureTimeAnalog]
Measure=Time

[MeasureDateAnalog]
Measure=Time
Format=%d

[MeasureDayAnalog]
Measure=Time
Format=%a

[MeasureSecond]
Measure=Time
Format=%#S
OnChangeAction=[!CommandMeasure MeasureBounce "Reset"]

[MeasureSecondAngle]
Measure=Calc
Formula=(MeasureSecond * 6)

[MeasureMinute]
Measure=Time
Format=%#M

[MeasureMinuteAngle]
Measure=Calc
Formula=(MeasureMinute * 6) + (MeasureSecond / 60 * 6)

[MeasureHour]
Measure=Time
Format=%#I

[MeasureHourAngle]
Measure=Calc
Formula=(MeasureHour * 30) + (MeasureMinute / 60 * 30) + (MeasureSecond / 3600 * 30)

[Measure24Hour]
Measure=Time
Format=%R

[Measure24HourAngle]
Measure=Calc
Formula=(Measure24Hour * 15) + (MeasureMinute / 60 * 15)

[MeasureBounce]
Measure=Loop
StartValue=0
EndValue=2
Increment=2
InvertMeasure=1
LoopCount=1

[MeasureRotate]
Measure=Calc
Formula=(Measure24HourAngle % 360) + 1
MaxValue=360
MinValue=0