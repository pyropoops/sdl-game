#pragma once

#include <vector>

#include "renderwindow.h"
#include "entity.h"

class Game
{
public:
    Game();
    void init();
    void registerEntity(Entity entity);

private:
    std::vector<Entity> entities;
    bool running;
    RenderWindow window;
    RenderWindow initializeWindow();
    void initializeEntities();
};