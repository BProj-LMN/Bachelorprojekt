#include "SerielleUebertragung.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>

SerielleUebertragung::SerielleUebertragung() {
    hCom = CreateFile(COMPORT, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    serialconfig.DCBlength = sizeof (DCB); // Laenge des Blockes MUSS gesetztsein!
    GetCommState(hCom, &serialconfig); // COM-Einstellungen holen und aendern
    serialconfig.BaudRate = 115200; // Baudrate
    serialconfig.ByteSize = 8; // Datenbits
    serialconfig.Parity = NOPARITY; // Parität
    serialconfig.StopBits = ONESTOPBIT; // Stopbits
    SetCommState(hCom, &serialconfig); // COM-Einstellungen speichern
    Startwerte[0] = 0x00;
    Startwerte[1] = 0x87;
    Startwerte[2] = 0x8a;
    Startwerte[3] = 0x81;
    Regelwerte[0] = 0xFF; // (4)
    Regelwerte[1] = 0x00;
    Regelwerte[2] = 0x87;
    Regelwerte[3] = 0x8a;
    Regelwerte[4] = 0x81;
}

void SerielleUebertragung::Serialwrite() {
    WriteFile(hCom, &Regelwerte, sizeof (Regelwerte), &iBytesWritten, NULL);
}

void SerielleUebertragung::Serialread() {
    ReadFile(hCom, &Buffer, 4, &BytesRead, NULL);
}

void SerielleUebertragung::HochRunter(double Regelung){
    Regelwerte[1] = Startwerte[0] + Regelung;
    hochRegelung=Regelung;
}

void SerielleUebertragung::RechtLinks(double Regelung){
    Regelwerte[3] = Startwerte[2] + Regelung;
}

void SerielleUebertragung::VorZurueck(double Regelung){
     Regelwerte[2] = Startwerte[1] + Regelung;
}

int SerielleUebertragung::HochAktuell(){
    return hochRegelung;
}