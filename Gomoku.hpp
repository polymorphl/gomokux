/* 
 * File:   Gomoku.hpp
 * Author: benjamin
 *
 * Created on October 16, 2014, 1:56 PM
 */

#ifndef GOMOKU_HPP
#define	GOMOKU_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Exception.hpp"
#include "Player.hpp"

enum t_flag {
    FREE, TEAM_1, TEAM_2
};

enum t_direction {
    HORIZONTAL, VERTICAL, DIAGONALONE, DIAGONALTWO
};

class Gomoku
{
public:
    Gomoku();
    ~Gomoku();
//    const std::vector<t_flag>& getMap() const {return _map;}
    int getWinner() const {return _winner;}
    Player *getPlayerOne() const {return _playerOne;}
    Player *getPlayerTwo() const {return _playerTwo;}
    int createPlayer(const int &);
    void setWinner(const int& t) {_winner = t;}
    void createMap();
    t_flag invertTeam(const t_flag&);
    int getNbPion() const;

private:
    int checkWin(const t_flag&);
    int launchWatch(const int&, const int&, const t_flag&);
    int checkWinVertical(const int&, const int&, const t_flag&);
    int checkWinHorizontal(const int&, const int&, const t_flag&);
    int checkWinDiagonalOne(const int&, const int&, const t_flag&);
    int checkWinDiagonalTwo(const int&, const int&, const t_flag&);
    int ruleOfFive(const int&, const int&, const t_flag&, const t_direction&);
    int canIEat(const int&, const int&, const int&, const t_flag&);
    int checkEquality(const int&, const int&, const int&);
    void checkEat(const t_flag&);
    void checkEatVertical(const t_flag&);
    void checkEatHorizontal(const t_flag&);
    void checkEatDiagonalOne(const t_flag&);
    void checkEatDiagonalTwo(const t_flag&);
    int ruleOfThree(const t_flag&);
    void checkThreeVertical(const t_flag&, int*);
    void checkThreeHorizontal(const t_flag&, int*);
    void checkThreeDiagonalOne(const t_flag&, int*);
    void checkThreeDiagonalTwo(const t_flag&, int*);
    void addJackpot(const t_flag&);
protected:
    void updateMapRule(const t_flag&, const int &);
    int checkRules(const t_flag&);
//    std::vector<t_flag> _map;
    int _mapRule[19][19];
    Player *_playerOne;
    Player *_playerTwo;
    int _winner;
    int _playedX;
    int _playedY;
    bool _ruleOfThree;
    bool _ruleOfFive;
};

#endif	/* GOMOKU_HPP */

