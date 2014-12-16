#ifndef AI_HPP_
# define AI_HPP_

#include "LuaCommunication.hpp"

class		AI
{
public:
  AI(int team);
  ~AI();

  int	update(int map[19][19], bool three, bool five);
  void	pushEntitie();
  int	getResultScript(const char *fileName);

private:
  LuaCommunication _lua;
  int team;
};

#endif
