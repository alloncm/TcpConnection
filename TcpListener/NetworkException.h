#ifndef NEWTWORKEXCEPTION
#define NEWTWORKEXCEPTION
#include<exception>

class NetworkException : public std::exception
{
public:
    NetworkException(const char* message);
    virtual const char* what() const noexcept override;
private:
    const char* _message;
};

#endif

