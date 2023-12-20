#include "Asteroid.h"
#include "System.h"
#include "Sprite.h"
#include <iostream>

namespace cwing {

    Asteroid::Asteroid(int x, int y) : Sprite(x, y, 30, 30, SpriteType::Asteroid), speed(5) {  // Assuming each asteroid is 30x30 pixels
        SDL_Surface* temp = SDL_LoadBMP("path_to_asteroid_image.bmp");  // Replace with actual path
        if (temp == nullptr) {
            std::cerr << "Unable to load Asteroid image: " << SDL_GetError() << std::endl;
            exit(1);
        }
        texture = SDL_CreateTextureFromSurface(sys.getRenderer(), temp);
        SDL_FreeSurface(temp);
    }

    Asteroid::~Asteroid() {
        SDL_DestroyTexture(texture);
    }

    void Asteroid::draw(SDL_Renderer* renderer) const {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }

    void Asteroid::update() {
        rect.y += speed;
        if (rect.y > 600) {  // Assuming the screen height is 600 pixels
            rect.y = -rect.h; // Reset the asteroid to the top of the screen
        }
    }
}

