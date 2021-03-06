/*
 * UserInterface.cpp
 *
 * Funktion:
 *
 * Autor:    Kai Robin Möller
 */

#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface(int* Err) {
  zaehler = 0;
  pos = 0;
  status = 0;
  Error = Err;
}

bool UserInterface::EnterGedrueckt() {
  if (_kbhit()) {             // wenn eine Taste betätigt wurde
    char eingabe = _getch();  // die gedrückte Taste wird eingelesen
    fflush(stdin);            // buffer leeren
    if (eingabe == ESC) {
      *Error = 1;
    }
    if (eingabe == ENTER) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

bool UserInterface::LeertasteGedrueckt() {
  if (_kbhit()) {             // wenn eine Taste betätigt wurde
    char eingabe = _getch();  // die gedrückte Taste wird eingelesen
    fflush(stdin);            // buffer leeren
    if (eingabe == ESC) {
      *Error = 1;
    }
    if (eingabe == LEERTASTE) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

int UserInterface::sollEinlesen() {
  switch (status) {
    case 0:
      cout << "Sollwertvorgabe" << endl;
      soll[0] = 0;
      soll[1] = 0;
      soll[2] = 0;
      status = 1;
      break;
    case 1:
      cout << "X-Koordinate eingeben (300-3800 mm)" << endl;
      status = 4;
      pos = 0;
      break;
    case 2:
      cout << "Y-Koordinate eingeben (300-3700 mm)" << endl;
      status = 4;
      break;
    case 3:
      cout << "Z-Koordinate eingeben (300-2500 mm)" << endl;
      status = 4;
      break;

      // Zahl aufnehemen
    case 4:
      if (_kbhit()) {             // wenn eine Taste betätigt wurde
        char eingabe = _getch();  // die gedrückte Taste wird eingelesen
        fflush(stdin);            // buffer leeren
        cout << eingabe;          // die gedrückte Taste ausgeben
        if (eingabe == ESC) {
          *Error = 1;
        }
        if (eingabe == ENTER) {   // wenn Enter, dann neue zeile
          cout << endl;
          status = 5;
        } else {
          if ((eingabe == DEL) && (zaehler > 0)) {
            zaehler--;  // letzten buffer löschen
          } else {
            buffer[zaehler] = eingabe; // buffer füllen
            zaehler++;
          }
        }
      }
      break;

    case 5:
      for (int i = 0; i < zaehler; i++) {                             // läuft den gesamten buffer durch
        if ((0 <= buffer[i] - OFFSET) && (buffer[i] - OFFSET <= 9)) { // wenn im buffer eine Zahl steht
          soll[pos] += (buffer[i] - OFFSET);      // addiere die Zahl auf soll ..
          if (i < (zaehler - 1)) {                // solange nicht die letzte Zahl eingelesen wird
            soll[pos] *= 10;
          }
        } else {
          if (i == (zaehler - 1)) {               // wenn der letzte buffer Wert keine Zahl ist
            soll[pos] /= 10;
          }
        }
      }
      switch (pos) {
        case 0:
          if (soll[pos] > 3800) {
            soll[pos] = 3800;
          }
          if (soll[pos] < 300) {
            soll[pos] = 300;
          }
          break;
        case 1:
          if (soll[pos] > 3700) {
            soll[pos] = 3700;
          }
          if (soll[pos] < 300) {
            soll[pos] = 300;
          }
          break;
        case 2:
          if (soll[pos] > 2500) {
            soll[pos] = 2500;
          }
          if (soll[pos] < 300) {
            soll[pos] = 300;
          }
          break;
      }

      /*
      if (soll[pos] > 4500) {
        soll[pos] = 4500;
      }
      if (soll[pos] < 0) {
        soll[pos] = 0;
      }
       */

      cout << "=> " << soll[pos] << endl; // gib die eingelesene Zahl aus
      pos++;                              // nächste Zahl kann eingelesen werden
      zaehler = 0;
      if (pos <= 2) {           // solange nicht alle Werte eingelesen sind
        status = pos + 1;       // geht die switch durch
      } else {
        pos = 0;
        status = 0;
        return 1;               // gibt 1 zurück wenn alle Werte eingelesen wurden
      }
      break;
    default:
      ;
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
