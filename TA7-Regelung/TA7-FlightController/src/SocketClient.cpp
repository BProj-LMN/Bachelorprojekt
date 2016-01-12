/*
 * SocketClient.cpp
 *
 * function: create an UDP client for remote connection and control of server
 *
 * author: Jannik Beyerstedt
 */

#include "SocketClient.h"

#ifndef _WIN32
#include <arpa/inet.h>
#endif
#pragma warning(disable : 4996)


SocketClient::SocketClient(char ipAddress[], int port) {
  newServerMessage = false;

#ifndef _WIN32
  serverLen = sizeof(server);
  remoteLen = sizeof(remote);

  // startup sequence
  udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp_socket < 0) {
    fprintf(stderr, "ERROR: in SocketClient::SocketClient - opening socket \n");
    //exit(0);
  }
  server.sin_family = AF_INET;

  struct hostent *hp;
  hp = gethostbyname(ipAddress);
  bcopy((char *) hp->h_addr, (char *)&server.sin_addr, hp->h_length);

  server.sin_port = htons(port);

#else
  serverLen = sizeof(SOCKADDR_IN);
  remoteLen = sizeof(SOCKADDR_IN);

  WSADATA wsa;
  rc = WSAStartup(MAKEWORD(2, 0), &wsa);
  if (rc != 0) {
    fprintf(stderr, "ERROR: in SocketClient::SocketClient - startWinsock, code: %ld \n", rc);
    //exit(0);
  }

  udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp_socket == INVALID_SOCKET) {
    fprintf(stderr, "ERROR: in SocketClient::SocketClient - opening socket, code: %d\n", WSAGetLastError());
    //exit(0);
  }
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  inet_pton(AF_INET, ipAddress, &(server.sin_addr));

  u_long iMode = 1;
  ioctlsocket(udp_socket, FIONBIO, &iMode);
#endif

}

SocketClient::~SocketClient() {
#ifndef _WIN32
  close(udp_socket);
#else
  closesocket(udp_socket);
#endif
}

void SocketClient::evaluate() {
#ifndef _WIN32
  rc = recvfrom(udp_socket, message, MESSAGE_LEN, MSG_DONTWAIT, (struct sockaddr *) &remote, &remoteLen);

  if (rc > 0) {
    newServerMessage = true;

    write(1, "[LOG] received packet: ", 23);
    write(1, message, rc);
  }

#else
  rc = recvfrom(udp_socket, message, MESSAGE_LEN, 0, (SOCKADDR*) &remote, &remoteLen);//länge des strings


  if (rc != SOCKET_ERROR) {//wenn länge korrekt erfasst
    newServerMessage = true;
    message[rc] = '\0';

    //fprintf(stdout, "[LOG] received packet: ");
    //fprintf(stdout, "%s", message);
  }

#endif
}

bool SocketClient::get_message(char message[]) {
	for (int i = 0 ; i < MESSAGE_LEN ; i++){
		message[i] = this->message[i];
	}
  if (newServerMessage) {
    newServerMessage = false;
    return 1;
  } else {
    return 0;
  }

}

int SocketClient::sendMessage(char message[MESSAGE_LEN]) {
#ifndef _WIN32
  rc = sendto(udp_socket, message, strlen(message), 0, (struct sockaddr *) &server, serverLen);
  if (rc < 0) {
    fprintf(stderr, "[ERROR] in SocketClient::sendMessage - sendto\n");
    return -1;
  }
  return 0;

#else
  rc = sendto(udp_socket, message, strlen(message), 0, (SOCKADDR *) &server, serverLen);
  if (rc == SOCKET_ERROR) {
    printf("[ERROR] in SocketClient::sendMessage, code: %d\n", WSAGetLastError());
    return -1;
  }
  return 0;
#endif
}
