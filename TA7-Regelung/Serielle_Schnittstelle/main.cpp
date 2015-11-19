/* 
 * File:   main.cpp
 * Author: Robin
 *
 * Created on 14. November 2015, 16:02
 */
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <winbase.h>
#include <conio.h>
#include <time.h>
#include <iostream>
using namespace std;

DCB serialconfig;
DWORD iBytesWritten;
unsigned char Startwerte[5] = {0xFF, 0x98, 0x87, 0x8a, 0x81}; // (4)
unsigned char Buffer[5];
DWORD BytesRead;
HANDLE hCom = CreateFile("COM7", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
unsigned char eingabe = 0;
unsigned char test = 0xFF;

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
    WriteFile(hCom, &Startwerte, sizeof (Startwerte), &iBytesWritten, NULL);
    //cout << "Serialwrite" << endl;
}

void Serialread() {
    ReadFile(hCom, &Buffer, 4, &BytesRead, NULL);
}

void Steuerung() {
    switch (eingabe) {
        case 'w': Startwerte[1]++;
            if (Startwerte[1] > 0xFE)Startwerte[1] = 0xFE;
            break;
        case 'a': if (Startwerte[4] < 0x01)Startwerte[4] = 0x01;
            Startwerte[4]--;
            break;
        case 's':if (Startwerte[1] < 0x01)Startwerte[1] = 0x01;
            Startwerte[1]--;
            break;
        case 'd': Startwerte[4]++;
            if (Startwerte[4] > 0xFE)Startwerte[4] = 0xFE;
            break;
        case 'i': Startwerte[2]++;
            if (Startwerte[2] > 0xFE)Startwerte[2] = 0xFE;
            break;
        case 'j': if (Startwerte[3] < 0x01)Startwerte[3] = 0x01;
            Startwerte[3]--;
            break;
        case 'k':if (Startwerte[2] < 0x01)Startwerte[2] = 0x01;
            Startwerte[2]--;
            break;
        case 'l': Startwerte[3]++;
            if (Startwerte[3] > 0xFE)Startwerte[3] = 0xFE;
            break;
        default:;
    }
    Sleep(100);
    system("cls");
    cout << "Steuerung über w hoch a nach links drehen s nach unten dnach rechts drehen" << endl;
    cout << "i nachvorne bewegen j nach links bewegen k nuch hinten bewegen l nach rechts bewegen." << endl;
    cout << "Fuer Sprung nach rechts Enter betaetigen" << endl;
    cout << "throotle\t" << "pitch\t\t" << "roll\t\t" << "yaw" << endl;
    printf("%x\t\t%x\t\t%x\t\t%x\n",Startwerte[1],Startwerte[2],Startwerte[3],Startwerte[4]);
    //cout << hex << Startwerte[1] << "\t\t" << hex << Startwerte[2] << "\t\t" << hex << Startwerte[3] << "\t\t" << hex << Startwerte[4] << endl;
    Serialwrite();
    //Serialread();
   // printf("Rueckgabewert:%x",Buffer[0]);
        

}

int main(int argc, char** argv) {
    int j;
    Serialinit();
    //WriteFile (hCom, &ucMsg, 4, &iBytesWritten, NULL); // Senden von 4Bytes
    // oder:
    cout << "Sprungantwort aufnehmen:" << endl;
    cout << "Um Verbindung mit Fernbedienung aufzunehemen Enter druecken." << endl;
    do {
        if (kbhit()) {
            eingabe = getch();
            fflush(stdin);
        } else;
    } while (eingabe != 13);
    eingabe = 0;
        Startwerte[1] = 0;
    Serialwrite();
    Sleep(2000);
    Startwerte[1] = 254;
    Serialwrite();
     do{
         if (kbhit()) {
            eingabe = getch();
            fflush(stdin);
        } else;
    } while (eingabe != 13);
    eingabe = 0;
    Startwerte[1] = 0x98;
    Serialwrite();
     

    //cout << "Startschub eingeben:" << endl;
    //cin >> hex >> Startwerte[1];
    //Serialwrite();
    do {
        eingabe = 0;
        if (kbhit()) {
            eingabe = getch();
            fflush(stdin);
        } else;
        Steuerung();
    } while (eingabe != 13);
    eingabe = 0;
    Startwerte[1] = 254;
    Serialwrite();
    cout << "Um den Sprung zu beenden Enter druecken(Schub aus)" << endl;
    do {
        if (kbhit()) {
            eingabe = getch();
            fflush(stdin);
        } else;
    } while (eingabe != 13);
    eingabe = 0;
    Startwerte[1] = 0x00;
    Startwerte[2] = 0x84;
    Startwerte[3] = 0x84;
    Startwerte[4] = 0x84;
    Serialwrite();
     // COM1 schließen
    
   /* do { WriteFile(hCom, &Startwerte, sizeof (Startwerte), &iBytesWritten, NULL);
     Sleep(100);
      ReadFile(hCom, &Buffer, 4, &BytesRead, NULL);        
    CloseHandle(hCom);
    system("cls");
     cout<<"Buffer:"<<hex<<Buffer[0]<<endl;
     cout<<"Bytes"<<BytesRead<<endl;
        if (kbhit()) {
            eingabe = getch();
            fflush(stdin);
        } else;
    } while (eingabe != 13);*/
    return 0;
}

