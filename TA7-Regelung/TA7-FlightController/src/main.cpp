/*
 * main.cpp
 *
 * Funktion:
 *
 * Autor:   Kai Robin Möller
 */

#include <cstdlib>
#include <iostream>
//#include <fstream>
using namespace std;

#include "FlightController.h"

int main(int argc, char** argv) {
  FlightControllerClass flightcontroller = FlightControllerClass();

  flightcontroller.Initialisieren();  // Socket, Regler, Copter-Verbindung (COM-Port in SerielleUebertragung.cpp anpassen)
  flightcontroller.Startprozedur();   // für den Flug wichtig

  while (0 == flightcontroller.getError()) { // if error leave loop
    flightcontroller.SollwertVorgeben();
    flightcontroller.ZielAnfliegen();
  }

  flightcontroller.Landeprozedur(); // Copter landen lassen und Socket disconnect
  system("pause");                  // visual studio spezifisch, lässt Konsole offen
  return 0;
}
