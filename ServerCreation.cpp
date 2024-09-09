#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <netinet/in.h>
#include <ostream>
#include <sys/socket.h>
#include <unistd.h>

class ServerCreation {
  const char *ip;

public:
  ServerCreation(const char *ip) : ip(ip) {}
  sockaddr_in createServer(int port) {
    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serverAdress.sin_addr) <= 0) {
      std::cerr << "Invalid IP address" << std::endl;
      exit(0);
    }
    return serverAdress;
  }
};