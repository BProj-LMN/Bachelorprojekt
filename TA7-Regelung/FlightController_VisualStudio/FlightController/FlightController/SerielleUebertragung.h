/* 
 * File:   SerielleUebertragung.h
 * Author: Robin
 *
 * Created on 26. November 2015, 14:54
 */

#ifndef SERIELLEUEBERTRAGUNG_H
#define	SERIELLEUEBERTRAGUNG_H
//#define COMPORT "COM7"//nicht mehr benötigt, da string nicht geht sondern über LPCWSTR
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>

class SerielleUebertragung{
public:
    SerielleUebertragung();
    void Serialwrite(unsigned char* Buffer,int Bufferlaenge );
    void Serialread(unsigned char* Buffer,int Bufferlaenge);
    HANDLE hCom;
private:
	LPCWSTR Port ;//für Comport, muss in construktor zugewiesen werden
    DCB serialconfig;
DWORD iBytesWritten;
DWORD BytesRead;

};

#endif	/* SERIELLEUEBERTRAGUNG_H */

