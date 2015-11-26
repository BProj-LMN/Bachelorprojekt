/* 
 * File:   UserInterface.h
 * Author: Robin
 *
 * Created on 26. November 2015, 13:02
 */

#ifndef USERINTERFACE_H
#define	USERINTERFACE_H
#define ENTER 13
class UserInterface{
public:
    int sollEinlesen();
    bool EnterGedrueckt();
    double getX();
    double getY();
    double getZ();
private:
    double soll[3];    
};


#endif	/* USERINTERFACE_H */

