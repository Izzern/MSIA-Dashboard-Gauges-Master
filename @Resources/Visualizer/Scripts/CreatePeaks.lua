function Initialize()
  Bands = SELF:GetOption('BandsCount', 1)

-- FP stands for file path
  MeasurePeaksFP  = SKIN:MakePathAbsolute(SKIN:ReplaceVariables("#@#Visualizer\\Settings\\MeasurePeaks.inc"))
  MeterPeaksFP = SKIN:MakePathAbsolute(SKIN:ReplaceVariables("#@#Visualizer\\Styles\\Peaks.inc"))
  PeaksReflectionFP = SKIN:MakePathAbsolute(SKIN:ReplaceVariables("#@#Visualizer\\Styles\\PeaksReflection.inc"))

  GenerateAll(Bands)
end

function GenerateMeasurePeaks(Bands)
  MeasurePeaks = io.open(MeasurePeaksFP, "w")

  for i = 0, (Bands) do
    MeasurePeaks:write("[MeasureBand" .. i .. "]\n")
    MeasurePeaks:write("Measure=Plugin\n")
    MeasurePeaks:write("Plugin=AudioAnalyzer\n")
    MeasurePeaks:write("Parent=Analyzer\n")
    MeasurePeaks:write("Type=Child\n")
    MeasurePeaks:write("Index=" .. i .. "\n")
    MeasurePeaks:write("Channel=Auto\n")
    MeasurePeaks:write("HandlerName=MainFinalOutput\n\n")
  end

  MeasurePeaks:close()
end

function GenerateMeterPeaks(Bands)
  MeterPeaks = io.open(MeterPeaksFP, "w")

    -- Write Vars
    MeterPeaks:write("[Variables]\n")
	MeterPeaks:write("@includeVariablesUser=#@#Visualizer\\Settings\\VariablesUser.inc\n")
    MeterPeaks:write("@includeVariables=#@#Visualizer\\Settings\\VariablesVisualizer.inc\n")
    MeterPeaks:write("@includeMeasures=#@#Visualizer\\Settings\\MeasurePeaks.inc\n\n")
	
	-- Include Reflection
	MeterPeaks:write("[PeaksReflection]\n")
    MeterPeaks:write("@includePeaksReflection=#@#Visualizer\\Styles\\PeaksReflection.inc\n\n")	
	
	-- Write BG Image
	MeterPeaks:write("[VisualizerBGImage]\n")
    MeterPeaks:write("Meter=Image\n")
    -- MeterPeaks:write("Container=#Selection#\n")
    MeterPeaks:write("ImageName=#BGImage#\n")
    MeterPeaks:write("W=#SpectrumW#\n")
    MeterPeaks:write("H=#BarHeight#\n")
    MeterPeaks:write("X=0\n")
	MeterPeaks:write("Y=0\n")
	MeterPeaks:write("PreserveAspectRatio=2\n")
    MeterPeaks:write("UpdateDivider=-1\n\n")
	
	-- Write Settings
    MeterPeaks:write("[Settings]\n")
    MeterPeaks:write("Meter=Image\n")
    MeterPeaks:write("ImageName=#@#Visualizer\Icons\Gears\n")
    MeterPeaks:write("GrayScale=1\n")
    MeterPeaks:write("ImageTint=#StrokeColor#\n")
    MeterPeaks:write("H=(20 * #ScaleVis#)\n")
    MeterPeaks:write("Y=(#BarHeight# + (22 * #ScaleVis#))\n")
    MeterPeaks:write("LeftMouseUpAction=[!WriteKeyValue Variables Selection \"Visualizer\\Settings\\Panels\\VisualizerSystem\" \"#SKINSPATH##PATH#\\Settings\\Settings.ini\"][!ToggleConfig \"#Path#\\Settings\" \"Settings.ini\"]\n\n")
	
	-- Write Peaks
    MeterPeaks:write("[Peaks]\n")
    MeterPeaks:write("Meter=Shape\n")
    MeterPeaks:write("DynamicVariables=1\n\n")

    -- Dynamically generate the Peaks
    for i = 1, (Bands) do
        local shapeName = (i == 1) and "Shape=" or "Shape" .. i .. "="
        local xstart = "(#UnitStartX# * " .. (i - 1) .. ")"
        local ystart = "(([MeasureBand" .. (i - 1) .. "] * #Jump#))"
        local xend = "(#UnitStartX# * " .. i .. ")"
        local yend = "(([MeasureBand" .. i .. "] * #Jump#))"

        MeterPeaks:write("; Peaks " .. i .. "\n")
        MeterPeaks:write(shapeName .. "Line " .. xstart .. ", " .. ystart .. ", " .. xend .. ", " .. yend .. " | Extend PeaksModifiers\n\n")
    end

    -- Write Peaks Modifiers
    MeterPeaks:write("PeaksModifiers=StrokeWidth 3 | Stroke Color #StrokeColor#\n")
	MeterPeaks:close()
end

function GeneratePeaksReflection(Bands)
  PeaksReflection = io.open(PeaksReflectionFP, "w")
	
	-- Write BG Image
	PeaksReflection:write("[ReflectionBGImage]\n")
    PeaksReflection:write("Meter=Image\n")
    PeaksReflection:write("Container=Reflection\n")
    PeaksReflection:write("ImageName=#BGImage#\n")
    PeaksReflection:write("W=#SpectrumW#\n")
    PeaksReflection:write("H=#SpectrumH#\n")
    PeaksReflection:write("X=0\n")
	PeaksReflection:write("Y=0\n")
    PeaksReflection:write("Hidden=(1 - #Reflection#)\n")
    PeaksReflection:write("UpdateDivider=-1\n\n")
	
	-- Write Reflection
    PeaksReflection:write("[Reflection]\n")
    PeaksReflection:write("Meter=Shape\n")
    PeaksReflection:write("Hidden=(1 - #Reflection#)\n")
    PeaksReflection:write("DynamicVariables=1\n\n")

    -- Dynamically generate the Peaks reflection
    for i = 1, (Bands) do
        local shapeName = (i == 1) and "Shape=" or "Shape" .. i .. "="
        local xstart = "(#UnitStartX# * " .. (i - 1) .. ")"
        local ystart = "(([MeasureBand" .. (i - 1) .. "] * #Jump#))"
        local xend = "(#UnitStartX# * " .. i .. ")"
        local yend = "(([MeasureBand" .. i .. "] * #Jump#))"

        PeaksReflection:write("; Peaks " .. i .. "\n")
        PeaksReflection:write(shapeName .. "Line " .. xstart .. ", " .. ystart .. ", " .. xend .. ", " .. yend .. " | Extend ReflectionModifiers\n\n")
    end

    -- Write Reflection Modifiers
    PeaksReflection:write("ReflectionModifiers=StrokeWidth 3 | Stroke Color #StrokeColor#,#Alpha#\n\n")
	PeaksReflection:close()
end

function GenerateAll(Bands)
  Bands = Bands or 1 -- safety check
  GenerateMeasurePeaks(Bands)
  GenerateMeterPeaks(Bands)
  GeneratePeaksReflection(Bands)
end