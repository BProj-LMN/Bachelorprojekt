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

using namespace std;
double istX, istY, istZ;
DCB serialconfig;
DWORD iBytesWritten;
unsigned char Startwerte[4] = {0x00, 0x87, 0x8a, 0x81};
unsigned char Regelwerte[5] = {0xFF, 0x00, 0x87, 0x8a, 0x81}; // (4)
unsigned char Buffer[5];
DWORD BytesRead;
HANDLE hCom = CreateFile("COM7", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

PID_Regler reglerX = PID_Regler();
PID_Regler reglerY = PID_Regler();
PID_Regler reglerZ = PID_Regler();

Trajectory trajec = Trajectory();

UserInterface UI = UserInterface();

void Serialinit() {
    //unsigned char ucMsg = 'C';    // zu sendendes Zeichen (1)
    serialconfig.DCBlength = sizeof (DCB); // Laenge des Blockes MUSS gesetztsein!
    GetCommState(hCom, &serialconfig); // COM-Einstellungen holen und aendern
    serialconfig.BaudRate = 115200; // Baudrate
    serialconfig.ByteSize = 8; // Datenbits
    serialconfig.Parity = NOPARITY; // Parität
    serialconfig.StopBits = ONESTOPBIT; // Stopbits
    SetCommState(hCom, &serialconfig); // COM-Einstellungen speichern

}

void Serialwrite() {
    WriteFile(hCom, &Regelwerte, sizeof (Regelwerte), &iBytesWritten, NULL);
}

void Serialread() {
    ReadFile(hCom, &Buffer, 4, &BytesRead, NULL);
}

void Sollwertvorgabe() {
    reglerX.setSoll(trajec.getNextCheckpointX());
    reglerY.setSoll(trajec.getNextCheckpointY());
    reglerZ.setSoll(trajec.getNextCheckpointZ());
}

int main(int argc, char** argv) {

    reglerX.setfactors(KPXY, KIXY, KDXY, 1);
    reglerY.setfactors(KPXY, KIXY, KDXY, 1);
    reglerZ.setfactors(KPZ, KIZ, KDZ, 1);
    Serialinit();
    //Sollwerte einlesen
    UI.sollEinlesen();
    //Istwerte einlesen

    //Trajectorie Checkpoints berechnen
    trajec.calcCheckpoints(istX, istY, istZ, UI.getX(), UI.getY(), UI.getZ());
    cout << "Checkpoints berechnet" << endl;
    // erster checkpoint als soll vorgeben
    Sollwertvorgabe();
    // Startprozedur
   // TODO
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
        Regelwerte[2] = Startwerte[1] + reglerX.getControlValue(istX);
        Regelwerte[3] = Startwerte[2] + reglerY.getControlValue(istY);
        Regelwerte[1] = Startwerte[0] + reglerZ.getControlValue(istZ);
        //Copter ansteuern
        Serialwrite();
        cout << "Regelt" << endl;
    } while (!UI.EnterGedrueckt());
    //Landenprozedur
    cout<<"Landen"<<endl;
    Regelwerte[2] = Startwerte[1];
    Regelwerte[3] = Startwerte[2];
    do {
        Regelwerte[1]--;
        Sleep(100);
        Serialwrite();
    } while (Regelwerte[1] == 0);
    cout<<"Gelandet"<<endl;
    return 0;
}

