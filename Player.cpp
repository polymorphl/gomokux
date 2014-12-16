
#include "Player.hpp"

Player::Player(const t_tplayer t, const int& tm) {
    playerType = t;
    nbPion = 0;
    team = tm;
    _ai = new AI(tm);
}

Player::~Player() {
    
}

void Player::addPion() {
    nbPion+= 2;
}
