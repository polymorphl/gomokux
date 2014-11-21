
#include "Gomoku.hpp"
#include "Graphic.hpp"

Gomoku::Gomoku() {
    _winner = 0;
    _ruleOfFive = true;
    _ruleOfThree = true;
    for (int cptX = 0; cptX != 19; cptX++) {
        for (int cptY = 0; cptY != 19; cptY++) {
            _mapRule[cptX][cptY] = 0;
        }
    }
}

void Gomoku::createMap() {
    _winner = 0;
    for (int cptX = 0; cptX != 19; cptX++) {
        for (int cptY = 0; cptY != 19; cptY++) {
            _mapRule[cptX][cptY] = 0;
        }
    }    
}

Gomoku::~Gomoku() {

}

int Gomoku::canIEat(const int& beFree, const int& beTeam, const int& beInvert, const t_flag& team) {
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

int Gomoku::ruleOfFive(const int& y, const int& x, const t_flag& team, const t_direction& dir) {
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

int Gomoku::checkWinVertical(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    if (y - 4 >= 0) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y - i][x] == team  && !ruleOfFive(y - i, x, team, VERTICAL))
                cpt++;
            else
                break;
        }
    }
    if (y + 4 <= 18) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y + i][x] == team && !ruleOfFive(y + i, x, team, VERTICAL))
                cpt++;
            else
                break;
        }
    }
    if (cpt <= 5)
        return 1;
    return 0;
}

int Gomoku::checkWinHorizontal(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    if (x - 4 >= 0) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y][x - i] == team && !ruleOfFive(y, x - i, team, HORIZONTAL))
                cpt++;
            else
                break;
        }
    }
    if (x + 4 <= 18) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y][x + i] == team && !ruleOfFive(y, x + i, team, HORIZONTAL))
                cpt++;
            else
                break;
        }
    }
    if (cpt <= 5)
        return 1;
    return 0;
}

int Gomoku::checkWinDiagonalOne(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    if (y - 4 >= 0 && x - 4 >= 0) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y - i][x - i] == team && !ruleOfFive(y - i, x - i, team, DIAGONALONE))
                cpt++;
            else
                break;
        }
    }
    if (y + 4 <= 18 && x + 4 <= 18) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y + i][x + i] == team && !ruleOfFive(y + i, x + i, team, DIAGONALONE))
                cpt++;
            else
                break;
        }
    }
    if (cpt <= 5)
        return 1;
    return 0;
}

int Gomoku::checkWinDiagonalTwo(const int& y, const int& x, const t_flag& team) {
    int cpt = 0;
    if (y - 4 >= 0 && x + 4 <= 18) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y - i][x + i] == team && !ruleOfFive(y - i, x + i, team, DIAGONALTWO))
                cpt++;
            else
                break;
        }
    }
    if (y + 4 <= 18 && x - 4 >= 0) {
        for (int i = 0; i != 5; i++) {
            if (_mapRule[y + i][x - i] == team && !ruleOfFive(y + i, x - i, team, DIAGONALTWO))
                cpt++;
            else
                break;
        }
    }
    if (cpt <= 5)
        return 1;
    return 0;
}

int Gomoku::launchWatch(const int& y, const int& x, const t_flag& team) {

    if (!checkWinVertical(y, x, team))
        return 0;
    if (!checkWinHorizontal(y, x, team))
        return 0;
    if (!checkWinDiagonalOne(y, x, team))
        return 0;
    if (!checkWinDiagonalTwo(y, x, team))
        return 0;
    return 1;
}

int Gomoku::checkWin(const t_flag& team) {
    for (int i = 0; i != 19; i++) {
        for (int j = 0; j != 19; j++) {
            if (_mapRule[i][j] == team) {
                if (launchWatch(i, j, team) == 0)
                    return 0;                
            }
        }
    }
    if (team == TEAM_1 && _playerOne->getNbPion() >= 10)
        return 0;
    if (team == TEAM_2 && _playerTwo->getNbPion() >= 10)
        return 0;
    return 1;
}

void Gomoku::updateMapRule(const int& coord) {
    _playedX = coord % 19;
    _playedY = coord / 19;
}

t_flag Gomoku::invertTeam(const t_flag& team) {
    if (team == TEAM_1)
        return TEAM_2;
    return TEAM_1;
}

int Gomoku::checkEquality(const int& i, const int& j, const int& k) {
    if (i == j && j == k)
        return 0;
    return 1;
}

void Gomoku::addJackpot(const t_flag& team) {
    if (team == TEAM_1) {
        _playerOne->addPion();
        std::cout << "Joueur " << team << " mange, il a " << _playerOne->getNbPion() << " pions" << std::endl;
    }
    else {
        _playerTwo->addPion();
        std::cout << "Joueur " << team << " mange, il a " << _playerTwo->getNbPion() << " pions" << std::endl;        
    }
}

void Gomoku::checkEatVertical(const t_flag& team) {
    if (_playedY - 3 >= 0) {
        if (_mapRule[_playedY - 3][_playedX] == team && !checkEquality(_mapRule[_playedY - 2][_playedX], _mapRule[_playedY - 1][_playedX], invertTeam(team))) {
            _mapRule[_playedY - 2][_playedX] = FREE;
            _mapRule[_playedY - 1][_playedX] = FREE;
            addJackpot(team);
        }
    }
    if (_playedY + 3 <= 18) {
        if (_mapRule[_playedY + 3][_playedX] == team && !checkEquality(_mapRule[_playedY + 2][_playedX], _mapRule[_playedY + 1][_playedX], invertTeam(team))) {
            _mapRule[_playedY + 2][_playedX] = FREE;
            _mapRule[_playedY + 1][_playedX] = FREE;
            addJackpot(team);
        }
    }
}

void Gomoku::checkEatHorizontal(const t_flag& team) {
    if (_playedX - 3 >= 0) {
        if (_mapRule[_playedY][_playedX - 3] == team && !checkEquality(_mapRule[_playedY][_playedX - 2], _mapRule[_playedY][_playedX - 1], invertTeam(team))) {
            _mapRule[_playedY][_playedX - 2] = FREE;
            _mapRule[_playedY][_playedX - 1] = FREE;
            addJackpot(team);
        }
    }
    if (_playedX + 3 <= 18) {
        if (_mapRule[_playedY][_playedX + 3] == team && !checkEquality(_mapRule[_playedY][_playedX + 2], _mapRule[_playedY][_playedX + 1], invertTeam(team))) {
            _mapRule[_playedY][_playedX + 2] = FREE;
            _mapRule[_playedY][_playedX + 1] = FREE;
            addJackpot(team);
        }
    }
}

void Gomoku::checkEatDiagonalOne(const t_flag& team) {
    if (_playedX - 3 >= 0 && _playedY - 3 >= 0) {
        if (_mapRule[_playedY - 3][_playedX - 3] == team && !checkEquality(_mapRule[_playedY - 2][_playedX - 2], _mapRule[_playedY - 1][_playedX - 1], invertTeam(team))) {
            _mapRule[_playedY - 2][_playedX - 2] = FREE;
            _mapRule[_playedY - 1][_playedX - 1] = FREE;
            addJackpot(team);
        }
    }
    if (_playedX + 3 <= 18 && _playedY + 3 <= 18) {
        if (_mapRule[_playedY + 3][_playedX + 3] == team && !checkEquality(_mapRule[_playedY + 2][_playedX + 2], _mapRule[_playedY + 1][_playedX + 1], invertTeam(team))) {
            _mapRule[_playedY + 2][_playedX + 2] = FREE;
            _mapRule[_playedY + 1][_playedX + 1] = FREE;
            addJackpot(team);
        }
    }
}

void Gomoku::checkEatDiagonalTwo(const t_flag& team) {
    if (_playedX - 3 >= 0 && _playedY + 3 <= 18) {
        if (_mapRule[_playedY + 3][_playedX - 3] == team && !checkEquality(_mapRule[_playedY + 2][_playedX - 2], _mapRule[_playedY + 1][_playedX - 1], invertTeam(team))) {
            _mapRule[_playedY + 2][_playedX - 2] = FREE;
            _mapRule[_playedY + 1][_playedX - 1] = FREE;
            addJackpot(team);
        }
    }
    if (_playedY - 3 >= 0 && _playedX + 3 <= 18) {
        if (_mapRule[_playedY - 3][_playedX + 3] == team && !checkEquality(_mapRule[_playedY - 2][_playedX + 2], _mapRule[_playedY - 1][_playedX + 1], invertTeam(team))) {
            _mapRule[_playedY - 2][_playedX + 2] = FREE;
            _mapRule[_playedY - 1][_playedX + 1] = FREE;
            addJackpot(team);
        }
    }
}


void Gomoku::checkEat(const t_flag& team) {
    checkEatVertical(team);
    checkEatHorizontal(team);
    checkEatDiagonalOne(team);
    checkEatDiagonalTwo(team);
}

void Gomoku::checkThreeVertical(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedY - 2 >= 0)
        if (!checkEquality(_mapRule[_playedY - 1][_playedX], _mapRule[_playedY - 2][_playedX], team))
            cpt++;
    if (_playedY + 2 <= 18)
        if (!checkEquality(_mapRule[_playedY + 1][_playedX], _mapRule[_playedY + 2][_playedX], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

void Gomoku::checkThreeHorizontal(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedX - 2 >= 0)
        if (!checkEquality(_mapRule[_playedY][_playedX - 1], _mapRule[_playedY][_playedX - 2], team))
            cpt++;
    if (_playedX + 2 <= 18)
        if (!checkEquality(_mapRule[_playedY][_playedX + 1], _mapRule[_playedY][_playedX + 2], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

void Gomoku::checkThreeDiagonalOne(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedY - 2 >= 0 && _playedX - 2 >= 0)
        if (!checkEquality(_mapRule[_playedY - 1][_playedX - 1], _mapRule[_playedY - 2][_playedX - 2], team))
            cpt++;
    if (_playedY + 2 <= 18 && _playedX + 2 >= 0)
        if (!checkEquality(_mapRule[_playedY + 1][_playedX + 1], _mapRule[_playedY + 2][_playedX + 2], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

void Gomoku::checkThreeDiagonalTwo(const t_flag& team, int *nbThree) {
    int cpt = 0;
    
    if (_playedY - 2 >= 0 && _playedX + 2 <= 18)
        if (!checkEquality(_mapRule[_playedY - 1][_playedX + 1], _mapRule[_playedY - 2][_playedX + 2], team))
            cpt++;
    if (_playedY + 2 <= 18 && _playedX - 2 >= 0)
        if (!checkEquality(_mapRule[_playedY + 1][_playedX - 1], _mapRule[_playedY + 2][_playedX - 2], team))
            cpt++;
    if (cpt)
        *nbThree = *nbThree + 1;
}

int Gomoku::ruleOfThree(const t_flag& team) {
    int nbThree = 0;
    
    checkThreeVertical(team, &nbThree);
    checkThreeHorizontal(team, &nbThree);
    checkThreeDiagonalOne(team, &nbThree);
    checkThreeDiagonalTwo(team, &nbThree);
    if (nbThree > 1)
        return 1;
    return 0;
}

int Gomoku::checkRules(const t_flag& team) {
    if (_ruleOfThree && ruleOfThree(team))
        return 1;
    checkEat(team);
    _mapRule[_playedY][_playedX] = team;
    if (checkWin(team))
      return -1;
    _winner = team;
    std::cout << "Winner equipe " << _winner << std::endl;
    return 0;
}

int Gomoku::createPlayer(const int& choice)
{
    if (choice == 3 || choice == -1)
        return -1;
    if (choice == 1) {
        _playerOne = new Player(HUMAN);
        _playerTwo = new Player(HUMAN);
    }
    else {
        _playerOne = new Player(HUMAN);
        _playerTwo = new Player(IA);        
    }
    return choice;
}

int Gomoku::getNbPion() const {
    int nbPion = 0;
    
    for (int i = 0; i != 19; i++) {
        for (int j = 0; j != 19; j++) {
            if (_mapRule[i][j] != FREE)
                nbPion++;
        }
    }
    return nbPion;
}
