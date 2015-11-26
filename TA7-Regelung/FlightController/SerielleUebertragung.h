/* 
 * File:   SerielleUebertragung.h
 * Author: Robin
 *
 * Created on 26. November 2015, 14:54
 */

#ifndef SERIELLEUEBERTRAGUNG_H
#define	SERIELLEUEBERTRAGUNG_H
#define COMPORT "COM7"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>

class SerielleUebertragung{
public:
    SerielleUebertragung();
    void Serialwrite();
    void Serialread();
    void RechtLinks(double Regelung);
    void HochRunter(double Regelung);
    void VorZurueck(double Regelung);
    int HochAktuell();
private:
    int hochRegelung;
    DCB serialconfig;
DWORD iBytesWritten;
unsigned char Startwerte[4];
unsigned char Regelwerte[5] ;
unsigned char Buffer[5];
DWORD BytesRead;
HANDLE hCom;
};

#endif	/* SERIELLEUEBERTRAGUNG_H */

