
#include "Exception.hpp"

MyException::MyException (const std::string& where, const std::string& what) throw()
{
  _where = where;
  _what = what;
}

MyException::~MyException () throw()
{

}

const char*             MyException::what() const throw()
{
  std::string           tmp(_what);
  
  return tmp.c_str();
}

const char*             MyException::where() const throw()
{
  std::stringstream           ss;
  
  ss << "[ERROR] In function " << _where << ": ";
  std::string                   result(ss.str());
  return result.c_str();
}
