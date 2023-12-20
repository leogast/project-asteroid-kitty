#include "Constants.h"  // For gResPath and other global constants
#include "System.h"     // For initializing and managing SDL
#include "GameEngine.h" // For the game engine

int main(int argc, char** argv) 
{
    //cwing::System sys;
    cwing::GameEngine engine;

    // ... setup and run the game ...
    engine.run();

    return 0;
}
