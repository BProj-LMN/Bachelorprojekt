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

void Wrapper_Socket::disconnect() {
	Socket->sendMessage("exit");// remote zugriff auf tracking PC-> dort beenden
	Sleep(100);
}

int Wrapper_Socket::connect(){
	Socket->sendMessage("connect");
	long zeitstart = clock()/CLOCKS_PER_SEC;
	do{ Socket->evaluate();
	if (_kbhit()) { // Wenn eine Taste betätigt wurde
		char eingabe = _getch();//die gedrückte taste wird eingelesen
		fflush(stdin);//Buffer leeren
		if (eingabe == ESC) {
			return 1;
		}
	  }
	} while (Socket->get_message(Nachricht) == 0 && (((clock()/CLOCKS_PER_SEC)-zeitstart)<5));	//Nachricht erhalten oder Timeout
  if (strcmp(Nachricht, "you are connected\n") == 0) { return 0; }
 else return 1;

}

int Wrapper_Socket::updateIstwerte(){
	Socket->evaluate();
	if (Socket->get_message(Nachricht) == 1){// bei erhaltener Nachricht
		//istZ = (((int)Nachricht[5] << 8) & 0xff00 | (int)Nachricht[6] & 0x00ff) & 0x0000ffff;
		//printf("Nachricht : %d\n", istZ);
		if ((Nachricht[7] & 0x01) == 0x00){ // wenn etwas getrackt wurde
			if (0xDA == ((char)Nachricht[0] & 0xFF)){
				//std::cout << "lauft" << std::endl;
				istX = (((int)Nachricht[1] << 8) & 0xff00 | (int)Nachricht[2] & 0x00ff) & 0x0000ffff;
				istY = (((int)Nachricht[3] << 8) & 0xff00 | (int)Nachricht[4] & 0x00ff) & 0x0000ffff;
				istZ = (((int)Nachricht[5] << 8) & 0xff00 | (int)Nachricht[6] & 0x00ff) & 0x0000ffff;
				if (istZ >= 10000) {
					istZ = 0;
				}
				else {
					//return 1;
				}
			}
			else { std::cout << "keine gueltige Nachricht" << std::endl; }
	}
		//std::cout << istX << std::endl;
		
	}
	else;
	/*if ((istX > 3850) || (istX < 250)){ return 1; }
	if ((istY > 3750) || (istY < 250)){ return 1; }
	if (istZ > 2550){ return 1; }*/
	return 0;
}

unsigned int Wrapper_Socket::getX(){
	//std::cout <<"X-Koordinate"<< istX << std::endl;
	return istX;
}

unsigned int Wrapper_Socket::getY(){
	//std::cout << "Y-Koordinate" << istY << std::endl;
	return istY;
}

unsigned int Wrapper_Socket::getZ(){
	//std::cout <<"Z-Koordinate"<< istZ << std::endl;
	return istZ;
}
