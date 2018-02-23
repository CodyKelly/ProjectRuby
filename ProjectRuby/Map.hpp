#ifndef Map_hpp
#define Map_hpp

#include <FastNoise.h>

class Map
{
private:
    FastNoise noise;
    const int size = 100;
    float* heightMap;
    int* tileMap;
public:
    Map();
    inline int totalTiles() { return size*size; }
    int lookupTile(float);
    void generateHeightmap(float*);
    void generateTilemap(const float *const, int*);
    inline int getIndexFromCoord(int x, int y) { return y * size + x; }
};

#endif /* Map_hpp */
