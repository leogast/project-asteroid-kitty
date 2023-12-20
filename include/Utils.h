#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>
#include <string>

namespace cwing {

    class Utils {
    public:
        // Load a texture from a file
        static SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);

        // Check collision between two rectangles
        static bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
    };

}

#endif
