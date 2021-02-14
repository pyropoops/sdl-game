#include "entity.h"
#include "renderwindow.h"

Entity::Entity(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst) : texture(texture), src(src), dst(dst)
{
}

Entity::Entity(SDL_Texture *texture) : texture(texture) {}

SDL_Texture *Entity::getTexture()
{
    return this->texture;
}

SDL_Rect *Entity::getCurrentFrame()
{
    return &src;
}

void Entity::render(RenderWindow *window)
{
    window->render(this->texture, &src, &dst);
}