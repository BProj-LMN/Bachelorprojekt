/* 
 * File:   SerielleUebertragung.h
 * Author: Robin
 *
 * Created on 26. November 2015, 14:54
 */

#ifndef SERIELLEUEBERTRAGUNG_H
#define	SERIELLEUEBERTRAGUNG_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
using namespace std;

class SerielleUebertragung{
public:
    SerielleUebertragung();
    void Serialwrite(unsigned char* Buffer,int Bufferlaenge );
    void Serialread(unsigned char* Buffer,int Bufferlaenge);
    HANDLE hCom;
private:
	LPCWSTR Port; // für Comport, muss Datentyp LPCWSTR haben, aus Gründen. Ändern im Quellcode vom Kontruktor!
    DCB serialconfig;
DWORD iBytesWritten;
DWORD BytesRead;

};

#endif	/* SERIELLEUEBERTRAGUNG_H */

