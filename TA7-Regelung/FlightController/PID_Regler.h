/* 
 * File:   PID_Regler.h
 * Author: Robin
 *
 * Created on 15. November 2015, 14:56
 */
#include <windows.h>

#ifndef PID_REGLER_H
#define	PID_REGLER_H
#define IMAX 254
class PID_Regler {
public:
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
    LONGLONG Timealt;
    LONGLONG Timeneu;
    LONGLONG Frequenz;
};


#endif	/* PID_REGLER_H */

