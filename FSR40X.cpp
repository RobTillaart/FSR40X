//
//    FILE: FSR40X.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2026-04-16
// VERSION: 0.1.0
// PURPOSE: Arduino library for FSR40X Force Sensing Resistors.
//     URL: https://github.com/RobTillaart/FSR40X


#include "FSR40X.h"


FSR40X::FSR40X(uint8_t ADCpin, float voltage, uint16_t steps)
{
  _adcPin  = ADCpin;
  _voltage = voltage;
  _steps   = steps;
  _voltsPerStep = voltage / _steps;
  _resistor = 3000;
}

bool FSR40X::begin(float resistor)
{
  _resistor = resistor;
  return true;
}

bool FSR40X::setVoltage(float voltage)
{
  if (_voltage <= 1.0) return false;
  _voltage = voltage;
  _voltsPerStep = _voltage / _steps;
  return true;
}


/////////////////////////////////////////////
//
//  READ
//
float FSR40X::readNewton(uint8_t times)
{
  //  See FSR40X_formula_test.ino
  //
  //  MAGIC FORMULA based upon datasheet points on page 3.
  //  MAGIC numbers configurable?
  float FSR = readFSR(times) * 0.001;  //  in kOhm.
  float Fg = 26.9117452575 * pow(FSR, -1.114166333);
  return Fg;

  //  approximation, (from google).
  //  is faster and less exact as it has a jump in the graph.
  //
  //  float FSR = readFSR(times);     //  in Ohm
  //  float conductance = 1e6 / FSR;  //  in micro mho (micro Siemens)
  //  float Fg = 0;
  //  if (conductance < 1000) Fg = conductance * (1.0 / 80.0);
  //  else Fg = conductance * (1.0 / 30.0);
  //  return Fg;
}

float FSR40X::readKgf(uint8_t times)
{
  return readNewton(times) * (1.0 / 9.80655);
}

float FSR40X::readFSR(uint8_t times)
{
  float raw = readRaw(times);
  //  < 1% essentially zero
  if (raw < 10.0) return 50E6;  //  50 MOhm (max)

  float VOUT = (raw * _voltage) / _steps;
  float FSR = (_resistor * _voltage)/ VOUT - _resistor;
  return FSR;
}

float FSR40X::readRaw(uint8_t times)
{
  if (times == 0) times = 1;
  uint32_t raw = 0;
  for (uint8_t i = 0; i < times; i++)
  {
    raw += analogRead(A0);
  }
  return (1.0 * raw) / times;
}



///////////////////////////////////////////////
//
//  DERIVED CLASSES
//
FSR400::FSR400(uint8_t ADCpin, float voltage, uint16_t steps)
       :FSR40X(ADCpin, voltage, steps)
{
};

FSR402::FSR402(uint8_t ADCpin, float voltage, uint16_t steps)
       :FSR40X(ADCpin, voltage, steps)
{
};


FSR404::FSR404(uint8_t ADCpin, float voltage, uint16_t steps)
       :FSR40X(ADCpin, voltage, steps)
{
};


FSR406::FSR406(uint8_t ADCpin, float voltage, uint16_t steps)
       :FSR40X(ADCpin, voltage, steps)
{
};


FSR408::FSR408(uint8_t ADCpin, float voltage, uint16_t steps)
       :FSR40X(ADCpin, voltage, steps)
{
};


//  -- END OF FILE --

