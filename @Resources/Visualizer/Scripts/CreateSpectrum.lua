function Initialize()
  Bands = SELF:GetOption('BandsCount', 1)

-- FP stands for file path
  MeasureBandsFP  = SKIN:MakePathAbsolute(SKIN:ReplaceVariables("#@#Visualizer\\Settings\\MeasureBands.inc"))
  MeterSpectrumFP = SKIN:MakePathAbsolute(SKIN:ReplaceVariables("#@#Visualizer\\Styles\\Spectrum.inc"))
  SpectrumReflectionFP = SKIN:MakePathAbsolute(SKIN:ReplaceVariables("#@#Visualizer\\Styles\\SpectrumReflection.inc"))

  GenerateAll(Bands)
end

function GenerateMeasureBands(Bands)
  MeasureBands = io.open(MeasureBandsFP, "w")

  for i = 0, (Bands - 1) do
    MeasureBands:write("[MeasureBand" .. i .. "]\n")
    MeasureBands:write("Measure=Plugin\n")
    MeasureBands:write("Plugin=AudioAnalyzer\n")
    MeasureBands:write("Parent=Analyzer\n")
    MeasureBands:write("Type=Child\n")
    MeasureBands:write("Index=" .. i .. "\n")
    MeasureBands:write("Channel=Auto\n")
    MeasureBands:write("HandlerName=MainFinalOutput\n\n")
  end

  MeasureBands:close()
end

function GenerateMeterSpectrum(Bands)
  MeterSpectrum = io.open(MeterSpectrumFP, "w")

    -- Write Vars
    MeterSpectrum:write("[Variables]\n")
	MeterSpectrum:write("@includeVariablesUser=#@#Visualizer\\Settings\\VariablesUser.inc\n")
    MeterSpectrum:write("@includeVariables=#@#Visualizer\\Settings\\VariablesVisualizer.inc\n")
    MeterSpectrum:write("@includeMeasures=#@#Visualizer\\Settings\\MeasureBands.inc\n\n")
	
	-- Include Reflection
	MeterSpectrum:write("[SpectrumReflection]\n")
    MeterSpectrum:write("@includeSpectrumReflection=#@#Visualizer\\Styles\\SpectrumReflection.inc\n\n")	
	
	-- Write BG Image
	MeterSpectrum:write("[VisualizerBGImage]\n")
    MeterSpectrum:write("Meter=Image\n")
    MeterSpectrum:write("Container=#Selection#\n")
    MeterSpectrum:write("ImageName=#BGImage#\n")
    MeterSpectrum:write("W=#SpectrumW#\n")
    MeterSpectrum:write("H=#SpectrumH#\n")
    MeterSpectrum:write("X=0\n")
	MeterSpectrum:write("Y=0\n")
    MeterSpectrum:write("UpdateDivider=-1\n\n")
	
	-- Write Settings
    MeterSpectrum:write("[Settings]\n")
    MeterSpectrum:write("Meter=Shape\n")
    MeterSpectrum:write("DynamicVariables=1\n")
    MeterSpectrum:write("Shape=Rectangle 0, ((#BarHeight# * #ScaleVis#) - ([MeasureBand1] * #Jump#)), #UnitWidth#, (Neg([MeasureBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers\n\n")
    MeterSpectrum:write("Disabled=0\n")
    MeterSpectrum:write("LeftMouseUpAction=[!WriteKeyValue Variables Selection \"Visualizer\\Settings\\Panels\\VisualizerSystem\" \"#SKINSPATH##PATH#\\Settings\\Settings.ini\"][!ToggleConfig \"#Path#\\Settings\" \"Settings.ini\"]\n")
    MeterSpectrum:write("SpectrumModifiers=Fill Color 0,0,0,1 | StrokeWidth #StrokeWidth# | Stroke Color 0,0,0,1\n")
    MeterSpectrum:write("SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#\n\n")
	
	-- Write Spectrum
    MeterSpectrum:write("[Spectrum]\n")
    MeterSpectrum:write("Meter=Shape\n")
    MeterSpectrum:write("DynamicVariables=1\n\n")

    -- Dynamically generate the spectrum bands
    for i = 1, (Bands) do
        local shapeName = (i == 1) and "Shape=" or "Shape" .. i .. "="
        local x = "(#UnitStartX# * " .. (i - 1) .. ")"
        local y = "((#BarHeight# * #ScaleVis#) - ([MeasureBand" .. (i - 1) .. "] * #Jump#))"
        local width = "#UnitWidth#"
        local rounding = "#UnitRounding#"
        local disabled = "(#Bands# < " .. i .. ")"

        MeterSpectrum:write("; Spectrum Band " .. i .. "\n")
        MeterSpectrum:write(shapeName .. "Rectangle " .. x .. ", " .. y .. ", " .. width .. ", (Neg([MeasureBand" .. (i - 1) .. "] * #Gain#)), " .. rounding .. " | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient\n\n")
    end

    -- Write Spectrum Modifiers
    MeterSpectrum:write("SpectrumModifiers=Fill Color #BarColor# | StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#\n")
    MeterSpectrum:write("SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#\n")
    MeterSpectrum:write(";SpectrumGradient=90 | 0,255,0,#Alpha# ; #SpectrumStart# | 255,255,0,#Alpha# ; #SpectrumMid# | 255,0,0,1 ; #SpectrumEnd#\n")
	MeterSpectrum:close()
end

function GenerateSpectrumReflection(Bands)
  SpectrumReflection = io.open(SpectrumReflectionFP, "w")
	
	-- Write BG Image
	SpectrumReflection:write("[ReflectionBGImage]\n")
    SpectrumReflection:write("Meter=Image\n")
    SpectrumReflection:write("Container=Reflection\n")
    SpectrumReflection:write("ImageName=#BGImage#\n")
    SpectrumReflection:write("W=#SpectrumW#\n")
    SpectrumReflection:write("H=#SpectrumH#\n")
    SpectrumReflection:write("X=0\n")
	SpectrumReflection:write("Y=0\n")
    SpectrumReflection:write("Hidden=(1 - #Reflection#)\n")
    SpectrumReflection:write("UpdateDivider=-1\n\n")
	
	-- Write Reflection
    SpectrumReflection:write("[Reflection]\n")
    SpectrumReflection:write("Meter=Shape\n")
    SpectrumReflection:write("Hidden=(1 - #Reflection#)\n")
    SpectrumReflection:write("DynamicVariables=1\n\n")

    -- Dynamically generate the spectrum bands
    for i = 1, (Bands) do
        local shapeName = (i == 1) and "Shape=" or "Shape" .. i .. "="
        local x = "(#UnitStartX# * " .. (i - 1) .. ")"
        local y = " ((#UnitHeight# * #ScaleVis#) + ([MeasureBand" .. (i - 1) .. "] * #Jump#))"
        local width = "#UnitWidth#"
        local rounding = "#UnitRounding#"
        local disabled = "(#Bands# < " .. i .. ")"

        SpectrumReflection:write("; Spectrum Band " .. i .. "\n")
        SpectrumReflection:write(shapeName .. "Rectangle " .. x .. ", " .. y .. ", " .. width .. ", ([MeasureBand" .. (i - 1) .. "] * #Gain#), " .. rounding .. " | Extend ReflectionModifiers | Fill LinearGradient ReflectionGradient\n\n")
    end

    -- Write Reflection Modifiers
    SpectrumReflection:write("ReflectionModifiers=StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#,#Alpha#\n")
    SpectrumReflection:write("ReflectionGradient=270 | #BarColor#,#Alpha# ; #ReflectionStart# | #BarColor#,0 ; #ReflectionEnd#\n")
    SpectrumReflection:write(";ReflectionGradient=270 | 0,255,0,#Alpha# ; #ReflectionStart# | 255,255,0,#Alpha# ; #ReflectionMid# | 255,0,0,1 ; #ReflectionEnd#\n")
	SpectrumReflection:close()
end

function GenerateAll(Bands)
  Bands = Bands or 1 -- safety check
  GenerateMeasureBands(Bands)
  GenerateMeterSpectrum(Bands)
  GenerateSpectrumReflection(Bands)
end