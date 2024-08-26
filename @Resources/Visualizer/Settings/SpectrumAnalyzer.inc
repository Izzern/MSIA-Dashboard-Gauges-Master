[Analyzer]
Measure=Plugin
Plugin=AudioAnalyzer
Type=Parent

ProcessingUnits=Main
Unit-Main=Channels [#Channel] | Handlers MainFFT, MainResampler(MainFFT), MainTransform(MainResampler), MainFilter(MainTransform), MainMapper(MainFilter), MainFinalOutput(MainMapper) | Filter like-a

Handler-MainFFT=Type FFT | BinWidth [#BinWidth] | OverlapBoost [#OverlapBoost] | CascadesCount [#CascadesCount] | WindowFunction [#WindowFunction]

Handler-MainResampler=Type BandResampler | Bands log(Count (#Bands#), FreqMin [#FreqMin], FreqMax [#FreqMax])
Handler-MainTransform=Type BandCascadeTransformer | MinWeight 0.01 | TargetWeight 2
Handler-MainFilter=Type TimeResampler | Attack [#Attack] | Decay [#Decay]
Handler-MainMapper=Type ValueTransformer | Transform dB, Map(From -50 : -0), Clamp(to (#Visibility# / #Gain#) : [#BarHeight])
Handler-MainFinalOutput=Type UniformBlur | Radius [#BlurRadius]