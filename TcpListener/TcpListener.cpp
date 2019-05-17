#include"TcpListener.h"
#include<string>
#include<sys/socket.h>
#include"TcpClient.h"
#include"NetworkException.h"

TcpListener::TcpListener(in_addr_t address, int port)
{
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = address;
    _address.sin_port = port;
}

void TcpListener::Start()
{
    int opt = 1;
    if((_serverFd = socket(AF_INET,SOCK_STREAM,0))==0)
    {
        throw NetworkException("Error while creating socket descriptor");
    }

    if(setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        throw NetworkException("Error while setting the socket");
    }

    if(bind(_serverFd, (sockaddr *) &_address,sizeof(_address))<0)
    {
        throw NetworkException("Error while binding the socket");
    }

    if(listen(_serverFd, _queueConnectinsLength)<0)
    {
        throw NetworkException("Error while starting to listen");
    }
}

TcpClient TcpListener::Accept()
{
    int clientFd;
    int addrlen = sizeof(_address);
    if((clientFd = accept(_serverFd, (sockaddr*)&_address, (socklen_t*)&addrlen))<0)
    {
        throw NetworkException("Error while accepting connection");
    }

    return TcpClient(clientFd);
}

