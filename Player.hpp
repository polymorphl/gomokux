/* 
 * File:   Player.hpp
 * Author: benjamin
 *
 * Created on October 16, 2014, 2:46 PM
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

enum t_tplayer {
    HUMAN, IA
};

class Player {
public:
    Player(const t_tplayer t);
    ~Player();
    int getNbPion()const {return nbPion;}
    void addPion();
private:
    t_tplayer playerType;
    int nbPion;
};

#endif	/* PLAYER_HPP */

