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
    SDL_Event sdlEvent;

    enum GameEvent
    {
        GAME_NO_EVENT, GAME_QUIT,

        // Movement events
                GAME_MOVE_UP, GAME_MOVE_DOWN, GAME_MOVE_LEFT, GAME_MOVE_RIGHT
    };

    void quit();

public:
    Game();
    void gameCycle();
    GameEvent checkEvents();
};

#endif //MOVINGDOT_GAME_H
