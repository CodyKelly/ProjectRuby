#ifndef Map_hpp
#define Map_hpp

#include <FastNoise.h>

class Map
{
private:
    FastNoise noise;
    int width;
    int height;
public:
    Map() { }
    void generate();
};

#endif /* Map_hpp */
