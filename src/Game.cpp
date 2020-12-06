//
// Created by Cydeamon on 05.12.2020.
//

#include <iostream>
#include "Game.h"

using namespace std;


Game::Game()
{
    cout << "Game init" << endl;
    graphics = new Graphics();

    SDL_FillRect(graphics->getScreenSurface(), NULL, SDL_MapRGB(graphics->getScreenSurface()->format, 0, 0, 0));
    graphics->updateWindow();
}


void Game::gameCycle()
{
    cout << "Game cycle" << endl;
    GameEvent gameEvent = NO_EVENT;

    int dotX = 55;
    int dotY = 55;

    while (gameEvent != GAME_QUIT)
    {
        gameEvent = checkEvents();

        SDL_RenderDrawPoint(graphics->getRenderer(), dotX, dotY);

        graphics->updateWindow();
    }

    quit();
}


void Game::quit()
{
    cout << "Game quit" << endl;

    graphics->quit();
    delete graphics;
}


/**
 * @brief Check SDL Events
 */
Game::GameEvent Game::checkEvents()
{
    while (SDL_PollEvent(sdlEvent) != 0)
    {
        // Game quit
        if (sdlEvent->type == SDL_QUIT)
        {
            return GAME_QUIT;
        }
    }

    return NO_EVENT;
}
