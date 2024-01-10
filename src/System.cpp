#include "System.h"
#include <iostream>

System::System(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight)
{
    initSDL();
    createWindowAndRenderer(screenWidth, screenHeight);
}

System::~System()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    IMG_Quit();
    SDL_Quit();
}

void System::initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        throw std::runtime_error("SDL Initialization Failed");
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        throw std::runtime_error("SDL_image Initialization Failed");
    }
}

void System::createWindowAndRenderer(int width, int height)
{
    window = SDL_CreateWindow("Game Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        throw std::runtime_error("Window Creation Failed");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        throw std::runtime_error("Renderer Creation Failed");
    }
}

SDL_Renderer *System::getRenderer() const
{
    return renderer;
}

SDL_Texture *System::loadTexture(const std::string &path)
{
    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (!loadedSurface)
    {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!newTexture)
    {
        std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

int System::getScreenWidth() const
{
    return screenWidth;
}

int System::getScreenHeight() const
{
    return screenHeight;
}
