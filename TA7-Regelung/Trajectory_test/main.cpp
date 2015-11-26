/* 
 * File:   main.cpp
 * Author: Robin
 *
 * Created on 22. November 2015, 16:28
 */

#include <cstdlib>
#include "Trajectory.h"
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    Trajectory trajec =Trajectory();
    trajec.calcCheckpoints(-5000,205,17,5150,-201,18);
fstream f;
    f.open("test.txt",ios::out);
    for(i=0;i< CHECKPOINTMAX +1;i++){
      f<<trajec.getNextCheckpointX()<<"\t\t"<<trajec.getNextCheckpointY()<<"\t\t"<<trajec.getNextCheckpointZ()<<endl; 
      trajec.nextCheckpoint();
    }
    f.close();
    return 0;
}

