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
  Player(const t_tplayer t, const int& team);
    ~Player();
    int getNbPion()const {return nbPion;}
    int getPlayerType() const {return playerType;}
    void addPion();
//    int launchIA();
private:
    t_tplayer playerType;
    int nbPion;
    int team;
};

#endif	/* PLAYER_HPP */

