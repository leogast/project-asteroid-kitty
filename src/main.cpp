#include "System.h"     // For initializing and managing SDL
#include "GameEngine.h" // For the game engine

using namespace cwing;

int main(int argc, char** argv) 
{
    //cwing::System sys;
    GameEngine engine;

    // ... setup and run the game ...
    engine.run();

    return 0;
}
