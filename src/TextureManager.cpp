#include "TextureManager.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
    this->cleanup();
}

TextureManager& TextureManager::getInstance()
{
    static TextureManager instance;
    return instance;
}

void TextureManager::loadTexture(std::string textureName, std::string filename)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
        std::cerr << "ERROR > TextureManager::loadTexture::Cannot load texture file: " << filename << std::endl;
        return;
    }

    this->textures[textureName] = std::move(texture);
}

sf::Texture& TextureManager::getTexture(std::string textureName)
{
    if (this->textures.find(textureName) == this->textures.end())
    {
        std::cerr << "ERROR > TextureManager::getTexture::Texture not found: " << textureName << std::endl;
        static sf::Texture emptyTexture;
        return emptyTexture;
    }

    return this->textures[textureName];
}

void TextureManager::cleanup()
{
    this->textures.clear();
}
