#ifndef TCPCLIENT
#define TCPCLIENT

#include<netinet/in.h>

class TcpClient
{
public:
    TcpClient(in_addr address, int port);
    TcpClient(int sokcetFd);
    int Receive(char* data, int length);
    int Send(char* data, int length);

private:
    int _clientFd;
};

#endif