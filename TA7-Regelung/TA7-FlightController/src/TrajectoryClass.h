/*
 * TrajectoryClass.h
 *
 *  Created on: 19.11.2015
 *      Author: Marcel
 */

#ifndef TRAJECTORYCLASS_H_
#define TRAJECTORYCLASS_H_
#define CHECKPOINTMAX 20 // maximale Anzahl an Checkpoints
#define DIFMAX 100 // Toleranz ab wann der Checkpoint erreicht ist
#define ENTFMAX 150// maximale Entfernung zwischen Checkpoints
#define ARRAYMAX 800 // checkpoint array, größer lassen für genügend puffer
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
  int nextCheckpoint(); //nächsten Anflugpunkt berechnen
  int ArrayEndReached(); // if End Reached=0, if still not =1, Ende
private:
  int checkpointIst;
  int geradenparameter;
  double checkpointsX[ARRAYMAX]; // Arraymax wird nie erreicht, abbruch durch ArrayEndReached wenn nichts mehr beschrieben
  double checkpointsY[ARRAYMAX];
  double checkpointsZ[ARRAYMAX];
};

#endif /* TRAJECTORYCLASS_H_ */
