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
#include <windows.h>
#include <fstream>

#include  "PID_Regler.h"
#include "defines_Regler.h"
#include "TrajectoryClass.h"
#include "UserInterface.h"
#include "Wrapper_Steuerung.h"
#include "FlightController.h"


using namespace std;
double istX, istY, istZ;
int landen = 0;
int Error = 0;

int main(int argc, char** argv) {
  FlightControllerClass flightcontroller = FlightControllerClass();

  flightcontroller.Initialisieren();
  flightcontroller.Startprozedur();

  while (0==flightcontroller.getError()) { //if error leave loop
    flightcontroller.SollwertVorgeben();
    flightcontroller.ZielAnfliegen();
  }

  flightcontroller.Landeprozedur();
  system("pause"); //visual studio spezifisch, lässt konsole offen
  return 0;
}

