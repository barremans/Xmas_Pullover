# Animated Xmas pullover
[![N|Solid](https://img.shields.io/badge/platform-Arduino-blue)](https://img.shields.io/badge/platform-Arduino-blue) [![N|Solid](https://img.shields.io/badge/Model-ESP8266-yellowgreen)](https://img.shields.io/badge/Model-ESP8266-yellowgreen) [![N|Solid](https://img.shields.io/badge/Release-V%204.0.1-red)](https://img.shields.io/badge/Release-V%204.0.1-red) [![N|Solid](https://img.shields.io/badge/Type-Wearable-blueviolet)](https://img.shields.io/badge/Type-Wearable-blueviolet) [![N|Solid](https://img.shields.io/badge/Library-FASTLED-informational)](https://img.shields.io/badge/Library-FASTLED-informational)   



With this project we will make an animated pullover for the Christmas season.
Controlled by a 32x8 LED matrix and a wemos D1 mini.
The sprites are saved seperated in header files(*.h).

## Preparations

### Software

To create the sprites, it is best to use the free LEDMatrixStudio from maximumoctopus

### Hardware
D1 mini
LED matrix 32x 8
D1 mini battery shield
1x 1000µF Capacitor
1x100µF Capacitor
LiPo battery 3.7V
On - OFF switch
3 pin jumper
500 Ohm resistance


## _LEDMatrixStudio_
The software can be found at [Sourceforge.net](https://sourceforge.net/projects/led-matrix-studio/ "Sourceforge.net").

Beware there are different types of matrix LED direction options.
- ZIG ZAG (left to right and top to bottom)
- Alternating ZIG ZAG (left to right then right to left and top to bottom).

**Be sure to check this!**

### Tips for making sprites.

Work with layers.
Html use safe colors

When exporting it is VERY important to set the follow:

- SOURCE
Row's choice
To choose the direction, eg. Top to bottom and alternate Left/Right

- FRAME(S)
export each frame separately!
Example
frame(s) 1 to 1
row(s) 1 to 8

- RGB COLOR FORMAT
Usually the default is RGB

- RGB COLOR FORMAT
Usually the default is RGB

- EXPORT FORMAT
C-style (1 dimensional)

- NUMBER FORMAT
Hex

- NUMBER GROUPING
32 Bit

####CODE
You can then copy the code in the right window.

The code must be changed!

The following is needed to be changed:
- change uint32_t to const long
- name of the array: ledarray[] to own ascending name
- Add PROGMEM after the array


The code should be structured as follows:

*const long Xmas001[] PROGMEM = {
  0x00000000, 0x00000000, // 1
};*

## _Arduino_
#### Library(s)
[- FastLED](http://fastled.io/ "- FastLED")

#### Code 
The code is fairly basic.
- The matrix is ​​controlled by the RX pin.
- Depending on the size of the LED matrix, the number of LEDs will have to be adjusted.

- The brightness is set to 50% so as not to consume too much power.

- The function RUNMATRIX will fetch frame by frame in the xmas.h file.
With this function one can create multiple animations and choose which one to use.
