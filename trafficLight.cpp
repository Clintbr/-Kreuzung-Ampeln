#include "trafficLight.hpp"
#include "lightAction.hpp"

// Konstruktor: Initialisiert die State-Machine
void TrafficLight_ctor(TrafficLight* sm) {
    sm->stateId = TrafficLight_StateId_ROT; // Startzustand ist Rot
    sm->vars.gruenAnfrage = false;         // Standardmäßig keine Fußgängeranfrage
}

// Startet die Ampel mit der Initialkonfiguration
void TrafficLight_start(TrafficLight* sm) {
    pinMode(sm->vars.ledRot, OUTPUT);
    pinMode(sm->vars.ledGelb, OUTPUT);
    pinMode(sm->vars.ledGruen, OUTPUT);
    pinMode(sm->vars.btnRequest, INPUT_PULLUP);
    digitalWrite(sm->vars.ledRot, HIGH);  // Startet mit Rotlicht
}

// Verarbeitet die Ereignisse der State-Machine
void TrafficLight_dispatch_event(TrafficLight* sm, TrafficLight_EventId eventId) {
    sm -> vars.gruenAnfrage = (digitalRead(sm ->vars.btnRequest) == LOW);
    switch (sm->stateId) {
        case TrafficLight_StateId_ROT:
            if (eventId == TrafficLight_EventId_TICK && sm->vars.gruenAnfrage == true) {
                digitalWrite(sm->vars.ledRot, LOW);
                digitalWrite(sm->vars.ledGelb, HIGH);
                sm->stateId = TrafficLight_StateId_GELB;
                turnOffRedLight();
                turnOnYellowLight();
            }
            break;

        case TrafficLight_StateId_GELB:
            if (eventId == TrafficLight_EventId_TICK) {
                digitalWrite(sm->vars.ledGelb, LOW);
                digitalWrite(sm->vars.ledGruen, HIGH);
                sm->stateId = TrafficLight_StateId_GRUEN;
                turnOffYellowLight();
                turnOnGreenLight();
            }
            break;

        case TrafficLight_StateId_GRUEN:
            if (eventId == TrafficLight_EventId_TICK) {
                digitalWrite(sm->vars.ledGruen, LOW);
                digitalWrite(sm->vars.ledRot, HIGH);
                sm->vars.gruenAnfrage = false; // Anfrage zurücksetzen
                sm->stateId = TrafficLight_StateId_ROT;
                turnOffGreenLight();
                turnOnRedLight();
            }
            break;

        default:
            break;
    }
}
