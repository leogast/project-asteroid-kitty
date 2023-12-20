/*
 * För att köra programmet, behövs eventuellt hela katalogen "resources"
 * kopieras till katalogen "build/debug/"
 * Detta gäller framförallt Windows-användare
 */

#include "Constants.h" //gResPath-contains the path to your resources.
#include <string>
#include <SDL2/SDL.h>


/*  PATH TO YOUR RESOURCE FOLDER 'resources'
 *   'gResPath' is a global constant defined in "Constants.h",
 *   representing the relative path to your resource folders as a string,
 *   i.e. ' const std::string gResPath = "../../resources/" '
 *   Use it through its namespace, 'constants::gResPath'.
 *
 *   Change to your own path if you choose a different approach!
 *   Absolut Path(Second choice)
 *   gResPath = "/Users/kjellna/dev/cpp/sdl2_second/resources/";
 *
 *   If you need to copy your 'resources' folder into directory
 *   '/build/debug/', in that case change gResPath="./resources/"
 */

#define FPS 60


int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("My Window",
                                       100, 100, 700, 500, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    
    SDL_Surface* bgSurf = SDL_LoadBMP( (constants::gResPath + "images/bg.bmp").c_str() );
    SDL_Texture* bgTx = SDL_CreateTextureFromSurface(ren, bgSurf);
    SDL_FreeSurface(bgSurf);
    
    SDL_Surface* gubbSurf = SDL_LoadBMP( (constants::gResPath + "images/gubbe.bmp").c_str() );
    SDL_Rect gubbRect = { 0,0, gubbSurf->w, gubbSurf->h };
    Uint32 white = SDL_MapRGB(gubbSurf->format, 255, 255, 255);
    SDL_SetColorKey(gubbSurf, true, white);
    SDL_Texture* gubbTx = SDL_CreateTextureFromSurface(ren, gubbSurf);
    SDL_FreeSurface(gubbSurf);
    
    bool goOn = true;
    int varv = 0; // Anvands inte just nu!
    bool drag = false;
    
    const int tickInterval = 1000 / FPS;
    
    while (goOn) {
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            switch (eve.type) {
                case SDL_QUIT: goOn = false; break;
                case SDL_KEYDOWN:
                    switch (eve.key.keysym.sym) {
                        case SDLK_RIGHT: gubbRect.x++; break;
                        case SDLK_LEFT: gubbRect.x--; break;
                        case SDLK_UP: gubbRect.y--; break;
                        case SDLK_DOWN: gubbRect.y++; break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN: {
                    SDL_Point p = { eve.button.x, eve.button.y };
                    if (SDL_PointInRect(&p, &gubbRect))
                        drag = true;
                }
                    break;
                case SDL_MOUSEBUTTONUP:
                    drag = false;
                    break;
                case SDL_MOUSEMOTION:
                    if (drag) {
                        gubbRect.x += eve.motion.xrel;
                        gubbRect.y += eve.motion.yrel;
                    }
                    break;
            } // switch
        }
        
        gubbRect.x++;
        
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, bgTx, NULL, NULL);
        SDL_RenderCopy(ren, gubbTx, NULL, &gubbRect);
        SDL_RenderPresent(ren);
        
        int delay = nextTick - SDL_GetTicks();
        if (delay > 0){
            SDL_Delay(delay);
        }
        
    } // while
    
    
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
