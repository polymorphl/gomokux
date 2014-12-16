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
  (void)map;
  (void)three;
  (void)five;
  //   // le push entitie
   return (getResultScript("ai/main.lua"));
}

void	AI::pushEntitie()
{
  // _lua.pushCreateTable(((aggro * 2) * (aggro * 2) * 4) + 9);
}

int	AI::getResultScript(const char *fileName)
{
  // doit allouer la stack
  // _lua.pushSetGlobal("arg");
  _lua.executeLua(fileName);
  return (_lua.getDatas());
}
