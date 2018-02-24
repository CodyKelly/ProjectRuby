#ifndef AnimatedTexture_hpp
#define AnimatedTexture_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class AnimatedTexture
{
private:
    std::vector<sf::Texture> textures;
    int currentTexture = 0;
public:
    inline AnimatedTexture(sf::Texture t) { textures.push_back(t); }
    void addTexture(sf::Texture);
    bool addFromFile(std::string);
    inline sf::Texture getTexture() { return textures[currentTexture]; }
};

#endif /* AnimatedTexture_hpp */
