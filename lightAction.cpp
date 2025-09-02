#include <Arduino.h>
#include <stdio.h>
#include <stdbool.h>
#include "lightAction.hpp"

void turnOnYellowLight() {
    Serial.print("Gelbe Ampel eingeschaltet\n ...\n");
}
void turnOffYellowLight() {
    Serial.println("Gelbe Ampel ausgeschaltet \n ->\n");
}

void turnOnGreenLight() {
    Serial.println("Gruene Ampel eingeschaltet \n ...\n");
}

void turnOffGreenLight() {
    Serial.println("Gruene Ampel ausgeschaltet \n ->\n");
}

void turnOnRedLight() {
    Serial.print("Rote Ampel eingeschaltet \n ...\n");
}

void turnOffRedLight() {
    Serial.println("Rote Ampel ausgeschaltet \n ->\n");
}