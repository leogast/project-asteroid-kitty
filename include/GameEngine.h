#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
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
    void initializeLevel(int level) {}
    void cleanup() {}
    void setFrameRate(int fps); // New method to set frame rate

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

    int frameRate;     // New member to store the frame rate
    Uint32 frameDelay; // New member to store the delay per frame

    Mix_Music *backgroundMusic; // For background music

    void processEvents();
    void update();
    void render();
    void checkCollisions();
    void handleAsteroidSpawning();
    void spawnAsteroid();
    void gameOver();
    void calculateFrameDelay(); // New method to calculate frame delay
};

#endif
