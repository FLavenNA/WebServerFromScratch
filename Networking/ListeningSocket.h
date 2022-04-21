#ifndef ListeningSocket_h
#define ListeningSocket_h

#include <stdio.h>

#include "SimpleSocket.h"

namespace BSO
{
    class ListeningSocket: public SimpleSocket
    {
        public:
            // Constructor
            ListeningSocket(int domain, int service, int protocol, int port, u_long yourIpAddress, int backlog);
            // Virtual function from parent
            int connectToNetwork(int sock, struct sockaddr_in address); 
        private: 
            int m_Backlog;
    };
}



#endif /* ListeningSocket_h */