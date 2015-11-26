/*
 * TrajectoryClass.cpp
 *
 *  Created on: 19.11.2015
 *      Author: Marcel
 */

#include "TrajectoryClass.h"
#include <cmath>

Trajectory_Class::Trajectory_Class() {
  // TODO Auto-generated constructor stub

}

Trajectory_Class::~Trajectory_Class() {
  // TODO Auto-generated destructor stub

}

void Trajectory_Class::calcCheckpoints(double istX, double istY, double istZ, double sollX, double sollY,
                                       double sollZ) {
  int i;
  double xdif = sollX - istX; //berechnung Richtungsvektor
  double ydif = sollY - istY; //berechnung Richtungsvektor
  double zdif = sollZ - istZ; //berechnung Richtungsvektor
  checkpointsX[0] = istX;
  checkpointsY[0] = istY;
  checkpointsZ[0] = istZ;
  for (i = 0; i < (CHECKPOINTMAX / 2); i++) {
    double xn = xdif / (2 << i); // Hälfte, Viertel, Achtel etc der Geraden berechnen
    double yn = ydif / (2 << i);
    double zn = zdif / (2 << i);
    checkpointsX[(CHECKPOINTMAX / 2) - i] = istX + xn; // Geradenpunkte zur Ist und zur Soll Seite hinzufügen
    checkpointsY[(CHECKPOINTMAX / 2) - i] = istY + yn; //von der mitte an zu jeweils beiden seiten
    checkpointsZ[(CHECKPOINTMAX / 2) - i] = istZ + zn;
    checkpointsX[(CHECKPOINTMAX / 2) + i] = sollX - xn;
    checkpointsY[(CHECKPOINTMAX / 2) + i] = sollY - yn;
    checkpointsZ[(CHECKPOINTMAX / 2) + i] = sollZ - zn;
  }
  checkpointsX[CHECKPOINTMAX] = sollX;
  checkpointsY[CHECKPOINTMAX] = sollY;
  checkpointsZ[CHECKPOINTMAX] = sollZ;
  checkpointIst = 0;
}

double Trajectory_Class::getNextCheckpointX() {
  return checkpointsX[checkpointIst];
}

double Trajectory_Class::getNextCheckpointY() {
  return checkpointsY[checkpointIst];
}

double Trajectory_Class::getNextCheckpointZ() {
  return checkpointsZ[checkpointIst];
}

bool Trajectory_Class::checkpointReached(double istX, double istY, double istZ) {
  double xdif = abs(checkpointsX[checkpointIst] - istX); //absolute differenz zwischen checkpoint und Istwert
  double ydif = abs(checkpointsY[checkpointIst] - istY);
  double zdif = abs(checkpointsZ[checkpointIst] - istZ);

  if ((DIFMAX > xdif) && (DIFMAX > ydif) && (DIFMAX > zdif)) { // wenn Differenz kleiner als Toleranz
    return 1; //checkpoint reached sucessfully
  } else
    return 0; // checkpoint not reached
}

void Trajectory_Class::nextCheckpoint() {
  if (checkpointIst < CHECKPOINTMAX + 1)
    checkpointIst++;
}
