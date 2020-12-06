//
// Created by Cydeamon on 05.12.2020.
//

#include <iostream>
#include "Graphics.h"

using namespace std;


Graphics::Graphics()
{
    cout << "Graphics init" << endl;

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        exit(1);
    }

    // Getting display mode information
    SDL_GetCurrentDisplayMode(0, &displayMode);

    const int SCREEN_WIDTH = displayMode.w;
    const int SCREEN_HEIGHT = displayMode.h;

    // Init Window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);

    if (window == NULL)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        exit(1);
    }

    screenSurface = SDL_GetWindowSurface(window);

    // Init renderer
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
}


void Graphics::quit()
{
    cout << "Graphics quit" << endl;

    SDL_DestroyWindow(window);
    SDL_Quit();
}


void Graphics::updateWindow()
{
    SDL_UpdateWindowSurface(window);
}

/*************************************************************************************/
/******************************** Getters and setters ********************************/

SDL_Window *Graphics::getWindow() const
{
    return window;
}


void Graphics::setWindow(SDL_Window *window)
{
    this->window = window;
}


SDL_Surface *Graphics::getScreenSurface() const
{
    return screenSurface;
}


void Graphics::setScreenSurface(SDL_Surface *screenSurface)
{
    this->screenSurface = screenSurface;
}


SDL_DisplayMode Graphics::getDisplayMode() const
{
    return displayMode;
}


void Graphics::setDisplayMode(SDL_DisplayMode displayMode)
{
    this->displayMode = displayMode;
}


SDL_Renderer *Graphics::getRenderer() const
{
    return renderer;
}


void Graphics::setRenderer(SDL_Renderer *renderer)
{
    Graphics::renderer = renderer;
}
