#include "SimpleSocket.h"
#pragma comment(lib, "WSock32.lib")


BSO::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long  yourIpAddress)
{
    std::cout << "Simple socket constructed ! \n" ;
    
    // Init WinSock2 
    #if defined(_WIN32) || defined(WIN32) 
    int winSockInit = WinSock2Init(m_Wsa);
    #endif
    if(winSockInit != -1 )
    {
        // Define address structure 
        m_Address.sin_family = domain;
        m_Address.sin_port = htons(port);
        m_Address.sin_addr.s_addr = htonl(yourIpAddress);

        // Establish socket
        m_Sock = socket(domain, service, protocol);
        std::cout << "Socket creation : " << m_Sock << std::endl;
        testConnection(m_Sock);
    }
}

#if defined(_WIN32) || defined(WIN32)  
int BSO::SimpleSocket::WinSock2Init(WSADATA& wsa)
{
    std::cout << "Initialising Winsock..." << std::endl;
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
	    std::cout << "Failed. Error Code : " << WSAGetLastError() << std::endl;
		return -1;
	}    
}
#endif

// Test connection virtual function

void BSO::SimpleSocket::testConnection(int itemToTest)
{
    // Confirms that socket or connection has been properly established 
    if(itemToTest < 0)
    {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
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

// Setter functions

void BSO::SimpleSocket::setConnection(int connection)
{
    m_Connection = connection;
}