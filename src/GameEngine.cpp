#include "GameEngine.h"
#include "Constants.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>
#include <memory> // Include the <memory> header for std::shared_ptr
#include <iostream>

GameEngine::GameEngine(System &system)
    : system(system), running(true), collisionCount(0), lastAsteroidSpawnTime(0), frameRate(60) // Initialize frameRate to 60 FPS
{

    SDL_Init(SDL_INIT_EVERYTHING);
    backdrop = system.loadTexture(constants::gResPath + "images/backdrop1.png");

    // Initialize kitty sprite in the center of the screen
    int kittyX = (system.getScreenWidth() - constants::KITTY_WIDTH) / 2;
    int kittyY = (system.getScreenHeight() - constants::KITTY_HEIGHT) / 2;
    auto kittyTexture = system.loadTexture(constants::gResPath + "images/kitty1.png");
    kitty = std::make_shared<Kitty>(kittyTexture, kittyX, kittyY);
    addSprite(kitty);

    gameStartTime = SDL_GetTicks();
    srand(static_cast<unsigned int>(time(nullptr)));
    calculateFrameDelay(); // Calculate initial frame delay

    backgroundMusic = Mix_LoadMUS("sounds/music1.wav");
    if (!backgroundMusic)
    {
        std::cerr << "Failed to load background music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    else
    {
        if (Mix_PlayMusic(backgroundMusic, -1) == -1)
        { // -1 for looping
            std::cerr << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        }
    }
}

GameEngine::~GameEngine()
{
    if (backgroundMusic)
    {
        Mix_FreeMusic(backgroundMusic);
    }
    SDL_DestroyTexture(backdrop);
    SDL_Quit();
}

void GameEngine::run()
{
    Uint32 frameStart, frameTime;

    while (running)
    {
        frameStart = SDL_GetTicks();

        processEvents();
        update();
        render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void GameEngine::addSprite(std::shared_ptr<Sprite> sprite)
{
    sprites.push_back(sprite);
}

void GameEngine::removeSprite(Sprite *sprite)
{
    sprites.erase(std::remove_if(sprites.begin(), sprites.end(),
                                 [sprite](const std::shared_ptr<Sprite> &s)
                                 { return s.get() == sprite; }),
                  sprites.end());
}

void GameEngine::processEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        else
        {
            std::static_pointer_cast<Kitty>(kitty)->handleInput(event);
        }
    }
}

void GameEngine::update()
{
    handleAsteroidSpawning();
    for (auto &sprite : sprites)
    {
        sprite->update();
    }
    checkCollisions();
}

void GameEngine::render()
{
    SDL_Renderer *renderer = system.getRenderer();
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backdrop, NULL, NULL); // Render the backdrop

    for (auto &sprite : sprites)
    {
        sprite->draw(renderer);
    }

    SDL_RenderPresent(renderer);
}

void GameEngine::checkCollisions()
{
    // Collision detection logic
    for (auto &sprite : sprites)
    {
        if (sprite != kitty && kitty->checkCollision(*sprite))
        {
            collisionCount++;
            if (collisionCount >= 3)
            {
                gameOver();
                break;
            }
        }
    }
}

void GameEngine::handleAsteroidSpawning()
{
    Uint32 currentTime = SDL_GetTicks();
    Uint32 elapsed = currentTime - gameStartTime;
    Uint32 spawnInterval;

    if (elapsed < 5000)
    {
        spawnInterval = constants::INITIAL_ASTEROID_SPAWN_INTERVAL;
    }
    else if (elapsed < 10000)
    {
        spawnInterval = constants::INCREASED_SPAWN_INTERVAL_5SEC;
    }
    else
    {
        spawnInterval = constants::INCREASED_SPAWN_INTERVAL_10SEC;
    }

    if (currentTime - lastAsteroidSpawnTime > spawnInterval)
    {
        spawnAsteroid();
        lastAsteroidSpawnTime = currentTime;
    }
}

void GameEngine::spawnAsteroid()
{
    int asteroidX = rand() % system.getScreenWidth();
    auto asteroidTexture = system.loadTexture(constants::gResPath + "images/asteroid1.png");
    auto asteroid = std::make_shared<Asteroid>(asteroidTexture, asteroidX, 0);
    addSprite(asteroid);
}

void GameEngine::gameOver()
{
    running = false;
}

void GameEngine::setFrameRate(int fps)
{
    frameRate = fps;
    calculateFrameDelay();
}

void GameEngine::calculateFrameDelay()
{
    frameDelay = 1000 / frameRate; // 1000 ms in a second
}
