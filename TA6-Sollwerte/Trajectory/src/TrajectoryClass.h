/*
 * TrajectoryClass.h
 *
 *  Created on: 19.11.2015
 *      Author: Marcel
 */

#ifndef TRAJECTORYCLASS_H_
#define TRAJECTORYCLASS_H_
//nur gerade zahlen zugelassen
#define CHECKPOINTMAX 20 // maximale Anzahl an Checkpoints
#define DIFMAX 10 // Toleranz ab wann der Checkpoint erreicht ist

using namespace std;

class Trajectory_Class {
public:
  Trajectory_Class();
  virtual ~Trajectory_Class();
  void calcCheckpoints(double istX, double istY, double istZ, double sollX, double sollY, double sollZ);
  double getNextCheckpointX();
  double getNextCheckpointY();
  double getNextCheckpointZ();
  bool checkpointReached(double istX, double istY, double istZ);
  void nextCheckpoint();
private:
  int checkpointIst;
  double checkpointsX[CHECKPOINTMAX + 1]; // damit soll wert noch abgespeichert werden kann
  double checkpointsY[CHECKPOINTMAX + 1];
  double checkpointsZ[CHECKPOINTMAX + 1];

};

#endif /* TRAJECTORYCLASS_H_ */
