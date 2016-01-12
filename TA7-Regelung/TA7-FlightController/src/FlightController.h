/* 
 * File:   FlightController.h
 * Author: Robin
 *
 * Created on 10. Dezember 2015, 10:06
 */

#ifndef FLIGHTCONTROLLER_H
#define	FLIGHTCONTROLLER_H

#include <cstdlib>
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <fstream>
#include <time.h>


#include "defines_Regler.h"
#include "TrajectoryClass.h"
#include "UserInterface.h"
#include "Wrapper_Steuerung.h"
#include "PID_Regler.h"
#include "Wrapper_Socket.h"

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
  int akkuKompenstation;
  int hoehealt;
  time_t zeitneu;
  time_t zeitalt;
  int landen;
  int Error;
  FILE *Datei;
  PID_Regler* reglerX;
  PID_Regler* reglerY;
  PID_Regler* reglerZ;
  Trajectory_Class* Trajectory;
  UserInterface *UI;
  Wrapper_Steuerung *Steuerung;
  Wrapper_Socket *Tracking;
};

#endif	/* FLIGHTCONTROLLER_H */

