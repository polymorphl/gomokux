
#include "Player.hpp"

Player::Player(const t_tplayer t, const int& tm) {
    playerType = t;
    nbPion = 0;
    team = tm;
}

Player::~Player() {
    
}

void Player::addPion() {
    nbPion+= 2;
}

//int Player::launchIA() {
//    std::cout << this->_map[0][0] << std::endl;
//    return -20;
//}
