//
// Exception.hpp for nbbler in /tmp/cpp_nibbler
// 
// Made by nadalie thomas
// Login   <nadali_t@epitech.net>
// 
// Started on  Sun Apr  6 20:52:29 2014 nadalie thomas
// Last update Sun Apr  6 20:52:33 2014 nadalie thomas
//

#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

#include        <iostream>
#include        <sstream>
#include        <exception>

class MyException : public std::exception
{
public:
  MyException (const std::string& where, const std::string& what) throw();
  virtual ~MyException() throw();
  virtual const char* what() const throw();
  virtual const char* where() const throw();
 
private:
  std::string       _what;
  std::string       _where;
};

#endif	/* EXCEPTION_HPP */

