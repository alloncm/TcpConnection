#include"NetworkException.h"

NetworkException::NetworkException(const char* message)
    :
    _message(message)
    {}

const char* NetworkException::what() const noexcept
{
    return _message;
}

