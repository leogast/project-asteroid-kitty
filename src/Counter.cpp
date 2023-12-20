#include "Counter.h"
#include "System.h"
#include <iostream>

namespace cwing {

    Counter::Counter(int x, int y) : rect{x, y, 100, 30}, points(0), texture(nullptr) {
        text = "Score: 0";
        updateTexture(sys.getRenderer());
    }

    Counter::~Counter() {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }

    void Counter::draw(SDL_Renderer* renderer) const {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Light gray background
        SDL_RenderFillRect(renderer, &rect);

        if (texture) {
            int textWidth, textHeight;
            TTF_SizeText(sys.get_font(), text.c_str(), &textWidth, &textHeight);
            SDL_Rect textRect = { rect.x + (rect.w - textWidth) / 2, rect.y + (rect.h - textHeight) / 2, textWidth, textHeight };
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
        }
    }

    void Counter::update(int newPoints) {
        points = newPoints;
        text = "Score: " + std::to_string(points);
        updateTexture(sys.getRenderer());
    }

    void Counter::updateTexture(SDL_Renderer* renderer) {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {0, 0, 0}); // Black text
        if (!surf) {
            std::cerr << "Unable to create text surface: " << TTF_GetError() << std::endl;
            return;
        }
        texture = SDL_CreateTextureFromSurface(renderer, surf);
        if (!texture) {
            std::cerr << "Unable to create text texture: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(surf);
    }

}
