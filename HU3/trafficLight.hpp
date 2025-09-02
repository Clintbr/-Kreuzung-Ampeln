
#ifndef TRAFFIC_LIGHT_HPP
#define TRAFFIC_LIGHT_HPP
#include "Arduino.h"

// Zustände der Ampel
typedef enum {
    TrafficLight_StateId_ROT,   // Rotlicht aktiv
    TrafficLight_StateId_GELB,  // Gelblicht aktiv
    TrafficLight_StateId_GRUEN  // Grünlicht aktiv
} TrafficLight_StateId;

// Events der Ampel
typedef enum {
    TrafficLight_EventId_TICK   // Zeitliches Ereignis
} TrafficLight_EventId;

// Struktur für Variablen der State-Machine
typedef struct {
    int ledRot;        // Pin für die rote LED
    int ledGelb;       // Pin für die gelbe LED
    int ledGruen;      // Pin für die grüne LED
    int btnRequest;    // Pin für die Fußgängeranfrage
    bool gruenAnfrage; // Status der Fußgängeranfrage
} TrafficLight_Variables;

// Struktur für die State-Machine
typedef struct {
    TrafficLight_StateId stateId; // Aktueller Zustand der Ampel
    TrafficLight_Variables vars;  // Variablen für die Ampelsteuerung
} TrafficLight;

// Funktionen der State-Machine
void TrafficLight_ctor(TrafficLight* sm);
void TrafficLight_start(TrafficLight* sm);
void TrafficLight_dispatch_event(TrafficLight* sm, TrafficLight_EventId eventId);

#endif