#ifndef LUACOMMUNICATION_HPP_
# define LUACOMMUNICATION_HPP__

# include <lua.h>
# include <iostream>
# include <sstream>

class LuaCommunication
{
public:
  LuaCommunication();
  ~LuaCommunication();

  void	pushCreateTable(const int nb);
  void  pushIntString(const int index, const char *val) const;
  void  pushStringString(const char *index, const char *val) const;
  void  pushIntInt(const int index, const int val) const;
  void  pushStringInt(const char *index, const int val) const;
  void	pushSetGlobal(const char *name) const;
  void	executeLua(const char *name);
  void	closeState() const;
  void	popStack() const;
  int   getDatas();

  lua_State* getState() const;

private:
  lua_State*	_luaState;
  int 		    _status;
};

#endif
