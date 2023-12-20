#ifndef KITTY_H
#define KITTY_H

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <array>

namespace cwing
{
    class Kitty : public Sprite
    {
    public:
        Kitty(int x, int y);
        virtual ~Kitty();

        void draw(SDL_Renderer *renderer) const override;
        void update() override;

        void move(int dx, int dy);
        void setPosition(int x, int y);
        void switchTexture(int textureId); // New method to switch textures

    private:
        std::array<SDL_Texture *, 3> textures; // Array to store textures for kitty1, kitty2, kitty3
        int currentTexture;                    // Index of the current texture
    };
}

#endif
