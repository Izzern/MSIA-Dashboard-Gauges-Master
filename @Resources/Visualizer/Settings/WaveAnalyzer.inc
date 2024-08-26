[WaveAnalyzer]
Measure=Plugin
Plugin=AudioAnalyzer
Type=Parent
ProcessingUnits=Main
Unit-Main=Channels Auto | Handlers Waveform | Filter none

Handler-Waveform=Type Waveform | Folder [#@]Visualizer\Images | Width [#SpectrogramW] | Height [#BarHeight] | UpdateRate 200 | Stationary false | BorderSize 0 | Connected true | DefaultColorSpace sRGB255 | BackgroundColor [#BGColor] | WaveColor [#BarColor] | LineColor [#StrokeColor] | FadingRatio 0.33 | LineDrawingPolicy Never | SilenceThreshold -70 | Transform dB, Map(From -25 : 1000, to [#MinHeight] : [#MaxHeight]), Clamp(to [#MinHeight] : [#MaxHeight])