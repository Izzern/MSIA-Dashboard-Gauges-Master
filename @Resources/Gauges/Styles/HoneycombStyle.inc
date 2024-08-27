;===============================================================
;--------------------------- HoneyComb Style -------------------
;===============================================================
[Variables]
BGSize=(60 * #ScaleGauge#)

IconWideX=(9 * #ScaleGauge#)
IconWideY=(26 * #ScaleGauge#)

IconSquareX=(15 * #ScaleGauge#)
IconSquareY=(31.67 * #ScaleGauge#)

FPSIconOffsetX=(-3 * #ScaleGauge#)
FPSIconOffsetY=(5 * #ScaleGauge#)

FPSTextOffsetX=(-5 * #ScaleGauge#)
FPSTextOffsetY=(-1 * #ScaleGauge#)

[StyleFPS] ;Text options
FontColor=#FontColorPerct#
FontEffectColor=#BorderColorFPS#
FontFace=#FontFaceFPS#
FontSize=(#FontSizeLg# * #ScaleGauge#)
StringAlign=#StringAlignCC#
StringStyle=#StringStyleBold#
StringEffect=#StringEffectBorder#

[BG]
Meter=Image
ImageName=#@#Gauges\Images\background.png
H=#BGSize#
AutoScale=1
AntiAlias=1
ImageTint=[MeasureColor]
DynamicVariables=1