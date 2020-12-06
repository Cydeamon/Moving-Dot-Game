//
// Created by Cydeamon on 05.12.2020.
//

#ifndef MOVINGDOT_GAME_H
#define MOVINGDOT_GAME_H

#include "Graphics.h"

class Game
{
private:
    Graphics *graphics;
    SDL_Event *sdlEvent;

    enum GameEvent
    {
        NO_EVENT, GAME_QUIT
    };

    void quit();

public:
    Game();
    void gameCycle();
    GameEvent checkEvents();
};

#endif //MOVINGDOT_GAME_H
