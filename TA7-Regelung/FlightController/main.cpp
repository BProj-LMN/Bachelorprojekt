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
int landen=0;

PID_Regler reglerX = PID_Regler();
PID_Regler reglerY = PID_Regler();
PID_Regler reglerZ = PID_Regler();

Trajectory trajec = Trajectory();

UserInterface UI = UserInterface();

SerielleUebertragung Serial = SerielleUebertragung();

void Sollwertvorgabe() {
    reglerX.setSoll(trajec.getNextCheckpointX());
    reglerY.setSoll(trajec.getNextCheckpointY());
    reglerZ.setSoll(trajec.getNextCheckpointZ());
}

void Startprozedur(){
    cout << "Copter konekten"<<endl;
    Serial.HochRunter(254);
    Serial.Serialwrite();
    while(!UI.EnterGedrueckt());
        Serial.HochRunter(0);
         Serial.Serialwrite();
}

int main(int argc, char** argv) {

    reglerX.setfactors(KPXY, KIXY, KDXY, 1);
    reglerY.setfactors(KPXY, KIXY, KDXY, 1);
    reglerZ.setfactors(KPZ, KIZ, KDZ, 1);
    //Sollwerte einlesen
    UI.sollEinlesen();
    //Istwerte einlesen

    //Trajectorie Checkpoints berechnen
    trajec.calcCheckpoints(istX, istY, istZ, UI.getX(), UI.getY(), UI.getZ());
    cout << "Checkpoints berechnet" << endl;
    // erster checkpoint als soll vorgeben
    Sollwertvorgabe();
    // Startprozedur
    Startprozedur();
            //Regelung starten
    cout<<"Gestartet"<<endl;
    do {
        //Istwerte einlesen

        if (trajec.checkpointReached(istX, istY, istZ)) { //wenn checkpoint erreicht
            trajec.nextCheckpoint();
            Sollwertvorgabe();
            cout << "Checkpoint erreicht" << endl;
        } else;
        //Regeln
        Serial.HochRunter(reglerZ.getControlValue(istZ));
        Serial.RechtLinks(reglerY.getControlValue(istY));
        Serial.VorZurueck(reglerX.getControlValue(istX));
        //Copter ansteuern
       Serial.Serialwrite();
        cout << "Regelt" << endl;
    } while (!UI.EnterGedrueckt());
    //Landenprozedur
    cout<<"Landen"<<endl;
    
    Serial.RechtLinks(0);
    Serial.VorZurueck(0);
    for(landen = Serial.HochAktuell();landen>0;landen--){
          Serial.HochRunter(landen);
        Sleep(60);
      Serial.Serialwrite();
    } 
    cout<<"Gelandet"<<endl;
    return 0;
}

