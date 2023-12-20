#ifndef ASTEROID_H
#define ASTEROID_H

#include "Sprite.h"
#include <SDL2/SDL.h>

namespace cwing
{

    class Asteroid : public Sprite
    {
    public:
        Asteroid(int x, int y);
        ~Asteroid();

        void draw(SDL_Renderer *renderer) const override; // Declaration only
        void update() override;                           // Declaration only

    private:
        SDL_Texture *texture; // Texture for the asteroid image
        int speed;            // Speed at which the asteroid falls
    };

}

#endif
