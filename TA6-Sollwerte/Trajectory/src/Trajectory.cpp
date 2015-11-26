//============================================================================
// Name        : Trajectory.cpp
// Author      : Marcel Schmid
// Version     :
// Copyright   : Open-Source
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TrajectoryClass.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int i;
  Trajectory_Class Trajectory = Trajectory_Class();
  Trajectory.calcCheckpoints(0, 0, 0, 15, 15, 15);
  fstream f;
  f.open("Geradenwerte.txt", ios::out);
  for (i = 0; i < CHECKPOINTMAX + 1; i++) {
    f << Trajectory.getNextCheckpointX() << "\t\t" << Trajectory.getNextCheckpointY() << "\t\t"
      << Trajectory.getNextCheckpointZ() << endl;
    Trajectory.nextCheckpoint();
  }
  f.close();
  return 0;
}

