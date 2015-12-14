/*
 * Flightcontroller.cpp
 *
 *  Created on: 11.12.2015
 *      Author: Marcel
 */

#include "FlightController.h"
#include "stdio.h"
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

FlightControllerClass::FlightControllerClass() {
  //Regler für Vor Zurück erzeugen Grenzwerte für Regelung von -127 bis 127
  reglerX = new PID_Regler(-REGELMAX / 2, REGELMAX / 2);
  //Regler für Rechts Links erzeugen Grenzwerte für Regelung von -127 bis 127
  reglerY = new PID_Regler(-REGELMAX / 2, REGELMAX / 2);
  //Regler für Hoch Runter erzeugen Grenzwerte für Regelung von 0 bis 254
  reglerZ = new PID_Regler(0, REGELMAX);
  //Trajektorien Klasse erzeugen
  Trajectory = new Trajectory_Class();
  //UserInterface erzeugen
  UI = new UserInterface(&Error);
  //Serielle Schnittstelle erzeugen
  Steuerung = new Wrapper_Steuerung();

  istX = 0;
  istY = 0;
  istZ = 0;
  landen = 0;
  Error = 0;

}

FlightControllerClass::~FlightControllerClass() {
  delete reglerX;
  delete reglerY;
  delete reglerZ;
  delete Trajectory;
  delete UI;
  delete Steuerung;
}

void FlightControllerClass::ReglerSollwertvorgabe() {
  //nächsten Checkpoint zuweisen
  reglerX->setSoll(Trajectory->getNextCheckpointX());
  reglerY->setSoll(Trajectory->getNextCheckpointY());
  reglerZ->setSoll(Trajectory->getNextCheckpointZ());
}

void FlightControllerClass::Initialisieren() {
  //Regler koeffizienten zuweisen
  reglerX->setfactors(KPXY, KIXY, KDXY, 1);
  reglerY->setfactors(KPXY, KIXY, KDXY, 1);
  reglerZ->setfactors(KPZ, KIZ, KDZ, 1);
  //Um eine Verbindung mit dem Copter aufzubauen muss der Schub einmal auf Maximalausschlag und wieder zurück
  cout << "Mit dem Copter Verbindung aufbauen" << endl;
  Steuerung->HochRunter(REGELMAX);
  Steuerung->Steuern();
  while (!UI->EnterGedrueckt())
    ; //Warten auf Enter
  Steuerung->HochRunter(0);
  Steuerung->Steuern();
  cout << "Rechner ist mit Copter verbunden" << endl;
}

void FlightControllerClass::Landeprozedur() {
  if (Steuerung->HochAktuell() != 0) {
    //Landenprozedur
    cout << "Copter soll landen" << endl;
    Steuerung->RechtLinks(REGLEROFFSETRL); //Stabilen Wert vorgeben
    Steuerung->VorZurueck(REGLEROFFSETVZ); //Stabilen Wert vorgeben
    for (landen = 0x90; landen > 0; landen--) {
      Steuerung->HochRunter(landen);
      Sleep(60);
      Steuerung->Steuern();
    }
    cout << "Copter ist gelandet" << endl;
  } else {
    cout << "Flug wurde abgebrochen" << endl;
  }

}

void FlightControllerClass::Startprozedur() {

  cout << "Copter Regelung ist gestartet" << endl;
  cout << "Um den Copter landen zu lassen Leertaste betaetigen" << endl;
  cout << "oder Enter betaetigen um neue Sollwerte zu definieren" << endl;

}

void FlightControllerClass::SollwertVorgeben() {

  cout << "Neue Sollwerte definieren" << endl;
  //Sollwerte einlesen bis alle vorhanden sind

  while (!UI->sollEinlesen() && (Error == 0)) {
    //Istwerte einlesen

    //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
    Steuerung->HochRunter((int) reglerZ->getControlValue(istZ));
    Steuerung->RechtLinks((int) reglerY->getControlValue(istY));
    Steuerung->VorZurueck((int) reglerX->getControlValue(istX));
    //Regelwerte an die Fernsteuerung senden
    Steuerung->Steuern();
  }
  //neue Trajektorie wird berrechnet
  Trajectory->calcCheckpointsB(istX, istY, istZ, UI->getX(), UI->getY(), UI->getZ());
  cout << "Checkpoints wurden berechnet" << endl;
  cout << "Um Copter weiter fliegen zu lassen Enter betaetigen" << endl;
  //Wartet bis Enter betätigt wird bevor der Copter wieder losfliegt
  while (!UI->EnterGedrueckt() && (Error == 0)) {
    //Istwerte einlesen

    //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
    Steuerung->HochRunter((int) reglerZ->getControlValue(istZ));
    Steuerung->RechtLinks((int) reglerY->getControlValue(istY));
    Steuerung->VorZurueck((int) reglerX->getControlValue(istX));
    //Regelwerte an die Fernsteuerung senden
    Steuerung->Steuern();
  }
}

void FlightControllerClass::ZielAnfliegen() {
  while ((!UI->EnterGedrueckt()) && (0 == Error)) {
    //Istwerte einlesen

    //wenn der aktuelle Checkpoint erreicht ist
    if (Trajectory->checkpointReached(istX, istY, istZ)) {
      Trajectory->nextCheckpoint(); // nächsten Checkpoint auswählen
      ReglerSollwertvorgabe(); //neuen Checkpoint dem Regler übergeben
      cout << "Checkpoint wurde erreicht" << endl;
    } else
      ;
    //Regeln
    //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
    Steuerung->HochRunter((int) reglerZ->getControlValue(istZ));
    Steuerung->RechtLinks((int) reglerY->getControlValue(istY));
    Steuerung->VorZurueck((int) reglerX->getControlValue(istX));
    //Regelwerte an die Fernsteuerung senden
    Steuerung->Steuern();
  }

}

