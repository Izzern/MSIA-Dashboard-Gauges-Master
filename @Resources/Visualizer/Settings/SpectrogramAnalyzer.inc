[SpectrogramAnalyzer]
Measure=Plugin
Plugin=AudioAnalyzer
Type=Parent
ProcessingUnits=Main
Unit-Main=Channels Auto | Handlers FFT -> Resampler -> CascadeTransformer, UniformBLur(CascadeTransformer), ReMaper(CascadeTransformer), Transformer(UniformBLur) -> Spectrogram | Filter none

Handler-FFT=Type FFT | BinWidth [#BinWidth] | OverlapBoost [#OverlapBoost] | CascadesCount [#CascadesCount] | WindowFunction [#WindowFunction]
; --------------------------------------------------------------------------------------
Handler-Resampler=Type BandResampler | Bands Linear(Count #Bands#, FreqMin #FreqMin#, FreqMax #FreqMax#) | CubicInterpolation true
; --------------------------------------------------------------------------------------
Handler-CascadeTransformer=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2
; --------------------------------------------------------------------------------------
Handler-UniformBLur=Type UniformBlur | Radius 1
; --------------------------------------------------------------------------------------
Handler-ReMaper=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | UpdateRate (40) | Transform dB, Map(From -25 : 1000, to [#MinHeight] : [#BarHeight]), Clamp(to [#MinHeight] : [#BarHeight])
; --------------------------------------------------------------------------------------
Handler-Transformer=Type ValueTransformer | Transform dB, Map(From -70 : 20)
; --------------------------------------------------------------------------------------
; --------------------------------------------------------------------------------------
Handler-Spectrogram=Type Spectrogram | Folder [#@]Visualizer\Images | UpdateRate 20 | SilenceThreshold -70 | Stationary false | BorderSize 0 | DefaultColorSpace sRGB255 | MixMode hsl | FadingRatio 0.33 | BorderColor @sRGB255 255, 171, 92 | Colors 0.0: @srgb255 #BGColor#; 0.35: @srgb255 #BarColor#,255 ; 0.4: @srgb255 #StrokeColor#,255