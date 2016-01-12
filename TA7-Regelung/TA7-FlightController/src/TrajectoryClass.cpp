/*
 * TrajectoryClass.cpp
 *
 *  Created on: 19.11.2015
 *      Author: Marcel
 */

#include "TrajectoryClass.h"

Trajectory_Class::Trajectory_Class() {
  // TODO Auto-generated constructor stub
  checkpointIst = 0;
  geradenparameter = 0;
}

Trajectory_Class::~Trajectory_Class() {
  // TODO Auto-generated destructor stub

}

void Trajectory_Class::calcCheckpointsA(double istX, double istY, double istZ, double sollX, double sollY,
                                       double sollZ) {
  int i;
  double xdif = sollX - istX; //berechnung Richtungsvektor
  double ydif = sollY - istY; //berechnung Richtungsvektor
  double zdif = sollZ - istZ; //berechnung Richtungsvektor
  checkpointsX[0] = istX; // Ortsvektor
  checkpointsY[0] = istY; // Ortsvektor
  checkpointsZ[0] = istZ; // Ortsvektor
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
  geradenparameter=CHECKPOINTMAX;
}

void Trajectory_Class::calcCheckpointsB(double istX, double istY, double istZ, double sollX, double sollY,
                                        double sollZ) {
  int k = 0;
  double OrtsvX = istX; // Ortsvektor
  double OrtsvY = istY; // Ortsvektor
  double OrtsvZ = istZ; // Ortsvektor
  double RichtungsvX = sollX - istX; //berechnung Richtungsvektor
  double RichtungsvY = sollY - istY; //berechnung Richtungsvektor
  double RichtungsvZ = sollZ - istZ; //berechnung Richtungsvektor
  while ((RichtungsvX > ENTFMAX) || (RichtungsvY > ENTFMAX) || (RichtungsvZ > ENTFMAX)) { //Richtungsvektor verkleinern
    RichtungsvX /= 2;
    RichtungsvY /= 2;
    RichtungsvZ /= 2;
  }
  for (k = 0; k < ((sollX - OrtsvX) / RichtungsvX); k++) { //K berechnen und hochzählen bis Sollwert erreicht erreicht
    checkpointsX[k] = OrtsvX + k * RichtungsvX;
    checkpointsY[k] = OrtsvY + k * RichtungsvY;
    checkpointsZ[k] = OrtsvZ + k * RichtungsvZ;
  }
  geradenparameter = k - 1; // k speichern, Anzahl des beschriebenen Arrrays minus 1

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

int Trajectory_Class::nextCheckpoint() {
  if (checkpointIst < geradenparameter + 1) {
    checkpointIst++;
    return 1;
  } else {
    return -1;
  }
}

int Trajectory_Class::ArrayEndReached() {
  if (checkpointIst < geradenparameter + 1) {
    return 1;
  } else {
    return 0;
  }

}

