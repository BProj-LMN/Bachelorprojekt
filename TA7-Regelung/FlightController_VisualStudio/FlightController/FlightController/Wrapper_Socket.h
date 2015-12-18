/* 
 * File:   Wrapper_Socket.h
 * Author: Robin
 *
 * Created on 10. Dezember 2015, 10:21
 */

#ifndef WRAPPER_SOCKET_H
#define	WRAPPER_SOCKET_H

#include "SocketClient.h"
using namespace std;
class Wrapper_Socket{
public:

  Wrapper_Socket();
  ~Wrapper_Socket();
  int connect();
  void updateIstwerte();
    unsigned int getX();
    unsigned int getY();
    unsigned int getZ();
    
private:
    string Nachricht;
   char Antwort[MESSAGE_LEN];
    unsigned int istX;
    unsigned int istY;
    unsigned int istZ;
    SocketClient *Socket;
};


#endif	/* WRAPPER_SOCKET_H */

