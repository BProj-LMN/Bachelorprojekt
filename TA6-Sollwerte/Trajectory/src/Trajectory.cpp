//============================================================================
// Name        : Trajectory.cpp
// Author      : Marcel Schmid
// Version     :
// Copyright   : Open-Source
// Description : Trajectory_main(test), Ansi-style
//============================================================================

#include <iostream>
#include "TrajectoryClass.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

  Trajectory_Class Trajectory = Trajectory_Class();
  Trajectory.calcCheckpointsB(0, 0, 0, 150, 150, 150);
  fstream f;
  f.open("Geradenwerte.txt", ios::out);
  while (true == Trajectory.ArrayEndReached()) { ///false nur gleich null nichts anderes!!!!!!!!!!!!!!
    f << Trajectory.getNextCheckpointX() << "\t\t" << Trajectory.getNextCheckpointY() << "\t\t"
      << Trajectory.getNextCheckpointZ() << endl;
    Trajectory.nextCheckpoint();
  }
  f.close();
  return 0;
}

