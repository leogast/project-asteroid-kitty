#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <functional>
#include <string>

namespace cwing {

    class Button {
    public:
        Button(int x, int y, int w, int h, const std::string& text, std::function<void()> onClick);
        ~Button();

        void draw(SDL_Renderer* renderer) const;
        void handleEvent(const SDL_Event& e);
        bool isMouseOver(int x, int y) const;
        void performClick() const;

    private:
        SDL_Rect rect;
        std::string text;
        std::function<void()> onClick;
        SDL_Texture* texture;  // Texture for the button text

        void createTexture(SDL_Renderer* renderer);
    };

}

#endif
