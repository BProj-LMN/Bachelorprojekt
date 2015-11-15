/*
 * Socket.cpp
 *
 *  Created on: 15.11.2015
 *      Author: Jannik
 */

#include "Socket.h"

Socket::Socket(int port) {
  serverLen = sizeof(server);
  remoteLen = sizeof(remote);

  udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp_socket < 0) {
    fprintf(stderr, "ERROR: opening socket \n");
    exit(0);
  }
  bzero(&server, serverLen);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);
  if (bind(udp_socket, (struct sockaddr *) &server, serverLen) < 0) {
    fprintf(stderr, "ERROR: binding \n");
    exit(0);
  }

}

Socket::~Socket() {
  close(udp_socket);
}

void Socket::evaluate() {
  rc = recvfrom(udp_socket, message, 1024, MSG_DONTWAIT, (struct sockaddr *) &remote, &remoteLen);

  if (rc > 0) {
    newClientMessage = true;

    write(1, "[LOG] received packet: ", 23);
    write(1, message, rc);

    if (0 == strncmp(message, "connect", 7)) {
      clientConnected = true;
      newClientMessage = false;

      rc = sendto(udp_socket, "you are connected\n", 19, 0, (struct sockaddr *) &remote, remoteLen);
      if (rc < 0) {
        fprintf(stderr, "[ERROR] in Socket::evaluate - sendto\n");
        clientConnected = false;
      }
    } // only send ack if connection is requested, so there is no else

  }

}

int Socket::get_message(std::string & message) {
  message = this->message;

  if (newClientMessage) {
    newClientMessage = false;
    return 1;
  } else {
    return 0;
  }

}

int Socket::sendMessage(char message[MESSAGE_LEN]) {
  if (clientConnected) {
    rc = sendto(udp_socket, message, MESSAGE_LEN, 0, (struct sockaddr *) &remote, remoteLen);
    if (rc < 0) {
      fprintf(stderr, "[ERROR] in Socket::sendMessage - sendto\n");
      return 0;
    }
  }
  return 1;
}
