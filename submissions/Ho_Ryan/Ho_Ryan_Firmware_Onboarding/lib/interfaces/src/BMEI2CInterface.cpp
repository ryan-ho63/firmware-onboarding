#include "BMEI2CInterface.h"

bool BMEI2CInterfaceImpl::begin()
{
    return _bme.begin(BMEConstants::BME_I2C_ADDR);
}

float BMEI2CInterfaceImpl::readTemperature()
{
    return _bme.readTemperature();
}