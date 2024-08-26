	function Initialize()
    -- Get the number of bands from the skin
    bands = SELF:GetOption('Bands', 64)

    -- Define file path
    spectrumFP = SKIN:MakePathAbsolute(SKIN:ReplaceVariables("#@#Visualizer\\Styles\\spectrum2.inc"))

    -- Generate the spectrum shapes
    GenerateSpectrum(bands)
end

function GenerateSpectrum(bands)
    local file = io.open(spectrumFP, "w")

    -- Write Settings
    file:write("[Variables]\n")
    file:write("@includeVariables=#@#VariablesVisualizer.inc\n")
    file:write("@includeCalcs=#@#Visualizer\\CalcBands.inc\n")
    file:write("@includeMeasures=#@#Visualizer\\MeasureBands.inc\n\n")
    file:write("UnitWidth=(#BarWidth# * #ScaleVis#)\n")
    file:write("UnitHeight=((#BarHeight# + #BarSpacingY#) * #ScaleVis#)\n")
    file:write("UnitRounding=((#BarWidth# / 2) * #ScaleVis#)\n")
    file:write("UnitStartX=((#BarWidth# + #BarSpacingX#) * #ScaleVis#)\n")
    file:write("UnitStartY=((#BarHeight# + #BarSpacingY# + #Jump#) * #ScaleVis#)\n\n")
    file:write("[CreateSpectrum]\n")
    file:write("Measure=Script\n")
    file:write("ScriptFile=#@#Scripts\\CreateSpectrumBars.lua\n")
    file:write("Disabled=1\n\n")
    file:write("[Settings]\n")
    file:write("Meter=Shape\n")
    file:write("DynamicVariables=1\n")
    file:write("Shape=Rectangle 0, ((#BarHeight# * #ScaleVis#) - ([CalcBand1] * #Jump#)), #UnitWidth#, (Neg([CalcBand1] * #Gain#)), #UnitRounding# | Extend SpectrumModifiers\n\n")
    file:write("Disabled=0\n")
    file:write("LeftMouseUpAction=[!ToggleConfig \"#Path#\\Settings\" \"Settings.ini\"]\n")
    file:write("RightMouseUpAction=[!CommandMeasure CreateSpectrum \"Run\"]\n\n")
    file:write("SpectrumModifiers=Fill Color 0,0,0,1 | StrokeWidth #StrokeWidth# | Stroke Color 0,0,0,1\n")
    file:write("SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#\n\n")
    file:write("[Spectrum]\n")
    file:write("Meter=Shape\n")
    file:write("DynamicVariables=1\n\n")

    -- Dynamically generate the spectrum bands
    for i = 1, bands do
        local shapeName = (i == 1) and "Shape=" or "Shape" .. i .. "="
        local x = "(#UnitStartX# * " .. (i - 1) .. ")"
        local y = "((#BarHeight# * #ScaleVis#) - ([CalcBand" .. i .. "] * #Jump#))"
        local width = "#UnitWidth#"
        local rounding = "#UnitRounding#"
        local disabled = "(#Bands# < " .. i .. ")"

        file:write("; Spectrum Band " .. i .. "\n")
        file:write(shapeName .. "Rectangle " .. x .. ", " .. y .. ", " .. width .. ", (Neg([CalcBand" .. i .. "] * #Gain#)), " .. rounding .. " | Extend SpectrumModifiers | Fill LinearGradient SpectrumGradient\n")
        file:write("Disabled=" .. disabled .. "\n\n")
    end

    -- Write Spectrum Modifiers
    file:write("SpectrumModifiers=Fill Color #BarColor# | StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#\n")
    file:write("ReflectionModifiers=StrokeWidth #StrokeWidth# | Stroke Color #StrokeColor#,#Alpha#\n")
    file:write("SpectrumGradient=90 | 0,255,0,255 ; #SpectrumStart# | 255,255,0,255 ; #SpectrumMid# | 255,0,0,150 ; #SpectrumEnd#\n")
    file:write(";SpectrumGradient=90 | 0,255,0,#Alpha# ; #SpectrumStart# | 255,255,0,#Alpha# ; #SpectrumMid# | 255,0,0,1 ; #SpectrumEnd#\n")
    file:write("ReflectionGradient=270 | #BarColor#,#Alpha# ; #ReflectionStart# | #BarColor#,0 ; #ReflectionEnd#\n")
    file:write(";ReflectionGradient=270 | 0,255,0,#Alpha# ; #ReflectionStart# | 255,255,0,#Alpha# ; #ReflectionMid# | 255,0,0,1 ; #ReflectionEnd#\n")

    file:close()
end
