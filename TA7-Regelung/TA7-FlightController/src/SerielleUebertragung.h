/*
 * SerielleUebertragung.h
 *
 * Funktion:
 *
 * Autor:    Kai Robin Möller
 */

#ifndef SERIELLEUEBERTRAGUNG_H
#define SERIELLEUEBERTRAGUNG_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
using namespace std;

class SerielleUebertragung {
public:
  SerielleUebertragung();
  void Serialwrite(unsigned char* Buffer, int Bufferlaenge);
  void Serialread(unsigned char* Buffer, int Bufferlaenge);
  HANDLE hCom;
private:
  LPCWSTR Port; // für Comport, muss Datentyp LPCWSTR haben, aus Gründen. ändern im Quellcode vom Kontruktor!
  DCB serialconfig;
  DWORD iBytesWritten;
  DWORD BytesRead;

};

#endif /* SERIELLEUEBERTRAGUNG_H */
