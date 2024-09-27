#include "AudioManager.h"

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{
    this->cleanup();
}

void AudioManager::playMusic(std::string filename, float volume, bool loop)
{
    if (!this->music.openFromFile(filename)) {
        std::cerr << "ERROR > AudioManager::playMusic::Cannot load music file: " << filename << std::endl;
        return;
    }

    this->music.setLoop(loop);
    this->music.setVolume(volume);
    this->music.play();
}

void AudioManager::stopMusic()
{
    this->music.stop();
}

void AudioManager::playSound(std::string soundName)
{
    if (this->soundBuffers.find(soundName) == this->soundBuffers.end()) {
        std::cerr << "ERROR > AudioManager::playSound::Sound not found: " << soundName << std::endl;
        return;
    }

    std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>();
    sound->setBuffer(this->soundBuffers[soundName]);
    sound->play();

    this->sounds.push_back(std::move(sound));
}

void AudioManager::loadSound(std::string soundName, std::string filename)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename)) {
        std::cerr << "ERROR > AudioManager::loadSound::Cannot load sound file: " << filename << std::endl;
        return;
    }

    this->soundBuffers[soundName] = std::move(buffer);
}

void AudioManager::cleanup()
{
    this->stopMusic();
    this->soundBuffers.clear();
    this->sounds.clear();
}
