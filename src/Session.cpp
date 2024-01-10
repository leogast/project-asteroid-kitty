#include "Session.h"

Session::Session(System &system)
    : gameEngine(std::make_unique<GameEngine>(system)) {}

void Session::startNewGame()
{
    gameEngine->run(); // Start the game loop
}

void Session::endCurrentGame() {} // Implement any necessary cleanup or state reset logic

void Session::run()
{
    startNewGame(); // Start a new game session
}
