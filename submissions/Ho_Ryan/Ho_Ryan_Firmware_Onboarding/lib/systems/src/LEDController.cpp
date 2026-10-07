#include "LEDController.h"

void LEDController::begin() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void LEDController::setTemperature(float tempC) {
    float t = constrain(tempC, BMEConstants::TEMP_MIN_C, BMEConstants::TEMP_MAX_C);
    float f = (t - BMEConstants::TEMP_MIN_C) / (BMEConstants::TEMP_MAX_C - BMEConstants::TEMP_MIN_C);
    _interval = BMEConstants::SLOW_MS - (unsigned long)(f * (BMEConstants::SLOW_MS - BMEConstants::FAST_MS));
}

void LEDController::update() {
    unsigned long now = millis();
    if (now - _lastToggle >= _interval) {
        _lastToggle = now;
        _state = !_state;
        digitalWrite(_pin, _state);
    }
}