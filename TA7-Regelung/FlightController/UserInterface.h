/* 
 * File:   UserInterface.h
 * Author: Robin
 *
 * Created on 26. November 2015, 13:02
 */

#ifndef USERINTERFACE_H
#define	USERINTERFACE_H
#define ENTER 13
#define LEERTASTE 32
#define DEL 8
#define OFFSET 48

class UserInterface{
public:
    UserInterface();
    int sollEinlesen();
    bool EnterGedrueckt();
    double getX();
    double getY();
    double getZ();
    bool LeertasteGedrueckt();
private:
    double soll[3];    
    char buffer[16];
    int status;
    int pos;
    int zaehler;
};


#endif	/* USERINTERFACE_H */

