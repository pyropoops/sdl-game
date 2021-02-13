// Going to be a smol cube for now

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.h"

class Player : public Entity
{
public:
    void update();
    Player(RenderWindow *window);

private:
    RenderWindow *window;
};