#include "PID_Regler.h"
#include <windows.h>
#include <iostream>
using namespace std;
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
    SollValue = Soll;
}

double PID_Regler::getControlValue(double IstValue) {
    QueryPerformanceCounter((LARGE_INTEGER*) & Timeneu);
    double Timediff = (((double) (Timeneu - Timealt)) / ((double) Frequenz));
    e = SollValue - IstValue;
    esum += e;
    if(esum*Timediff*Ki >IMAX){
        esum =IMAX/(Timediff * Ki);
    }
    else;
    ControlValue = Kp * e + Ki * Timediff * esum + Kd * (e - ealt) / Timediff;
    ealt = e;
    QueryPerformanceCounter((LARGE_INTEGER*) & Timealt);
    ControlValue *= ScaleValue;
    return ControlValue;
}