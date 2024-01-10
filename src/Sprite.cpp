#include "Sprite.h"
#include "Constants.h"
#include <cmath>

Sprite::Sprite(SDL_Texture *texture, int x, int y, int width, int height)
    : rect{x, y, width, height}, texture(texture) {}

Sprite::~Sprite()
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::draw(SDL_Renderer *renderer) const
{
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

bool Sprite::checkCollision(const Sprite &other) const
{
    // Simple AABB collision detection
    return rect.x < other.rect.x + other.rect.w &&
           rect.x + rect.w > other.rect.x &&
           rect.y < other.rect.y + other.rect.h &&
           rect.h + rect.y > other.rect.y;
}

void Sprite::update()
{
    // Default update does nothing, to be overridden by derived classes
}

Kitty::Kitty(SDL_Texture *texture, int x, int y)
    : Sprite(texture, x, y, constants::KITTY_WIDTH, constants::KITTY_HEIGHT) {}

void Kitty::update()
{
    // Kitty specific update logic (if any)
}

void Kitty::handleInput(const SDL_Event &event)
{
    // Handle keyboard or mouse input to move the kitty
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            rect.x -= 10; // Move left
            break;
        case SDLK_RIGHT:
            rect.x += 10; // Move right
            break;
        }
    }
    // Add more controls if necessary, e.g., for mouse input
}

Asteroid::Asteroid(SDL_Texture *texture, int x, int y)
    : Sprite(texture, x, y, constants::ASTEROID_WIDTH, constants::ASTEROID_HEIGHT) {}

void Asteroid::update()
{
    rect.y += 5; // Assuming a constant speed for asteroid fall
    if (rect.y > constants::SCREEN_HEIGHT)
    {
        // Reset or remove the asteroid when it goes off-screen
        rect.y = -constants::ASTEROID_HEIGHT; // Reset to top (as an example)
    }
}
