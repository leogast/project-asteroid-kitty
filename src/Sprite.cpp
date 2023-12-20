#include "Sprite.h"

namespace cwing
{

    Sprite::Sprite(int x, int y, int w, int h, SpriteType type)
        : rect{x, y, w, h}, type(type)
    {
        // Constructor body (if any)
    }

    SDL_Rect Sprite::getRect() const
    {
        return rect; // Return the current position and size of the sprite
    }

}
