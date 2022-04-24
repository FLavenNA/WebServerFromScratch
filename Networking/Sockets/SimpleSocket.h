#ifndef SimpleSocket_h
#define SimpleSocket_h

#include <stdio.h>
#include <iostream>
#include <WinSock2.h>


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
            WSADATA m_Wsa;  
            

    };
}




#endif /* SimpleSocket_h */