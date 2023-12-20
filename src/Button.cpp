#include "Button.h"
#include "System.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace cwing
{

    Button::Button(int x, int y, int w, int h, const std::string &text, std::function<void()> onClick)
        : rect{x, y, w, h}, text(text), onClick(onClick), texture(nullptr)
    {
        createTexture(sys.getRenderer());
    }

    Button::~Button()
    {
        if (texture)
        {
            SDL_DestroyTexture(texture);
        }
    }

    void Button::createTexture(SDL_Renderer *renderer)
    {
        SDL_Surface *surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {0, 0, 0}); // Black text
        if (surf == nullptr)
        {
            std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
            return;
        }
        texture = SDL_CreateTextureFromSurface(renderer, surf);
        if (texture == nullptr)
        {
            std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(surf);
    }

    void Button::draw(SDL_Renderer *renderer) const
    {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Light gray background
        SDL_RenderFillRect(renderer, &rect);

        if (texture)
        {
            int textWidth, textHeight;
            TTF_SizeText(sys.get_font(), text.c_str(), &textWidth, &textHeight);
            SDL_Rect textRect = {rect.x + (rect.w - textWidth) / 2, rect.y + (rect.h - textHeight) / 2, textWidth, textHeight};
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
        }
    }

    void Button::handleEvent(const SDL_Event &e)
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
                mouseY >= rect.y && mouseY <= rect.y + rect.h)
            {
                onClick();
            }
        }
    }

    bool Button::isMouseOver(int x, int y) const
    {
        // Check if the given coordinates are within the button's rectangle
        return x >= rect.x && x <= rect.x + rect.w &&
               y >= rect.y && y <= rect.y + rect.h;
    }

    void Button::performClick() const
    {
        // Execute the button's action
        if (onClick)
        {
            onClick();
        }
    }

}
