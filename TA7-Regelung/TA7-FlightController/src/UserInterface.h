/*
 * UserInterface.h
 *
 * Funktion:
 *
 * Autor:    Kai Robin Möller
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#define ENTER     13
#define LEERTASTE 32
#define DEL       8
#define ESC       27

#define OFFSET    48

#include <stdio.h>
#include <iostream>
#include <conio.h>

class UserInterface {
public:
  UserInterface(int* Err);
  int sollEinlesen();
  bool EnterGedrueckt();
  double getX();
  double getY();
  double getZ();
  bool LeertasteGedrueckt();

private:
  double soll[3];
  char buffer[16];
  int status;
  int pos;
  int zaehler;
  int* Error;
};

#endif /* USERINTERFACE_H */
