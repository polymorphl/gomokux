#include "AI.hpp"

AI::AI(int team)
  : _lua(), team(team)
{
}

AI::~AI()
{
}

int	AI::update(int map[19][19], bool three, bool five)
{
  _lua.pushCreateTable(19*19 + 3);
  (void)map;
  (void)three;
  (void)five;

  _lua.pushStringInt("three", (int)three);
  _lua.pushStringInt("five", (int)five);
  pushEntitie(map);
  return (getResultScript("ai/main.lua"));
}

void	AI::pushEntitie(int map[19][19])
{
  int a = 0;
  int b = 0;
  int c = 1;

  while (a < 19)
    {
      b = 0;
      while (b < 19)
        {
          _lua.pushIntInt(c, map[a][b]);
          ++c;
          ++b;
        }
      ++a;
    }
}

int	AI::getResultScript(const char *fileName)
{
  _lua.pushSetGlobal("stack");
  _lua.executeLua(fileName);
  return (_lua.getDatas());
}
