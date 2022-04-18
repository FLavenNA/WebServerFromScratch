#include "SimpleSocket.h"

BSO::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long  yourIpAddress)
{
    std::cout << "Simple socket constructed ! \n" ;
    // Define address structure 
    m_Address.sin_family = domain;
    m_Address.sin_port = htons(port);
    m_Address.sin_addr.s_addr = htonl(yourIpAddress);

    // Establish socket
    m_Sock = socket(domain, service, protocol);
    testConnection(m_Sock);
    // Establish network connection 
    m_Connection = connectToNetwork(m_Sock, m_Address);
    testConnection(m_Connection);
}

// Test connection virtual function

void BSO::SimpleSocket::testConnection(int itemToTest)
{
    // Confirms that socket or connection has been properly established 

    if(itemToTest < 0)
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
}   

// Getter functions 

const struct sockaddr_in& BSO::SimpleSocket::address() const
{
    return m_Address;
}

int BSO::SimpleSocket::sock() const
{
    return m_Sock;
};

int BSO::SimpleSocket::connection() const
{
    return m_Connection;
}