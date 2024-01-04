#include "GameEngine.h"
#include "Button.h"
#include "Kitty.h"
#include "Utils.h"
#include <SDL2/SDL.h>

namespace cwing
{
    GameEngine::GameEngine()
        : currentState(GameState::MainMenu),
          startButton(100, 100, 200, 50, "Start", [this]()
                      { currentState = GameState::Playing; }),
          exitButton(100, 200, 200, 50, "Exit", [this]()
                     { running = false; })
    {
        // Initialize other resources...
    }

    GameEngine::~GameEngine()
    {
        // Clean up resources if needed
    }

    void GameEngine::addSprite(Sprite *sprite)
    {
        sprites.emplace_back(sprite);

        // Assuming kitty is the first sprite added for simplicity
        if (!kitty)
        {
            kitty = dynamic_cast<Kitty *>(sprite);
        }
    }

    void GameEngine::updateGameLogic()
    {
        if (checkCollisions())
        {
            dynamic_cast<Kitty *>(kitty)->switchTexture(1); // Switch to kitty2 on collision
            // Additional logic for handling the collision (e.g., reducing lives)
        }

        // ... other game logic ...
    }

    void GameEngine::run()
    {
        running = true;
        while (running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) // Check for window close event
                {
                    running = false; // Set running to false to exit the main loop
                    break;
                }
                switch (currentState)
                {
                case GameState::MainMenu:
                    handleMainMenuEvents(event);
                    break;
                case GameState::Playing:
                    handlePlayingEvents(event);
                    break;
                case GameState::GameOver:
                    handleGameOverEvents(event);
                    break;
                }
            }

            render();
        }
    }
    void GameEngine::handleMainMenuEvents(const SDL_Event &event)
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouseX = event.button.x;
            int mouseY = event.button.y;

            // Check if the start or exit button is clicked
            if (startButton.isMouseOver(mouseX, mouseY))
            {
                startButton.performClick(); // Change the game state to Playing
            }
            else if (exitButton.isMouseOver(mouseX, mouseY))
            {
                exitButton.performClick(); // Quit the game
            }
        }
    }

    void GameEngine::handlePlayingEvents(const SDL_Event &event)
    {
        // Handle events when in the Playing state
        if (event.type == SDL_KEYDOWN)
        {
            handleKeyboardEvent(event.key);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (kitty && isMouseOnSprite(event.button.x, event.button.y, kitty->getRect()))
            {
                draggingKitty = true;
            }
        }
        else if (event.type == SDL_MOUSEBUTTONUP)
        {
            draggingKitty = false;
        }
        else if (event.type == SDL_MOUSEMOTION)
        {
            if (draggingKitty && kitty)
            {
                Kitty *kittyPtr = dynamic_cast<Kitty *>(kitty);
                if (kittyPtr)
                {
                    kittyPtr->setPosition(event.motion.x, event.motion.y);
                }
            }
        }
        updateSprites();
    }

    void GameEngine::handleGameOverEvents(const SDL_Event &event)
    {
        // Handle GameOver state events (e.g., restart or return to main menu)
        // if (event.type == SDL_MOUSEBUTTONDOWN) {
        //     // Handle button clicks for restarting or exiting
        // }
    }

    void GameEngine::render()
    {
        SDL_RenderClear(sys.getRenderer()); // Clear the screen

        switch (currentState)
        {
        case GameState::MainMenu:
            renderMainMenu();
            break;
        case GameState::Playing:
            renderPlaying();
            break;
        case GameState::GameOver:
            renderGameOver();
            break;
        }

        SDL_RenderPresent(sys.getRenderer()); // Update the screen
    }

    void GameEngine::renderMainMenu()
    {
        startButton.draw(sys.getRenderer());
        exitButton.draw(sys.getRenderer());
    }

    void GameEngine::renderPlaying()
    {
        for (const auto &sprite : sprites)
        {
            sprite->draw(sys.getRenderer());
        }
        // Add other gameplay rendering here (e.g., score, lives)
    }

    void GameEngine::renderGameOver()
    {
        // Render GameOver screen items (e.g., messages, buttons)
    }

    void GameEngine::handleKeyboardEvent(const SDL_KeyboardEvent &keyEvent)
    {
        Kitty *kittyPtr = dynamic_cast<Kitty *>(kitty);
        if (kittyPtr)
        {
            switch (keyEvent.keysym.sym)
            {
            case SDLK_UP:
                kittyPtr->move(0, -5);
                break; // Move kitty up
            case SDLK_DOWN:
                kittyPtr->move(0, 5);
                break; // Move kitty down
            case SDLK_LEFT:
                kittyPtr->move(-5, 0);
                break; // Move kitty left
            case SDLK_RIGHT:
                kittyPtr->move(5, 0);
                break; // Move kitty right
            }
        }
    }

    bool GameEngine::isMouseOnSprite(int mouseX, int mouseY, const SDL_Rect &rect)
    {
        return mouseX >= rect.x && mouseX <= rect.x + rect.w &&
               mouseY >= rect.y && mouseY <= rect.y + rect.h;
    }

    void GameEngine::updateSprites()
    {
        for (auto &sprite : sprites)
        {
            sprite->update();
        }
    }

    bool GameEngine::checkCollisions()
    {
        for (const auto &sprite : sprites)
        {
            if (isAsteroid(sprite.get()) && Utils::checkCollision(sprite->getRect(), kitty->getRect()))
            {
                return true; // Collision detected
            }
        }
        return false; // No collision
    }

    // Helper function to determine if a sprite is an asteroid
    bool GameEngine::isAsteroid(const Sprite *sprite)
    {
        // Implement logic to determine if the sprite is an asteroid
        return false;
    }

}
