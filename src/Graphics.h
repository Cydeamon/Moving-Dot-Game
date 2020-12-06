//
// Created by Cydeamon on 05.12.2020.
//

#include <SDL2/SDL.h>

#ifndef MOVINGDOT_GRAPHICS_H
#define MOVINGDOT_GRAPHICS_H

class Graphics
{

private:
    SDL_Window *window;
    SDL_Surface *screenSurface;
    SDL_DisplayMode displayMode;
    SDL_Renderer *renderer;

public:
    Graphics();
    void quit();
    void updateWindow();

    SDL_Window *getWindow() const;
    void setWindow(SDL_Window *window);
    SDL_Surface *getScreenSurface() const;
    void setScreenSurface(SDL_Surface *screenSurface);
    SDL_DisplayMode getDisplayMode() const;
    void setDisplayMode(SDL_DisplayMode displayMode);
    SDL_Renderer *getRenderer() const;
    void setRenderer(SDL_Renderer *renderer);
};

#endif //MOVINGDOT_GRAPHICS_H
