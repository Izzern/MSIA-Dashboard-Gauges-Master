[Variables]
@includeVars=#@#Variables.inc
@includeFPSVars=#@#VariablesFPS.inc

StringAlign1=CENTERCENTER
StringCase1=PROPER
StringStyle1=BOLD
StringEffect1=BORDER

[StyleLabelPercent] ;Text options
FontColor=#FontColorPerct#
FontEffectColor=#FontEffectPerct#
FontFace=#FontFacePerct#
FontSize=(#FontSizeLg# * #Scale#)
StringAlign=#StringAlign1#
StringCase=#StringCase1#
StringStyle=#StringStyle1#
StringEffect=#StringEffect1#

[StyleLabelTemp] ;Text options
FontColor=#FontColorTemp#
FontEffectColor=#FontEffectTemp#
FontFace=#FontFaceTemp#
FontSize=(#FontSizeLg# * #Scale#)
StringAlign=#StringAlign1#
StringCase=#StringCase1#
StringStyle=#StringStyle1#
StringEffect=#StringEffect1#

[StyleLabelFPS] ;Text options
FontColor=[MeasureColor]
FontEffectColor=#BorderColorFPS#
FontFace=#FontFaceFPS#
FontSize=(#FontSizeFPS# * #Scale#)
StringAlign=#StringAlign2#
StringStyle=#StringStyle1#
StringEffect=#StringEffect1#

[StyleLabelOverlay] ;Text options
FontColor=[MeasureColor]
FontEffectColor=#BorderColorFPS#
FontFace=#FontFaceFPS#
FontSize=(#FontSizeFPS2# * #Scale#)
StringAlign=RIGHTCENTER
StringCase=Upper
StringStyle=BOLD
StringEffect=BORDER