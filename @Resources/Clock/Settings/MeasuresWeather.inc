
; © 2021 by xxenium

;Weather.com API

[Variables]
@includeVariablesWeather=#@#Clock\Settings\VariablesWeather.inc
@includeRegExp=#@#Clock\Settings\RegExp.inc
;DropDownVisibility=0


[WEATHER.COMSuperParent]
Measure=WebParser
URL=#URL#
UpdateRate=600
UserAgent=Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:81.0) Gecko/20100101 Firefox/81.0
Flags=Resync | NoCookies
DecodeCharacterReference=1
LogSubstringErrors=0
RegExp=(?siU)^(.*)$
StringIndex=1
FinishAction=[!EnableMeasureGroup Parents]

;[MeasureDDVisibility]
;Measure=CALC
;Formula=(#DropDownVisibility#)
;DynamicVariables=1
;OnChangeAction=[!UpdateMeasure MeasureTimeSUN]

; ========================================
;                 LOCATION
; ========================================

[MeasureLocation]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#Location#
LogSubstringErrors=0

[MeasureAdminDistrictCode]
Measure=WebParser
Url=[MeasureLocation]
StringIndex=4
Substitute="null":"",'"':""
DecodeCodePoints=1

[MeasureCountry]
Measure=WebParser
Url=[MeasureLocation]
StringIndex=5
Substitute="null":"",'"':""
DecodeCodePoints=1

[MeasureCity]
Measure=WebParser
Url=[MeasureLocation]
StringIndex=7
Substitute="null":"",'"':""
DecodeCodePoints=1

; ========================================
;             CURRENT WEATHER
; ========================================

[MeasureCurrentObservations]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#CurrentObservations#
LogSubstringErrors=0
FinishAction=[!EnableMeasureGroup CurrentTime]

[MeasureIcon]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=1

[MeasurePressure]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=2

[MeasureHumidity]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=5

[MeasureTemperature]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=6

[MeasureFeelsLike]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=8

[MeasureUpdate]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=11
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureUpdateTimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureUpdate]
TimeStampFormat=%H:%M
Format=%#I:%M %p
Substitute="AM":"am","PM":"pm"
Group=CurrentTime
Disabled=1

[MeasureSeconds]
Measure=Time
Format=%S

[MeasureVisibility]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=12

[MeasureWindDirectionAngle]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=13

[MeasureWindDirection]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=14

[MeasureWindSpeed]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=16
Substitute="\u002F":"/"

[MeasureCondition]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=17
Substitute="\u002F":"/"

[MeasureUpdateTimeZoneAbbrev]
Measure=WebParser
URL=https://api.weather.com/v3/dateTime?geocode=#Latitude#,#Longitude#&format=json&apiKey=#APIKey#
RegExp=(?siU)"timeZoneAbbreviation":"(.*)"
UpdateRate=600
Flags=Resync | NoCookies
UserAgent=Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:81.0) Gecko/20100101 Firefox/81.0
StringIndex=1

; ========================================
;              5-DAY FORECAST
; ========================================

;============= MOON ==================
[MeasureMoon]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastMOON#
LogSubstringErrors=0
FinishAction=[!EnableMeasureGroup MoonTime]

[MeasureMoonPhase]
Measure=WebParser
Url=[MeasureMoon]
StringIndex=1
DecodeCodePoints=1

[MeasureMoonPhaseCode]
Measure=WebParser
Url=[MeasureMoon]
StringIndex=2

[MeasureMoonrise]
Measure=WebParser
Url=[MeasureMoon]
StringIndex=3
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1","":"[MeasureMoonriseNext]"
DynamicVariables=1

[MeasureMoonriseNext]
Measure=WebParser
Url=[MeasureMoon]
StringIndex=4
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureMoonset]
Measure=WebParser
Url=[MeasureMoon]
StringIndex=5
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1","":"[MeasureMoonsetNext]"
DynamicVariables=1

[MeasureMoonsetNext]
Measure=WebParser
Url=[MeasureMoon]
StringIndex=6
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureMoonriseTimeFormat12H]
Measure=Time
TimeStamp=[MeasureMoonrise]
TimeStampFormat=%H:%M
Format=%#I:%M %p
Substitute="AM":"am","PM":"pm"
DynamicVariables=1
Group=MoonTime
Disabled=1

[MeasureMoonsetTimeFormat12H]
Measure=Time
TimeStamp=[MeasureMoonset]
TimeStampFormat=%H:%M
Format=%#I:%M %p
Substitute="AM":"am","PM":"pm"
DynamicVariables=1
Group=MoonTime
Disabled=1

;============= SUN ==================
[MeasureSun]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastSUN#
LogSubstringErrors=0
FinishAction=[!EnableMeasureGroup SunTime]

[MeasureSunrise]
Measure=WebParser
Url=[MeasureSun]
StringIndex=1
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1","":"[MeasureSunriseNext]"
DynamicVariables=1

[MeasureSunriseNext]
Measure=WebParser
Url=[MeasureSun]
StringIndex=2
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureSunset]
Measure=WebParser
Url=[MeasureSun]
StringIndex=3
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1","":"[MeasureSunsetNext]"
DynamicVariables=1

[MeasureSunsetNext]
Measure=WebParser
Url=[MeasureSun]
StringIndex=4
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureSunriseTimeFormat12H]
Measure=Time
TimeStamp=[MeasureSunrise]
TimeStampFormat=%H:%M
Format=%#I:%M %p
Substitute="AM":"am","PM":"pm"
DynamicVariables=1
Group=SunTime
Disabled=1

[MeasureSunsetTimeFormat12H]
Measure=Time
TimeStamp=[MeasureSunset]
TimeStampFormat=%H:%M
Format=%#I:%M %p
Substitute="AM":"am","PM":"pm"
DynamicVariables=1
Group=SunTime
Disabled=1

;============= TEMP MAX ==============
[MeasureDailyForecastTempMax]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastTempMax#
LogSubstringErrors=0

[MeasureTempMaxForecast]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=1
Substitute="[":""
IfMatch=null
IfMatchAction=[!SetOption MeterTEMPHi Text "--- °"]

[MeasureTempMax1]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=1
Substitute="[":""
IfMatch=null
IfMatchAction=[!SetOption MeterFT1 Text "--- °/%2"]
IfNotMatchAction=[!SetOption MeterFT1 Text "%1°/%2"]

[MeasureTempMax1Vert]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=1
Substitute="[":""
IfMatch=null
IfMatchAction=[!SetOption MeterFT1Vert Text "---#CRLF#%2°"]
IfNotMatchAction=[!SetOption MeterFT1Vert Text "%1°#CRLF#%2°"]

[MeasureTempMax2]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=2

[MeasureTempMax3]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=3

[MeasureTempMax4]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=4

[MeasureTempMax5]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=5

;============== TEMP MIN ==============
[MeasureDailyForecastTempMin]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastTempMin#
LogSubstringErrors=0

[MeasureTempMin1]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=1
Substitute="[":""

[MeasureTempMin2]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=2

[MeasureTempMin3]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=3

[MeasureTempMin4]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=4

[MeasureTempMin5]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=5

;============= DAYS ==================
[MeasureDailyForecastDate]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastDate#
LogSubstringErrors=0
FinishAction=[!EnableMeasureGroup DaysTime]

[MeasureDate1]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=1
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay1]
Measure=Time
TimeStamp=[MeasureDate1]
TimeStampFormat=%Y-%m-%d
Format=#DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDate2]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=2
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay2]
Measure=Time
TimeStamp=[MeasureDate2]
TimeStampFormat=%Y-%m-%d
Format=%a#CRLF##DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDay2Horiz]
Measure=Time
TimeStamp=[MeasureDate2]
TimeStampFormat=%Y-%m-%d
Format=%a #DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDate3]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=3
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay3]
Measure=Time
TimeStamp=[MeasureDate3]
TimeStampFormat=%Y-%m-%d
Format=%a#CRLF##DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDay3Horiz]
Measure=Time
TimeStamp=[MeasureDate3]
TimeStampFormat=%Y-%m-%d
Format=%a #DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDate4]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=4
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay4]
Measure=Time
TimeStamp=[MeasureDate4]
TimeStampFormat=%Y-%m-%d
Format=%a#CRLF##DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDay4Horiz]
Measure=Time
TimeStamp=[MeasureDate4]
TimeStampFormat=%Y-%m-%d
Format=%a #DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDate5]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=5
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay5]
Measure=Time
TimeStamp=[MeasureDate5]
TimeStampFormat=%Y-%m-%d
Format=%a#CRLF##DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

[MeasureDay5Horiz]
Measure=Time
TimeStamp=[MeasureDate5]
TimeStampFormat=%Y-%m-%d
Format=%a #DateFormat#
FormatLocale=#Language#
DynamicVariables=1
Group=DaysTime
Disabled=1

;============= DAY PART ===============
[MeasureDailyForecastDayPart]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastDayPart#
LogSubstringErrors=0

[MeasureDayPartDay1]
Measure=WebParser
Url=[MeasureDailyForecastDayPart]
StringIndex=1
Substitute='"':"","[":"","null":"[MeasureDayPartNight1]","\":""
DynamicVariables=1
DecodeCodePoints=1

[MeasureDayPartNight1]
Measure=WebParser
Url=[MeasureDailyForecastDayPart]
StringIndex=2
DecodeCodePoints=1

;========= DAILY ICON CODES ===========
[MeasureDailyForecastIcon]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastIconCode#
LogSubstringErrors=0

[MeasureDailyIconDay1]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=1
Substitute="[":"","null":"[MeasureDailyIconNight1]"
DynamicVariables=1

[MeasureDailyIconNight1]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=2

[MeasureDailyIconDay2]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=3

[MeasureDailyIconDay3]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=5

[MeasureDailyIconDay4]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=7

[MeasureDailyIconDay5]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=9

;========= DAILY DETAILS ==============
[MeasureDailyForecastDetails]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastDetails#
LogSubstringErrors=0

[MeasureDetailsDay1]
Measure=WebParser
Url=[MeasureDailyForecastDetails]
StringIndex=1
Substitute='"':"","\u002F":"/","[":"","\u00BAC":"°","\":"","null":"[MeasureDetailsNight1]"
DynamicVariables=1
DecodeCodePoints=1

[MeasureDetailsNight1]
Measure=WebParser
Url=[MeasureDailyForecastDetails]
StringIndex=2
Substitute="\u002F":"/","\u00BAC":"°"
DecodeCodePoints=1

;===== DAILY PRECIPITATION CHANCE ======
[MeasureDailyForecastPrecip]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastPrecip#
LogSubstringErrors=0

[MeasureDailyPrecipDay1]
Measure=WebParser
Url=[MeasureDailyForecastPrecip]
StringIndex=1
Substitute="[":"","null":"[MeasureDailyPrecipNight1]"
DynamicVariables=1

[MeasureDailyPrecipNight1]
Measure=WebParser
Url=[MeasureDailyForecastPrecip]
StringIndex=2

;========= DAILY CONDITIONS ===========

[MeasureDailyForecastCond]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastCondition#
LogSubstringErrors=0

[MeasureDailyCondDay1]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=1
Substitute='"':"","\u002F":"/","[":"","null":"[MeasureDailyCondNight1]","\":""
DynamicVariables=1
DecodeCodePoints=1

[MeasureDailyCondNight1]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=2
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureDailyCondDay2]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=3
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureDailyCondDay3]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=5
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureDailyCondDay4]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=7
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureDailyCondDay5]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=9
Substitute="\u002F":"/"
DecodeCodePoints=1

; ========================================
;             12-HOUR FORECAST
; ========================================

;=========== HOURLY ICON CODES ===========
[MeasureHourlyForecastIconCode]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#HourlyForecastIconCode#
LogSubstringErrors=0

[MeasureHourlyIcon1]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=1
Substitute="[":""

[MeasureHourlyIcon2]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=2

[MeasureHourlyIcon3]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=3

[MeasureHourlyIcon4]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=4

[MeasureHourlyIcon5]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=5

[MeasureHourlyIcon6]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=6

[MeasureHourlyIcon7]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=7

[MeasureHourlyIcon8]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=8

[MeasureHourlyIcon9]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=9

[MeasureHourlyIcon10]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=10

[MeasureHourlyIcon11]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=11

[MeasureHourlyIcon12]
Measure=WebParser
Url=[MeasureHourlyForecastIconCode]
StringIndex=12
Substitute="]":""

;============= HOURLY TEMP ================
[MeasureHourlyForecastTemp]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#HourlyForecastTemp#
LogSubstringErrors=0

[MeasureHourlyTemp1]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=1
Substitute="[":""

[MeasureHourlyTemp2]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=2

[MeasureHourlyTemp3]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=3

[MeasureHourlyTemp4]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=4

[MeasureHourlyTemp5]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=5
Group=HourlyTemp

[MeasureHourlyTemp6]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=6

[MeasureHourlyTemp7]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=7

[MeasureHourlyTemp8]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=8

[MeasureHourlyTemp9]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=9

[MeasureHourlyTemp10]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=10

[MeasureHourlyTemp11]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=11

[MeasureHourlyTemp12]
Measure=WebParser
Url=[MeasureHourlyForecastTemp]
StringIndex=12
Substitute="]":""

;=============== HOURS ===================
[MeasureHourlyForecastHour]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#HourlyForecastHour#
LogSubstringErrors=0
FinishAction=[!EnableMeasureGroup HoursTime]

[MeasureHourlyDate1]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=1
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour1]
Measure=Time
TimeStamp=[MeasureHourlyDate1]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour1TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate1]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate2]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=2
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour2]
Measure=Time
TimeStamp=[MeasureHourlyDate2]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour2TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate2]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate3]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=3
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour3]
Measure=Time
TimeStamp=[MeasureHourlyDate3]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour3TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate3]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate4]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=4
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour4]
Measure=Time
TimeStamp=[MeasureHourlyDate4]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour4TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate4]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate5]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=5
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour5]
Measure=Time
TimeStamp=[MeasureHourlyDate5]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour5TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate5]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate6]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=6
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour6]
Measure=Time
TimeStamp=[MeasureHourlyDate6]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour6TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate6]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate7]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=7
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour7]
Measure=Time
TimeStamp=[MeasureHourlyDate7]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour7TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate7]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate8]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=8
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour8]
Measure=Time
TimeStamp=[MeasureHourlyDate8]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour8TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate8]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate9]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=9
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour9]
Measure=Time
TimeStamp=[MeasureHourlyDate9]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour9TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate9]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate10]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=10
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour10]
Measure=Time
TimeStamp=[MeasureHourlyDate10]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour10TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate10]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate11]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=11
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour11]
Measure=Time
TimeStamp=[MeasureHourlyDate11]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour11TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate11]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

[MeasureHourlyDate12]
Measure=WebParser
Url=[MeasureHourlyForecastHour]
StringIndex=12
RegExpSubstitute=1
Substitute="^(.*)T(.*):.*$":"\1 \2"

[MeasureHour12]
Measure=Time
TimeStamp=[MeasureHourlyDate12]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#H:%M#CRLF#%a
FormatLocale=#Language#
DynamicVariables=1
Group=HoursTime
Disabled=1

[MeasureHour12TimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureHourlyDate12]
TimeStampFormat=%Y-%m-%d %H:%M
Format=%#I %p#CRLF#%a
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"
Group=HoursTime
Disabled=1

;=========== HOURLY CONDITIONS =============
[MeasureHourlyForecastCondition]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#HourlyForecastCondition#
LogSubstringErrors=0

[MeasureHourlyCond1]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=1
Substitute='"':"","[":"","\u002F":"/"

[MeasureHourlyCond2]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=2
Substitute="\u002F":"/"

[MeasureHourlyCond3]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=3
Substitute="\u002F":"/"

[MeasureHourlyCond4]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=4
Substitute="\u002F":"/"

[MeasureHourlyCond5]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=5
Substitute="\u002F":"/"

[MeasureHourlyCond6]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=6
Substitute="\u002F":"/"

[MeasureHourlyCond7]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=7
Substitute="\u002F":"/"

[MeasureHourlyCond8]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=8
Substitute="\u002F":"/"

[MeasureHourlyCond9]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=9
Substitute="\u002F":"/"

[MeasureHourlyCond10]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=10
Substitute="\u002F":"/"

[MeasureHourlyCond11]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=11
Substitute="\u002F":"/"

[MeasureHourlyCond12]
Measure=WebParser
Url=[MeasureHourlyForecastCondition]
StringIndex=12
Substitute="\u002F":"/"

; ========================================
;         WEATHER PARAMETERS LABELS
; ========================================
[MeasureFeelsLikeLabels]
Measure=String
String=#FeelsLike#

[MeasureWindLabels]
Measure=String
String=#Wind#

[MeasureHumidityLabels]
Measure=String
String=#Humidity#

[MeasurePressureLabels]
Measure=String
String=#Pressure#

[MeasureVisibilityLabels]
Measure=String
String=#Visibility#

; ========================================
;          WEATHER PARAMETERS UNITS
; ========================================
[MeasureMph]
Measure=String
String=#mph#

[MeasureKmh]
Measure=String
String=#km/h#

[MeasureIn]
Measure=String
String=#in#

[MeasureMb]
Measure=String
String=#mb#

[MeasureMile]
Measure=String
String=#mi#

[MeasureKm]
Measure=String
String=#km#

[];==================================
;------- MEASURES SUN CALC ----------
;====================================
[MeasureSunriseHour]
Measure=String
String=[MeasureSunrise]
RegExpSubstitute=1
Substitute="^(\d{1,2}):\d{1,2}$":"\1","^$":"0"
DynamicVariables=1

[MeasureSunriseMinute]
Measure=String
String=[MeasureSunrise]
RegExpSubstitute=1
Substitute="^\d{1,2}:(\d{1,2})$":"\1","^$":"0"
DynamicVariables=1

[MeasureSunriseMoment]
Measure=Calc
Formula=( 60 * [MeasureSunriseHour] + [MeasureSunriseMinute] )
DynamicVariables=1

[MeasureSunsetHour]
Measure=String
String=[MeasureSunset]
RegExpSubstitute=1
Substitute="^(\d{1,2}):\d{1,2}$":"\1","^$":"0"
DynamicVariables=1

[MeasureSunsetMinute]
Measure=String
String=[MeasureSunset]
RegExpSubstitute=1
Substitute="^\d{1,2}:(\d{1,2})$":"\1","^$":"0"
DynamicVariables=1

[MeasureSunsetMoment]
Measure=Calc
Formula=( 60 * [MeasureSunsetHour] + [MeasureSunsetMinute] )
DynamicVariables=1

[MeasureHour]
Measure=Time
Format=%#H

[MeasureMinute]
Measure=Time
Format=%M

[MeasureDayLengthSUN]
Measure=Calc
Formula=( MeasureSunsetMoment - MeasureSunriseMoment )

[MeasureSinceSunrise]
Measure=Calc
Formula=(( 60 * MeasureHour + MeasureMinute - MeasureSunriseMoment ) / ( 0.00001 + MeasureDayLengthSUN ))

[MeasureTimeSUN]
Measure=Calc
Formula=( 60 * MeasureHour + MeasureMinute )
IfCondition=(((MeasureSunsetMoment>MeasureSunriseMoment)&&((#CURRENTSECTION#>=MeasureSunriseMoment)&&(#CURRENTSECTION#<MeasureSunsetMoment)))||((MeasureSunriseMoment>MeasureMoonsetMoment)&&((#CURRENTSECTION#>=MeasureSunriseMoment)||(#CURRENTSECTION#<MeasureSunsetMoment))))
;IfCondition=((MeasureDDVisibility = 1) && ([MeasureSinceSunrise] >= 0) || (((MeasureSunsetMoment>MeasureSunriseMoment)&&((#CURRENTSECTION#>=MeasureSunriseMoment)&&(#CURRENTSECTION#<MeasureSunsetMoment)))||((MeasureSunriseMoment>MeasureSunsetMoment)&&((#CURRENTSECTION#>=MeasureSunriseMoment)||(#CURRENTSECTION#<MeasureSunsetMoment)))))
IfTrueAction=[!ShowMeter "MeterSun"]
IfFalseAction=[!HideMeter "MeterSun"]

[];==================================
;------- MEASURES MOON CALC ---------
;====================================
[MeasureMoonriseHour]
Measure=String
String=[MeasureMoonrise]
RegExpSubstitute=1
Substitute="^(\d{1,2}):\d{1,2}$":"\1","^$":"0"
DynamicVariables=1

[MeasureMoonriseMinute]
Measure=String
String=[MeasureMoonrise]
RegExpSubstitute=1
Substitute="^\d{1,2}:(\d{1,2})$":"\1","^$":"0"
DynamicVariables=1

[MeasureMoonriseMoment]
Measure=Calc
Formula=( 60 * [MeasureMoonriseHour] + [MeasureMoonriseMinute] )
DynamicVariables=1

[MeasureMoonsetHour]
Measure=String
String=[MeasureMoonset]
RegExpSubstitute=1
Substitute="^(\d{1,2}):\d{1,2}$":"\1","^$":"0"
DynamicVariables=1

[MeasureMoonsetMinute]
Measure=String
String=[MeasureMoonset]
RegExpSubstitute=1
Substitute="^\d{1,2}:(\d{1,2})$":"\1","^$":"0"
DynamicVariables=1

[MeasureMoonsetMoment]
Measure=Calc
Formula=( 60 * [MeasureMoonsetHour] + [MeasureMoonsetMinute] )
DynamicVariables=1

[MeasureDayLengthMOON]
Measure=Calc
Formula=(( MeasureMoonsetMoment > MeasureMoonriseMoment ) ? ( MeasureMoonsetMoment - MeasureMoonriseMoment ) : ( 1440 - MeasureMoonriseMoment + MeasureMoonsetMoment ))

[MeasureSinceMoonrise]
Measure=Calc
Formula=(( MeasureMoonsetMoment > MeasureMoonriseMoment ) ? (( 60 * MeasureHour + MeasureMinute - MeasureMoonriseMoment ) / ( 0.00001 + MeasureDayLengthMOON )) : ((( 60 * MeasureHour + MeasureMinute ) >= MeasureMoonriseMoment ) ? (( 60 * MeasureHour + MeasureMinute - MeasureMoonriseMoment ) / ( 0.00001 + MeasureDayLengthMOON )) : (( 1440 - MeasureMoonriseMoment + 60 * MeasureHour + MeasureMinute ) / ( 0.00001 + MeasureDayLengthMOON ))))

[MeasureTimeMOON]
Measure=Calc
Formula=( 60 * MeasureHour + MeasureMinute )
;IfCondition=(((MeasureMoonsetMoment>MeasureMoonriseMoment)&&((#CURRENTSECTION#>=MeasureMoonriseMoment)&&(#CURRENTSECTION#<MeasureMoonsetMoment)))||((MeasureMoonriseMoment>MeasureMoonsetMoment)&&((#CURRENTSECTION#>=MeasureMoonriseMoment)||(#CURRENTSECTION#<MeasureMoonsetMoment))))

IfCondition=(MeasureSunsetMoment>MeasureSunriseMoment)

;IfCondition=([Group=DropDown] && [MeasureSinceMoonrise] >= 0) || (((MeasureMoonsetMoment>MeasureMoonriseMoment)&&((#CURRENTSECTION#>=MeasureMoonriseMoment)&&(#CURRENTSECTION#<MeasureMoonsetMoment)))||((MeasureMoonriseMoment>MeasureMoonsetMoment)&&((#CURRENTSECTION#>=MeasureMoonriseMoment)||(#CURRENTSECTION#<MeasureMoonsetMoment))))
IfTrueAction=[!ShowMeter "MeterMoon"]
IfFalseAction=[!HideMeter "MeterMoon"]

; © 2021 by xxenium