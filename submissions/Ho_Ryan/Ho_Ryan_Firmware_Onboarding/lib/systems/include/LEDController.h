#pragma once
#include <Arduino.h>
#include "BMEConstants.h"

class LEDController
{
public:
    explicit LEDController(uint8_t pin) : _pin(pin) {}

    void begin();
    void setTemperature(float tempC);  
    void update();                     

    unsigned long interval() const { return _interval; }

private:
    uint8_t       _pin;
    unsigned long _interval   = BMEConstants::SLOW_MS;
    unsigned long _lastToggle = 0;
    bool          _state      = false;
};