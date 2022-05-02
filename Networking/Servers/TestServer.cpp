#include "TestServer.h"

BSO::TestServer::TestServer() : SimpleServer (AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    std::cout << "Test server constructed ! " << std::endl;
    launch();
}


void BSO::TestServer::accepter()
{
    struct sockaddr_in address = socket()->address();
    int addrlen = sizeof(address);
    m_NewSocket = accept(socket()->sock(), (struct sockaddr*)&address, (socklen_t*)&addrlen);
    recv(m_NewSocket, m_Buffer, 30000, 0);
    
}

void BSO::TestServer::handler()
{
    std::cout << m_Buffer << std::endl;
}

void BSO::TestServer::responder()
{
    char* hello = "Hello from the server ! ";
    send(m_NewSocket, hello, strlen(hello), 0);
    closesocket(m_NewSocket);
}

void BSO::TestServer::launch()
{
    while(true)
    {
        std::cout << "===== WAITING =====" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "===== DONE =====" << std::endl; 
    }
}