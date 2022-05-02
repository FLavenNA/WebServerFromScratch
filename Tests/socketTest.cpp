#include "../Networking/Sockets/ListeningSocket.h"

int main()
{
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Starting... " << std::endl;
    std::cout << "-------------------------------" << std::endl;

    std::cout << "-------------------------------" << std::endl;    
    std::cout << "Binding Socket..." << std::endl;
    BSO::BindingSocket bs = BSO::BindingSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);
    std::cout << "-------------------------------" << std::endl;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Listening Socket..." << std::endl;
    BSO::ListeningSocket ls = BSO::ListeningSocket(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY, 10);
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Success! " << std::endl;

}

        