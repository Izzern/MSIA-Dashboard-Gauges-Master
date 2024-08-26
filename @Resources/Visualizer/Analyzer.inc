[Variables]
;@includeVariablesVisualizer=#@#Visualizer\Settings\VariablesVisualizer.inc

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
Handler-MainMapper=Type ValueTransformer | Transform dB, Map(From -50 : -0), Clamp
Handler-MainFinalOutput=Type UniformBlur | Radius [#BlurRadius]

[AnalyzerSpectrogram]
Measure=Plugin
Plugin=AudioAnalyzer_1_1
Type=Parent
Processing=proc1
Processing_proc1=channels auto | handlers fft,resampler,transformer,mapper,_spec,_wave
Handler_fft=type fft | attack 1 | decay 1 | binWidth 20 | cascadesCount 5| testRandom 0 | overlap 0.8
Handler_resampler=type BandResampler | source fft | freqList flist
Handler_transformer=type BandCascadeTransformer | source resampler | mixFunction | minweight | targetWeight | weightFallback |
Handler_mapper=type LogarithmicValueMapper |source transformer | offset 0.1 | sensitivity 40
Handler__spec=type spectrogram |length 300 |resolution 20 |source mapper | baseColor 0.1,0.1,0.1,0.8 |maxColor 0.9,0.85,0.5,1.5
Handler__wave=type waveform |width 300 |height 101 |resolution 0.1*3*2 | backgroundColor 0.6,0.6,0.6,0.8 |waveColor 0.1,0.1,0.1,2 |lineColor 0.5,0.5,0.5| lineDrawingPolicy always | gain 3
FreqList_flist=log 100 50 200003

[AnalyzerLines]
Measure=Plugin
Plugin=AudioAnalyzer
Type=Parent
ProcessingUnits=Main
Unit-Main=Channels [#Channel] | Handlers MainFFT, Layer1BR(MainFFT), Layer1BCT(Layer1BR), Layer1Output(Layer1BCT), Layer2BR(MainFFT), Layer2BCT(Layer2BR), Layer2Output(Layer2BCT), Layer3BR(MainFFT), Layer3BCT(Layer3BR), Layer3Output(Layer3BCT) | Filter Custom bqHighPass(Q 0.2, Freq 20, ForcedGain 5.58), bqLowPass(Q 1, Freq 16000, ForcedGain 20)
Handler-MainFFT=Type FFT | BinWidth 8 | OverlapBoost 10 | CascadesCount 2 | WindowFunction [#WindowFunction]

Handler-Layer1BR=Type BandResampler | Bands Log(Count 21, FreqMin 20, FreqMax 16000) | CubicInterpolation true
Handler-Layer1BCT=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2 | ZeroLevelMultiplier 1
Handler-Layer1Output=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | Transform dB, Map(From -[#MaxSensitivity] : -[#MinSensitivity]), Clamp


Handler-Layer2BR=Type BandResampler | Bands Log(Count 40, FreqMin 20, FreqMax 16000) | CubicInterpolation true
Handler-Layer2BCT=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2 | ZeroLevelMultiplier 1
Handler-Layer2Output=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | Transform dB, Map(From -[#MaxSensitivity] : -[#MinSensitivity]), Clamp


Handler-Layer3BR=Type BandResampler | Bands Log(Count 78, FreqMin 20, FreqMax 16000) | CubicInterpolation true
Handler-Layer3BCT=Type BandCascadeTransformer | MixFunction Average | MinWeight 0.01 | TargetWeight 2 | ZeroLevelMultiplier 1
Handler-Layer3Output=Type TimeResampler | Attack [#Attack] | Decay [#Decay] | Transform dB, Map(From -[#MaxSensitivity] : -[#MinSensitivity]), Clamp


LogUnusedOptions=false



