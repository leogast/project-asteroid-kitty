#include "Kitty.h"
#include "System.h"
#include "Constants.h"
#include "Utils.h"
#include <iostream>

namespace cwing
{

    Kitty::Kitty(int x, int y) : Sprite(x, y, 50, 50, SpriteType::Kitty)
    {
        // Load textures for all kitty images
        textures[0] = Utils::loadTexture(constants::gResPath + "kitty1.png", sys.getRenderer());
        textures[1] = Utils::loadTexture(constants::gResPath + "kitty2.png", sys.getRenderer());
        textures[2] = Utils::loadTexture(constants::gResPath + "kitty3.png", sys.getRenderer());

        for (auto &texture : textures)
        {
            if (!texture)
            {
                std::cerr << "Unable to load Kitty image: " << SDL_GetError() << std::endl;
                exit(1);
            }
        }
    }

    Kitty::~Kitty()
    {
        for (auto &texture : textures)
        {
            SDL_DestroyTexture(texture);
        }
    }

    void Kitty::draw(SDL_Renderer *renderer) const
    {
        SDL_RenderCopy(renderer, textures[currentTexture], NULL, &rect);
    }

    void Kitty::switchTexture(int textureId)
    {
        if (textureId >= 0 && textureId < static_cast<int>(textures.size()))
        {

            currentTexture = textureId;
        }
    }

    void Kitty::update()
    {
        // Update Kitty's state and position here (for future use)
    }

    void Kitty::move(int dx, int dy)
    {
        rect.x += dx;
        rect.y += dy;
    }

    void Kitty::setPosition(int x, int y)
    {
        rect.x = x;
        rect.y = y;
    }

}
