#pragma once

#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>

class TextureManager {
private:
    TextureManager();
    ~TextureManager();

    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    std::map<std::string, sf::Texture> textures;

public:
    static TextureManager& getInstance();

    void loadTexture(std::string textureName, std::string filename);
    sf::Texture& getTexture(std::string textureName);
    void cleanup();
};
