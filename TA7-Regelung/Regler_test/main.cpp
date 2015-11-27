/* 
 * File:   main.cpp
 * Author: Robin
 *
 * Created on 19. November 2015, 09:50
 */

#include <cstdlib>
#include "PID_Regler.h"
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    int j;
    fstream f;
    f.open("test.txt",ios::out);
    PID_Regler test=PID_Regler(-127,127);
    test.setfactors(0.46,1,0.1874,1);
    test.setSoll(50);
    for(i=0;i<1000;i++){
        j=test.getControlValue(1);
    f<<j<< endl;
    Sleep(10);
    }
     test.setSoll(0);
    for(i=0;i<1000;i++){
        j=test.getControlValue(1);
    f<<j<< endl;
    Sleep(10);
    }
    f.close();
    return 0;
}

