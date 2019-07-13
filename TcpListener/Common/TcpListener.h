#ifndef TCPLISTENER
#define TCPLISTENER

#include<netinet/in.h>

class TcpClient;
 
class TcpListener
{
public:
    TcpListener(in_addr_t address, int port);
    void Start();
    TcpClient Accept();

private:
    int _queueConnectinsLength; 
    int _serverFd;
    sockaddr_in _address;
    
};



#endif