# Nevma
A USB gadget to transform your gestures to keyboard and mouse events.

## Overview
Nevma (means "gesture" in Greek) is a simple to build, program and use device that translates your hand gestures into keyboard and mouse input. Just plug it in your USB port and magically wave through your presentations, documents, pictures, songs and the like.

## How does it work
Nevma implements two basic functions. Gesture recognition and keyboard and mouse event generation over USB. The former is realized through the [APDS-9960](https://learn.sparkfun.com/tutorials/apds-9960-rgb-and-gesture-sensor-hookup-guide) sensor while the latter by utilizing the USB HID capabilities of the ATMega32U4 chip.

Nevma can by default recognize a plethora of gestures; swipe left, right, up, down, and moving the hand closer or further from the sensor, using the [APDS-9960 library](https://github.com/sparkfun/SparkFun_APDS-9960_Sensor_Arduino_Library) by Sparkfun.

## Components
* Nevma board PCB
* [Mini SS Micro ATMEGA32U4](https://www.aliexpress.com/item/New-Arrival-Mini-SS-Micro-ATMEGA32U4-Pro-Micro-Module-Board-Compatible-For-Arduino/32777411276.html)
* [APDS-9960 module](https://www.aliexpress.com/item/GY-9960LLC-APDS-9960-RGB-and-Gesture-Sensor-Module-I2C-Breakout-for-Arduino/32746930049.html)

## Media
*  [Nevma: Gesture control for the masses](https://platis.solutions/blog/2017/11/26/nevma-gesture-control-for-the-masses)
