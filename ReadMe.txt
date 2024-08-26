==================================================================
------------------ Izzern System Monitor Gauges ------------------
==================================================================

These skins were designed to be a simple and easily customizable
system monitor. As such they require very little setup by the
user and the look can be adjusted using the GUI.

Variables monitored:
CPU Usage (%)
CPU Temp (C)
FPS
GPU Usage
  * Core Load (%)
  * VRAM/Process (GB)
GPU Temp (C)
Network usage (kbps)
RAM usage (%)
Wifi Strength (%)

The gauges fill up and change color according to the value being
measured. Thresholds for most variables (in % or [\x00B0]C are)
Low			  Mid 			High
<60 | >60 - 80 | >80 - 95 | >95

The Welcome skin automatically retrieves and writes hardware
specifications to @ResourcesGauges\VariablesHardware.inc when 
started or refreshed. These variables are required for proper
functioning.
There is also a button to set variables in the settings skin.
This should only be used if devices are not showing after a 
refresh or if you change the folder name.

=================================================================
-------------------------- Customization ------------------------
=================================================================

To customize the look of Izzern's System Monitor Gauges use the
GUI, by clicking on one of the icons (CPU, GPU, RAM, FPS, etc.).
The icons also display information about the device(s) being
monitored. Within the GUI is a button to restore default settings.

=================================================================
------------------------- MSI Afterburner -----------------------
=================================================================

I have included the plugin for MSI Afterburner (MSIA) and links
to MSIA and the plugin below.

If you have multiple GPUs simply select the appropriate checkbox
in the settings.
To use the Network gauge input your adapter's max transmission
speed.

MSIAfterburner:
https://www.msi.com/Landing/afterburner/graphics-cards

MSIAfterburner.dll:
https://forums.guru3d.com/threads/rainmeter-plugin-for-msi-afterburner.319558/
(Alternate links on page 10 of the forum)