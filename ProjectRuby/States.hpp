#ifndef States_hpp
#define States_hpp

#include <StateMachine.hpp>
#include <string>
#include <SFML/Window.hpp>
#include <vector>

class MainMenu : public State
{
public:
    MainMenu();
    void update(std::vector<sf::Event>) override;
    void draw() override;
private:
    
};

#endif /* States_hpp */
