#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <SFML/Window.hpp>

#include "StateMachine.hpp"

class MainMenu : public State
{
public:
    MainMenu();
    void update(std::vector<sf::Event>) override;
    void draw(sf::RenderWindow&) override;
private:
    std::pair<double, double> circlePos = std::pair<double, double>(0, 0);
    int circleWidth = 10;
    sf::Color circleColor = sf::Color::Green;
    sf::CircleShape circle;
};

#endif /* MainMenu_hpp */
