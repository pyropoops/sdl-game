#include "player.h"
#include "renderwindow.h"
#include <iostream>

Player::Player(RenderWindow *window) : window(window), Entity(window->loadTexture("img/player.png"))
{
    std::cout << "Constructor started!\n";

    // Load texture map
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    dst.x = 50;
    dst.y = 50;
    dst.w = 64;
    dst.h = 64;

    std::cout << "Constructor finished!\n";
}

void Player::update()
{
    // Gravitational constant
    dst.y -= 10;

    // Reaching the floor
    if (dst.y < dst.h)
    {
        dst.y = dst.h;
    }
}