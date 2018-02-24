#ifndef Map_hpp
#define Map_hpp

#include <FastNoise.h>
#include <SFML/Graphics.hpp>

/*
 TODO:
 - Finish createMap function
    - Creates a drawable vertex array
    - Loads textures
 - Finish update function
    - Updates animated textures
 - Multithread map updating?
    - Check for changes in tile/heightmaps in different threads
 */

class Map : public sf::Drawable, public sf::Transformable
{
private:
    FastNoise noise;
    const int size = 100;
    float* heightMap;
    int* tileMap;
    sf::VertexArray m_vertices;
    inline int totalTiles() { return size*size; }
    int lookupTile(float);
    void generateHeightmap(float*);
    void generateTilemap(const float *const, int*);
    inline int getIndexFromCoord(int x, int y) { return y * size + x; }
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
public:
    Map();
};

#endif /* Map_hpp */
