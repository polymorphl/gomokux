/* 
 * File:   Gomoku.hpp
 * Author: benjamin
 *
 * Created on October 16, 2014, 1:56 PM
 */

#ifndef GOMOKU_HPP
#define	GOMOKU_HPP

#include "Rules.hpp"
#include "Exception.hpp"

class Gomoku : public Rules
{
protected:
    void updateMapRule(const int &);
    void copyMapRule();
    int _map[19][19];
    Player *_playerOne;
    Player *_playerTwo;
    int _playedX;
    int _playedY;
public:
    Gomoku();
    ~Gomoku();
    Player *getPlayerOne() const {return _playerOne;}
    Player *getPlayerTwo() const {return _playerTwo;}
    int createPlayer(const int &);
    void createMap();
    int getNbPion() const;
    int launchJudge(const t_flag&);

};

#endif	/* GOMOKU_HPP */
