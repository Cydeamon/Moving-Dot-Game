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
        GAME_NO_EVENT,
        GAME_QUIT,
        GAME_START_MOVE_UP,
        GAME_START_MOVE_DOWN,
        GAME_START_MOVE_LEFT,
        GAME_START_MOVE_RIGHT,
        GAME_START_FAST_MOVEMENT,
        GAME_END_MOVE_UP,
        GAME_END_MOVE_DOWN,
        GAME_END_MOVE_LEFT,
        GAME_END_MOVE_RIGHT,
        GAME_END_FAST_MOVEMENT
    };

    void quit();

public:
    Game();
    void gameCycle();
    GameEvent checkEvents();
};

#endif //MOVINGDOT_GAME_H
