#pragma once

#include <exception>

namespace zzpal
{

class Exception:std::exception
{
public:
    explicit Exception(std::string& what_arg);
    explicit Exception(const char* what_arg);
    vrtual ~Exception() throw();

    virtual const char* what() const throw();
    const char* stackTrace() const throw();

private:
    void fillStackTrace();
  
    string _message;
    string _stack;    


}; //end of class Exception

} // end of namespace zzpal