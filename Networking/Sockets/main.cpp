#include "ListeningSocket.h"

int main()
{
    std::cout << "Starting... " << std::endl;

    /*std::cout << "Binding Socket..." << std::endl;
    BSO::BindingSocket bs = BSO::BindingSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);
    */

    std::cout << "Listening Socket..." << std::endl;
    BSO::ListeningSocket ls = BSO::ListeningSocket(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY, 10);
    std::cout << "Success! " << std::endl;
    
}

 