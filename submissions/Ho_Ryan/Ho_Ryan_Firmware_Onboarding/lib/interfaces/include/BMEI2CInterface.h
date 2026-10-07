#pragma once
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterfaceImpl {
    public:

        BMEI2CInterfaceImpl() = default;

        bool  begin();
        float readTemperature();

    private:

        Adafruit_BME280 _bme;            
};
using BMEI2CInterface = etl::singleton<BMEI2CInterfaceImpl>;