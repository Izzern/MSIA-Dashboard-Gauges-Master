[Metadata]
Name=ASTRO Weather
Author=xxenium (Forecast style variant by Izzern)
Information=Time, current weather conditions, current sun position, current moon position, dropdown forecast  
Version=TIME FORECAST
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0

; © 2020 by xxenium

[Variables]
@IncludeVarsClock=#@#Clock\Settings\VariablesClock.inc
@IncludeRegExp=#@#Clock\Settings\RegExp.inc
;@IncludeMeasuresWeather=#@#Clock\Settings\MeasuresWeather.inc
;@IncludeVarsWeather=#@#Clock\Settings\VariablesWeather.inc

[];===============================================================
;-------------------------- Containers ---------------------------
;=================================================================
[ContainerBG]
Meter=Shape
Shape=Rectangle 0,0,#ContainerBGW#,#ContainerBGH#,#CompactR# | Fill color #AnalogPrimaryColor#,255 | StrokeWidth #CompactStrokeW# | Stroke Color #AnalogSecondaryColor#,255
X=0
Y=0

[BG]
Meter=Shape
Container=ContainerBG
Shape=Rectangle 0,0,#CompactW#,#CompactH#,#CompactR# | Fill color #AnalogPrimaryColor#,#BGAlpha# | StrokeWidth #CompactStrokeW# | Stroke Color #AnalogSecondaryColor#,50
X=#BGOffset#
Y=#BGOffset#

[DropDownBox]
Meter=Shape
Group=DropDown
X=0
Y=0
Shape=Rectangle 0,0,#ContainerBGW#,#ContainerBGW#,#CompactR#,#CompactR# | Fill color #AnalogPrimaryColor#,#BGAlpha# | StrokeWidth #CompactStrokeW# | Stroke Color #AnalogSecondaryColor#,50
Hidden=1
DynamicVariables=1
MiddleMouseDownAction=[!ShowMeterGroup "DropDown"][!HideMeter "BG"][!SetOption DropDownBox Hidden "0"][!SetOption Clip Hidden "0"][!HideMeter "MeterIconBG"][!UpdateMeter "BG"][!UpdateMeter "DropDownBox"][!Redraw]
MouseLeaveAction=[!HideMeterGroup "DropDown"][!ShowMeter "BG"][!SetOption DropDownBox Hidden "1"][!SetOption Clip Hidden "1"][!ShowMeter "MeterIconBG"][!UpdateMeter "BG"][!UpdateMeter "DropDownBox"][!Redraw]

[Clip]
Meter=Shape
Group=DropDown
Shape=Rectangle 0,0,#ContainerBGW#,(100 * #Scale#),#CompactR#,#CompactR#
Hidden=1

[];==================================
;------------- METERS ---------------
;====================================
[MeterIconBG]
Meter=IMAGE
Container=ContainerBG
MeasureName=MeasureIcon
ImagePath=#@#Clock\Icon\Weather
ImageAlpha=100
W=#CompactH#
H=#CompactH#
X=((#CompactW# - [MeterIconBG:W]) / 2)
Y=((#CompactH# - [MeterIconBG:H]) / 2)
DynamicVariables=1
Hidden=0

LeftMouseUpAction=[!ToggleConfig "#ROOTCONFIG#\Settings" "Settings.ini"]
RightMouseUpAction=[!ShowMeterGroup "DropDown"][!HideMeter "BG"][!SetOption DropDownBox Hidden "0"][!SetOption Clip Hidden "0"][!HideMeter "MeterIconBG"][!UpdateMeter "BG"][!UpdateMeter "DropDownBox"][!UpdateMeter Clip][!Redraw]

[MeterHour]
Meter=STRING
MeterStyle=stringstyleTime
FontFace=TR LCD
FontSize=(28 * #Scale#)
InlineSetting=CharacterSpacing | 4 | 2
MeasureName=MeasureTime
;X=#TextHourX#
X=(87 * #Scale#)
Y=0
Text="%1"
DynamicVariables=1

[MeterBlink]
Meter=STRING
MeterStyle=stringstyleTime
FontFace=TR LCD
FontSize=(28 * #Scale#)
FontColor=0,187,249,[MeasureBlink]
FontEffectColor=241,91,181,[MeasureBlink]
X=#Spacing1#r
;Y=0r
Y=(-5 * #Scale#)
Text=":"
DynamicVariables=1

[MeterSeconds]
Meter=String
MeterStyle=stringstyleSeconds
FontFace=TR LCD
;FontSize=(28 * #Scale#)
MeasureName=MeasureSeconds
;X=#TextSecondX#
X=(90*#Scale#)r
;Y=#TextSecondY#r
Y=(3 * #Scale#)
Text="%1"
InlineSetting=CharacterSpacing | #Spacing1# | #TextSecondSpacing#
DynamicVariables=1

[MeterAmPm]
Meter=STRING
MeterStyle=stringstyleSeconds
FontFace=TR LCD
MeasureName=MeasureAmPm
X=0r
Y=(#TextAMPMY# + (2 * #Scale#))r
;Y=#TextAMPMY#
Text="%1"
DynamicVariables=1
UpdateDivider=600

;[MeterSettings]
;Meter=Image
;ImageName=#@#Clock\Icon\Gears.png
;GrayScale=1
;ImageTint=#AnalogSecondaryColor#
;X=#GearX#
;Y=#GearY#r
;W=#GearW#
;LeftMouseUpAction=[!ToggleConfig "#ROOTCONFIG#\Settings" "Settings.ini"]
;RightMouseUpAction=[!ShowMeterGroup "DropDown"][!HideMeter "BG"][!SetOption DropDownBox Hidden "0"][!SetOption Clip Hidden "0"][!HideMeter "MeterIconBG"][!UpdateMeter "BG"][!UpdateMeter "DropDownBox"][!UpdateMeter Clip][!Redraw]

[MeterDate]
Meter=STRING
MeterStyle=stringstyleDate
MeasureName=MeasureDate
W=#CompactW#
H=#DateH#
X=(#CompactW# / 2)
Y=(#DateY#+#GearY#)r
Text="%1"
DynamicVariables=1
UpdateDivider=3600

[];===============================================================
;----------------------- Drop Down Meters ------------------------
;=================================================================
[DropDown]
@IncludeDropDown=#@#Clock\Settings\DropDown.inc


; © 2020by xxenium