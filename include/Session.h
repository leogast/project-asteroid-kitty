#ifndef SESSION_H
#define SESSION_H

#include "GameEngine.h"
#include <memory>

class Session
{
public:
    explicit Session(System &system);
    void startNewGame();
    void endCurrentGame();
    void run();

private:
    std::unique_ptr<GameEngine> gameEngine;
    int currentLevel = 0;
};

#endif
