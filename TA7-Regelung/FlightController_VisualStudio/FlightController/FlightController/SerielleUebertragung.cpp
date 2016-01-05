#include "SerielleUebertragung.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "defines_Regler.h"
using namespace std;


SerielleUebertragung::SerielleUebertragung() {
	a = L"COM7";// nötig da define von string nicht funktioniert, visual studio will LPCWSTR haben  COM PORT MUSS EINSTELLIG BLEIBEN
    hCom = CreateFile(a, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    serialconfig.DCBlength = sizeof (DCB); // Laenge des Blockes MUSS gesetztsein!
    GetCommState(hCom, &serialconfig); // COM-Einstellungen holen und aendern
    serialconfig.BaudRate = 115200; // Baudrate
    serialconfig.ByteSize = 8; // Datenbits
    serialconfig.Parity = NOPARITY; // Parität
    serialconfig.StopBits = ONESTOPBIT; // Stopbits
    SetCommState(hCom, &serialconfig); // COM-Einstellungen speichern
}

void SerielleUebertragung::Serialwrite(unsigned char* Buffer, int Bufferlaenge) {
WriteFile(hCom, Buffer,Bufferlaenge , &iBytesWritten, NULL);
}

void SerielleUebertragung::Serialread(unsigned char* Buffer,int Bufferlaenge) {
    ReadFile(hCom, Buffer, Bufferlaenge, &BytesRead, NULL);
}