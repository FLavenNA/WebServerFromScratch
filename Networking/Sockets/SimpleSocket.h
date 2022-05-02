#ifndef SimpleSocket_h
#define SimpleSocket_h

#include <stdio.h>
#include <iostream>


// We include our system headers depending on the OS 
#if defined(_WIN32) || defined(WIN32) 
#include <WinSock2.h>
#elif defined(__linux__) || defined(__unix__) 
#include <sys/socket.h>
#include <netinet/in.h>
#endif




namespace BSO   
{
    class SimpleSocket 
    {
        public:
            // Constructor
            SimpleSocket(int domain, int service, int protocol, int port, u_long yourIpAddress);   

            //WinSock2 initialization for Windows
            #if defined(_WIN32) || defined(WIN32) 
            int WinSock2Init(WSADATA& wsa);
            #endif
            // Virtual function to connect to a network
            virtual int connectToNetwork(int sock, struct sockaddr_in address) = 0;
            // Function to test sockets and connections
            void testConnection(int);
 
        public: 
            // Getter functions
            const struct sockaddr_in& address() const;
            int sock() const ;
            int connection() const;
            // Setter functions
            void setConnection(int connection);
            
        private:
            struct sockaddr_in m_Address;
            int m_Sock;
            int m_Connection;
            #if defined(_WIN32) || defined(WIN32) 
            WSADATA m_Wsa;  
            #endif
            
    };
}




#endif /* SimpleSocket_h */