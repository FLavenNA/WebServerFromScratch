#include "BindingSocket.h"


// Constructor
BSO::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long yourIpAdress)
    :SimpleSocket(domain, service, protocol, port, yourIpAdress)
    {
        setConnection(connectToNetwork(sock(), address()));
        testConnection(connection());
    };


// Definition of connectToNetwork virtual function
int BSO::BindingSocket::connectToNetwork(int sock, struct sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}