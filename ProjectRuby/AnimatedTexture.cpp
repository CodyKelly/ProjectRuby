#include "AnimatedTexture.hpp"
#include "ResourcePath.hpp"

void AnimatedTexture::addTexture(sf::Texture texture)
{
    textures.push_back(texture);
}

bool AnimatedTexture::addFromFile(std::string path)
{
    sf::Texture texture;
    bool success;
    
    success = texture.loadFromFile(resourcePath() + path);
    
    if (success)
    {
        textures.push_back(texture);
    }
    
    return success;
}
