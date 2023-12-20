#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

namespace cwing
{

    class System
    {
    public:
        System();
        ~System();

        SDL_Renderer *getRenderer() const;
        TTF_Font *get_font() const;

        // Prevent copy construction and assignment
        System(const System &) = delete;
        System &operator=(const System &) = delete;

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
    };

    // Global system object
    extern System sys;
}

#endif
