#include "IA.hpp"

IA::IA(int team)
  : _lua(), team(team)
{
}

IA::~IA()
{
}

int	IA::update(int map[19][19], bool three, bool five)
{
  (void)map;
  (void)three;
  (void)five;
  //   // le push entitie
  //  return (getResultScript("ai/main.lua"));
  return -20;
}

void	IA::pushEntitie()
{
  // _lua.pushCreateTable(((aggro * 2) * (aggro * 2) * 4) + 9);
}

int	IA::getResultScript(const char *fileName)
{
  _lua.pushSetGlobal("arg");
  _lua.executeLua(fileName);
  return (_lua.getDatas());
}
