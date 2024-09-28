#pragma once

#include <iostream>
#include <map>

#include <SFML/Audio.hpp>

class AudioManager
{
private:
    AudioManager();
    ~AudioManager();

    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;

    sf::Music music;
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::vector<std::unique_ptr<sf::Sound>> sounds;

public:
    static AudioManager& getInstance();

    void playMusic(std::string filename, float volume, bool loop);
    void stopMusic();
    void loadSound(std::string soundName, std::string filename);
    void playSound(std::string soundName);
    void cleanup();
};
