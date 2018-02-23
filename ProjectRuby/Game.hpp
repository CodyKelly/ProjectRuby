#ifndef Game_hpp
#define Game_hpp

#include <State.hpp>
#include <SFML/Window.hpp>
#include <FastNoise.h>

#include "Map.hpp"

class Game : public State
{
protected:
    void on_enter() override;
public:
    inline Game() : State("GAME") { }
    void draw(sf::RenderWindow&) override;
    void update(std::vector<sf::Event>) override;
    Map map;
};

#endif /* Game_hpp */
