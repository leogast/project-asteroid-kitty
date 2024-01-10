#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class System
{
public:
    System(int screenWidth, int screenHeight);
    ~System();

    System(const System &) = delete;
    System &operator=(const System &) = delete;
    System(System &&) = delete;
    System &operator=(System &&) = delete;

    SDL_Renderer *getRenderer() const;
    SDL_Texture *loadTexture(const std::string &path);
    int getScreenWidth() const;
    int getScreenHeight() const;

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    int screenWidth = 0;
    int screenHeight = 0;

    void initSDL();
    void createWindowAndRenderer(int width, int height);
};

#endif
