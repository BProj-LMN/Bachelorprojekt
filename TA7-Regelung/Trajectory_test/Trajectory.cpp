#include "Trajectory.h"
#include <cmath> 

void Trajectory::calcCheckpoints(double istX, double istY, double istZ, double sollX, double sollY, double sollZ) {
    int i;
    double xdif = sollX - istX;
    double ydif = sollY - istY;
    double zdif = sollZ - istZ;
    checkpointsX[0]=istX;
    checkpointsY[0]=istY;
    checkpointsZ[0]=istZ;
    for (i = 0; i < (CHECKPOINTMAX/2); i++) {
        double xn=xdif/(2<<i);
         double yn=ydif/(2<<i);
          double zn=zdif/(2<<i);
        checkpointsX[(CHECKPOINTMAX / 2) - i] = istX + xn;
            checkpointsY[(CHECKPOINTMAX / 2) - i] = istY + yn;
            checkpointsZ[(CHECKPOINTMAX / 2) - i] = istZ + zn;
            checkpointsX[(CHECKPOINTMAX / 2)+i] = sollX - xn;
            checkpointsY[(CHECKPOINTMAX / 2)+i] = sollY - yn;
            checkpointsZ[(CHECKPOINTMAX / 2)+i] = sollZ - zn;      
    }
    checkpointsX[CHECKPOINTMAX]=sollX;
    checkpointsY[CHECKPOINTMAX]=sollY;
    checkpointsZ[CHECKPOINTMAX]=sollZ;
    checkpointIst=0;
}

double Trajectory::getNextCheckpointX() {
    return checkpointsX[checkpointIst];
}

double Trajectory::getNextCheckpointY() {
    return checkpointsY[checkpointIst];
}

double Trajectory::getNextCheckpointZ() {
    return checkpointsZ[checkpointIst];
}

bool Trajectory::checkpointReached(double istX, double istY, double istZ) {
    double xdif = std::abs(checkpointsX[checkpointIst] - istX);
    double ydif = std::abs(checkpointsY[checkpointIst] - istY);
    double zdif = std::abs(checkpointsZ[checkpointIst] - istZ);

    if ((DIFMAX > xdif) && (DIFMAX > ydif) && (DIFMAX > zdif))return 1;
    else return 0;
}

void Trajectory::nextCheckpoint() {
    if (checkpointIst < CHECKPOINTMAX + 1)
        checkpointIst++;
}
