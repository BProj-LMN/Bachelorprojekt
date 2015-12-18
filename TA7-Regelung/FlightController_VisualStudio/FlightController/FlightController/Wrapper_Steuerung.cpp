#include "Wrapper_Steuerung.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "defines_Regler.h"
#include "SerielleUebertragung.h"
#include <iostream>
using namespace std;

Wrapper_Steuerung::Wrapper_Steuerung(){
    Startwerte[0] = 0x00;
    Startwerte[1] = REGELMAX / 2; // Stabilerwert 0x87
    Startwerte[2] = REGELMAX / 2; //Stabilerwert 0x8a
    Startwerte[3] = REGELMAX / 2; //Stabilerwert 0x0x81
    Regelwerte[0] = 0xFF; // Startbyte
    Regelwerte[1] = 0x00;// Stabilerwert 0x00
    Regelwerte[2] = (REGELMAX / 2) + REGLEROFFSETRL; // Stabilerwert 0x87
    Regelwerte[3] = (REGELMAX / 2) + REGLEROFFSETVZ; //Stabilerwert 0x8a
    Regelwerte[4] = (REGELMAX / 2) + REGLEROFFSETD; //Stabilerwert 0x0x81
}


void Wrapper_Steuerung::HochRunter(double Regelung) {
    Regelwerte[1] = Startwerte[0] + Regelung;
    hochRegelung = Regelung;
}

void Wrapper_Steuerung::RechtLinks(double Regelung) {
    Regelwerte[3] = Startwerte[2] + Regelung;
}

void Wrapper_Steuerung::VorZurueck(double Regelung) {
    Regelwerte[2] = Startwerte[1] + Regelung;
}

int Wrapper_Steuerung::HochAktuell() {
    return hochRegelung;
}

void Wrapper_Steuerung::Steuern(){
    Serial.Serialwrite(&Regelwerte[0],sizeof (Regelwerte));
}
