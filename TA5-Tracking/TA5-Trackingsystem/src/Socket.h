/*
 * Socket.h
 *
 *  Created on: 15.11.2015
 *      Author: Jannik
 */

#ifndef SRC_SOCKET_H_
#define SRC_SOCKET_H_

#define MESSAGE_LEN 256

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <iostream>

class Socket {
  long rc;
  int udp_socket;
  struct sockaddr_in server;
  socklen_t serverLen;
  struct sockaddr_in remote;
  socklen_t remoteLen;

  char message[MESSAGE_LEN];
  bool newClientMessage;

  bool clientConnected;

public:
  Socket(int port);
  virtual ~Socket();

  void evaluate();
  int get_message(std::string & message); // returns 1 if new data
  int sendMessage(char message[MESSAGE_LEN]); // returns 1 if success

};

#endif /* SRC_SOCKET_H_ */
