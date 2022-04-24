#ifndef ListeningSocket_h
#define ListeningSocket_h

#include <stdio.h>

#include "BindingSocket.h"

namespace BSO
{
    class ListeningSocket: public BindingSocket
    {
        public:
            // Constructor
            ListeningSocket(int domain, int service, int protocol, int port, u_long yourIpAddress, int backlog);
            void starListening();

        private: 
            int m_Backlog;
            int m_Listening;
    };
}



#endif /* ListeningSocket_h */