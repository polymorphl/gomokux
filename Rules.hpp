/* 
 * File:   Rules.hpp
 * Author: benjamin
 *
 * Created on December 19, 2014, 12:09 PM
 */

#ifndef RULES_HPP
#define	RULES_HPP

// GRaphic herite de Gomoku
//Gomoku herite de Rules
// les Player sont dans Gomoku
// Player herite de rules

#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

enum t_flag {
    FREE = 1, TEAM_1, TEAM_2, TRY
};

enum t_direction {
    HORIZONTAL, VERTICAL, DIAGONALONE, DIAGONALTWO
};

class Rules {
public:
    Rules();
    ~Rules();
    int getWinner() const {return _winner;}
    void setWinner(const int& t) {_winner = t;}
    t_flag invertTeam(const t_flag&);

protected:
    int checkRules(const t_flag&);
    int checkRules(const t_flag&, Player&);
    int checkWin(const t_flag&);
    int checkWinVertical(const int&, const int&, const t_flag&);
    int checkWinHorizontal(const int&, const int&, const t_flag&);
    int checkWinDiagonalOne(const int&, const int&, const t_flag&);
    int checkWinDiagonalTwo(const int&, const int&, const t_flag&);
    int _winner;
    bool _ruleOfThree;
    bool _ruleOfFive;
    int _mapRule[19][19];
    int _playedXRules;
    int _playedYRules;

private:
    int checkWin(const t_flag&, Player&);
    int launchWatch(const int&, const int&, const t_flag&);
    int ruleOfFive(const int&, const int&, const t_flag&, const t_direction&);
    int canIEat(const int&, const int&, const int&, const t_flag&);
    int checkEquality(const int&, const int&, const int&);
    void checkEat(const t_flag&, Player&);
    void checkEatVertical(const t_flag&, Player&);
    void checkEatHorizontal(const t_flag&, Player&);
    void checkEatDiagonalOne(const t_flag&, Player&);
    void checkEatDiagonalTwo(const t_flag&, Player&);
    int ruleOfThree(const t_flag&);
    void checkThreeVertical(const t_flag&, int*);
    void checkThreeHorizontal(const t_flag&, int*);
    void checkThreeDiagonalOne(const t_flag&, int*);
    void checkThreeDiagonalTwo(const t_flag&, int*);
    void addJackpot(const t_flag&, Player&);
    
};

#endif	/* RULES_HPP */

