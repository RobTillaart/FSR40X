#pragma once
//
//    FILE: FSR40X.h
//  AUTHOR: Rob Tillaart
//    DATE: 2026-04-16
// VERSION: 0.1.0
// PURPOSE: Arduino library for FSR40X Force Sensing Resistors.
//     URL: https://github.com/RobTillaart/FSR40X


#include "Arduino.h"

#define FSR40X_LIB_VERSION         (F("0.1.0"))


class FSR40X
{
  public:
  //  CONSTRUCTOR
  FSR40X(uint8_t ADCpin, float voltage, uint16_t steps);

  //  initial calibration of resistor used in Ohm
  //  default R = 10 kOhm.
  bool    begin(float resistor = 10000);
  //  adjust voltage of ADC runtime
  bool    setVoltage(float voltage);

  //  READ
  //  raw converted to Newtons
  float   readNewton(uint8_t times = 1);
  //  raw converted to kilogram force
  float   readKgf(uint8_t times = 1);
  float   readFSR(uint8_t times = 1);  //  raw FSR in Ohm
  float   readRaw(uint8_t times = 1);  //  raw ADC in steps

  protected:
  uint8_t  _adcPin;
  float    _voltage;
  uint16_t _steps;
  float    _voltsPerStep;
  float    _resistor;
};


//  DERIVED CLASSES

class FSR400 : public FSR40X
{
  public:
  FSR400(uint8_t ADCpin, float voltage, uint16_t steps);
};


class FSR402 : public FSR40X
{
  public:
  FSR402(uint8_t ADCpin, float voltage, uint16_t steps);
};


class FSR404 : public FSR40X
{
  public:
  FSR404(uint8_t ADCpin, float voltage, uint16_t steps);
};


class FSR406 : public FSR40X
{
  public:
  FSR406(uint8_t ADCpin, float voltage, uint16_t steps);
};


class FSR408 : public FSR40X
{
  public:
  FSR408(uint8_t ADCpin, float voltage, uint16_t steps);
};


//  -- END OF FILE --


