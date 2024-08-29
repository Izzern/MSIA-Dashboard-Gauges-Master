;=================================================================
;--------------- Gauges User Variables Config File ---------------
;=================================================================
;To customize or restore defaults click on any of the Izzern Gauge Icons (CPU, GPU, RAM, etc.).

[Variables]
;======================================
;---------- User Selections -----------
;======================================
NetAdapterNameSelection=Intel(R) I211 Gigabit Network Connection
NetAdapterIPSelection=192.168.1.41
NetAdapterConnSelection=Connected
NetAdapterDNSSelection=192.168.1.1
MaxAdapterSpeed=1000

NetState=1

GPUSelection=NVIDIA GeForce GTX 1060 6GB
VRAMSelection=6

GPUState=0

StyleSelection=#@#Gauges\Styles\DefaultStyle.inc
;Add settings entry for switching
ActiveStyle=Gauge

;======================================
;--------------- Gauges ---------------
;======================================
;---------- Position & Scale ----------
ScaleGauge=1

TextGaugeX=30
TextGaugeY=24

;--------------- Fonts ----------------
FontFacePerct=Segoe UI
FontFaceTemp=Segoe UI

;--------------- Colors ---------------
FontColorPerct=[MeasureColor]

PercentLevel1=0,245,212
PercentLevel2=0,187,249
PercentLevel3=155,93,229
PercentLevel4=241,91,181

FontEffectPerct=0,0,0

FontColorTemp=[MeasureColor]

TempLevel1=7,190,184
TempLevel2=252,186,4
TempLevel3=255,144,0
TempLevel4=148,43,59

FontEffectTemp=0,0,0

FontColorDn=50,200,0
FontColorUp=155,93,229
FontColorPing=[MeasureColor]

FontEffectColor=0,0,0
FontEffectColor1=0,0,0

BGColor=255,255,255

CPUIconTint=237,28,36

GPUIconTint=118,185,0

RAMIconTint=236,232,26

NetIconTint=50,255,10

WifiIconTint=0,113,197

;======================================
;---------------- FPS -----------------
;======================================
;---------- Position & Scale ----------
ScaleFPS=1

TextFPSX=30
TextFPSY=22
OverlayOffsetX=0
OverlayOffsetY=0
OverlayW=80
OverlayH=25

;--------------- Fonts ----------------
FontFaceFPS=Segoe UI

;--------------- Colors ---------------
PercentLevel1FPS=241,91,181
PercentLevel2FPS=155,93,229
PercentLevel3FPS=0,187,249
PercentLevel4FPS=0,245,212

BGColorFPS=255,255,255
GearTintFPS=155,155,155
FPSIconTint=255,0,0
BorderColorFPS=0,0,0

;======================================
;---------------- Clock ---------------
;======================================
ClockLayout=CompactForecast
