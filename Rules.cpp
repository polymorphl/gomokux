
#include "Rules.hpp"
#include "Player.hpp"
#include "Graphic.hpp"

Rules::Rules() {
    _winner = 0;
    _ruleOfFive = true;
    _ruleOfThree = true;
}

Rules::~Rules() {
    
}

int Rules::canIEat(const int& beFree, const int& beTeam, const int& beInvert, const t_flag& team) {
    if (_mapRule[beFree / 19][beFree % 19] != FREE) {
        return 1;
    }
    if (_mapRule[beTeam / 19][beTeam % 19] != team) {
        return 1;
    }
    if (_mapRule[beInvert / 19][beInvert % 19] != invertTeam(team)) {
        return 1;
    }
    return 0;
}

int Rules::ruleOfFive(const int& y, const int& x, const t_flag& team, const t_direction& dir) {
    if (!_ruleOfFive)
        return 0;
    if (dir != VERTICAL) {
        if (y - 2 >= 0 && y + 1 <= 18 && !canIEat(((y + 1) * 19) + x, ((y - 1) * 19) + x, ((y - 2) * 19) + x, team))
            return 1;            
        if (y - 1 >= 0 && y + 2 <= 18 && !canIEat(((y - 1) * 19) + x, ((y + 1) * 19) + x, ((y + 2) * 19) + x, team))
            return 1;
    }
    if (dir != HORIZONTAL) {
        if (x - 2 >= 0 && x + 1 <= 18 && !canIEat((y * 19) + x + 1, (y * 19) + x - 1, (y * 19) + x - 2, team))
            return 1;            
        if (x - 1 >= 0 && x + 2 <= 18 && !canIEat((y * 19) + x - 1, (y * 19) + x + 1, (y * 19) + x + 2, team))
            return 1;
    }
    if (dir != DIAGONALONE) {
        if (x - 2 >= 0 && y - 2 >= 0 && x + 1 <= 18 && y + 1 <= 18 && !canIEat(((y + 1) * 19) + x + 1, ((y - 1) * 19) + x - 1, ((y - 2) * 19) + x - 2, team))
            return 1;            
        if (x - 1 >= 0 && y - 1 >= 0 && x + 2 <= 18 && y + 2 <= 18 && !canIEat(((y - 1) * 19) + x - 1, ((y + 1) * 19) + x + 1, ((y + 2) * 19) + x + 2, team))
            return 1;
    }
    if (dir != DIAGONALTWO) {
        if (x - 2 >= 0 && y + 2 <= 18 && x + 1 <= 18 && y - 1 >= 0 && !canIEat(((y - 1) * 19) + x + 1, ((y + 1) * 19) + x - 1, ((y + 2) * 19) + x - 2, team))
            return 1;            
        if (x - 1 >= 0 && y + 1 <= 18 && x + 2 <= 18 && y - 2 <= 0 && !canIEat(((y + 1) * 19) + x - 1, ((y - 1) * 19) + x + 1, ((y - 2) * 19) + x + 2, team))
            return 1;
    }
    return 0;
}

int Rules::checkWinVertical(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    int verifBlock = 0;
    for (int i = 0; i != 5; i++) {
        if (y - i >= 0) {
            if (_mapRule[y - i][x] == team  && !ruleOfFive(y - i, x, team, VERTICAL))
                cpt++;
            else{
                if (_mapRule[y - i][x] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }
    if (cpt != 0)
        cpt--;
    for (int i = 0; i != 5; i++) {
        if (y + i <= 18) {
            if (_mapRule[y + i][x] == team && !ruleOfFive(y + i, x, team, VERTICAL))
                cpt++;
            else{
                if (_mapRule[y + i][x] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }
//    if (cpt <= 5) {
//        return cpt + 1;        
//    }
//    return 0;
//    (0-5)
    
    if (cpt < 5) {
        if (verifBlock == 1)
            return cpt * -1;
        if (verifBlock >= 2)
            return (cpt * -1) - 5;
        return cpt;
    }
    return 10;

}

int Rules::checkWinHorizontal(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    int verifBlock = 0;
    for (int i = 0; i != 5; i++) {
        if (x - i >= 0) {
            if (_mapRule[y][x - i] == team && !ruleOfFive(y, x - i, team, HORIZONTAL))
                cpt++;
            else{
                if (_mapRule[y][x - i] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }
    if (cpt != 0)
        cpt--;
    for (int i = 0; i != 5; i++) {
        if (x + i <= 18) {
            if (_mapRule[y][x + i] == team && !ruleOfFive(y, x + i, team, HORIZONTAL))
                cpt++;
            else{
                if (_mapRule[y][x + i] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }
//    (0-5)
    
    if (cpt < 5) {
        if (verifBlock == 1)
            return cpt * -1;
        if (verifBlock >= 2)
            return (cpt * -1) - 5;
        return cpt;
    }
    return 10;

}

int Rules::checkWinDiagonalOne(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    int verifBlock = 0;
    for (int i = 0; i != 5; i++) {
        if (y - i >= 0 && x - i >= 0) {
            if (_mapRule[y - i][x - i] == team && !ruleOfFive(y - i, x - i, team, DIAGONALONE))
                cpt++;
            else{
                if (_mapRule[y - i][x - i] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }
    if (cpt != 0)
        cpt--;
    for (int i = 0; i != 5; i++) {
        if (y + i <= 18 && x + i <= 18) {
            if (_mapRule[y + i][x + i] == team && !ruleOfFive(y + i, x + i, team, DIAGONALONE))
                cpt++;
            else{
                if (_mapRule[y + i][x + i] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }
//    (0-5)
    
    if (cpt < 5) {
        if (verifBlock == 1)
            return cpt * -1;
        if (verifBlock >= 2)
            return (cpt * -1) - 5;
        return cpt;
    }
    return 10;

}

int Rules::checkWinDiagonalTwo(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    int verifBlock = 0;
    for (int i = 0; i != 5; i++) {
        if (y - i >= 0 && x + i <= 18) {
            if (_mapRule[y - i][x + i] == team && !ruleOfFive(y - i, x + i, team, DIAGONALTWO))
                cpt++;
            else{
                if (_mapRule[y - i][x + i] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }
    if (cpt != 0)
        cpt--;
    for (int i = 0; i != 5; i++) {
        if (y + i <= 18 && x - i >= 0) {
            if (_mapRule[y + i][x - i] == team && !ruleOfFive(y + i, x - i, team, DIAGONALTWO))
                cpt++;
            else{
                if (_mapRule[y + i][x - i] == invertTeam(team))
                    verifBlock++;
                break;
            }
        }
        else {
            verifBlock++;
            break;
        }
    }

/*
 * (1 | 5) -> alignement bon
 * 0-> gagne
 * (-1 | -5) -> alignement bloque 1
 * (-6 | -10) -> alignement bloque 2
 */    
//    (0-4)
//    if (cpt < 5) {
////        if (verifBlock == 1)
////            return -3;
//        if (verifBlock >= 2)
//            return -2;        
//        return cpt;
//    }
//    return -1;
    
    if (cpt < 5) {
        if (verifBlock == 1)
            return cpt * -1;
        if (verifBlock >= 2)
            return (cpt * -1) - 5;
        return cpt;
    }
    return 10;
}

int Rules::launchWatch(const int& y, const int& x, const t_flag& team) {

    if (checkWinVertical(y, x, team) == 10)
        return 0;
    if (checkWinHorizontal(y, x, team) == 10)
        return 0;
    if (checkWinDiagonalOne(y, x, team) == 10)
        return 0;
    if (checkWinDiagonalTwo(y, x, team) == 10)
        return 0;
    return 1;
}

int Rules::checkWin(const t_flag& team) {
    for (int i = 0; i != 19; i++) {
        for (int j = 0; j != 19; j++) {
            if (_mapRule[i][j] == team) {
                if (launchWatch(i, j, team) == 0)
                    return 0;
            }
        }
    }
//    if (team == TEAM_1 && _playerOne->getNbPion() >= 10)
//        return 0;
//    if (team == TEAM_2 && _playerTwo->getNbPion() >= 10)
//        return 0;
    return 1;
}

int Rules::checkWin(const t_flag& team, Player& pl) {
    for (int i = 0; i != 19; i++) {
        for (int j = 0; j != 19; j++) {
            if (_mapRule[i][j] == team) {
                if (launchWatch(i, j, team) == 0) {
                    return 0;
                }
            }
        }
    }
    if (pl.getNbPion() >= 10)
        return 0;
    return 1;
}

int Rules::checkEquality(const int& i, const int& j, const int& k) {
    if (i == j && j == k)
        return 0;
    return 1;
}

void Rules::addJackpot(const t_flag& team, Player& pl) {
    pl.addPion();
    std::cout << CYAN << "Player " << team - 1 << " eat, he has " << pl.getNbPion() << " points" << END << std::endl;
}

void Rules::checkEatVertical(const t_flag& team, Player& pl) {
    if (_playedYRules - 3 >= 0) {
        if (_mapRule[_playedYRules - 3][_playedXRules] == team && !checkEquality(_mapRule[_playedYRules - 2][_playedXRules], _mapRule[_playedYRules - 1][_playedXRules], invertTeam(team))) {
            _mapRule[_playedYRules - 2][_playedXRules] = FREE;
            _mapRule[_playedYRules - 1][_playedXRules] = FREE;
            addJackpot(team, pl);
        }
    }
    if (_playedYRules + 3 <= 18) {
        if (_mapRule[_playedYRules + 3][_playedXRules] == team && !checkEquality(_mapRule[_playedYRules + 2][_playedXRules], _mapRule[_playedYRules + 1][_playedXRules], invertTeam(team))) {
            _mapRule[_playedYRules + 2][_playedXRules] = FREE;
            _mapRule[_playedYRules + 1][_playedXRules] = FREE;
            addJackpot(team, pl);
        }
    }
}

void Rules::checkEatHorizontal(const t_flag& team, Player& pl) {
    if (_playedXRules - 3 >= 0) {
        if (_mapRule[_playedYRules][_playedXRules - 3] == team && !checkEquality(_mapRule[_playedYRules][_playedXRules - 2], _mapRule[_playedYRules][_playedXRules - 1], invertTeam(team))) {
            _mapRule[_playedYRules][_playedXRules - 2] = FREE;
            _mapRule[_playedYRules][_playedXRules - 1] = FREE;
            addJackpot(team, pl);
        }
    }
    if (_playedXRules + 3 <= 18) {
        if (_mapRule[_playedYRules][_playedXRules + 3] == team && !checkEquality(_mapRule[_playedYRules][_playedXRules + 2], _mapRule[_playedYRules][_playedXRules + 1], invertTeam(team))) {
            _mapRule[_playedYRules][_playedXRules + 2] = FREE;
            _mapRule[_playedYRules][_playedXRules + 1] = FREE;
            addJackpot(team, pl);
        }
    }
}

void Rules::checkEatDiagonalOne(const t_flag& team, Player& pl) {
    if (_playedXRules - 3 >= 0 && _playedYRules - 3 >= 0) {
        if (_mapRule[_playedYRules - 3][_playedXRules - 3] == team && !checkEquality(_mapRule[_playedYRules - 2][_playedXRules - 2], _mapRule[_playedYRules - 1][_playedXRules - 1], invertTeam(team))) {
            _mapRule[_playedYRules - 2][_playedXRules - 2] = FREE;
            _mapRule[_playedYRules - 1][_playedXRules - 1] = FREE;
            addJackpot(team, pl);
        }
    }
    if (_playedXRules + 3 <= 18 && _playedYRules + 3 <= 18) {
        if (_mapRule[_playedYRules + 3][_playedXRules + 3] == team && !checkEquality(_mapRule[_playedYRules + 2][_playedXRules + 2], _mapRule[_playedYRules + 1][_playedXRules + 1], invertTeam(team))) {
            _mapRule[_playedYRules + 2][_playedXRules + 2] = FREE;
            _mapRule[_playedYRules + 1][_playedXRules + 1] = FREE;
            addJackpot(team, pl);
        }
    }
}

void Rules::checkEatDiagonalTwo(const t_flag& team, Player& pl) {
    if (_playedXRules - 3 >= 0 && _playedYRules + 3 <= 18) {
        if (_mapRule[_playedYRules + 3][_playedXRules - 3] == team && !checkEquality(_mapRule[_playedYRules + 2][_playedXRules - 2], _mapRule[_playedYRules + 1][_playedXRules - 1], invertTeam(team))) {
            _mapRule[_playedYRules + 2][_playedXRules - 2] = FREE;
            _mapRule[_playedYRules + 1][_playedXRules - 1] = FREE;
            addJackpot(team, pl);
        }
    }
    if (_playedYRules - 3 >= 0 && _playedXRules + 3 <= 18) {
        if (_mapRule[_playedYRules - 3][_playedXRules + 3] == team && !checkEquality(_mapRule[_playedYRules - 2][_playedXRules + 2], _mapRule[_playedYRules - 1][_playedXRules + 1], invertTeam(team))) {
            _mapRule[_playedYRules - 2][_playedXRules + 2] = FREE;
            _mapRule[_playedYRules - 1][_playedXRules + 1] = FREE;
            addJackpot(team, pl);
        }
    }
}


void Rules::checkEat(const t_flag& team, Player& pl) {
    checkEatVertical(team, pl);
    checkEatHorizontal(team, pl);
    checkEatDiagonalOne(team, pl);
    checkEatDiagonalTwo(team, pl);
}

void Rules::checkThreeVertical(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedYRules - 2 >= 0)
        if (!checkEquality(_mapRule[_playedYRules - 1][_playedXRules], _mapRule[_playedYRules - 2][_playedXRules], team))
            cpt++;
    if (_playedYRules + 2 <= 18)
        if (!checkEquality(_mapRule[_playedYRules + 1][_playedXRules], _mapRule[_playedYRules + 2][_playedXRules], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

void Rules::checkThreeHorizontal(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedXRules - 2 >= 0)
        if (!checkEquality(_mapRule[_playedYRules][_playedXRules - 1], _mapRule[_playedYRules][_playedXRules - 2], team))
            cpt++;
    if (_playedXRules + 2 <= 18)
        if (!checkEquality(_mapRule[_playedYRules][_playedXRules + 1], _mapRule[_playedYRules][_playedXRules + 2], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

void Rules::checkThreeDiagonalOne(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedYRules - 2 >= 0 && _playedXRules - 2 >= 0)
        if (!checkEquality(_mapRule[_playedYRules - 1][_playedXRules - 1], _mapRule[_playedYRules - 2][_playedXRules - 2], team))
            cpt++;
    if (_playedYRules + 2 <= 18 && _playedXRules + 2 >= 0)
        if (!checkEquality(_mapRule[_playedYRules + 1][_playedXRules + 1], _mapRule[_playedYRules + 2][_playedXRules + 2], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

void Rules::checkThreeDiagonalTwo(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedYRules - 2 >= 0 && _playedXRules + 2 <= 18)
        if (!checkEquality(_mapRule[_playedYRules - 1][_playedXRules + 1], _mapRule[_playedYRules - 2][_playedXRules + 2], team))
            cpt++;
    if (_playedYRules + 2 <= 18 && _playedXRules - 2 >= 0)
        if (!checkEquality(_mapRule[_playedYRules + 1][_playedXRules - 1], _mapRule[_playedYRules + 2][_playedXRules - 2], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

int Rules::ruleOfThree(const t_flag& team) {
    int nbThree = 0;
    
    checkThreeVertical(team, &nbThree);
    checkThreeHorizontal(team, &nbThree);
    checkThreeDiagonalOne(team, &nbThree);
    checkThreeDiagonalTwo(team, &nbThree);
    if (nbThree > 1)
        return 1;
    return 0;
}

t_flag Rules::invertTeam(const t_flag& team) {
    if (team == TEAM_1)
        return TEAM_2;
    return TEAM_1;
}


int Rules::checkRules(const t_flag& team) {
    if (_ruleOfThree && ruleOfThree(team))
        return 1;
//    checkEat(team);
    _mapRule[_playedYRules][_playedXRules] = team;
    if (checkWin(team))
        return -1;
    _winner = team;
    return 0;
}

int Rules::checkRules(const t_flag& team, Player& pl) {
    if (_ruleOfThree && ruleOfThree(team))
        return 1;
    checkEat(team, pl);
    _mapRule[_playedYRules][_playedXRules] = team;
    if (checkWin(team, pl))
        return -1;
    _winner = team;
    return 0;
}