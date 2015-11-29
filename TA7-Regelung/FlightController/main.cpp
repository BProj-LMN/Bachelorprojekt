/* 
 * File:   main.cpp
 * Author: Robin
 *
 * Created on 19. November 2015, 13:54
 */

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <fstream>

#include  "PID_Regler.h"
#include "defines_Regler.h"
#include "Trajectory.h"
#include "UserInterface.h"
#include "SerielleUebertragung.h"

using namespace std;
double istX, istY, istZ;
int landen = 0;
int Error = 0;

//Regler für Vor Zurück erzeugen Grenzwerte für Regelung von -127 bis 127
PID_Regler reglerX = PID_Regler(-REGELMAX / 2, REGELMAX / 2);
//Regler für Rechts Links erzeugen Grenzwerte für Regelung von -127 bis 127
PID_Regler reglerY = PID_Regler(-REGELMAX / 2, REGELMAX / 2);
//Regler für Hoch Runter erzeugen Grenzwerte für Regelung von 0 bis 254
PID_Regler reglerZ = PID_Regler(0, REGELMAX);
//Trajektorien Klasse erzeugen
Trajectory trajec = Trajectory();
//UserInterface erzeugen
UserInterface UI = UserInterface(&Error);
//Serielle Schnittstelle erzeugen
SerielleUebertragung Serial = SerielleUebertragung();

void Sollwertvorgabe() {
    //nächsten Checkpoint zuweisen
    reglerX.setSoll(trajec.getNextCheckpointX());
    reglerY.setSoll(trajec.getNextCheckpointY());
    reglerZ.setSoll(trajec.getNextCheckpointZ());
}

void Startprozedur() {
    //Um eine Verbindung mit dem Copter aufzubauen muss der Schub einmal auf Maximalausschlag und wieder zurück 
    cout << "Mit dem Copter Verbindung aufbauen" << endl;
    Serial.HochRunter(REGELMAX);
    Serial.Serialwrite();
    while (!UI.EnterGedrueckt()); //Warten auf Enter
    Serial.HochRunter(0);
    Serial.Serialwrite();
    cout << "Rechner ist mit Copter verbunden" << endl;
}

int main(int argc, char** argv) {
    //Regler koeffizienten zuweisen
    reglerX.setfactors(KPXY, KIXY, KDXY, 1);
    reglerY.setfactors(KPXY, KIXY, KDXY, 1);
    reglerZ.setfactors(KPZ, KIZ, KDZ, 1);
    //Sollwerte einlesen
    while (!UI.sollEinlesen()&&(Error == 0));
    //Wartet solange bis alle werte eingelesen sind
    //Istwerte einlesen

    //Trajectorie Checkpoints berechnen
    trajec.calcCheckpoints(istX, istY, istZ, UI.getX(), UI.getY(), UI.getZ()); // Checkpoints berrechnen
    cout << "Checkpoints berechnet" << endl;
    // erster checkpoint als soll vorgeben
    Sollwertvorgabe();
    // Startprozedur
    Startprozedur();
    //Regelung starten
    cout << "Um den Flug zu starten Enter betaetigen" << endl;
    while (!UI.EnterGedrueckt()&&(Error == 0)) {
        if (UI.LeertasteGedrueckt()) {
            Error = 1;
        }
    }
    //Warten auf Enter
    cout << "Copter Regelung ist gestartet" << endl;
    cout << "Um den Copter landen zulassen Leertaste betaetigen" << endl;
    cout << "oder Enter betaetigen um neue Sollwerte zu definieren" << endl;
    do {
        if (UI.LeertasteGedrueckt()) {
            Error = 1;
        }
        //Istwerte einlesen

        //wenn der aktuelle Checkpoint erreicht ist
        if (trajec.checkpointReached(istX, istY, istZ)) {
            trajec.nextCheckpoint(); // nächsten Checkpoint auswählen
            Sollwertvorgabe(); //neuen Checkpoint dem Regler übergeben
            cout << "Checkpoint wurde erreicht" << endl;
        } else;
        //Regeln
        //Übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
        Serial.HochRunter((int) reglerZ.getControlValue(istZ));
        Serial.RechtLinks((int) reglerY.getControlValue(istY));
        Serial.VorZurueck((int) reglerX.getControlValue(istX));
        //Regelwerte an die Fernsteuerung senden
        Serial.Serialwrite();
        //Wenn Enter betätigt wird können neue Sollwerte definiert werden dabei soll der Copter die aktuelle position halten
        if (UI.EnterGedrueckt()) {
            //Istwerte einlesen

            //Aktuelle Position als Sollwert vorgeben
            reglerX.setSoll(istX);
            reglerY.setSoll(istX);
            reglerZ.setSoll(istX);

            cout << "Neue Sollwerte definieren" << endl;
            //Sollwerte einlesen bis alle vorhanden sind
            while (!UI.sollEinlesen()&&(Error == 0)) {
                //Istwerte einlesen

                //Übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
                Serial.HochRunter((int) reglerZ.getControlValue(istZ));
                Serial.RechtLinks((int) reglerY.getControlValue(istY));
                Serial.VorZurueck((int) reglerX.getControlValue(istX));
                //Regelwerte an die Fernsteuerung senden
                Serial.Serialwrite();
            }
            //neue Trajektorie wird berrechnet
            trajec.calcCheckpoints(istX, istY, istZ, UI.getX(), UI.getY(), UI.getZ());
            cout << "Checkpoints wurden berechnet" << endl;
            cout << "Um Copter weiter fliegen zu lassen Enter betaetigen" << endl;
            //Wartet bis Enter betätigt wird bevor der Copter wieder losfliegt
            while (!UI.EnterGedrueckt()&&(Error == 0)) {
                //Istwerte einlesen

                //Übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
                Serial.HochRunter((int) reglerZ.getControlValue(istZ));
                Serial.RechtLinks((int) reglerY.getControlValue(istY));
                Serial.VorZurueck((int) reglerX.getControlValue(istX));
                //Regelwerte an die Fernsteuerung senden
                Serial.Serialwrite();
            }
        }
        //Um Copter landen zu lassen Leertaste betätigen
    } while ((!UI.LeertasteGedrueckt())&&(Error == 0));
    if (Serial.HochAktuell()!=0) {
        //Landenprozedur
        cout << "Copter soll landen" << endl;
        Serial.RechtLinks(REGLEROFFSETRL); //Stabilen Wert vorgeben
        Serial.VorZurueck(REGLEROFFSETVZ); //Stabilen Wert vorgeben
        for (landen = 0x90; landen > 0; landen--) {
            Serial.HochRunter(landen);
            Sleep(60);
            Serial.Serialwrite();
        }
        cout << "Copter ist gelandet" << endl;
    } else {
        cout<<"Flug wurde abgebrochen"<<endl;
    }
    return 0;
}

