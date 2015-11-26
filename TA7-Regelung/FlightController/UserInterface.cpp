#include "UserInterface.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

bool UserInterface::EnterGedrueckt(){
     if (kbhit()) {
            char eingabe = getch();
            fflush(stdin);
            if(eingabe == ENTER ){
                return 1;
            }
            else{
                return 0;
            }
        } else;
}

int UserInterface::sollEinlesen(){
    cout <<"Sollwertvorgabe" <<endl;
    cout <<"X-Koordinate eingeben (in cm)"<<endl;
    cin >> soll[0];
    cout <<"Y-Koordinate eingeben (in cm)"<<endl;
    cin >> soll[1];
    cout <<"Z-Koordinate eingeben (in cm)"<<endl;
    cin >> soll[2]; 
}

double UserInterface::getX(){
    return soll[0];
}

double UserInterface::getY(){
    return soll[1];
}
double UserInterface::getZ(){
    return soll[2];
}