#include "BMESPIInterface.h"

bool BMESPIInterfaceImpl::begin() {
    return _bme.begin();             
}

float BMESPIInterfaceImpl::readTemperature() {
    return _bme.readTemperature();   
}