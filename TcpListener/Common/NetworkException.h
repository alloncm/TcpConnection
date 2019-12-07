#ifndef NEWTWORKEXCEPTION
#define NEWTWORKEXCEPTION
#include<exception>

class NetworkException : public std::exception
{
public:
    NetworkException(const char* message);
};

#endif

