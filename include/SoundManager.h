#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SDL2/SDL_mixer.h>
#include <string>
#include <unordered_map>

namespace cwing {

    class SoundManager {
    public:
        SoundManager();
        ~SoundManager();

        void loadSound(const std::string& name, const std::string& path);
        void playSound(const std::string& name, int loops = 0);

        void loadMusic(const std::string& path);
        void playMusic(int loops = -1);
        void stopMusic();

    private:
        std::unordered_map<std::string, Mix_Chunk*> soundEffects;
        Mix_Music* music;

        // Helper function to safely load and assign sounds
        Mix_Chunk* loadSoundEffect(const std::string& path);
    };

}

#endif
