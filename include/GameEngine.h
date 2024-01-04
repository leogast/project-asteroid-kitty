#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "System.h"
#include "Sprite.h"
#include "Button.h"
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

namespace cwing
{

    class GameEngine
    {
    public:
        GameEngine();
        ~GameEngine();

        void addSprite(Sprite *sprite);
        void run();
        void handleMainMenuEvents(const SDL_Event &event);
        void handlePlayingEvents(const SDL_Event &event);
        void handleGameOverEvents(const SDL_Event &event);
        void render();
        void renderMainMenu();
        void renderPlaying();
        void renderGameOver();
        void updateGameLogic();
        bool checkCollisions();
        bool isAsteroid(const Sprite *sprite);

        //nedan följer test
        void add(Sprite* s);
        //slut på test

    private:
        std::vector<std::unique_ptr<Sprite>> sprites;
        bool running;
        bool draggingKitty;
        Sprite *kitty;

        enum class GameState
        {
            MainMenu,
            Playing,
            GameOver,
            Quit
        };
        GameState currentState;

        Button startButton;
        Button exitButton;

        void handleKeyboardEvent(const SDL_KeyboardEvent &keyEvent);
        bool isMouseOnSprite(int mouseX, int mouseY, const SDL_Rect &rect);
        void updateSprites();
        void renderSprites();
    };

}

#endif // GAME_ENGINE_H
