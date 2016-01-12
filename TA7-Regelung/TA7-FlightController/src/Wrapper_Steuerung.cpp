/*
 * Wrapper_Steuerung.cpp
 *
 * Funktion:
 *
 * Autor:    Kai Robin Möller
 */

#include "Wrapper_Steuerung.h"

Wrapper_Steuerung::Wrapper_Steuerung() {
  Startwerte[0] = REGLEROFFSETHR;
  Startwerte[1] = (REGELMAX / 2) + REGLEROFFSETVZ;  // stabiler Wert 0x87
  Startwerte[2] = (REGELMAX / 2) - REGLEROFFSETRL;  // stabiler Wert 0x8a
  Startwerte[3] = (REGELMAX / 2) + REGLEROFFSETD;   // stabiler Wert 0x0x81
  Regelwerte[0] = 0xFF;                             // Startbyte
  Regelwerte[1] = REGLEROFFSETHR;                   // stabiler Wert 0x00
  Regelwerte[2] = (REGELMAX / 2) + REGLEROFFSETVZ;  // stabiler Wert 0x87
  Regelwerte[3] = (REGELMAX / 2) - REGLEROFFSETRL;  // stabiler Wert 0x8a
  Regelwerte[4] = (REGELMAX / 2) + REGLEROFFSETD;   // stabiler Wert 0x81
}

void Wrapper_Steuerung::HochRunter(double Regelung, int Akkukompensation) {
  Regelwerte[1] = Startwerte[0] + Akkukompensation + Regelung;
  if (Regelwerte[1] > 254) {
    Regelwerte[1] = 254;
  }
  if (Regelwerte[1] < 0) {
    Regelwerte[1] = 0;
  }
  hochRegelung = Regelung;

  //cout << (int)Regelwerte[1] << endl;
}

void Wrapper_Steuerung::RechtLinks(double Regelung) {
  Regelwerte[3] = Startwerte[2] - Regelung;
  if (Regelwerte[3] > 254) {
    Regelwerte[3] = 254;
  }
  if (Regelwerte[3] < 0) {
    Regelwerte[3] = 0;
  }
}

void Wrapper_Steuerung::VorZurueck(double Regelung) {
  Regelwerte[2] = Startwerte[1] + Regelung;
  if (Regelwerte[2] > 254) {
    Regelwerte[2] = 254;
  }
  if (Regelwerte[2] < 0) {
    Regelwerte[2] = 0;
  }
}

int Wrapper_Steuerung::HochAktuell() {
  return Regelwerte[1];
}

void Wrapper_Steuerung::Steuern() {
  Serial.Serialwrite(&Regelwerte[0], sizeof(Regelwerte));
}
