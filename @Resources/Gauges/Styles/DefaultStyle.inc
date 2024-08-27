[Variables]
;======================================
;------------- Text Styles ------------
;======================================
FontSizeXS=8
FontSizeSm=9
FontSizeMd=11
FontSizeLg=16
FontSizeXL=22

StringAlignCC=CENTERCENTER
StringAlignRC=RIGHTCENTER
StringAlignRT=RIGHTTOP
StringCaseLower=LOWER
StringCaseProper=PROPER
StringCaseUpper=UPPER
StringStyleBold=BOLD
StringEffectBorder=BORDER

[StylePercent] ;Text options
FontColor=#FontColorPerct#
FontEffectColor=#FontEffectPerct#
FontFace=#FontFacePerct#
FontSize=(#FontSizeMd# * #ScaleGauge#)
StringAlign=#StringAlignCC#
StringCase=#StringCaseProper#
StringStyle=#StringStyleBold#
StringEffect=#StringEffectBorder#

[StyleTemp] ;Text options
FontColor=#FontColorTemp#
FontEffectColor=#FontEffectTemp#
FontFace=#FontFaceTemp#
FontSize=(#FontSizeMd# * #ScaleGauge#)
StringAlign=#StringAlignCC#
StringCase=#StringCaseProper#
StringStyle=#StringStyleBold#
StringEffect=#StringEffectBorder#

[StylePing] ;Text options
FontColor=[MeasureColor]
FontEffectColor=#FontEffectTemp#
FontFace=#FontFaceTemp#
FontSize=(#FontSizeSm# * #ScaleGauge#)
StringAlign=#StringAlignCC#
StringCase=#StringCaseLower#
StringStyle=#StringStyleBold#
StringEffect=#StringEffectBorder#

[StyleOverlay] ;Text options
FontColor=[MeasureColor]
FontEffectColor=#BorderColorFPS#
FontFace=#FontFaceFPS#
FontSize=(#FontSizeXL# * #ScaleFPS#)
StringAlign=#StringAlignRC#
StringCase=#StringCaseUpper#
StringStyle=#StringStyleBold#
StringEffect=#StringEffectBorder#
