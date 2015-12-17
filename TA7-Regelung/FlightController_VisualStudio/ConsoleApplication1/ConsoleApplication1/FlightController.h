/* 
 * File:   FlightController.h
 * Author: Robin
 *
 * Created on 10. Dezember 2015, 10:06
 */

#ifndef FLIGHTCONTROLLER_H
#define	FLIGHTCONTROLLER_H
#include "PID_Regler.h"
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

class FlightControllerClass {
public:
  FlightControllerClass();
  virtual ~FlightControllerClass();
  void Initialisieren();
  void Landeprozedur();
  void Startprozedur();
  void SollwertVorgeben();
  void ZielAnfliegen();
  int getError();// if Error -> 1

private:
  void ReglerSollwertvorgabe();

  double istX, istY, istZ;
  int landen;
  int Error;
  PID_Regler* reglerX;
  PID_Regler* reglerY;
  PID_Regler* reglerZ;
  Trajectory_Class* Trajectory;
  UserInterface *UI;
  Wrapper_Steuerung *Steuerung;
};

#endif	/* FLIGHTCONTROLLER_H */

