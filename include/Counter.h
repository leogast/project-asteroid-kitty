#ifndef COUNTER_H
#define COUNTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace cwing {

    class Counter {
    public:
        Counter(int x, int y);
        ~Counter();

        void draw(SDL_Renderer* renderer) const;
        void update(int points);

    private:
        SDL_Rect rect;
        int points;
        SDL_Texture* texture;  // Texture for displaying the score
        mutable std::string text;  // Mutable to allow modification in const draw method

        void updateTexture(SDL_Renderer* renderer);
    };

}

#endif
