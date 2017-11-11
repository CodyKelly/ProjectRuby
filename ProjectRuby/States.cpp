#include "States.hpp"

MainMenu::MainMenu() : State("MAINMENU")
{
    circle.setRadius(circleWidth);
    circle.setOrigin(circlePos.first, circlePos.second);
    circle.setFillColor(circleColor);
};

void MainMenu::update(std::vector<sf::Event> events)
{
    circlePos.first -= 0.001;
    circlePos.second -= 0.001;
    circle.setOrigin(circlePos.first, circlePos.second);
}

void MainMenu::draw(sf::RenderWindow& window)
{
    window.draw(circle);
    if (circlePos.second < -600)
    {
        exit = true;
    }
}
