#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"


LEDController led(BMEConstants::LED_PIN);
unsigned long lastRead = 0;

void setup() {
    Serial.begin(115200);
    led.begin();

    BMEI2CInterface::create();
    if (!BMEI2CInterface::instance().begin()) {
        Serial.println(F("BME280 not found (I2C). Check wiring/address."));
        while (true) delay(10);
    }
}

void loop() {
    unsigned long now = millis();
    if (now - lastRead >= BMEConstants::READ_EVERY_MS) {
        lastRead = now;
        float t = BMEI2CInterface::instance().readTemperature();
        led.setTemperature(t);

        Serial.print(F("I2C  "));
        Serial.print(t);
        Serial.print(F(" C -> "));
        Serial.print(led.interval());
        Serial.println(F(" ms"));
    }
    led.update();
}