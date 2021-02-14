#include "game.h"
#include "player.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game()
{
    this->entities = {};
    this->running = false;
}

void Game::init()
{
    // Initialize SDL shit here
    this->running = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "Image initialization has failed. Error: " << SDL_GetError() << std::endl;
    }

    std::cout << "Window initialization begin.\n";
    this->window = initializeWindow();

    if (&window == nullptr)
    {
        std::cout << "Failed to initialize window. Error: " << SDL_GetError() << std::endl;
    }
    std::cout << "Window initialized.\n";

    this->initializeEntities();

    SDL_Event event;

    while (this->running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                this->running = false;
            }
        }

        window.clear();
        // Call render shit

        for (Entity &e : entities)
        {
            e.render(&window);
        }

        window.display();
        // Await ((1000 / fps) - elapsed) ms
    }

    window.cleanUp();
    SDL_Quit();
}

void Game::registerEntity(Entity entity)
{
    this->entities.push_back(entity);
}

RenderWindow Game::initializeWindow()
{
    RenderWindow w("Game", 1280, 720);
    return w;
}

void Game::initializeEntities()
{
    Player player(&window);
    registerEntity(player);
}