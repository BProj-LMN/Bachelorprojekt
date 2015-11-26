/* 
 * File:   Trajectory.h
 * Author: Robin
 *
 * Created on 20. November 2015, 19:08
 */

#ifndef TRAJECTORY_H
#define	TRAJECTORY_H
//nur gerade zahlen zugelassen
#define CHECKPOINTMAX 20  
#define DIFMAX 10

class Trajectory {
public:
    void calcCheckpoints(double istX, double istY, double istZ, double sollX, double sollY, double sollZ);
    double getNextCheckpointX();
    double getNextCheckpointY();
    double getNextCheckpointZ();
    bool checkpointReached(double istX, double istY, double istZ);
    void nextCheckpoint();
private:
    int checkpointIst;
    double checkpointsX[CHECKPOINTMAX+1];
    double checkpointsY[CHECKPOINTMAX+1];
    double checkpointsZ[CHECKPOINTMAX+1];
    
};

#endif	/* TRAJECTORY_H */

