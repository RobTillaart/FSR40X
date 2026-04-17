
[![Arduino CI](https://github.com/RobTillaart/FSR40X/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/FSR40X/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/FSR40X/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/FSR40X/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/FSR40X/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/FSR40X.svg)](https://github.com/RobTillaart/FSR40X/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/FSR40X/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/FSR40X.svg?maxAge=3600)](https://github.com/RobTillaart/FSR40X/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/FSR40X.svg)](https://registry.platformio.org/libraries/robtillaart/FSR40X)


# FSR40X

Arduino library for FSR40X Force Sensing Resistors.


## Description

**Experimental**

This library is to use Force Sensing Resistors of the FSR400 series.
Main goal of the library is to convert a raw ADC voltage to Newtons
or kilogram force.
The accuracy of the sensors is limited (~5% ??) and thus only
gives an **indication** of the force applied.

The library has (derived) classes for the FSR400, FSR402, FSR404, FSR406, FSR408.
Currently these are wrappers and are identical to the base class FSR40X.
In the future they might have specific functions.


|  type    |  description   | notes  |
|:--------:|:---------------|:-------|
|  FSR40X  |  base class    |
|  FSR400  |  05 mm circle  |
|  FSR402  |  13 mm circle  |
|  FSR404  |  20 mm donut   |  5 mm hole
|  FSR406  |  38 mm square  |
|  FSR408  |  10 mm strip   |  length 50..500 mm

The FSR40X device needs to be in a voltage divider, with the middle connected
to the analog input of your choice.
The non actuated resistance is larger than 10 MΩ.

The library is not tested yet with hardware (need to order).

Feedback as always is welcome.


### Hardware setup

```
Essentially a voltage divider.


  Vcc ----[ FSR ]-----x------[ 10K ]------- GND
                      |
                      |
                  analogPort

```

The 10 K resistor gives a broad range of values.
See datasheet for possible other values and their range.


### Special characters

Ω == Ohm = ALT-234 (Windows)
µ == micro = ALT-0181 (Windows)

### Compatibility

There are no known compatible FSR's at the moment.
Please let me know if you have one.


### Warning

_Do not apply this product to safety protection devices or emergency stop equipment, 
and any other applications that may cause personal injury due to the product's failure._


### Related

- https://github.com/RobTillaart/FSR40X - this library
- https://github.com/RobTillaart/Pressure - unit conversion
- https://github.com/RobTillaart/PrintHelpers - scientific and engineering notation.


https://www.youtube.com/watch?v=dfGScD0UKZM


### Tested

TODO: Test on Arduino UNO and ESP32


### Performance

Performance depends on the ADC / board used.


## Interface

```cpp
#include "FSR40X.h"
```

### Constructor

- **FSR40X()** 
- **bool begin(float resistor)**
- **bool setVoltage(float voltage)** runtime adjustment of the voltage
of the ADC as specified in the constructor.

### Read

- **float readNewton(uint8_t times = 1)** read and converted to Newtons.
- **float readKgf(uint8_t times = 1)** read and converted to kilogram force.
Conversion constant 1 kgf = 9.80655 Newton.
- **float readFSR(uint8_t times = 1)** read resistance of the FSR in Ohm.
- **float readRaw(uint8_t times = 1)** read raw ADC.


## Future

#### Must

- improve documentation
- get hardware to test

#### Should


#### Could

- add examples
- create unit tests if possible
- add readPressure as area is "known" for some derived sensors.

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


