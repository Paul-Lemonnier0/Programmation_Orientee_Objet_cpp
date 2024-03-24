#include "resultatexception.h"

const char *resultatexception::what() const noexcept
{
    const char * what_msg = _msg.c_str();
    return what_msg;
}
