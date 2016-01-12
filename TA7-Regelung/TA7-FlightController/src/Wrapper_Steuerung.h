/* 
 * File:   Wrapper_Steuerung.h
 * Author: Robin
 *
 * Created on 3. Dezember 2015, 09:32
 */

#ifndef WRAPPER_STEUERUNG_H
#define	WRAPPER_STEUERUNG_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "defines_Regler.h"
#include "SerielleUebertragung.h"

class Wrapper_Steuerung{
public:
    Wrapper_Steuerung();
      void RechtLinks(double Regelung);
	  void HochRunter(double Regelung, int Akkukompensation);
    void VorZurueck(double Regelung);
    int HochAktuell();
    void Steuern();
private:
    SerielleUebertragung Serial;
    unsigned char  Regelwerte[5] ;
    unsigned char Startwerte[4];
    double hochRegelung;
};


#endif	/* WRAPPER_STEUERUNG_H */

