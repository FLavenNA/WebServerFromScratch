#ifndef BindingSocket_h
#define BindingSocket_h

#include <stdio.h>

#include "SimpleSocket.h"

namespace BSO
{
    class BindingSocket: public SimpleSocket
    {
        public:
            BindingSocket(int domain, int service, int protocol, int port, u_long yourIpAddress);
            int connectToNetwork(int sock, struct sockaddr_in address); 
    };
}



#endif /* BindingSocket_h */