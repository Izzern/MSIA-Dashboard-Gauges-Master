function Update()
    for i=0, 31 do
        local meterName = "MeterBand" .. i
        local scale = tonumber(SKIN:GetVariable("Scale"))

        local currentValue = tonumber(SKIN:GetMeasure("MeasureAudioRMS_Band" .. i):GetValue())
        local percentage = currentValue / 100  -- Calculate the percentage

        local newY = currentValue + (percentage * scale)

        SKIN:Bang("!SetOption", meterName, "Y", newY)
    end
end