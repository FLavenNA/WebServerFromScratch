#include "ListeningSocket.h"

BSO::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long yourIpAdress, int backlog )
: BindingSocket(domain, service, protocol, port ,yourIpAdress)
{
    std::cout << "Listening socket constructed ! " << std::endl;
    m_Backlog = backlog;
    starListening();
    testConnection(m_Listening);
}  

void BSO::ListeningSocket::starListening()
{
    std::cout << "Started listennig ! " << std::endl;
    m_Listening = listen(sock(), m_Backlog);
}   