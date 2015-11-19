/*
 * Socket.cpp
 *
 *  Created on: 15.11.2015
 *      Author: Jannik
 */

#include "Socket.h"

Socket::Socket(int port) {
#ifndef _WIN32
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
  rc = bind(udp_socket, (struct sockaddr *) &server, serverLen);
  if (rc < 0) {
    fprintf(stderr, "ERROR: binding \n");
    exit(0);
  }

#else
  serverLen = sizeof(SOCKADDR_IN);
  remoteLen = sizeof(SOCKADDR_IN);

  WSADATA wsa;
  rc = WSAStartup(MAKEWORD(2, 0), &wsa);
  if (rc != 0) {
    fprintf(stderr, "ERROR: startWinsock, code: %d\n", rc);
    exit(0);
  }

  udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp_socket == INVALID_SOCKET) {
    fprintf(stderr, "ERROR: opening socket, code: %d\n", WSAGetLastError());
    exit(0);
  }
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = ADDR_ANY;
  server.sin_port = htons(UDP_PORT);
  rc = bind(udp_socket, (SOCKADDR*) &server, sizeof(SOCKADDR_IN));
  if (rc == SOCKET_ERROR) {
    printf("ERROR: binding, code: %d\n", WSAGetLastError());
    return 1;
  }
#endif

}

Socket::~Socket() {
#ifndef _WIN32
  close(udp_socket);
#else
  // TODO windows close socket
#endif
}

void Socket::evaluate() {
#ifndef _WIN32
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

#else
  rc = recvfrom(udp_socket, message, MESSAGE_LEN, MSG_DONTWAIT, (SOCKADDR*) &remote, &remoteLen);

  if (rc != SOCKET_ERROR) {
    newClientMessage = true;

    write(1, "[LOG] received packet: ", 23);
    write(1, message, rc);

    if (0 == strncmp(message, "connect", 7)) {
      clientConnected = true;
      newClientMessage = false;

      rc = sendto(udp_socket, "you are connected\n", 19, 0, (SOCKADDR*) &remote, remoteLen);
      if (rc == SOCKET_ERROR) {
        fprintf(stderr, "[ERROR] in Socket::evaluate - sendto\n");
        clientConnected = false;
      }
    } // only send ack if connection is requested, so there is no else

  }

#endif

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
#ifndef _WIN32
  if (clientConnected) {
    rc = sendto(udp_socket, message, MESSAGE_LEN, 0, (struct sockaddr *) &remote, remoteLen);
    // TODO send correct lenght sizeof(message);
    if (rc < 0) {
      fprintf(stderr, "[ERROR] in Socket::sendMessage - sendto\n");
      return 0;
    }
  }
  return 1;

#else
  if (clientConnected) {
    rc = sendto(udp_socket, message, MESSAGE_LEN, 0, (SOCKADDR*) &remote, remoteLen);
    // TODO send correct lenght sizeof(message);
    if (rc == SOCKET_ERROR) {
      fprintf(stderr, "[ERROR] in Socket::sendMessage - sendto\n");
      return 0;
    }
  }
  return 1;
#endif
}
