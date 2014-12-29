/* 
 * File:   AI.hpp
 * Author: benjamin
 *
 * Created on December 19, 2014, 1:11 PM
 */

#ifndef AI_HPP
#define	AI_HPP

#include "Rules.hpp"

enum t_ia_type {
    ATT, DEF
};

class AI : public Rules {
public:
    AI(const t_ia_type&);
    ~AI();
    int launchAI(const int tab[19][19], const t_flag&, const int&, const int&);
    void displayInfo(const int&);
private:
    int _nbPionOne;
    int _nbPionTwo;
    t_flag _initTeam;
    t_ia_type _type;
    int minMax(const t_flag&);
    int min(const t_flag&, const int&);
    int max(const t_flag&, const int&);
    int eval();
    int verifWin();
    int howManyCoin(const int&, const int&);
    int higher(const int&, const int&);
    int negamax(const t_flag&, const int&);
    int verifEat(const int&, const int&);
    int checkBlock(const int&, const int&);
    int verifAlign(std::vector<int>);
};

#endif	/* AI_HPP */

