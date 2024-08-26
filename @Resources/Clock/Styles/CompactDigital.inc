[Metadata]
Name=Compact Digital Clock
Author=Izzern, Special thanks to jsmorley for all the forum posts.
Information=Rainmeter minimalist digital clock skin.
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0
Version=1.0

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

[];==================================
;------------- METERS ---------------
;====================================
[MeterHour]
Meter=STRING
MeterStyle=stringstyleTime
MeasureName=MeasureTime
X=#TextHourX#
Y=0
Text="%1"
DynamicVariables=1

[MeterBlink]
Meter=STRING
MeterStyle=stringstyleTime
FontColor=0,187,249,[MeasureBlink]
FontEffectColor=241,91,181,[MeasureBlink]
X=#Spacing1#r
Y=0r
Text=":"
DynamicVariables=1

[MeterSeconds]
Meter=String
MeterStyle=stringstyleSeconds
MeasureName=MeasureSeconds
X=#TextSecondX#
Y=#TextSecondY#r
Text="%1"
InlineSetting=CharacterSpacing | #Spacing1# | #TextSecondSpacing#
DynamicVariables=1

[MeterAmPm]
Meter=STRING
MeterStyle=stringstyleSeconds
MeasureName=MeasureAmPm
X=0r
Y=#TextAMPMY#r
Text="%1"
DynamicVariables=1
UpdateDivider=600

[MeterSettings]
Meter=Image
ImageName=#@#Clock\Icon\Gears.png
GrayScale=1
ImageTint=#AnalogSecondaryColor#
X=#GearX#
Y=#GearY#r
W=#GearW#
LeftMouseUpAction=[!ToggleConfig "#ROOTCONFIG#\Settings" "Settings.ini"]

[MeterDate]
Meter=STRING
MeterStyle=stringstyleDate
MeasureName=MeasureDate
W=#CompactW#
H=#DateH#
X=(#CompactW# / 2)
Y=#DateY#r
Text="%1"
DynamicVariables=1
UpdateDivider=3600