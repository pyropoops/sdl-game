#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
    RenderWindow(const char *title, int width, int height);
    void cleanUp();
    SDL_Texture *loadTexture(const char *filepath);
    void clear();
    void render(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dst);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};