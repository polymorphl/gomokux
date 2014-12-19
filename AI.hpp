/* 
 * File:   AI.hpp
 * Author: benjamin
 *
 * Created on December 19, 2014, 1:11 PM
 */

#ifndef AI_HPP
#define	AI_HPP

#include "Rules.hpp"

class AI : public Rules {
public:
    AI();
    ~AI();
    int launchAI(const int tab[19][19], const t_flag&);
    
private:
    int minMax(const t_flag&);
    int min(const t_flag&, const int&);
    int max(const t_flag&, const int&);
    int eval(const t_flag&);
    int verifWin();
    int howManyCoin(const int&, const int&, const t_flag&);
    int higher(const int&, const int&);
};

#endif	/* AI_HPP */

