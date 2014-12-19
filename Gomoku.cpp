
#include "Gomoku.hpp"
#include "Graphic.hpp"

Gomoku::Gomoku() {
    for (int cptX = 0; cptX != 19; cptX++) {
        for (int cptY = 0; cptY != 19; cptY++) {
            _map[cptX][cptY] = 0;
        }
    }
}

void Gomoku::createMap() {
    //map a modif
    this->setWinner(0);
    for (int cptX = 0; cptX != 19; cptX++) {
        for (int cptY = 0; cptY != 19; cptY++) {
            _map[cptX][cptY] = 1;
        }
    }    
}

Gomoku::~Gomoku() {

}

void Gomoku::updateMapRule(const int& coord) {
    //modif de playedX et playedY
    _playedX = coord % 19;
    _playedY = coord / 19;
    for (int cptY = 0; cptY != 19; cptY++) {
        for (int cptX = 0; cptX != 19; cptX++) {
            _mapRule[cptY][cptX] = _map[cptY][cptX];
        }
    }
}


int Gomoku::createPlayer(const int& choice)
{
    if (choice == 3 || choice == -1)
        return -1;
    if (choice == 1) {
      _playerOne = new Player(HUMAN, TEAM_1);
        _playerTwo = new Player(HUMAN, TEAM_2);
    }
    else {
        std::cout << "humain ia" << std::endl;
        _playerOne = new Player(HUMAN, TEAM_1);
        _playerTwo = new Player(IA, TEAM_2);
    }
    return choice;
}

int Gomoku::getNbPion() const {
    int nbPion = 0;
    
    for (int i = 0; i != 18; i++) {
        for (int j = 0; j != 18; j++) {
            if (_map[i][j] != FREE)
                nbPion++;
        }
    }
    return nbPion;
}

void Gomoku::copyMapRule() {
    for (int cptY = 0; cptY != 19; cptY++) {
        for (int cptX = 0; cptX != 19; cptX++) {
            _map[cptY][cptX] = _mapRule[cptY][cptX];
        }
    }   
}

int Gomoku::launchJudge(const t_flag& team) {
    int ret;
    this->_playedXRules = _playedX;
    this->_playedYRules = _playedY;
    if (team == TEAM_1)
        ret = this->checkRules(team, *_playerOne);
    else
        ret = this->checkRules(team, *_playerTwo);
    
    if (ret == -1)
        copyMapRule();
    
    return ret;
}