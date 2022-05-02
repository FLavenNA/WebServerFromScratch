#ifndef TestServer_h
#define TestServer_h

#include <stdio.h>

#include "SimpleServer.h"

namespace BSO
{
    class TestServer: public SimpleServer
    {
    public:
        TestServer();
        void launch();

    private:
        char m_Buffer[30000] = {0};
        int m_NewSocket;
        
        void accepter();
        void handler();
        void responder();

    };
      
}

#endif /* TestServer_h */