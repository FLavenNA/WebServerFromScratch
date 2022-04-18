#include "BindingSocket.h"

int BSO::BindingSocket::connectToNetwork(int sock, struct sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}