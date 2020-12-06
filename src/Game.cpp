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

    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp = false;
    bool movingDown = false;

    bool playerInGoalZone = false;

    SDL_Rect goal;
    goal.w = 200;
    goal.h = 200;
    goal.x = rand() % (graphics->getWindowWidth() - goal.w);
    goal.y = rand() % (graphics->getWindowHeight() - goal.h);

    while (true)
    {
        /**********************************************************************/
        /******************************* EVENTS *******************************/
        gameEvent = checkEvents();

        if (gameEvent == GAME_QUIT)
        {
            break;
        }

        switch (gameEvent)
        {
            case GAME_START_MOVE_DOWN:
                movingDown = true;
                break;
            case GAME_START_MOVE_UP:
                movingUp = true;
                break;
            case GAME_START_MOVE_LEFT:
                movingLeft = true;
                break;
            case GAME_START_MOVE_RIGHT:
                movingRight = true;
                break;

            case GAME_END_MOVE_DOWN:
                movingDown = false;
                break;
            case GAME_END_MOVE_UP:
                movingUp = false;
                break;
            case GAME_END_MOVE_LEFT:
                movingLeft = false;
                break;
            case GAME_END_MOVE_RIGHT:
                movingRight = false;
                break;
        }

        /**********************************************************************/
        /************************** PLAYER MOVEMENT ***************************/
        if (movingDown)
        {
            dotY += 3;
        }

        if (movingUp)
        {
            dotY -= 3;
        }

        if (movingLeft)
        {
            dotX -= 3;
        }

        if (movingRight)
        {
            dotX += 3;
        }

        /**********************************************************************/
        /***************************** GAME LOGIC *****************************/

        // Check if player in goal zone
        playerInGoalZone = (dotX < goal.x + goal.w && dotX > goal.x) && (dotY < goal.y + goal.h && dotY > goal.y);

        if (playerInGoalZone)
        {
            goal.x = rand() % (graphics->getWindowWidth() - goal.w);
            goal.y = rand() % (graphics->getWindowHeight() - goal.h);
        }

        /**********************************************************************/
        /******************************** DRAW ********************************/
        graphics->clearRenderer();

        // Draw goal
        graphics->setDrawColor(0, 255, 0, 255);
        SDL_RenderDrawRect(graphics->getRenderer(), &goal);

        // Draw point
        graphics->setDrawColor(255, 0, 0, 255);
        SDL_RenderDrawPoint(graphics->getRenderer(), dotX, dotY);

        // Draw background color
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
                    return GAME_START_MOVE_UP;
                case SDLK_LEFT:
                    return GAME_START_MOVE_LEFT;
                case SDLK_RIGHT:
                    return GAME_START_MOVE_RIGHT;
                case SDLK_DOWN:
                    return GAME_START_MOVE_DOWN;
            }
        }

        if (sdlEvent.type == SDL_KEYUP)
        {
            switch (sdlEvent.key.keysym.sym)
            {
                case SDLK_UP:
                    return GAME_END_MOVE_UP;
                case SDLK_LEFT:
                    return GAME_END_MOVE_LEFT;
                case SDLK_RIGHT:
                    return GAME_END_MOVE_RIGHT;
                case SDLK_DOWN:
                    return GAME_END_MOVE_DOWN;
            }
        }
    }

    return GAME_NO_EVENT;
}
