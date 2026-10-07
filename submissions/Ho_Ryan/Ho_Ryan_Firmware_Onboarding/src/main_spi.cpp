#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"


LEDController led(BMEConstants::LED_PIN);
unsigned long lastRead = 0;

void setup() {
    Serial.begin(115200);
    led.begin();

    BMESPIInterface::create();
    if (!BMESPIInterface::instance().begin()) {
        Serial.println(F("BME280 not found (SPI). Check wiring."));
        while (true) delay(10);
    }
}

void loop() {
    unsigned long now = millis();
    if (now - lastRead >= BMEConstants::READ_EVERY_MS) {
        lastRead = now;
        float t = BMESPIInterface::instance().readTemperature();
        led.setTemperature(t);

        Serial.print(F("SPI  "));
        Serial.print(t);
        Serial.print(F(" C -> "));
        Serial.print(led.interval());
        Serial.println(F(" ms"));
    }
    led.update();
}