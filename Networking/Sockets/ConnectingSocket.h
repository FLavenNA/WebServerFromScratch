#ifndef ConnectingSocket_h
#define ConnectingSocket_h

#include <stdio.h>

#include "SimpleSocket.h"

namespace BSO
{
    class ConnectingSocket: public SimpleSocket
    {
        public:
            ConnectingSocket(int domain, int service, int protocol, int port, u_long yourIpAddress);
            int connectToNetwork(int sock, struct sockaddr_in address); 
    };
}



#endif /* ConnectingSocket_h */