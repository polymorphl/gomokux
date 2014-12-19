/* 
 * File:   Graphic.hpp
 * Author: benjamin
 *
 * Created on October 16, 2014, 2:24 PM
 */

#ifndef GRAPHIC_HPP
#define	GRAPHIC_HPP

#include "Gomoku.hpp"
#include "AI.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define BLOCK_SIZE 32
#define DELAY 100

enum keyType {
    UP, DOWN, LEFT, RIGHT, ENTER, ESCAPE, CLIC, MOVE
};

class Graphic : public Gomoku {
public:
    Graphic();
    ~Graphic();
    void handleGame();
    void launchGame();

private:
    int launchMenu();
    int getKey();
    void displayMenu(const int&);
    void activeUpdate(int*);
    void drawSquare();
    void drawLine();
    void drawPawn();
    void drawEat();
    void drawZoneEat();
    void drawRule();
    int verifClick(const t_flag&);
    int verifPosition();
    bool inversBool(const bool &);
    int catchClick();
    int transformInCase();
    void updateMouse(const t_flag&);
    int checkPresentPlayer(const int &);
    int preparCheckRule(const t_flag&);
    void clearMapTry();
    SDL_Event *_event;
    int _height;
    int _width;
    SDL_Surface *_screen;
    SDL_Surface *_img[6];
    SDL_Rect _mouse;
    int _clicX;
    int _clicY;
};

#endif	/* GRAPHIC_HPP */

