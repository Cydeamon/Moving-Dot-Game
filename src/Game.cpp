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
}


void Game::gameCycle()
{
    cout << "Game cycle" << endl;
    GameEvent gameEvent;

    // Start position is at center of the screen
    int dotX = graphics->getWindowWidth() / 2;
    int dotY = graphics->getWindowHeight() / 2;

    while (true)
    {
        gameEvent = checkEvents();

        if (gameEvent == GAME_QUIT)
        {
            break;
        }

        graphics->clearRenderer();

        graphics->setDrawColor(255, 0, 0, 255);
        SDL_RenderDrawPoint(graphics->getRenderer(), dotX, dotY);
        graphics->setDrawColor(0, 0, 0, 255);

        SDL_RenderPresent(graphics->getRenderer());
    }

    quit();
}


void Game::quit()
{
    cout << "Game quit" << endl;

    graphics->quit();
    delete graphics;
}


Game::GameEvent Game::checkEvents()
{
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent) != 0)
    {
        // Game quit
        if (sdlEvent.type == SDL_QUIT)
        {
            return GAME_QUIT;
        }
    }

    return NO_EVENT;
}
