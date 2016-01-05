#include "Wrapper_Socket.h"
#include <string.h>

Wrapper_Socket::Wrapper_Socket(){
  Socket = new SocketClient("127.0.0.1", 1362);
istX=0;
istY=0;
istZ=0;
}

Wrapper_Socket::~Wrapper_Socket(){
  delete Socket;
}

int Wrapper_Socket::connect(){
  Socket->sendMessage("connect");
  while(Socket->get_message(Nachricht)==1){
  Socket->evaluate();
  }
  if (strcmp(Nachricht, "connected") == 0) { return 1; }
 else return 0;
}

void Wrapper_Socket::updateIstwerte(){
Socket->evaluate();
if (Socket->get_message(Nachricht)==1){
  if(Nachricht[0]==0xDA){
    istX=(Nachricht[1]<<8)|Nachricht[2];
    istY=(Nachricht[3]<<8)|Nachricht[4];
    istZ=(Nachricht[5]<<8)|Nachricht[6];
  }
  else;
}
else;

}

unsigned int Wrapper_Socket::getX(){
return istX;
}

unsigned int Wrapper_Socket::getY(){
return istY;
}

unsigned int Wrapper_Socket::getZ(){
return istZ;
}
