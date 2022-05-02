
/*
ListeningSocket is a child of BindingSocket, specifying that once bound, the socket is  to listen to the network on the given pot
    for incoming connections.
*/

#include "ListeningSocket.h"

/* CONSTRUCTORS */

BSO::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long yourIpAdress, int backlog )
: BindingSocket(domain, service, protocol, port ,yourIpAdress)
{
    std::cout << "Listening socket constructed ! " << std::endl;
    // Set backlog variable
    m_Backlog = backlog;
    // Start listening to the network using listen() from our Winsock2.h or sys/socket.h
    startListening();
    // Confirm the connection was successful
    testConnection(m_Listening);
}  

/* MUTATORS */
void BSO::ListeningSocket::startListening()
{
    std::cout << "Started listennig ! " << std::endl;
    // Start listening on the network 
    m_Listening = listen(sock(), m_Backlog);
}   

/* GETTERS */ 

int BSO::ListeningSocket::listening() const
{
    return m_Listening;
}

int BSO::ListeningSocket::backlog() const 
{
    return m_Backlog;
}