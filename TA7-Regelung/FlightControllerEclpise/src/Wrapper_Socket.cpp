#include "Wrapper_Socket.h"
#include "SocketClient.h"
Wrapper_Socket::Wrapper_Socket(){
  Socket = new SocketClient("127.0.0.1", 1362);
istX=0;
istY=0;
istZ=0;
}

Wrapper_Socket::~Wrapper_Socket(){
  delete Socket;
}

void Wrapper_Socket::updateIstwerte(){
if (Socket->get_message(Werte[MESSAGE_LEN])==1){
  if(Werte[0]==0xDA){
    istX=(Werte[1]<<8)|Werte[2];
    istY=(Werte[3]<<8)|Werte[4];
    istZ=(Werte[5]<<8)|Werte[6];
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
