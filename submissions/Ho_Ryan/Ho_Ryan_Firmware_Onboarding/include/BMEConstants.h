#pragma once
#include <Arduino.h>

namespace BMEConstants {
    constexpr uint8_t BME_CS_PIN = 10;
    constexpr uint8_t BME_I2C_ADDR = 0x76;
    constexpr uint8_t LED_PIN = 8;

    constexpr float TEMP_MIN_C = 20.0f;      
    constexpr float TEMP_MAX_C = 35.0f;      
    constexpr unsigned long SLOW_MS = 1000;
    constexpr unsigned long FAST_MS = 80;

    constexpr unsigned long READ_EVERY_MS = 500;
}