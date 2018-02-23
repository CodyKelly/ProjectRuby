#include <random>

#include "Map.hpp"

Map::Map()
{
    heightMap = new float[totalTiles()];
    tileMap = new int[totalTiles()];
    generateHeightmap(heightMap);
    
}

void Map::generateHeightmap(float* map)
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            map[getIndexFromCoord(x, y)] = noise.GetValue(x, y);
        }
    }
}

void Map::generateTilemap(const float *const heightMap, int *tileMap)
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            int index = getIndexFromCoord(x, y);
            tileMap[index] = lookupTile(heightMap[index]);
        }
    }
}

int Map::lookupTile(float height)
{
    return 1;
}
