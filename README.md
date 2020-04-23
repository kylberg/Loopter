# Loopter

## Introduction
DIY motorized camera slider that also have timelapse capabilities. Arduino-based with simple controls.

### HW parts 

* Arduino FIO/Mega/Duo
* Stepper motor 28BYJ-48 5V unipolar, https://www.electrokit.com/produkt/stegmotor-28byj-48-med-drivkort-uln2003a/
* Stepper motor driver ULN2003A, https://www.electrokit.com/produkt/stegmotor-28byj-48-med-drivkort-uln2003a/ (or 4988?)
* OLED display 5V over SPI, (Adafruit Monochrome 0.96" 128x64 OLED graphic display) Gives us 8 rows of text. https://www.adafruit.com/product/326
* Releay (Zettler az850P2-3)
* Micro switch V4, https://www.electrokit.com/produkt/mikrobrytare-v4-on-on-simulerad-rullarm/

### Libs

* TinyStepper_28BYJ_48
* s

## 

OLED 5 digital pins
Stepper motor control 4 digital pins

## Set up environment

Add additionl url to find the Qduino board via Arduino Board Manager.    

"arduino.additionalUrls": "https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json",


https://github.com/sparkfun/Arduino_Boards