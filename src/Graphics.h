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
    SDL_DisplayMode displayMode;
    SDL_Renderer *renderer;

public:
    Graphics();
    void quit();
    void clearRenderer();

    [[nodiscard]] SDL_Window *getWindow() const;
    void setWindow(SDL_Window *window);
    [[nodiscard]] SDL_DisplayMode getDisplayMode() const;
    void setDisplayMode(SDL_DisplayMode displayMode);
    [[nodiscard]] SDL_Renderer *getRenderer() const;
    void setRenderer(SDL_Renderer *renderer);
    void setDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
};

#endif //MOVINGDOT_GRAPHICS_H
