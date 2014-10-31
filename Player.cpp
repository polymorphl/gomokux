
#include "Player.hpp"

Player::Player(const t_tplayer t) {
    playerType = t;
    nbPion = 0;
}

Player::~Player() {
    
}

void Player::addPion() {
    nbPion+= 2;
}