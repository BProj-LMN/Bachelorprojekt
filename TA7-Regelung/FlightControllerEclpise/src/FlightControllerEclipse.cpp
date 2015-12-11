//============================================================================
// Name        : FlightControllerEclipse.cpp
// Author      : Kai Robin M�ller
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
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
#include "TrajectoryClass.h"
#include "UserInterface.h"
#include "Wrapper_Steuerung.h"

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
Trajectory_Class Trajectory = Trajectory_Class();
//UserInterface erzeugen
UserInterface UI = UserInterface(&Error);
//Serielle Schnittstelle erzeugen
Wrapper_Steuerung Steuerung = Wrapper_Steuerung();

void Sollwertvorgabe() {
    //nächsten Checkpoint zuweisen
    reglerX.setSoll(Trajectory.getNextCheckpointX());
    reglerY.setSoll(Trajectory.getNextCheckpointY());
    reglerZ.setSoll(Trajectory.getNextCheckpointZ());
}

void Startprozedur() {
    //Um eine Verbindung mit dem Copter aufzubauen muss der Schub einmal auf Maximalausschlag und wieder zurück
    cout << "Mit dem Copter Verbindung aufbauen" << endl;
    Steuerung.HochRunter(REGELMAX);
    Steuerung.Steuern();
    while (!UI.EnterGedrueckt()); //Warten auf Enter
    Steuerung.HochRunter(0);
    Steuerung.Steuern();
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
    Trajectory.calcCheckpointsB(istX, istY, istZ, UI.getX(), UI.getY(), UI.getZ()); // Checkpoints berechnen
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
    cout << "Um den Copter landen zu lassen Leertaste betaetigen" << endl;
    cout << "oder Enter betaetigen um neue Sollwerte zu definieren" << endl;
    while ((!UI.LeertasteGedrueckt())&&(Error == 0)) {
        if (UI.LeertasteGedrueckt()) {
            Error = 1;
        }
        //Istwerte einlesen

        //wenn der aktuelle Checkpoint erreicht ist
        if (Trajectory.checkpointReached(istX, istY, istZ)) {
            Trajectory.nextCheckpoint(); // nächsten Checkpoint auswählen
            Sollwertvorgabe(); //neuen Checkpoint dem Regler übergeben
            cout << "Checkpoint wurde erreicht" << endl;
        } else;
        //Regeln
        //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
        Steuerung.HochRunter((int) reglerZ.getControlValue(istZ));
        Steuerung.RechtLinks((int) reglerY.getControlValue(istY));
        Steuerung.VorZurueck((int) reglerX.getControlValue(istX));
        //Regelwerte an die Fernsteuerung senden
        Steuerung.Steuern();
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

                //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
                Steuerung.HochRunter((int) reglerZ.getControlValue(istZ));
                Steuerung.RechtLinks((int) reglerY.getControlValue(istY));
                Steuerung.VorZurueck((int) reglerX.getControlValue(istX));
                //Regelwerte an die Fernsteuerung senden
                Steuerung.Steuern();
            }
            //neue Trajektorie wird berrechnet
            Trajectory.calcCheckpointsA(istX, istY, istZ, UI.getX(), UI.getY(), UI.getZ());
            cout << "Checkpoints wurden berechnet" << endl;
            cout << "Um Copter weiter fliegen zu lassen Enter betaetigen" << endl;
            //Wartet bis Enter betätigt wird bevor der Copter wieder losfliegt
            while (!UI.EnterGedrueckt()&&(Error == 0)) {
                //Istwerte einlesen

                //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
                Steuerung.HochRunter((int) reglerZ.getControlValue(istZ));
                Steuerung.RechtLinks((int) reglerY.getControlValue(istY));
                Steuerung.VorZurueck((int) reglerX.getControlValue(istX));
                //Regelwerte an die Fernsteuerung senden
                Steuerung.Steuern();
            }
        }
        //Um Copter landen zu lassen Leertaste bet�tigen
    }
    if (Steuerung.HochAktuell()!=0) {
        //Landenprozedur
        cout << "Copter soll landen" << endl;
        Steuerung.RechtLinks(REGLEROFFSETRL); //Stabilen Wert vorgeben
        Steuerung.VorZurueck(REGLEROFFSETVZ); //Stabilen Wert vorgeben
        for (landen = 0x90; landen > 0; landen--) {
            Steuerung.HochRunter(landen);
            Sleep(60);
            Steuerung.Steuern();
        }
        cout << "Copter ist gelandet" << endl;
    } else {
        cout<<"Flug wurde abgebrochen"<<endl;
    }
    return 0;
}

