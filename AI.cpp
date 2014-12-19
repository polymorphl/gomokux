
#include "AI.hpp"

AI::AI() {
    
}

AI::~AI() {
    
}

int AI::higher(const int& a, const int& b) {
    if (a > b)
        return a;
    return b;
}

int AI::howManyCoin(const int& x, const int& y, const t_flag& team) {
    //compter le nombre de pion, horizontal, veritcal, diag un et diag deux
    t_flag tmpCase;
    int coin = 0;
    int coin2 = 0;
    
    if (team == _mapRule[y][x])
        tmpCase = team;
    else
        tmpCase = invertTeam(team);
    coin = higher(checkWinDiagonalOne(y, x, tmpCase), checkWinDiagonalTwo(y, x, tmpCase));
    coin2 = higher(checkWinHorizontal(y, x, tmpCase), checkWinVertical(y, x, tmpCase));
    coin = higher(coin, coin2);
    
    coin -= 2;
//    std::cout << "coin :::::: " << coin << std::endl;
    if (team != _mapRule[y][x])
        coin *= -1;
    return coin;
    //renvois le nombre de pion maximal (avec un *= -1 si la case est egal à invert team)
}

int AI::eval(const t_flag& team) {
    //attention a verifier la gagna avec -1000 et +1000
    if (verifWin() == team) {
        std::cout << "strat gagnante" << std::endl;
        return -1000;
    }
    if (verifWin() == invertTeam(team)) {
        std::cout << "strat perdante" << std::endl;
        return 1000;        
    }
    
    int valueMin = 1000, valueMax = -1000;
    int cptPion;
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_mapRule[y][x] != FREE && _mapRule[y][x] != TRY) {
                cptPion = howManyCoin(x, y, team);
                cptPion *= 100;
                if (cptPion < 0 && valueMin > cptPion)
                    valueMin = cptPion;
                else if (cptPion > 0 && valueMax < cptPion)
                    valueMax = cptPion;                
            }
        }
    }
    valueMin *= -1;
    if (valueMax > valueMin)
        return valueMax;
    return valueMin;
}

int AI::verifWin() {
    if (!checkWin(TEAM_1))
        return 1;
    if (!checkWin(TEAM_2))
        return 2;
    return 0;
    // faudrais verifier avec les pion aussi
}

int AI::min(const t_flag& team, const int& profondeur) {
    if (profondeur == 0 || verifWin())
        return eval(team);
    
    int min = 1000;
    int tmp;

    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_mapRule[y][x] == FREE) {
                _mapRule[y][x] = team;
                tmp = max(team, profondeur - 1);

                if (tmp < min || ( (tmp == min) && (rand()%10 == 0) ))
                    min = tmp;
                _mapRule[y][x] = 1;
            }
        }
    }
    return min;
}

int AI::max(const t_flag& team, const int& profondeur) {
    if (profondeur == 0 || verifWin() == 0)
        return eval(team);
    
    int max = -1000;
    int tmp;

    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_mapRule[y][x] == FREE) {
                _mapRule[y][x] = invertTeam(team);
                tmp = min(team, profondeur - 1);

                if (tmp > max || ( (tmp == max) && (rand()%10 == 0) ) )
                    max = tmp;
                _mapRule[y][x] = 1;
            }
        }
    }
    return max;
}

int AI::minMax(const t_flag& team) {
    int max = -1000;
    int tmp, maxY = 0, maxX = 0;
    int profondeur = 2;
    
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_mapRule[y][x] == FREE) {
                _mapRule[y][x] = team;
                tmp = min(team, profondeur - 1);
                
                if (tmp > max || ( (tmp == max) && (rand()%10 == 0) ) ) {
                    max = tmp;
                    maxY = y;
                    maxX = x;
                }
                _mapRule[y][x] = 1;
            }
        }
    }
    return (maxY * 19) + maxX;
}

/*
 need
 *  map : good
 *  option : good
 * numero de team
 * les player ou le nombre de pion
 */
int AI::launchAI(const int tab[19][19], const t_flag& team) {
    int toRet;
    //attention a la copi de map rule
    std::cout << "[ia entre]" << std::endl;
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            _mapRule[y][x] = tab[y][x];
        }
    }
    toRet = minMax(team);
    std::cout << "[ia sort : " << toRet << " ]" << std::endl;
    return toRet;
}