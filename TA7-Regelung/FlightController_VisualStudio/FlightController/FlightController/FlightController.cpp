/*
 * Flightcontroller.cpp
 *
 *  Created on: 11.12.2015
 *      Author: Marcel
 */

#include "FlightController.h"

FlightControllerClass::FlightControllerClass() {
  //Regler für Vor Zurück erzeugen Grenzwerte für Regelung von -127 bis 127
  reglerX = new PID_Regler(-REGELMAX / 2, REGELMAX / 2);
  //Regler für Rechts Links erzeugen Grenzwerte für Regelung von -127 bis 127
  reglerY = new PID_Regler(-REGELMAX / 2, REGELMAX / 2);
  //Regler für Hoch Runter erzeugen Grenzwerte für Regelung von 0 bis 254
  reglerZ = new PID_Regler(0, 30);
  //Trajektorien Klasse erzeugen
  Trajectory = new Trajectory_Class();
  //UserInterface erzeugen
  UI = new UserInterface(&Error);
  //Serielle Schnittstelle erzeugen
  Steuerung = new Wrapper_Steuerung();

  Tracking = new Wrapper_Socket();

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
  delete Tracking;
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
  reglerZ->setfactors(KPZ, KIZ, KDZ, 0.005);
  //Um eine Verbindung mit dem Copter aufzubauen muss der Schub einmal auf Maximalausschlag und wieder zurück
  cout << "Mit dem Copter Verbindung aufbauen" << endl;
  Steuerung->HochRunter(REGELMAX - REGLEROFFSETHR);
  Steuerung->Steuern();
  while ((!UI->EnterGedrueckt())&& (Error==0))
    ; //Warten auf Enter
  Steuerung->HochRunter(0);
  Steuerung->Steuern();
  cout << "Rechner ist mit Copter verbunden" << endl;
  if (Tracking->connect() == 0){ cout << "verbunden" << endl; }
  else { cout << "fehler" << endl;
  Error = 1;
  }
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
	Steuerung->RechtLinks(REGLEROFFSETRL); //Stabilen Wert vorgeben
	Steuerung->VorZurueck(REGLEROFFSETVZ); //Stabilen Wert vorgeben
	/*Steuerung->HochRunter(0x95);//Leichtsteigend
	Steuerung->Steuern();

	while ((Tracking->getZ()<= 500) && (Error == 0)){
		Tracking->updateIstwerte();
		UI->EnterGedrueckt();
	}*/
	reglerX->setSoll(2000);
	reglerY->setSoll(2000);
	reglerZ->setSoll(1000);

  cout << "Copter Regelung ist gestartet" << endl;
  cout << "Um den Copter landen zu lassen ESC betaetigen" << endl;
  cout << "oder Enter betaetigen um neue Sollwerte zu definieren" << endl;

}

void FlightControllerClass::SollwertVorgeben() {

  cout << "Neue Sollwerte definieren" << endl;
  //Sollwerte einlesen bis alle vorhanden sind

  while ((!UI->sollEinlesen()) && (Error == 0)) {
	  Sleep(1);
    //Istwerte einlesen
	  if (Tracking->updateIstwerte() == 1){ Error = 1; }
	  else;
    //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
    Steuerung->HochRunter((int) reglerZ->getControlValue(Tracking->getZ()));
	//Steuerung->RechtLinks((int)reglerY->getControlValue(Tracking->getY()));
	//Steuerung->VorZurueck((int)reglerX->getControlValue(Tracking->getX()));
    //Regelwerte an die Fernsteuerung senden
    Steuerung->Steuern();
  }
  //neue Trajektorie wird berrechnet
  if (Tracking->updateIstwerte() == 1){ Error = 1; }
  else;
  Trajectory->calcCheckpointsB(Tracking->getX(), Tracking->getY(), Tracking->getZ(), UI->getX(), UI->getY(), UI->getZ());
  cout << "Checkpoints wurden berechnet" << endl;
  cout << "Um Copter weiter fliegen zu lassen Enter betaetigen" << endl;
  //Wartet bis Enter betätigt wird bevor der Copter wieder losfliegt
  while (!UI->EnterGedrueckt() && (Error == 0)) {
    //Istwerte einlesen
	  if (Tracking->updateIstwerte() == 1){ Error = 1; }
	  else;
    //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
	  Steuerung->HochRunter((int)reglerZ->getControlValue(Tracking->getZ()));
	//Steuerung->RechtLinks((int)reglerY->getControlValue(Tracking->getY()));
	//Steuerung->VorZurueck((int)reglerX->getControlValue(Tracking->getX()));
    //Regelwerte an die Fernsteuerung senden
    Steuerung->Steuern();
  }
}

void FlightControllerClass::ZielAnfliegen() {
  while ((!UI->EnterGedrueckt()) && (0 == Error)) {
    //Istwerte einlesen
	  if (Tracking->updateIstwerte() == 1){ Error = 1; }
	  else;
    //wenn der aktuelle Checkpoint erreicht ist
	  if ((Trajectory->ArrayEndReached()==1)&&(Trajectory->checkpointReached(Tracking->getX(), Tracking->getY(), Tracking->getZ()))) {
      Trajectory->nextCheckpoint(); // nächsten Checkpoint auswählen
      ReglerSollwertvorgabe(); //neuen Checkpoint dem Regler übergeben
      cout << "Checkpoint wurde erreicht" << endl;
    } else;
    //Regeln
    //übergibt die Regelwerte an den puffer der Seriellen Schnittstelle
	  Steuerung->HochRunter((int)reglerZ->getControlValue(Tracking->getZ()));
	Steuerung->RechtLinks((int)reglerY->getControlValue(Tracking->getY()));
	Steuerung->VorZurueck((int)reglerX->getControlValue(Tracking->getX()));
    //Regelwerte an die Fernsteuerung senden
    Steuerung->Steuern();
  }

}
int FlightControllerClass::getError() {
	return Error;

}

