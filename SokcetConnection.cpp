#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <list>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "SocketCreation.cpp"
#include "ServerCreation.cpp"
#include "IConnection.cpp"



class SokcetConnection : public IConnection{
  const char* ip;
  int sPort;
  int ePort;
  SocketCreation sockCreation;
  ServerCreation *serverCreation;

public:
  std::list<int> ls = {};
  SokcetConnection(const char *ip, int sPort, int ePort) : ip(ip), sPort(sPort), ePort(ePort) {
    serverCreation = new ServerCreation(ip);
  }

  void connection() {
    for (int i = sPort; i < ePort; i++) {

      int socket = sockCreation.createSocket();
      sockaddr_in serverAdress = serverCreation->createServer(i);

      if (connect(socket, (struct sockaddr *)&serverAdress,
                  sizeof(serverAdress)) == 0) {
        ls.push_front(i);
        close(socket);
      }
    }
  }
 
 
};