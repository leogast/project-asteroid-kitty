#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class Sprite
{
public:
    Sprite(SDL_Texture *texture, int x, int y, int width, int height);
    virtual ~Sprite();
    virtual void draw(SDL_Renderer *renderer) const;
    virtual void update();
    virtual bool checkCollision(const Sprite &other) const;

protected:
    SDL_Rect rect;
    SDL_Texture *texture;
};

class Kitty : public Sprite
{
public:
    Kitty(SDL_Texture *texture, int x, int y);
    void update() override;
    void handleInput(const SDL_Event &event); // Handle input for moving the kitty
};

class Asteroid : public Sprite
{
public:
    Asteroid(SDL_Texture *texture, int x, int y);
    void update() override;
};

#endif
