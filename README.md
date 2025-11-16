# Lightsaber
## By Ayman Taleb 10/01/2024

A DIY Lightsaber for my Halloween costume, Anakin Skywalker. I found the model online and added some electronics to it. I used a Teesny 3.5 MCU, a lithium battery I harvested from a discarded vape, a TP4056 battery charger, a MAX98357A speaker amp, and some awesome Flexible Filament LED Strip. The actual lightsaber is from a file I found on Thingiverse. I modified the cap to make a hole for the wires and created a huge addition for the speaker. Its held together with command strips and sheer willpower. 

My initial idea was to use this [hall effect sensor](https://www.littelfuse.com/assetdocs/littelfuse-hall-effect-sensors-55100-datasheet?assetguid=6d69d457-770e-46ba-9998-012c5e0aedd7) to make the lightsaber turn on and off based on if it was extended. However, I neglected to realize that the filament LED strip I used would get caught in the sections of the blade. So, it is now permanently extended. Maybe I will figure it out in version 2. 

[Lightsaber Demo Video](https://youtube.com/shorts/LEdGR2bHXDM?feature=share)
#### Hardware:
[Teensy 3.5 MCU](https://www.pjrc.com/store/teensy35.html)
-  I used the built in SD card reader to hold the WAV files.

  

[MAX98357A I2S 3W Class D Amplifier Breakout](https://www.adafruit.com/product/3006)

[TP4056 USB-C Lithium Battery Charger](https://www.amazon.com/HiLetgo-Lithium-Charging-Protection-Functions/dp/B07PKND8KG)

[Flexible Filament LED Strip](https://www.amazon.com/dp/B0CDWZB5T6?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)

#### Software:
I wrote a simple Arduino script. 

#### Files:
[Original Lightsaber file I modified](https://www.thingiverse.com/thing:4857992)

Honestly, you don't want to see my awful CAD files for the extra stuff I added. Just know that it all came together somehow. 

