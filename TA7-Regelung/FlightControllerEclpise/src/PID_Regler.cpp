#include "PID_Regler.h"
#include <windows.h>
#include <iostream>
using namespace std;

PID_Regler::PID_Regler(double UG, double OG) {
    untereGrenze = UG; //Obere Grenze des Reglers festlegen
    obereGrenze = OG; //Untere Grenze des Reglers festlegen
}

void PID_Regler::setfactors(double kp, double ki, double kd, double Scale) {
    Kp = kp;
    Ki = ki;
    Kd = kd;
    ScaleValue = Scale;
    esum = 0;
    ealt = 0;
    ControlValue = 0;
    if (!QueryPerformanceFrequency((LARGE_INTEGER*) & Frequenz))
        cout << "Performance Counter nicht vorhanden" << endl;
    QueryPerformanceCounter((LARGE_INTEGER*) & Timeneu);
    QueryPerformanceCounter((LARGE_INTEGER*) & Timealt);
}

void PID_Regler::setSoll(double Soll) {
    SollValue = Soll; //dem Regler den Sollwert vorgeben
}

double PID_Regler::getControlValue(double IstValue) {
    e = SollValue - IstValue; //Regeödifferenz bestimmen
    esum += e; //Summe bilden
    QueryPerformanceCounter((LARGE_INTEGER*) & Timeneu); // aktuelleZeit speichern
    double Timediff = (((double) (Timeneu - Timealt)) / ((double) Frequenz)); //Zeit differenz zur alten zeit erstellen
    //I Anteil begrenzen
    if (esum * Timediff * Ki > obereGrenze) {//Wenn der I Anteil größer als die Regelobergrenze ist
        esum = obereGrenze / (Timediff * Ki); //wird er auf die Regelobergrenze gesetzt
    }
    if (esum * Timediff * Ki < untereGrenze) {//Wenn der I Anteil kleiner als die Regeluntergrenze ist
        esum = untereGrenze / (Timediff * Ki); //wird er auf die Regeluntergrenze gesetzt
    }
    //eigentlicher Regelcode Addition der drei Anteile P, I und D
    ControlValue = Kp * e + Ki * Timediff * esum + Kd * (e - ealt) / Timediff; 
    ealt = e;//alte Regelabweichung wird zugewiesen
    QueryPerformanceCounter((LARGE_INTEGER*) & Timealt);// alte zeit wird definiert
    ControlValue *= ScaleValue;// Ggf ein Skalierungsfaktor auf die Regelwerte rechnen
    //Begrenzung vom Regelbereich
    if (ControlValue > obereGrenze) {
        ControlValue = obereGrenze;
    }
    if (ControlValue < untereGrenze) {
        ControlValue = untereGrenze;
    }
    return ControlValue;
}