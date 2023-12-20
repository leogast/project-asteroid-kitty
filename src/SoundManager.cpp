#include "SoundManager.h"
#include <iostream>

namespace cwing {

    SoundManager::SoundManager() : music(nullptr) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
            std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
            exit(1);
        }
    }

    SoundManager::~SoundManager() {
        for (auto& pair : soundEffects) {
            Mix_FreeChunk(pair.second);
        }
        if (music) {
            Mix_FreeMusic(music);
        }
        Mix_CloseAudio();
    }

    void SoundManager::loadSound(const std::string& name, const std::string& path) {
        Mix_Chunk* sound = loadSoundEffect(path);
        if (sound) {
            soundEffects[name] = sound;
        }
    }

    void SoundManager::playSound(const std::string& name, int loops) {
        auto it = soundEffects.find(name);
        if (it != soundEffects.end()) {
            Mix_PlayChannel(-1, it->second, loops);
        }
    }

    void SoundManager::loadMusic(const std::string& path) {
        if (music) {
            Mix_FreeMusic(music);
        }
        music = Mix_LoadMUS(path.c_str());
        if (!music) {
            std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        }
    }

    void SoundManager::playMusic(int loops) {
        if (music) {
            Mix_PlayMusic(music, loops);
        }
    }

    void SoundManager::stopMusic() {
        Mix_HaltMusic();
    }

    Mix_Chunk* SoundManager::loadSoundEffect(const std::string& path) {
        Mix_Chunk* sound = Mix_LoadWAV(path.c_str());
        if (!sound) {
            std::cerr << "Failed to load sound: " << Mix_GetError() << std::endl;
        }
        return sound;
    }

}
