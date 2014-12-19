
#include "Graphic.hpp"

Graphic::Graphic() {
    _img[0] = IMG_Load("assets/playerOne.png");
    _img[1] = IMG_Load("assets/playerTwo.png");
    _img[2] = IMG_Load("assets/fiveActive.png");
    _img[3] = IMG_Load("assets/fivePassive.png");
    _img[4] = IMG_Load("assets/threeActive.png");
    _img[5] = IMG_Load("assets/threePassive.png");
    _event = new SDL_Event();
    _clicX = -1;
    _clicY = -1;
}

Graphic::~Graphic() {
}

int Graphic::getKey() {
    while (SDL_PollEvent(_event)) {
        switch (_event->type) {
            case SDL_QUIT:
                return ESCAPE;
            case SDL_MOUSEBUTTONUP:
                _clicX = _event->button.x;
                _clicY = _event->button.y;
                return CLIC;
            case SDL_KEYDOWN:
                switch (_event->key.keysym.sym) {
                    case SDLK_UP:
                        return UP;
                    case SDLK_DOWN:
                        return DOWN;
                    case SDLK_ESCAPE:
                        return ESCAPE;
                    case SDLK_SPACE:
                        return ENTER;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return (-1);
}

void Graphic::handleGame() {
    while (this->createPlayer(launchMenu()) != -1) {
        _clicX = -1;
        _clicY = -1;
        createMap();
        launchGame();
    }
}

void Graphic::displayMenu(const int& active) {
    std::ostringstream oss;
    oss << "assets/menu" << active << ".png";
    SDL_Surface *deep = IMG_Load("assets/menu.png");
    SDL_Surface *activ = IMG_Load(oss.str().c_str());
    SDL_Rect posDeep;
    SDL_Rect posActive;
    
    posDeep.x = 0;
    posDeep.y = 0;
    posActive.x = 125;
    posActive.y = 250 + ((active - 1) * 150);
    SDL_BlitSurface(deep, NULL, _screen, &posDeep);
    SDL_BlitSurface(activ, NULL, _screen, &posActive);
    SDL_Flip(_screen);
}

void Graphic::activeUpdate(int *active) {
    if (*active > 3)
        *active = 1;
    if (*active < 1)
        *active = 3;
}


int Graphic::launchMenu() {
    int active = 1;
    int key;
    
    this->_height = 18 * BLOCK_SIZE + 200;
    this->_width = 18 * BLOCK_SIZE + 150;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw(MyException("launchMenu", "Can't init sdl"));
    this->_screen = SDL_SetVideoMode(_width, _height, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gomoklax", NULL);
    while (1) {
        key = getKey();
        if (key == UP)
            active--;
        if (key == DOWN)
            active++;
        if (key == ENTER)
            return active;
        if (key == ESCAPE)
            return -1;
        activeUpdate(&active);
        displayMenu(active);
        SDL_Delay(DELAY);        
    }
}

void Graphic::drawLine() {
    SDL_Rect rect[19 + 19];
    
    for (int i = 0; i != 19 + 19; i++) {
        if (i <= 18) {
            rect[i].x = 75;
            rect[i].y = 74 + (i * BLOCK_SIZE);
            rect[i].w = BLOCK_SIZE * 18;
            rect[i].h = 1;
        }
        else {
            rect[i].x = 75 + ((i - 19) * BLOCK_SIZE);
            rect[i].y = 75;
            rect[i].w = 1;
            rect[i].h = BLOCK_SIZE * 18;            
        }
        SDL_FillRect(_screen, &(rect[i]), SDL_MapRGB(_screen->format, 0, 0, 0));
    }
    SDL_Flip(_screen);
}

void Graphic::drawPawn() {
    int nbPion;
    int cpt = 0;
    
    nbPion = getNbPion() + 2;
    SDL_Rect position[nbPion];    
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_map[y][x] == TEAM_1) {
                position[cpt].x = 59 + (((y * 19 + x) % 19) * BLOCK_SIZE);
                position[cpt].y = 59 + (((y * 19 + x) / 19) * BLOCK_SIZE);
                SDL_BlitSurface(_img[0], NULL, _screen, &position[cpt]);
                cpt++;
            }
            if (_map[y][x] == TEAM_2) {
                position[cpt].x = 59 + (((y * 19 + x) % 19) * BLOCK_SIZE);
                position[cpt].y = 59 + (((y * 19 + x) / 19) * BLOCK_SIZE);
                SDL_BlitSurface(_img[1], NULL, _screen, &position[cpt]);
                cpt++;
            }
        }
    }
}

void Graphic::drawZoneEat() {
    SDL_Rect zoneOne;
    SDL_Rect zoneTwo;

    zoneOne.x = 15;
    zoneOne.y = 155;
    zoneOne.h = 10 * (BLOCK_SIZE + 10);
    zoneOne.w = BLOCK_SIZE;
    SDL_FillRect(_screen, &(zoneOne), SDL_MapRGB(_screen->format, 255, 255, 255));
    zoneTwo.x = _width - 15 - BLOCK_SIZE;
    zoneTwo.y = 155;
    zoneTwo.h = 10 * (BLOCK_SIZE + 10);
    zoneTwo.w = BLOCK_SIZE;
    SDL_FillRect(_screen, &(zoneTwo), SDL_MapRGB(_screen->format, 255, 255, 255));
}


void Graphic::drawEat() {
    int cpt = 0;
    int nbPion = _playerOne->getNbPion() + _playerTwo->getNbPion();
    
    SDL_Rect position[nbPion];
    drawZoneEat();
    for (int pion = 0; pion != _playerOne->getNbPion(); pion++) {
        position[cpt].x = 15;
        position[cpt].y = 155 + (pion * (BLOCK_SIZE + 10));
        SDL_BlitSurface(_img[0], NULL, _screen, &position[cpt]);
        cpt++;
    }
    for (int pion = 0; pion != _playerTwo->getNbPion(); pion++) {
        position[cpt].x = _width - 15 - BLOCK_SIZE;
        position[cpt].y = 155 + (pion * (BLOCK_SIZE + 10));
        SDL_BlitSurface(_img[1], NULL, _screen, &position[cpt]);
        cpt++;
    }
}

void Graphic::drawRule() {
    SDL_Rect position[2];
    
    position[0].x = 230;
    position[0].y = _height - 110;
    position[1].x = 230;
    position[1].y = _height - 60;
    (_ruleOfFive) ? SDL_BlitSurface(_img[2], NULL, _screen, &position[0]) :  SDL_BlitSurface(_img[3], NULL, _screen, &position[0]);
    (_ruleOfThree) ? SDL_BlitSurface(_img[4], NULL, _screen, &position[1]) :  SDL_BlitSurface(_img[5], NULL, _screen, &position[1]);
}

void Graphic::drawSquare() {
    SDL_Rect desk;
    SDL_Rect deep;
    
    deep.x = 0;
    deep.y = 0;
    deep.h = 18 * BLOCK_SIZE + 200;
    deep.w = 18 * BLOCK_SIZE + 150;
    SDL_FillRect(_screen, &(deep), SDL_MapRGB(_screen->format, 152, 152, 152));
    desk.x = 75;
    desk.y = 75;
    desk.h = 18 * BLOCK_SIZE;
    desk.w = 18 * BLOCK_SIZE;
    SDL_FillRect(_screen, &(desk), SDL_MapRGB(_screen->format, 255, 255, 255));        
    drawLine();
    drawPawn();
    drawEat();
    drawRule();
    SDL_Flip(_screen);
}

int Graphic::transformInCase() {
    for (int cpt = 0; cpt != 19*19; cpt++) {
        if ((_clicX >= 59 + ((cpt % 19) * BLOCK_SIZE) &&
                _clicX <= 59 + ((cpt % 19) * BLOCK_SIZE) + BLOCK_SIZE) &&
                (_clicY >= 59 + ((cpt / 19) * BLOCK_SIZE) &&
                _clicY <= 59 + ((cpt / 19) * BLOCK_SIZE) + BLOCK_SIZE)) {
            updateMapRule(cpt);
            _clicX = -1;
            _clicY = -1;
            return 0;
        }
    }
    _clicX = -1;
    _clicY = -1;
    return -1;
}

bool Graphic::inversBool(const bool& toInvers) {
    if (toInvers)
        return 0;
    return 1;
}

int Graphic::verifPosition() {
    if (_clicX >= 59 && _clicX <= 667 && _clicY <= 667 && _clicY >= 59)
        return 0;
    if (_clicX >= 230 && _clicX <= 500 && _clicY < _height - 70 && _clicY >= _height - 110) {
        _ruleOfFive = inversBool(_ruleOfFive);
        drawSquare();
    }
    if (_clicX >= 230 && _clicX <= 500 && _clicY < _height - 20 && _clicY >= _height - 70) {
        _ruleOfThree = inversBool(_ruleOfThree);
        drawSquare();
    }
    return 1;
}

int Graphic::preparCheckRule(const t_flag& player) {
    //verification a revoir pour les mask
    if (_playedX < 0 || _playedY < 0)
        return 1;
    if (_map[_playedY][_playedX] != FREE)
        return 1;
    if (launchJudge(player) == 1) {
        _map[_playedY][_playedX] = TRY;
        return 1;
    }
    return 0;
}

int Graphic::verifClick(const t_flag& player) {
    if (verifPosition())
        return 1;
    if ((transformInCase()) == -1) {
        return 1;        
    }
    if (preparCheckRule(player) == 1)
        return 1;
    return (0);
}

int Graphic::catchClick() {
    int key;

    key = getKey();
    if (key == ESCAPE)
        return ESCAPE;
    if (key == CLIC)
        return CLIC;
    if (key == MOVE)
        return MOVE;
    SDL_Delay(DELAY);
    return -1;
}

int Graphic::checkPresentPlayer(const int& activ) {
  if (activ == TEAM_1 && this->_playerOne->getPlayerType() == IA)
    return IA;
  if (activ == TEAM_2 && this->_playerTwo->getPlayerType() == IA)
    return IA;
  return HUMAN;
}

void Graphic::clearMapTry() {
    for (int y = 0; y < 19; y++) {
        for (int x = 0; x < 19; x++) {
            if (_map[y][x] == TRY)
                _map[y][x] = FREE;
        }
    }
}

void Graphic::launchGame() {
//    int key;
    int retFlag;
    int retIa;
    t_flag activPlayer = TEAM_1;
    AI* ai;
    
    if (_playerOne->getPlayerType() == IA || _playerTwo->getPlayerType() == IA)
        ai = new AI();
    
    while (this->_winner == 0) {
        drawSquare();
//        key = getKey();
//        if (key == ESCAPE)
//            return;
//        _playedX = -1;
//        _playedY = -1;
        if (checkPresentPlayer(activPlayer) == HUMAN) {
            std::cout << "humain joue" << std::endl;
            while (verifClick(activPlayer)) {
                _clicX = -1;
                _clicY = -1;
                retFlag = catchClick();
                if (retFlag == ESCAPE)
                    return;
            }            
        }
        else {
            std::cout << "ia joue" << std::endl;
            while (preparCheckRule(activPlayer) == 1) {
                retIa = ai->launchAI(_map, activPlayer);
                
//                (void)ai;
//	      if (activPlayer == TEAM_1)
//		ia = _playerOne->launchIA();
//	      else
//		ia = _playerTwo->launchIA();
                retFlag = catchClick();
                if (retFlag == ESCAPE)
                    return;
                std::cout << "ia boucle" << std::endl;
                _playedX = retIa % 19;
                _playedY = retIa / 19;
            }
            clearMapTry();
        }
        activPlayer = invertTeam(activPlayer);
        SDL_Delay(DELAY);
    }
    std::cout << "Winner equipe " << _winner << std::endl;
}
