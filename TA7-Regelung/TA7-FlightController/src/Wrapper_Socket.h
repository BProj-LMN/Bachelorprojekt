/*
 * Wrapper_Socket.h
 *
 * Funktion:
 *
 * Autor:    Kai Robin Möller
 */

#ifndef WRAPPER_SOCKET_H
#define WRAPPER_SOCKET_H

#define ESC 27

#include <iostream>
//#include <string.h>
#include <stdio.h>
//#include <conio.h>
#include <time.h>

#include "SocketClient.h"

class Wrapper_Socket {
public:
  Wrapper_Socket();
  ~Wrapper_Socket();
  int connect();
  void disconnect();
  int updateIstwerte();
  unsigned int getX();
  unsigned int getY();
  unsigned int getZ();

private:
  char Nachricht[MESSAGE_LEN];
  char Antwort[MESSAGE_LEN];
  int istX;
  int istY;
  int istZ;

  SocketClient *Socket;
};

#endif /* WRAPPER_SOCKET_H */
