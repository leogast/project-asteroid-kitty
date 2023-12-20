
# README - Asteroid Kitty

## Project Overview
Welcome to the "Asteroid Kitty" game, a fun and engaging 2D arcade-style game developed in C++ using the SDL2 library. In this game, players guide a kitty through an asteroid shower, avoiding collisions to survive.

## Prerequisites
- C++ Compiler (GCC or similar)
- SDL2 library
- SDL2_image, SDL2_ttf, and SDL2_mixer extensions

## Building the Project
To build the project, follow these steps:
1. Ensure SDL2 and its extensions are correctly installed on your system.
2. Clone the repository or download the project files.
3. Navigate to the project directory.
4. Run the `make` command to build the project:
   ```
   make
   ```

## Running the Game
After building the project, you can run the game by executing the compiled binary located in the `build/debug` directory.


## Game Instructions
### Objective
Guide the kitty through an asteroid shower in the desert, avoiding collisions to survive.

### Controls
- The kitty follows your mouse cursor.
- Alternatively, use the arrow keys on the keyboard to move the kitty.

### Gameplay
- Navigate through the gaps between asteroids.
- Avoid collisions with asteroids.
- The kitty changes sprite upon collisions and recovers after a short period.
- The game is over after three collisions.

### Scoring
- Points are earned based on the duration of survival.
- The score is displayed on the top-left corner of the screen.

## Game Features
- Start and Quit options at the beginning and end of the game.
- Three kitty sprite states: normal, hit, and flying.
- Progressive difficulty with faster-moving asteroids.
- Background music and sound effects.

## File Structure
Refer to the project's file structure for the organization of source code, resources, and documentation.

## Additional Notes
- The game is compatible with Linux and Windows platforms.
- No external DLLs or libraries are included in the submission; ensure SDL2 and its extensions are installed on your system.

