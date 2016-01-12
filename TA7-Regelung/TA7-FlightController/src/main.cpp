//============================================================================
// Name        : FlightControllerEclipse.cpp
// Author      : Kai Robin M�ller
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * File:   main.cpp
 * Author: Robin
 *
 * Created on 19. November 2015, 13:54
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#include "FlightController.h"


int main(int argc, char** argv) {
  FlightControllerClass flightcontroller = FlightControllerClass();

  flightcontroller.Initialisieren();// Socket und Regler und copter Verbindung(hier COM-Port anpassen-SerielleUebertragung.cpp)
  flightcontroller.Startprozedur(); //für den flug wichtig

  while (0==flightcontroller.getError()) { //if error leave loop
    flightcontroller.SollwertVorgeben();
    flightcontroller.ZielAnfliegen();
  }

  flightcontroller.Landeprozedur(); //Copter landen lassen und Socket disconnect
  system("pause"); //visual studio spezifisch, lässt konsole offen
  return 0;
}

