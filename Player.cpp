
#include "Player.hpp"

Player::Player(const t_tplayer t, const int& tm, const int& type) {
    playerType = t;
    nbPion = 0;
    team = tm;
    _type = type;
}

Player::~Player() {
    
}

void Player::addPion() {
    nbPion+= 2;
}
