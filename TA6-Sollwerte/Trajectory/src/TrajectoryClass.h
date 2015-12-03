/*
 * TrajectoryClass.h
 *
 *  Created on: 19.11.2015
 *      Author: Marcel
 */

#ifndef TRAJECTORYCLASS_H_
#define TRAJECTORYCLASS_H_
#define CHECKPOINTMAX 20 // maximale Anzahl an Checkpoints
#define DIFMAX 10 // Toleranz ab wann der Checkpoint erreicht ist
#define ENTFMAX 15// maximale Entfernung zwischen Checkpoints
#define ARRAYMAX 20 // checkpoint array nur zum testen vorerst
using namespace std;

class Trajectory_Class {
public:
  Trajectory_Class();
  virtual ~Trajectory_Class();
  void calcCheckpointsA(double istX, double istY, double istZ, double sollX, double sollY, double sollZ); //halbieren
  void calcCheckpointsB(double istX, double istY, double istZ, double sollX, double sollY, double sollZ); //mit max Entfernung berechnen
  double getNextCheckpointX();
  double getNextCheckpointY();
  double getNextCheckpointZ();
  bool checkpointReached(double istX, double istY, double istZ); // 1 if checkpoint reached successfully
  int nextCheckpoint();
  int ArrayEndReached();
private:
  int checkpointIst;
  int geradenparameter;
  double checkpointsX[CHECKPOINTMAX + 1]; // damit sollwert noch abgespeichert werden kann
  double checkpointsY[CHECKPOINTMAX + 1];
  double checkpointsZ[CHECKPOINTMAX + 1];
  double checkpointsX2[ARRAYMAX]; // test
  double checkpointsY2[ARRAYMAX];
  double checkpointsZ2[ARRAYMAX];
};

#endif /* TRAJECTORYCLASS_H_ */
