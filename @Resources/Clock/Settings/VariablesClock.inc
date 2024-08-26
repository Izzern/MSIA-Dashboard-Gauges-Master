[Variables]
@includeVarsUser=#@#Clock\Settings\VariablesUser.inc
@IncludeMeasures=#@#Clock\Settings\MeasuresWeather.inc


;---------- Time Formatting -----------
AMPMCompact=%p
DayAnalog=%a
DateAnalog=%d
DateCompact=%A, %B %#d, %Y
HourAnalog=%#I
HourCompact=%I
MinuteAnalog=%#M
SecondAnalog=%#S
SecondCompact=%S
TimeCompact=%I %M

;---------- Size & Position -----------
AnalogD=(60 * #Scale#)
AnalogR=(#AnalogD# / 2)
AnalogR1=(#AnalogR# + (1 * #Scale#))

BGOffset=(2 * #Scale#)

ClockHandY=(-2.5 * #Spacing1#)
CircleX=(#AnalogR# + #Spacing1#)
CircleY=(33.3 * #Scale#)
CircleR=(2 * #Scale#)
CircleStrokeWidth=(1.5 * #Scale#)
CircleButtonR=(5 * #Scale#)

CompactH=(60 * #Scale#)
CompactW=(225 * #Scale#)
CompactR=(8 * #Scale#)
CompactStrokeW=(2 * #Scale#)

ContainerBGW=(#CompactW# + (2 * #Scale#))
ContainerBGH=(#CompactH# + (2 * #Scale#))

DateH=(20 * #Scale#)
DateY=(27 * #Scale#)

DayDateH=(15 * #Scale#)
DayDateW=(10 * #Scale#)
DayDateY=(42 * #Scale#)

DayNightW=(#AnalogD# - (20 * #Scale#))
DayNightH=(#AnalogD# - (20 * #Scale#))
DayNightOffSetX=(11 * #Scale#)
DayNightOffSetY=(11 * #Scale#)
DayNightLineStart=(3 * #Scale#)
DayNightLineLength=(19 * #Scale#)
DayNightStartAngle=(Rad(200))
DayNightRotationAngle=(Rad(140))

GearX=(214 * #Scale#)
GearY=(13 * #Scale#)
GearW=(10 * #Scale#)

HandW=(2 * #Scale#)
HandBGW=(3 * #Scale#)
HandHourRotateY=(16 * #Scale#)
HandMinuteRotateY=(25 * #Scale#)
HandSecondRotateY=(27 * #Scale#)
HandRotateX=(#HandW# / 2)
HandRotateBGX=(#HandBGW# / 2)
HandImgW=(80 * #Scale#)
HandHourImgH=(#AnalogR# / 1.45)
HandMinuteImgH=(#AnalogR# / 1.15)
HandSecondImgH=(#AnalogR# - #CompactStrokeW#)

LineStartY=(33 * #Scale#)
LineSencondEndY=(6 * #Scale#)
LineMinuteEndY=(8 * #Scale#)
LineHourEndY=(17 * #Scale#)

Spacing1=(1 * #Scale#)

TextAMPMY=(15 * #Scale#)
TextHourX=(95 * #Scale#)
TextSecondX=(187 * #Scale#)
TextSecondY=(4 * #Scale#)
TextSecondSpacing=(2.5 * #Scale#)

;======================================
;----------- Fonts & Colors -----------
;======================================
AnalogPrimaryColor=0,0,0
AnalogSecondaryColor=255,255,255

BGAlpha=70
BGColor=0,0,0

FontColorDate=7,190,184,200
FontColorSeconds=7,190,184,200
FontColorTime=0,187,249,200

FontEffectColorDate=0,0,0,150
FontEffectColorSeconds=155,93,229,200
FontEffectColorTime=241,91,181,200

FontFace=Square Sans Serif 7
FontFace2=Segoe UI
FontFace3=NewsGoth Cn BT

FontSizeXS=(9 * #Scale#)
FontSizeSm=(10 * #Scale#)
FontSizeMd=(13 * #Scale#)
FontSizeLg=(35 * #Scale#)

GearColor=150,150,150,200

HandAlpha=255
HandBGAlpha=200

StrokeColor=255,255,255

[];====================================
;--------------- Styles ---------------
;======================================
[stringstyleTime] ;Time
FontColor=#FontColorTime#
FontEffectColor=#FontEffectColorTime#
FontFace=#FontFace#
FontSize=#FontSizeLg#
FontWeight=5
InlineSetting=CharacterSpacing | (1.5 * #Scale#)  | (-1 * #Scale#)
StringAlign=CENTERTOP
StringCase=NONE
StringEffect=BORDER
StringStyle=BOLD
AntiAlias=1
ClipString=1

[stringstyleSeconds] ;SecondAMPM
FontColor=#FontColorSeconds#
FontEffectColor=#FontEffectColorSeconds#
FontFace=#FontFace#
FontSize=#FontSizeMd#
InlineSetting=CharacterSpacing | 1 | 1
StringAlign=LEFTTOP
StringCase=NONE
StringEffect=BORDER
StringStyle=BOLD
AntiAlias=1
ClipString=1

[stringstyleDate] ;Date
FontColor=#FontColorDate#
FontEffectColor=#FontEffectColorDate#
FontFace=#FontFace2#
FontSize=(11 * #Scale#)
StringAlign=CENTERBOTTOM
StringCase=NONE
StringEffect=BORDER
StringStyle=BOLD
AntiAlias=1
ClipString=1

[stringstyle3] ;conditions
StringAlign=LEFTCENTER
StringCase=PROPER
StringStyle=BOLD
StringEffect=BORDER
FontEffectColor=0,0,0,150
FontColor=0,245,212,200
FontFace=Segoe UI
FontSize=(11 * #scale#)
AntiAlias=1
NumOfDecimals=0
DynamicVariables=1

[stringstyle4] ;temp
StringAlign=LEFTCENTER
StringCase=NONE
StringStyle=BOLD
StringEffect=BORDER
FontEffectColor=0,0,0,150
FontColor=0,245,212,200
FontFace=Segoe UI
FontSize=(12 * #scale#)
AntiAlias=1
NumOfDecimals=0
DynamicVariables=1

[stringstyle5] ;PP
StringAlign=LEFTTOP
StringCase=PROPER
InlineSetting=CharacterSpacing | 0 | 1
StringEffect=BORDER
FontEffectColor=0,0,0,150
FontColor=150,170,255,200
FontFace=Arial
FontSize=(11 * #scale#)
AntiAlias=1
ClipString=1
NumOfDecimals=0
DynamicVariables=1

[stringstyle6] ;TempHi
StringAlign=RIGHTTOP
StringCase=PROPER
InlineSetting=CharacterSpacing | 1 | 0
StringEffect=BORDER
FontEffectColor=0,0,0,150
FontColor=255,144,0,200
FontFace=Arial
FontSize=(11 * #scale#)
AntiAlias=1
ClipString=1
NumOfDecimals=0
DynamicVariables=1

[stringstyle7] ;TempLo
StringAlign=RIGHTTOP
StringCase=PROPER
InlineSetting=CharacterSpacing | 1 | 0
StringEffect=BORDER
FontEffectColor=0,0,0,150
FontColor=0,187,249,200
FontFace=Arial
FontSize=(11 * #scale#)
AntiAlias=1
ClipString=1
NumOfDecimals=0
DynamicVariables=1

;[stringstyle8] ;Date
;StringAlign=CENTER, BOTTOM 
;StringCase=NONE
;StringStyle=BOLD
;StringEffect=BORDER
;FontEffectColor=0,0,0,150
;FontColor=7,190,184,200
;FontFace=Segoe UI
;FontSize=(11 * #scale#)
;AntiAlias=1
;ClipString=1
;DynamicVariables=1

[stringstyle9] ;HideMeterGroup
StringAlign=LEFTTOP
StringCase=PROPER
StringStyle=BOLD
StringEffect=BORDER
FontEffectColor=0,0,0,150
FontColor=0,245,212,200
FontFace=Segoe UI
FontSize=(9 * #scale#)
AntiAlias=1
ClipString=1
NumOfDecimals=0
DynamicVariables=1

[stringstyle10] ;Update
StringAlign=LEFT, BOTTOM
StringCase=Proper
StringStyle=BOLD
StringEffect=BORDER
FontEffectColor=0,0,0,150
FontColor=255,255,255,200
FontFace=Segoe UI
FontSize=(7 * #scale#)
AntiAlias=1
ClipString=1
NumOfDecimals=0
DynamicVariables=1
