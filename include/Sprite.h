#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

namespace cwing
{

    enum class SpriteType
    {
        Kitty,
        Asteroid
        // ... other types if needed ...
    };

    class Sprite
    {
    public:
        Sprite(int x, int y, int w, int h, SpriteType type);
        virtual ~Sprite() = default;

        virtual void draw(SDL_Renderer *renderer) const = 0;
        virtual void update() = 0;

        SpriteType getType() const { return type; }

        SDL_Rect getRect() const;

    protected:
        SDL_Rect rect;
        SpriteType type;
    };

}

#endif
