#include "GameEngine.h"
#include "System.h"
#include "Session.h"
#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        System sys(800, 600); // Initialize the system (SDL, window, renderer)
        Session session(sys);
        session.startNewGame(); // Start a new game
        session.run();          // Enter the game loop
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error occurred: " << e.what() << std::endl;
        return 1; // Return a non-zero value to indicate error
    }

    return 0; // Successful execution
}
