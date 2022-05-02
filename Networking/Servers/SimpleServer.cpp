#include "SimpleServer.h"

BSO::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long yourIpAddress, int backlog)
{
    std::cout << "Simple server constructed ! ";        
    m_Socket = new ListeningSocket(domain, service, protocol, port, yourIpAddress, backlog);    
}

BSO::SimpleServer::~SimpleServer()
{
    delete m_Socket;
}

BSO::ListeningSocket* BSO::SimpleServer::socket()
{
    return m_Socket;
}