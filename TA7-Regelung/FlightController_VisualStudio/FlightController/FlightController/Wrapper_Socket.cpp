#include "Wrapper_Socket.h"

Wrapper_Socket::Wrapper_Socket(){
	Socket = new SocketClient("141.22.27.193", 1362);
	istX = 0;
	istY = 0;
	istZ = 0;
}

Wrapper_Socket::~Wrapper_Socket(){
	delete Socket;
}

int Wrapper_Socket::connect(){
	Socket->sendMessage("connect");
	do{ Socket->evaluate();
	} while (Socket->get_message(Nachricht) == 0);	
  if (strcmp(Nachricht, "you are connected\n") == 0) { return 1; }
 else return 0;

}

int Wrapper_Socket::updateIstwerte(){
	Socket->evaluate();
	if (Socket->get_message(Nachricht) == 1){
		if (Nachricht[7] & 0x01 == 0x00){
		istX = (((int)Nachricht[1] << 8) & 0xff00 | (int)Nachricht[2] & 0x00ff) & 0x0000ffff;
		istY = (((int)Nachricht[3] << 8) & 0xff00 | (int)Nachricht[4] & 0x00ff) & 0x0000ffff;
		istZ = (((int)Nachricht[5] << 8) & 0xff00 | (int)Nachricht[6] & 0x00ff) & 0x0000ffff;
		if (istZ >= 10000) {
			istZ = 0;
		}
		else { return 1;
		}
	}
		//std::cout << istX << std::endl;
		
	}
	else;
	return 0;
}

unsigned int Wrapper_Socket::getX(){
	//std::cout << istX << std::endl;
	return istX;
}

unsigned int Wrapper_Socket::getY(){
	//std::cout << istY << std::endl;
	return istY;
}

unsigned int Wrapper_Socket::getZ(){
	//std::cout << istZ << std::endl;
	return istZ;
}
