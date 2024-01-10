#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants
{
    // gResPath-contains the relative path to your resources.
    const std::string gResPath = "../../resources/";

    // Screen dimensions
    const int SCREEN_WIDTH = 800;  // Default width of the game window
    const int SCREEN_HEIGHT = 600; // Default height of the game window

    // Sprite dimensions
    const int KITTY_WIDTH = 64;     // Width of the kitty sprite
    const int KITTY_HEIGHT = 64;    // Height of the kitty sprite
    const int ASTEROID_WIDTH = 32;  // Width of the asteroid sprite
    const int ASTEROID_HEIGHT = 32; // Height of the asteroid sprite

    // Game settings
    const int INITIAL_ASTEROID_SPAWN_INTERVAL = 1000; // Time in milliseconds
    const int INCREASED_SPAWN_INTERVAL_5SEC = 500;    // Time in milliseconds after 5 seconds
    const int INCREASED_SPAWN_INTERVAL_10SEC = 250;   // Time in milliseconds after 10 seconds
}

#endif