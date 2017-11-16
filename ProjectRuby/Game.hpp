#ifndef Game_hpp
#define Game_hpp

#include <StateMachine.hpp>
#include <SFML/Window.hpp>

class Game : public State
{
protected:
    void on_enter() override;
public:
    inline Game() : State("GAME") { }
    void draw(sf::RenderWindow&) override;
    void update(std::vector<sf::Event>) override;
};

#endif /* Game_hpp */
