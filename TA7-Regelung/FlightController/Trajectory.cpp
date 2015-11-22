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
    for (i = 0; i < (CHECKPOINTMAX); i++) {
        if (i >= (CHECKPOINTMAX / 2)) {
            checkpointsX[i] = sollX - (xdif / pow(2, (i-(CHECKPOINTMAX / 2)+1)));
            checkpointsY[i] = sollY - (ydif / pow(2, (i-(CHECKPOINTMAX / 2)+1)));
            checkpointsZ[i] = sollZ - (zdif / pow(2, (i- (CHECKPOINTMAX / 2)+1)));
        } else {
            checkpointsX[(CHECKPOINTMAX / 2) - i] = istX + (xdif / pow(2, i+1));
            checkpointsY[(CHECKPOINTMAX / 2) - i] = istY + (ydif / pow(2, i+1));
            checkpointsZ[(CHECKPOINTMAX / 2) - i] = istZ + (zdif / pow(2, i+1));
        }
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
