#Include "exception.h"

namespace zzpal
{
    Exception::Exception(std::string& what_arg):
    _message(what_arg)
    {

    }
    Exception::Exception(const char* what_arg)
    _message(what_arg)
    {

    }
    Exception::~Exception()
    {

    }

    const char* what() const throw()
    {
        return _message.c_str();
    }
    const char* stackTrace() const throw()
    {
        return _stack.c_str();
    }

    void Exception::fillStackTrace()
    {

    }
   


}; //end of class Exception

} // e