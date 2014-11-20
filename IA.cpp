#include "IA.hpp"

IA::IA()
  : _lua()
{
}

IA::~IA()
{
}

void	IA::update()
{
  // int res = getResultScript(aggro[_level - 1], static_cast<int>(_orient), "ai/main.lua");
}

void	IA::pushEntitie(int x, int y, int *cnt, int aggro)
{
  // int c1 = 1;
  // int c2 = 1;

  // for (int i = y ; i < y + (aggro * 2) + 1; ++i)
  //   {
  //     c2 = 1;
  //     for (int j = x ; j < x + (aggro * 2) + 1; ++j)
  //     	{
  //     	  int type = _gameInfo->map->checkMapColision(j, i);
  //     	  if (*cnt == 0)
  //     	    _lua.pushCreateTable(((aggro * 2) * (aggro * 2) * 4) + 9);
  //     	  Flame	*ff;
  //     	  if ((ff = static_cast<Flame*>(_gameInfo->map->getEntityIf(j, i, FLAME))) != NULL)
  //     	    put_abstract_flame(ff, i, j, c1, c2, cnt);
  //     	  if (i == std::floor(_y) && j == std::floor(_x))
  //     	    {
  //     	      if (type == BOMB || _gameInfo->map->getEntityIf(j, i, BOMB) != NULL)
  //     	      	_lua.pushStringInt("bomb", 1);
  //     	      else
  //     	      	_lua.pushStringInt("bomb", 0);
  //     	      _lua.pushStringInt("y", c1);
  //     	      _lua.pushStringInt("x", c2);
  //     	    }
  //     	  _lua.pushIntInt(++(*cnt), type);
  //     	  _lua.pushIntInt(++(*cnt), c1);
  //     	  _lua.pushIntInt(++(*cnt), c2);
  //     	  ++c2;
  //     	}
  //     ++c1;
  //   }
}

int	IA::getResultScript(const char *fileName)
{
  // _lua.pushStringInt("orientation", orient);
  // _lua.pushStringInt("bomb_range", 4);
  // _lua.pushStringInt("level", _level);
  // _lua.pushStringInt("aggro", aggro);
  // _lua.pushSetGlobal("arg");
  // _lua.executeLua(fileName);
  // return (_lua.getDatas());
}
