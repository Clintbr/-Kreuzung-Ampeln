# Umsetzung von Kreuzungsampeln

Dieses Projekt wurde im Rahmen der Veranstaltung **Technische Informatik 2** erstellt.  
Ziel ist die Simulation und Implementierung einer **Ampelsteuerung für eine Kreuzung** mithilfe von Arduino (C++/INO) und der Simulationsumgebung **Wokwi**.

---

## 🚦 Projektbeschreibung

Das Programm steuert mehrere Ampeln einer Kreuzung nach einem festgelegten Ablaufplan.  
Dabei werden typische Verkehrslichtphasen berücksichtigt:

- **Rot → Rot/Gelb → Grün → Gelb → Rot**
- Sicherstellung, dass sich die Fahrtrichtungen nicht gegenseitig blockieren
- Modularer Aufbau durch getrennte Klassen und Header-Dateien (`trafficLight`, `lightAction`)

---
## ⚙️ Voraussetzungen

Um das Projekt auszuführen, benötigst du:

- [Arduino IDE](https://www.arduino.cc/en/software) oder [PlatformIO](https://platformio.org/)  
- Optional: [Wokwi Online-Simulator](https://wokwi.com/) (für schnelle Tests)  
- Grundkenntnisse in **C++ und Arduino-Programmierung**

---

## ▶️ Installation & Nutzung

1. **Repository klonen**:
   ```bash
   git clone <repository-url>
   cd Technische_Inf_2

2. **In Arduino IDE öffnen**:

Die Datei sketch.ino öffnen

Das passende Board (z. B. Arduino UNO) auswählen

Kompilieren und hochladen

3. **Simulation in Wokwi starten**:

diagram.json und wokwi-project.txt in Wokwi importieren

Start drücken und den Ampelablauf beobachten

## ✨ Features

- Realistische Ampelschaltung für Kreuzungen

- Modularer Aufbau (leicht erweiterbar für mehr Ampeln)

- Simulation in Wokwi oder direkt auf echter Arduino-Hardware

- Klar strukturierter Code mit Klassen für Ampeln und Lichtaktionen

## 📖 Weiterentwicklung

Mögliche Erweiterungen:

- Fußgängerampeln mit Taster

- Adaptive Steuerung (Sensoren / Verkehrsfluss)

- Erweiterung auf mehrspurige Kreuzungen

👨‍💻 Autor

Dieses Projekt wurde im Rahmen von Technische Informatik 2 erstellt.
Fachbereich: MNI
Semester: 2
Jahr: 2024

📜 Lizenz

Dieses Projekt ist frei nutzbar für Bildungszwecke.
Eine kommerzielle Nutzung ist nur mit Zustimmung des Autors erlaubt.
