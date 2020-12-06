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
    int movementSpeed = 3;

    while (true)
    {
        // Handle game events
        gameEvent = checkEvents();

        if (gameEvent == GAME_QUIT)
        {
            break;
        }

        switch (gameEvent)
        {
            case GAME_MOVE_DOWN:
                dotY += movementSpeed;
                break;
            case GAME_MOVE_UP:
                dotY -= movementSpeed;
                break;
            case GAME_MOVE_LEFT:
                dotX -= movementSpeed;
                break;
            case GAME_MOVE_RIGHT:
                dotX += movementSpeed;
                break;
        }

        // Draw stuff
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
    while (SDL_PollEvent(&sdlEvent) != 0)
    {
        // Game quit
        if (sdlEvent.type == SDL_QUIT)
        {
            return GAME_QUIT;
        }

        // Keyboard input
        if (sdlEvent.type == SDL_KEYDOWN)
        {
            switch (sdlEvent.key.keysym.sym)
            {
                case SDLK_UP:
                    return GAME_MOVE_UP;
                case SDLK_LEFT:
                    return GAME_MOVE_LEFT;
                case SDLK_RIGHT:
                    return GAME_MOVE_RIGHT;
                case SDLK_DOWN:
                    return GAME_MOVE_DOWN;
            }
        }
    }

    return GAME_NO_EVENT;
}
