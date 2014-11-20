#ifndef IA_HPP_
# define IA_HPP_

#include "LuaCommunication.hpp"

class		IA
{
public:
  IA(int team);
  ~IA();

  int	update(int map[19][19], bool three, bool five);
  void	pushEntitie();
  int	getResultScript(const char *fileName);

private:
  LuaCommunication _lua;
  int team;
};

#endif
