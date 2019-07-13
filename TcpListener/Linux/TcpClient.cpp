#include"../Common/TcpClient.h"
#include<sys/socket.h>
#include<unistd.h>
#include<string>
#include"../Common/NetworkException.h"

TcpClient::TcpClient(in_addr address, int port)
{
    sockaddr_in serverAddress;
    serverAddress.sin_addr = address;
    serverAddress.sin_port = port;
    serverAddress.sin_family = AF_INET;
    if((_clientFd = socket(AF_INET,SOCK_STREAM,0))<0)
    {
        throw NetworkException("Error while creating socket descriptor");
    }
    if(connect(_clientFd, (const sockaddr *)&serverAddress, sizeof(serverAddress))<0)
    {
        throw NetworkException("Error while creating socket descriptor");
    }
}
TcpClient::TcpClient(int socketFd)
{
    _clientFd = socketFd;
}

int TcpClient::Receive(char* data, int length)
{
    return read(_clientFd, data, length);
}
int TcpClient::Send(char* data, int length)
{
    return send(_clientFd, data,length,0);
}