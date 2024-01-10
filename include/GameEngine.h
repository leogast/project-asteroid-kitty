#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "System.h"

class GameEngine
{
public:
    explicit GameEngine(System &system);
    ~GameEngine();
    void run();
    void addSprite(std::shared_ptr<Sprite> sprite);
    void removeSprite(Sprite *sprite);
    void initializeLevel(int level)
    {
        // Function definition for initializeLevel
        // Add your code here
    }
    void cleanup()
    {
        // Function definition for cleanup
        // Add your code here
    }

private:
    System &system;
    bool running;
    std::vector<std::shared_ptr<Sprite>> sprites;
    std::shared_ptr<Sprite> kitty; // Kitty sprite
    int collisionCount;
    Uint32 lastAsteroidSpawnTime;
    Uint32 gameStartTime;
    SDL_Renderer *renderer;
    SDL_Texture *backdrop;

    void processEvents();
    void update();
    void render();
    void checkCollisions();
    void handleAsteroidSpawning();
    void spawnAsteroid();
    void gameOver();
};

#endif
