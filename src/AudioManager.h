#pragma once

#include <iostream>
#include <map>

#include <SFML/Audio.hpp>

class AudioManager
{
private:
    sf::Music music;
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::vector<std::unique_ptr<sf::Sound>> sounds;

public:
    AudioManager();
    virtual ~AudioManager();

    void playMusic(std::string filename, float volume, bool loop);
    void stopMusic();
    void playSound(std::string soundName);
    void loadSound(std::string soundName, std::string filename);
    void cleanup();
};
