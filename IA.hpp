#ifndef IA_HPP_
# define IA_HPP_

#include <cmath>

class		IA
{
public:
  IA();
  ~IA();

  void	update();
  void	pushEntitie(int x, int y, int *cnt, int aggro);
  int	  getResultScript(const char * fileName);

private:
  LuaCommunication _lua;
};

#endif
