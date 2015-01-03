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
  Player(const t_tplayer t, const int& team, const int&);
    ~Player();
    int getNbPion()const {return nbPion;}
    int getType()const {return _type;}
    int getPlayerType() const {return playerType;}
    void addPion();
private:
    t_tplayer playerType;
    int nbPion;
    int team;
    int _type;
};

#endif	/* PLAYER_HPP */

