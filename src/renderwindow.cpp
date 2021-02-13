#include <iostream>
#include "renderwindow.h"
#include "helper.h"

RenderWindow::RenderWindow(const char *title, int width, int height)
{
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (this->window == nullptr)
    {
        std::cout << "Window failed to initialize. Error: " << SDL_GetError() << std::endl;
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

SDL_Texture *RenderWindow::loadTexture(const char *filepath)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(this->renderer, filepath);

    if (texture == nullptr)
    {
        Helper::errorMessage(strcat("Loading texture: ", filepath));
    }

    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dst)
{
    SDL_RenderCopy(this->renderer, texture, src, dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}