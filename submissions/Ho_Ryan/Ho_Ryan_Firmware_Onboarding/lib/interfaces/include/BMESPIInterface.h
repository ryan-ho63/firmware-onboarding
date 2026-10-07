#pragma once
#include <SPI.h>
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterfaceImpl {
    public:

        BMESPIInterfaceImpl() = default;

        bool  begin();
        float readTemperature();

    private:

        Adafruit_BME280 _bme{BMEConstants::BME_CS_PIN};   

};
using BMESPIInterface = etl::singleton<BMESPIInterfaceImpl>;