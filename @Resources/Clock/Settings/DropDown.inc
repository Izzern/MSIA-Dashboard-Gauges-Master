[MeterSunPath]
Meter=Shape
Container=Clip
Group=DropDown
X=(#scale#*5)
Y=(#scale#*90)
Shape=Arc (#scale#*11.25),0,(#scale#*200),0,(#scale#*100),(#scale#*100) | Extend MyModifiers1
MyModifiers1=StrokeWidth 2 | Stroke Color 185,185,185,170
UpdateDivider=-1
Hidden=1

[MeterMoon]
Meter=Shape
Container=Clip
Group=DropDown
X=(#scale#*5)
Y=(#scale#*107)
Shape=Ellipse ((#scale#*11.5)+(#scale#*200)*[MeasureSinceMoonrise]), ((#scale#*40)*(Abs([MeasureSinceMoonrise]-0.5))+(#scale#*12.5)*(1-Abs(2*[MeasureSinceMoonrise]-1.2))-(#scale#*100)*Sin(Acos(2*[MeasureSinceMoonrise]-1))), (#scale#*12.5) | StrokeWidth (#scale#*3) | Stroke Color 255,255,255,50 | Fill RadialGradient MyGradient1
MyGradient1=3,2 | 192,192,192 ; 0.0 | 60,60,60 ; 1.0
DynamicVariables=1
Hidden=1

[MeterSun]
Meter=Shape
Container=Clip
Group=DropDown
X=(#scale#*5)
Y=(#scale#*112)
Shape=Ellipse ((#scale#*11.5)+(#scale#*200)*[MeasureSinceSunrise]),((#scale#*60)*(Abs([MeasureSinceSunrise]-0.5))+(#scale#*12.5)*(1-Abs(2*[MeasureSinceSunrise]-1.2))-(#scale#*100)*Sin(Acos(2*[MeasureSinceSunrise]-1))),(#scale#*12) | StrokeWidth (#scale#*1) | Stroke Color 255,120,0 | Fill RadialGradient MyGradient1
MyGradient1=3,2 | 255,140,0 ; 0.0 | 255,215,0 ; 1.0
DynamicVariables=1
Hidden=1

[MeterIcon]
MeasureName=MeasureIcon
Meter=IMAGE
ImagePath=#@#Clock\Icon\Weather
Group=DropDown
X=(#scale#*2)
Y=(#scale#*0)r
W=(#scale#*45)
H=(#scale#*45)
ToolTipTitle=[MeasureCity] [MeasureAdminDistrictCode], [MeasureCountry]
ToolTipType=1
ToolTipWidth=250
ToolTipText="[MeasureUpdate#TimeFormat#] [MeasureUpdateTimeZoneAbbrev]#CRLF##CRLF#[MeasureFeelsLikeLabels] [MeasureFeelsLike][\x00B0]#CRLF#[MeasureWindLabels] [MeasureWindDirection] [MeasureWindSpeed] [Measure#SpeedUnit#]#CRLF#[MeasureHumidityLabels] [MeasureHumidity]%#CRLF#[MeasurePressureLabels] [MeasurePressure] [Measure#PressureUnit#]#CRLF#[MeasureVisibilityLabels] [MeasureVisibility:2] [Measure#VisibilityUnit#]#CRLF##CRLF# [\x263C][\x2191]  [MeasureSunrise#TimeFormat#]     [\x263C][\x2193]  [MeasureSunset#TimeFormat#]#CRLF# [\x263E] [\x2191]  [MeasureMoonrise#TimeFormat#]      [\x263E] [\x2193]  [MeasureMoonset#TimeFormat#]"
DynamicVariables=1
Hidden=1

[MeterConditions]
Meter=String
MeterStyle=stringstyle3
Group=DropDown
ClipString=1
MeasureName=MeasureCondition
X=(#scale#*50)
Y=(#scale#*12)r
W=(#scale#*145)
H=(#scale#*20)
Text="%1"
Hidden=1

[MeterTEMPHi]
Meter=String
MeterStyle=stringstyle6
MeasureName=MeasureTempMaxForecast
Group=DropDown
X=(#scale#*222)
Y=([MeterConditions:X] - (#scale#*-14))
W=(#scale#*45)
H=(#scale#*20)
Text="[\x2191]%1[\x00B0]"
Hidden=1

[MeterTEMP]
Meter=String
MeterStyle=stringstyle4
MeasureName=MeasureTemperature
Group=DropDown
X=(#scale#*51)
Y=(#scale#*25)r
W=(#scale#*35)
H=(#scale#*50)
Text="%1[\x00B0]"
Hidden=1

[drop]
Meter=IMAGE
ImageName=#@#Clock\Icon\Weather\drop.png
grayscale=1
ImageTint=120,170,255,255
Group=DropDown
X=(#scale#*30)r
Y=(#scale#*-7)r
W=(#scale#*18)
H=(#scale#*16)
Hidden=1

[MeterPP]
Meter=String
MeterStyle=stringstyle5
MeasureName=MeasureDailyPrecipDay1
FontColor=120,170,255,200
FontEffectColor=30,0,75,255
Group=DropDown
X=(#scale#*17)r
Y=(#scale#*-1)r
W=(#scale#*50)
H=(#scale#*20)
Text="%1%"
Hidden=1

[Humidity]
Meter=IMAGE
ImageName=#@#Clock\Icon\Weather\humidity.png
ImageTint=180,200,0,200
Group=DropDown
X=(#scale#*35)r
Y=(#scale#*1)r
W=(#scale#*14)
H=(#scale#*17)
Hidden=1

[MeterHumidity]
Meter=String
MeterStyle=stringstyle5
MeasureName=MeasureHumidity
FontColor=180,200,0,200
Group=DropDown
X=(#scale#*17)r
Y=(#scale#*-1)r
W=(#scale#*55)
H=(#scale#*20)
Text="%1%"
Hidden=1

[MeterTEMPLo]
Meter=String
MeterStyle=stringstyle7
MeasureName=MeasureTempMin1
Group=DropDown
X=(#scale#*222)
Y=(#scale#*0)r
W=(#scale#*45)
H=(#scale#*20)
Text="[\x2193]%1[\x00B0]"
Hidden=1

[ForecastIcon1]
MeasureName=MeasureDailyIconDay2
Meter=IMAGE
ImagePath=#@#Clock\Icon\Weather
Group=DropDown
X=(#scale#*10)
Y=(#scale#*97)
;W=(#scale#*45)
H=(#scale#*50)
ToolTipText="[MeasureDailyCondDay2]"
DynamicVariables=1
Hidden=1

[ForecastTempHi1]
Meter=String
MeterStyle=stringstyle6
StringAlign=CENTERCENTER
Group=DropDown
MeasureName=MeasureTempMax2
X=(#scale#*25)r
Y=(#scale#*60)r
W=(#scale#*72)
H=(#scale#*60)
Text="%1[\x00B0]"
Hidden=1

[ForecastTempLo1]
Meter=String
MeterStyle=stringstyle7
StringAlign=CENTERCENTER
Group=DropDown
MeasureName=MeasureTempMin2
X=(#scale#*0)r
Y=(#scale#*20)r
W=(#scale#*72)
H=(#scale#*60)
Text="%1[\x00B0]"
Hidden=1

[Forecast1]
Meter=String
Group=DropDown
MeterStyle=stringstyle3
StringAlign=CENTERCENTER
MeasureName=MeasureDay2
X=(#scale#*0)r
Y=(#scale#*30)r
W=(#scale#*81)
H=(#scale#*70)
Hidden=1
ClipString=1

[ForecastIcon2]
MeasureName=MeasureDailyIconDay2
Meter=IMAGE
ImagePath=#@#Clock\Icon\Weather
Group=DropDown
X=(#scale#*90)
Y=(#scale#*97)
;W=(#scale#*45)
H=(#scale#*50)
ToolTipText="[MeasureDailyCondDay2]"
DynamicVariables=1
Hidden=1

[ForecastTempHi2]
Meter=String
MeterStyle=stringstyle6
StringAlign=CENTERCENTER
Group=DropDown
MeasureName=MeasureTempMax3
X=(#scale#*25)r
Y=(#scale#*60)r
W=(#scale#*72)
H=(#scale#*60)
Text="%1[\x00B0]"
Hidden=1

[ForecastTempLo2]
Meter=String
MeterStyle=stringstyle7
StringAlign=CENTERCENTER
Group=DropDown
MeasureName=MeasureTempMin3
X=(#scale#*0)r
Y=(#scale#*20)r
W=(#scale#*72)
H=(#scale#*60)
Text="%1[\x00B0]"
Hidden=1

[Forecast2]
Meter=String
Group=DropDown
MeterStyle=stringstyle3
StringAlign=CENTERCENTER
MeasureName=MeasureDay3
X=(#scale#*0)r
Y=(#scale#*30)r
W=(#scale#*81)
H=(#scale#*70)
Hidden=1
ClipString=1

[ForecastIcon3]
MeasureName=MeasureDailyIconDay2
Meter=IMAGE
ImagePath=#@#Clock\Icon\Weather
Group=DropDown
X=(#scale#*165)
Y=(#scale#*97)
;W=(#scale#*45)
H=(#scale#*50)
ToolTipText="[MeasureDailyCondDay2]"
DynamicVariables=1
Hidden=1

[ForecastTempHi3]
Meter=String
MeterStyle=stringstyle6
StringAlign=CENTERCENTER
Group=DropDown
MeasureName=MeasureTempMax4
X=(#scale#*25)r
Y=(#scale#*60)r
W=(#scale#*72)
H=(#scale#*60)
Text="%1[\x00B0]"
Hidden=1

[ForecastTempLo3]
Meter=String
MeterStyle=stringstyle7
StringAlign=CENTERCENTER
Group=DropDown
MeasureName=MeasureTempMin4
X=(#scale#*0)r
Y=(#scale#*20)r
W=(#scale#*72)
H=(#scale#*60)
Text="%1[\x00B0]"
Hidden=1

[Forecast3]
Meter=String
Group=DropDown
MeterStyle=stringstyle3
StringAlign=CENTERCENTER
MeasureName=MeasureDay4
X=(#scale#*0)r
Y=(#scale#*30)r
W=(#scale#*81)
H=(#scale#*70)
Hidden=1
ClipString=1