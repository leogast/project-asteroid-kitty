#include "Utils.h"
#include <iostream>

namespace cwing {

    SDL_Texture* Utils::loadTexture(const std::string& path, SDL_Renderer* renderer) {
        SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
        if (!loadedSurface) {
            std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
            return nullptr;
        }

        SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);

        if (!newTexture) {
            std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
        }

        return newTexture;
    }

    bool Utils::checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
        return a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y;
    }

}
