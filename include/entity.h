#pragma once

#include <SDL2/SDL.h>

#include "renderwindow.h"

class Entity
{
public:
    Entity(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dst);
    Entity(SDL_Texture *texture);
    SDL_Texture *getTexture();
    SDL_Rect *getCurrentFrame();
    void render(RenderWindow *window);

protected:
    SDL_Texture *texture;
    SDL_Rect *src;
    SDL_Rect *dst;
    RenderWindow *window;
};