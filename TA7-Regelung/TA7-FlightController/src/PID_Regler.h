/* 
 * File:   PID_Regler.h
 * Author: Robin
 *
 * Created on 15. November 2015, 14:56
 */

#ifndef PID_REGLER_H
#define	PID_REGLER_H

#include <windows.h>
#include <iostream>
using namespace std;

class PID_Regler {
public:
    PID_Regler(double OG,double UG);
    void setfactors(double kp, double ki, double kd, double Scale);
    void setSoll(double Soll);
    double getControlValue(double IstValue);
private:
    double Kp;
    double Ki;
    double Kd;
    double esum;
    double ealt;
    double e;
    double ScaleValue;
    double SollValue;
    double ControlValue;
    double obereGrenze;
    double untereGrenze;
    LONGLONG Timealt;
    LONGLONG Timeneu;
    LONGLONG Frequenz;
};


#endif	/* PID_REGLER_H */

