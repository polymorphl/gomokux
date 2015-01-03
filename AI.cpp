
#include "AI.hpp"

AI::AI(const t_ia_type& t) {
    _type = t;
}

AI::~AI() {
    
}

int AI::higher(const int& a, const int& b) {
    if (a > b)
        return a;
    return b;
}

int AI::verifAlign(std::vector<int> tab) {
    int ret = 0;
    
    for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it) {
        if ((*it) < 0 && (*it) > -5)
            (*it) = (*it) * -1;
        if ((*it) > ret)
            ret = (*it);
    }
    return ret;
}

int AI::howManyCoin(const int& x, const int& y) {
    std::vector<int> tab;
    t_flag teams;
    int ret;
    if (_mapRule[y][x] == _initTeam)
        teams = _initTeam;
    else
        teams = invertTeam(_initTeam);
    
    tab.push_back(checkWinDiagonalOne(y, x, teams));
    tab.push_back(checkWinDiagonalTwo(y, x, teams));
    tab.push_back(checkWinHorizontal(y, x, teams));
    tab.push_back(checkWinVertical(y, x, teams));
    ret = verifAlign(tab);
    
    ret = ret * 100;
    return ret;
}

int AI::verifEat(const int& x, const int& y) {
    t_flag team;
    int ret = 0;

    if (_mapRule[y][x] == _initTeam)
        team = _initTeam;
    else
        team = invertTeam(_initTeam);
    if ((y - 2 >= 0 && y + 1 <= 18 && !canIEat(((y + 1) * 19) + x, ((y - 1) * 19) + x, ((y - 2) * 19) + x, team)) ||
            (y - 1 >= 0 && y + 2 <= 18 && !canIEat(((y - 1) * 19) + x, ((y + 1) * 19) + x, ((y + 2) * 19) + x, team)) || 
            (x - 2 >= 0 && x + 1 <= 18 && !canIEat((y * 19) + x + 1, (y * 19) + x - 1, (y * 19) + x - 2, team)) ||
            (x - 1 >= 0 && x + 2 <= 18 && !canIEat((y * 19) + x - 1, (y * 19) + x + 1, (y * 19) + x + 2, team)) ||
            (x - 2 >= 0 && y - 2 >= 0 && x + 1 <= 18 && y + 1 <= 18 && !canIEat(((y + 1) * 19) + x + 1, ((y - 1) * 19) + x - 1, ((y - 2) * 19) + x - 2, team)) ||
            (x - 1 >= 0 && y - 1 >= 0 && x + 2 <= 18 && y + 2 <= 18 && !canIEat(((y - 1) * 19) + x - 1, ((y + 1) * 19) + x + 1, ((y + 2) * 19) + x + 2, team)) ||
            (x - 2 >= 0 && y + 2 <= 18 && x + 1 <= 18 && y - 1 >= 0 && !canIEat(((y - 1) * 19) + x + 1, ((y + 1) * 19) + x - 1, ((y + 2) * 19) + x - 2, team)) ||
            (x - 1 >= 0 && y + 1 <= 18 && x + 2 <= 18 && y - 2 <= 0 && !canIEat(((y + 1) * 19) + x - 1, ((y - 1) * 19) + x + 1, ((y - 2) * 19) + x + 2, team))) {
        if (team == _initTeam)
            ret = ((_nbPionTwo / 2) + 1) * 100;
        else
            ret = ((_nbPionOne / 2) + 1) * 100;
    }
    return ret + 1000;
}

int AI::checkBlock(const int& x, const int& y) {
    std::vector<int> tab;
    int ret = 0;

    tab.push_back(checkWinDiagonalOne(y, x, invertTeam(_initTeam)));
    tab.push_back(checkWinDiagonalTwo(y, x, invertTeam(_initTeam)));
    tab.push_back(checkWinHorizontal(y, x, invertTeam(_initTeam)));
    tab.push_back(checkWinVertical(y, x, invertTeam(_initTeam)));
    
    for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it) {
        if ((*it) < 0 && (*it) >= -5)
            ret += ((*it) * -1) * 200;
        else if ((*it) < -5 && (*it) >= -10)
            ret += ((*it) * -1) * 200;
    }
    return ret;
}

int AI::eval() {
    int ret = 0;
    int retEat = 0;
    int max = -1000000000;

    if (verifWin() == _initTeam)
        return 1000000000;        
    if (verifWin() == invertTeam(_initTeam))
        return -1000000000;
    
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_mapRule[y][x] != FREE && _mapRule[y][x] != TRY) {
                retEat = verifEat(x, y);
                ret += howManyCoin(x, y);
                ret = ret + retEat;
                if (_type == DEF && _mapRule[y][x] == invertTeam(_initTeam))
                    ret += checkBlock(x, y);

                if (ret > max)
                    max = ret;
            }
        }
    }
    return max;
}

int AI::verifWin() {
    if (!checkWin(TEAM_1))
        return TEAM_1;
    if (!checkWin(TEAM_2))
        return TEAM_2;
    return 0;
}

int AI::negamax(const t_flag& team, const int& profondeur) {
    int max;
    int tmp;

    max = eval();
    if (profondeur == 0 || verifWin() != 0)
        return max;
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_mapRule[y][x] == FREE) {
                _mapRule[y][x] = team;
                
                tmp = negamax(invertTeam(team), profondeur - 1);

                if ((tmp > max))
                    max = tmp;
                _mapRule[y][x] = FREE;
            }
        }
    }
    return max;
}

int AI::minMax(const t_flag& team) {
    int max = -1000000000;
    int tmp, maxY = 0, maxX = 0;
    int profondeur = 1;
    
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_mapRule[y][x] == FREE) {
                _mapRule[y][x] = team;
                
                tmp = negamax(invertTeam(team), profondeur - 1);
                
                if (tmp > max) {
                    max = tmp;
                    maxY = y;
                    maxX = x;
                }                
                _mapRule[y][x] = FREE;
            }
        }
    }
    return (maxY * 19) + maxX;
}

void AI::displayInfo(const int& poid) {
    std::cout << YELLOW << "\n\n";
    std::cout << "------------------------" << std::endl;
    std::cout << "Poid = " << poid << std::endl;
    for (int i = 0; i != 19; i++) {
        std::cout << "    ";
        for (int j = 0; j!= 19; j++) {
            std::cout << _mapRule[i][j];
        }
        std::cout << END << std::endl;
    }
}


int AI::launchAI(const int tab[19][19], const t_flag& team, const int& pionOne, const int& pionTwo) {
    int toRet;

    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            _mapRule[y][x] = tab[y][x];
        }
    }
    _nbPionOne = pionOne;
    _nbPionTwo = pionTwo;
    _initTeam = team;
    toRet = minMax(team);
    std::cout << MAGENTA << "[IA] Value ask : " << toRet << END << std::endl;
    return toRet;
}
