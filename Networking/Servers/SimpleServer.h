#ifndef SimpleServer_h
#define SimpleServer_h

#include <stdio.h>
#include "../bsolibc-networking.h"


#if defined(_WIN32) || defined(WIN32) 
#include <ws2tcpip.h>
#elif defined(__linux__) || defined(__unix__) 
#include <unistd.h>
#endif

namespace BSO
{
    class SimpleServer
    {
        public:
            SimpleServer(int domain, int service, int protocol, int port, u_long yourIpAddress, int backlog);
            ~SimpleServer();
            virtual void launch() = 0;

        public:
            ListeningSocket* socket();

        private:
            ListeningSocket* m_Socket;
            virtual void accepter() = 0;
            virtual void handler() = 0;
            virtual void responder() = 0;
            
    };
}



#endif /* SimpleServer_h */     