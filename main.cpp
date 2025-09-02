#include "Arduino.h"
#include "trafficLight.hpp"

// Definition der Pins für Ampel 1
#define LED_RED1     2
#define LED_YELLOW1  4
#define LED_GREEN1   5

// Definition der Pins für Ampel 2
#define LED_RED2     21
#define LED_YELLOW2  22
#define LED_GREEN2   23

// Pins für die Fußgängeranforderung
#define BTN_REQ1     34  // Taster für Fußgängeranfrage Ampel 1
#define BTN_REQ2     35  // Taster für Fußgängeranfrage Ampel 2

// Zwei Ampel-Objekte erstellen
TrafficLight sm1;  // Ampel 1
TrafficLight sm2;  // Ampel 2

void printMenu() {
  Serial.println("Wählen Sie einen Eintrag per Eingabe der Nummer:");
  Serial.println("1. Auslesen des Leucht-Zustands einer Ampel");
  Serial.println("2. Auslesen des Request-Zustands einer Ampel");
  Serial.println("3. Setzen des Requests bei einer Ampel");
  Serial.print("Auswahl: ____ \n"); // Eingabeaufforderung
}

void signalmenu(TrafficLight* sm) {
  Serial.println("Setzen Sie das Signal auf *false oder *true:");
  Serial.println("1. true");
  Serial.println("2. false");
  Serial.print("Auswahl:____\n");
  delay(5000);
  if(Serial.available() > 0) { 
    char signal = (char)Serial.read();
    Serial.print("Ihre Eingabe ist: ");
    Serial.println(signal);
    switch(signal) {
      case '1':
          sm->vars.gruenAnfrage = true;
          Serial.print("Signal auf true gesezt");
          break;
      case '2':
          sm->vars.gruenAnfrage = false;
          Serial.print("Signal auf false gesezt");
          break;
      default:
          Serial.print("falsche Eingabe");
          break;
    }
  }
}

void ampelAuslesen(TrafficLight* sm) {
  switch(sm->stateId) {
    case TrafficLight_StateId_ROT:
      Serial.print("rote Ampel leuchtet");
      break;
    case TrafficLight_StateId_GELB:
      Serial.print("gelbe Ampel leuchtet");
      break;
    case TrafficLight_StateId_GRUEN:
      Serial.print("gruene Ampel leuchtet");
      break;
  }
}

void choice(TrafficLight* sm) {
  Serial.print("Wähle aus:____ \n");
  delay(5000);
    char input = (char)Serial.read();
    Serial.print("Ihre Wahl ist: ");
    Serial.println(input);
    switch(input) {
    case '1':
        Serial.print("stateId: "); 
        ampelAuslesen(sm);
        break;
    case '2':
        Serial.print("request: ");
        Serial.println(sm->vars.gruenAnfrage);
        break;
    case '3':
        if(Serial.available() > 0) {
          delay(1000);
          signalmenu(sm);
        }
        break;
    default:
        Serial.print("falsche Eingabe");
        break;
        
    }
  
}

void setup() {
    Serial.begin(115200);
    while (!Serial) {
         // Warte, bis die serielle Verbindung aktiv ist
    }
    Serial.println("Kommandointerpreter gestartet!");
    printMenu(); // Menü anzeigen
    // Initialisieren der State-Machine für Ampel 1
    TrafficLight_ctor(&sm1);
    sm1.vars.ledRot = LED_RED1;
    sm1.vars.ledGelb = LED_YELLOW1;
    sm1.vars.ledGruen = LED_GREEN1;
    sm1.vars.btnRequest = BTN_REQ1;
    TrafficLight_start(&sm1);

    // Initialisieren der State-Machine für Ampel 2
    TrafficLight_ctor(&sm2);
    sm2.vars.ledRot = LED_RED2;
    sm2.vars.ledGelb = LED_YELLOW2;
    sm2.vars.ledGruen = LED_GREEN2;
    sm2.vars.btnRequest = BTN_REQ2;
    TrafficLight_start(&sm2);
}

void loop() {
    // Fußgängeranfragen für beide Ampeln prüfen
    sm1.vars.gruenAnfrage = (digitalRead(sm1.vars.btnRequest) == LOW);
    sm2.vars.gruenAnfrage = (digitalRead(sm2.vars.btnRequest) == LOW);

    // Zustandsverarbeitung für beide Ampeln
    while(sm1.vars.gruenAnfrage == true) {
      TrafficLight_dispatch_event(&sm1, TrafficLight_EventId_TICK);
      printMenu();
      delay(5000);
      choice(&sm1);
      delay(5000);
    }

    while(sm2.vars.gruenAnfrage == true) {
      TrafficLight_dispatch_event(&sm2, TrafficLight_EventId_TICK);
      printMenu();
      if(Serial.available() > 0) {
        delay(1000);
        choice(&sm2);
      }
      delay(5000);
    }

    delay(1000); // Zeitverzögerung von 1 Sekunde
}
