#include "UserInterface.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

UserInterface::UserInterface(int* Err) {
    zaehler = 0;
    pos = 0;
    status = 0;
    Error =Err;
}

bool UserInterface::EnterGedrueckt() {
    if (kbhit()) { // Wenn eine Taste betätigt wurde
        char eingabe = getch();//die gedrückte taste wird eingelesen
        fflush(stdin);//Buffer leeren
        if(eingabe == ESC) {
                    *Error =1;}
        if (eingabe == ENTER) {
            return 1;
        } else {
            return 0;
        }
    } else;
}

bool UserInterface::LeertasteGedrueckt() {
    if (kbhit()) {// Wenn eine Taste betätigt wurde
        char eingabe = getch();//die gedrückte taste wird eingelesen
        fflush(stdin);//Buffer leeren
        if(eingabe == ESC) {
                    *Error =1;}
        if (eingabe == LEERTASTE) {
            return 1;
        } else {
            return 0;
        }
    } else;
}

int UserInterface::sollEinlesen() {

    switch (status) {
        case 0:cout << "Sollwertvorgabe" << endl;
            soll[0] = 0;
            soll[1] = 0;
            soll[2] = 0;
            status = 1;
            break;
        case 1:cout << "X-Koordinate eingeben (in cm)" << endl;
            status = 4;
            pos = 0;
            break;
        case 2: cout << "Y-Koordinate eingeben (in cm)" << endl;
            status = 4;
            break;
        case 3:cout << "Z-Koordinate eingeben (in cm)" << endl;
            status = 4;
            break;
            //Zahl aufnehemen
        case 4: if (kbhit()) {// Wenn eine Taste betätigt wurde
                char eingabe = getch();//die gedrückte taste wird eingelesen
                fflush(stdin);//Buffer leeren
                cout << eingabe;//die gedrückte taste ausgeben
                if(eingabe == ESC) {
                    *Error =1;}
                if (eingabe == ENTER) {// Wenn eine Enter betätigt wurde neue zeile
                    cout << endl;
                    status = 5;
                } else {
                    //Wenn Entfernen dedrückt wurde undzähler größer null ist
                    if ((eingabe == DEL)&&(zaehler > 0)) {
                        zaehler--;//letzten buffer löschen
                    } else {
                        buffer[zaehler] = eingabe;//buffer füllen
                        zaehler++;//Zähler hochzählen
                    }
                }
            }
            break;
        case 5:for (int i = 0; i < zaehler; i++) {//läuft den gesamten buffer durch
                if ((0 <= buffer[i] - OFFSET)&& (buffer[i] - OFFSET <= 9)) {//wenn im buffer eine Zahl steht
                    soll[pos] += (buffer[i] - OFFSET);//addiere die Zahl auf soll ..
                    if (i < (zaehler - 1)) { //solange nicht die letzte zahl eingelesen wird
                        soll[pos] *= 10;//Rechne mal 10
                    }
                }
                else{
                    if (i == (zaehler - 1)){//wenn der letzte buffer wert keine zahl ist
                        soll[pos] /= 10;//teil durch 10
                    }
                }
            }
            cout << "=> " << soll[pos] << endl; // gib die eingelesene Zahl aus
            pos++; //nächste zahl kann eingelesen werden
            zaehler = 0;
            if (pos <= 2) {//solange nicht alle werte eingelesen sind
                status = pos + 1;//geht die switch durch
            } else {
                pos = 0;
                status = 0;
                return 1;// gibt ne 1 zurück wenn alle werte eingelesen wurden
            }
            break;
        default:;
    }
    return 0;
}

double UserInterface::getX() {
    return soll[0];
}

double UserInterface::getY() {
    return soll[1];
}

double UserInterface::getZ() {
    return soll[2];
}