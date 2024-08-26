;=================================================================
;------------- Settings Panel Variables Config File --------------
;=================================================================
;To customize or restore defaults click on any of the Izzern Honeycomb Icons (CPU, GPU, or RAM).

[Variables]
;======================================
;---------- Position & Scale ----------
;======================================
SettingsScale=0.8
IndicatorPosition=19
IndicatorPositionClock=19

Unchecked=[\x2610]
Checked=[\x2611]

; Background
BGW=(793 * #SettingsScale#)
BGH=(755 * #SettingsScale#)

; Style Columns
Column1X=(40 * #SettingsScale#)
Column2X=(360 * #SettingsScale#)
ColumnY=(130 * #SettingsScale#)

RowSpacing=(48 * #SettingsScale#)r

; Check Boxes
BoxModeSize=(5 * #SettingsScale#)
BoxModeX=(18 * #SettingsScale#)
BoxModeY=(40 * #SettingsScale#)
BoxSpacingTheme=(25 * #SettingsScale#)
BoxCheckSize=(10 * #SettingsScale#)

;Settings Scale
BoxValueSmW=(35 * #SettingsScale#)
BoxValueSmH=(25 * #SettingsScale#)
BoxValueSmX=(19 * #SettingsScale#)

BoxInputSmH=(20 * #SettingsScale#)
BoxInputSmY=(2.5 * #SettingsScale#)

; System and Position Boxes
BoxValueMdW=(60 * #SettingsScale#)
BoxValueMdH=(30 * #SettingsScale#)
BoxValueMdR=(5 * #SettingsScale#)
BoxValueMdX=(480 * #SettingsScale#)
BoxValueMdSpacingY=(5 * #SettingsScale#)

BoxInputMdW=(60 * #SettingsScale#)
BoxInputMdH=(20 * #SettingsScale#)
BoxInputMdY=(3 * #SettingsScale#)r
BoxInputMdX=(6 * #SettingsScale#)
BoxInputMdSpacingY=(5 * #SettingsScale#)

;Style Boxes
BoxValueLgW=(115 * #SettingsScale#)
BoxValueLgH=(30 * #SettingsScale#)
BoxValueLgSpacingY=(5 * #SettingsScale#)
BoxValueLgSpacingX=(60 * #SettingsScale#)

BoxInputLgH=(20 * #SettingsScale#)
BoxInputLgY=(3 * #SettingsScale#)r
BoxInputLgX=(6 * #SettingsScale#)
BoxInputLgSpacingY=(5 * #SettingsScale#)
MeterInputLgSpacingX=(150 * #SettingsScale#)
MeterInputLgSpacingY=(-5 * #SettingsScale#)

; Close Button
ButtonCloseSize=(20 * #SettingsScale#)
ButtonCloseR=(5 * #SettingsScale#)
ButtonCloseX=(757 * #SettingsScale#)
ButtonCloseY=(15 * #SettingsScale#)

; Bottom Buttons
ButtonBottomW=(220 * #SettingsScale#)
ButtonBottomH=(30 * #SettingsScale#)

; Dark/Light Toggle
ButtonToggleW=(26 * #SettingsScale#)
ButtonToggleH=(12 * #SettingsScale#)
ButtonToggleR=(5 * #SettingsScale#)
ButtonToggleX=(60 * #SettingsScale#)
ButtonToggleY=(6.5 * #SettingsScale#)

; Heading
HeaderH=(75 * #SettingsScale#)
HeaderW=#BGW#
HeaderX=(1 * #SettingsScale#)
HeaderY=(1 * #SettingsScale#)

;Icon
IconSquareH=(20 * #SettingsScale#)

; Title
TitleX=(15 * #SettingsScale#)
TitleY=(10 * #SettingsScale#)
TitleSpacing=(40 * #SettingsScale#)
TitleScaleX=(15 * #SettingsScale#)

; Selection Container
ContainerSelectionW=(675 * #SettingsScale#)
ContainerSelectionH=(620 * #SettingsScale#)
ContainerSelectionR=(18 * #SettingsScale#)
ContainerSelectionX=(113 * #SettingsScale#)
ContainerSelectionY=(129 * #SettingsScale#)

ContainerScaleH=(70 * #SettingsScale#)

; Settings Container (Bottom Left)
ContainerSettingsW=(105 * #SettingsScale#)
ContainerSettingsH=(215 * #SettingsScale#)
ContainerSettingsR=(10 * #SettingsScale#)
ContainerSettingsX=(7 * #SettingsScale#)
ContainerSettingsY=(495 * #SettingsScale#)

; Tab Selection Container
SelectionFrameW=(794 * #SettingsScale#)
SelectionFrameH=(763 * #SettingsScale#)
SelectionFrameX=(-9 * #SettingsScale#)
SelectionFrameY=(-7 * #SettingsScale#)

; Generic Spacing
Spacing1=(1 * #SettingsScale#)
Spacing-1=(-1 * #SettingsScale#)
Spacing2=(2 * #SettingsScale#)
Spacing3=(3 * #SettingsScale#)
Spacing10=(10 * #SettingsScale#)
Spacing-10=(-10 * #SettingsScale#)
Spacing15=(15 * #SettingsScale#)
Spacing50=(50 * #SettingsScale#)

; Misc
GPUTextW=(260 * #SettingsScale#)

; Tabs
TopTabW=(122 * #SettingsScale#)
TopTabH=(40 * #SettingsScale#)
TopTabX=(113 * #SettingsScale#)
TopTabY=(83 * #SettingsScale#)
SideTabW=(105 * #SettingsScale#)
SideTabH=(54 * #SettingsScale#)
SideTabX=(8 * #SettingsScale#)
SideTabY=(115 * #SettingsScale#)

; Shape Styles
Odd=Fill Color #FontColor#,1 | StrokeWidth 0 | Stroke Color 0,0,0,1
Even=Fill Color #ColorTint#,12 | StrokeWidth 0 | Stroke Color 0,0,0,1

TopTab=Fill Color 0,0,0,0 | StrokeWidth 0 | Stroke Color 255,255,255
SideTab=Fill Color 0,0,0,0 | StrokeWidth 0

;======================================
;--------------- Colors ---------------
;======================================
GearTint=155,155,155

;======================================
;------------- Text Styles ------------
;======================================
FontFace=Segoe UI

FontSizeTitle=(13 * #SettingsScale#)
FontSizeText=(12 * #SettingsScale#)
FontSizeButton=(14 * #SettingsScale#)

;======================================
;-------------- User Vars -------------
;======================================
FontColor=255,255,255
ThemeState=0
BGImage=D:\OneDrive\Documents\Rainmeter\Skins\MSIA Dashboard Gauges Master\@Resources\Settings\Images\Settings_BG-Dark.png
ContainerSettingsBG=D:\OneDrive\Documents\Rainmeter\Skins\MSIA Dashboard Gauges Master\@Resources\Settings\Images\PopUpBG-Dark.png
FontEffectColor=20,20,20
SolidColor=#ColorTint#,180
BorderColor=80,80,80
FrameColor=170,170,170,220
FrameAlpha=255
ColorTint=0,187,249
ColorSelection=4
Mode=1
HeaderImage=D:\OneDrive\Documents\Rainmeter\Skins\MSIA Dashboard Gauges Master\@Resources\Settings\Images\Header-Dark.png

;======================================
;--------------- Styles ---------------
;======================================
[TitleStyle]
FontColor=#FontColor#
FontEffectColor=#FontEffectColor#
FontFace=#FontFace#
FontSize=(12 * #SettingsScale#)
StringAlign=LEFTTOP
StringEffect=SHADOW
StringStyle=BOLD

[TextStyle]
FontColor=#FontColor#
FontEffectColor=#FontEffectColor#,200
FontFace=#FontFace#
FontSize=(11 * #SettingsScale#)
StringAlign=LEFTTOP
StringEffect=SHADOW

[DisplayStyle]
FontColor=255,255,20
FontEffectColor=#FontColor#,100
FontFace=#FontFace#
FontSize=(11 * #SettingsScale#)
StringAlign=CENTER
StringEffect=SHADOW

[ButtonStyle]
FontColor=#FontEffectColor#
FontEffectColor=#FontColor#,200
FontFace=#FontFace#
FontSize=(11 * #SettingsScale#)
StringAlign=CENTERCENTER
StringEffect=NONE
StringStyle=BOLD
Padding=(5.5 * #SettingsScale#),(5.5 * #SettingsScale#),(6 * #SettingsScale#),(5.5 * #SettingsScale#)
SolidColor=#SolidColor#

[ButtonTextStyle]
FontColor=#FontColor#
FontEffectColor=#FontEffectColor#,100
FontFace=#FontFace#
FontSize=(10 * #SettingsScale#)
StringAlign=LEFT
StringEffect=SHADOW
StringStyle=BOLD

[InputStyle]
FontColor=0,0,0
FontFace=#FontFace#
StringEffect=SHADOW
