/*
 * SocketClient.cpp
 *
 * function: create an UDP client for remote connection and control of server
 * usage:    - create Socket object e.g. for localhost: SocketClient myName = SocketClient("127.0.0.1", 1362);
 *           - call myName.evaluate() every cycle to refresh the object
 *           - receive last message with myName.get_message(...)
 *           - send messages with myName.sendMessage(...)
 *
 * author: Jannik Beyerstedt
 */

#ifndef SRC_SOCKETCLIENT_H_
#define SRC_SOCKETCLIENT_H_

#define MESSAGE_LEN 256

#ifndef _WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#else
#include <winsock2.h>
#include <WS2tcpip.h>
#endif

#include <iostream>
#include <stdio.h>

class SocketClient {
  long rc;

#ifndef _WIN32
  int udp_socket;
  struct sockaddr_in server;
  socklen_t serverLen;
  struct sockaddr_in remote;
  socklen_t remoteLen;

#else
  SOCKET udp_socket;
  SOCKADDR_IN server;
  int serverLen;

  SOCKADDR_IN remote;
  int remoteLen;
#endif

  char message[MESSAGE_LEN];
  bool newServerMessage;

public:
  SocketClient(char ipAddress[], int port);
  virtual ~SocketClient();

  void evaluate();
  bool get_message(std::string & message); // returns true if new data
  int sendMessage(char message[MESSAGE_LEN]);  // returns OK if success

};

#endif /* SRC_SOCKETCLIENT_H_ */
