#ifndef Control_hpp
#define Control_hpp

#include "StateMachine.hpp"
#include <SFML/Window.hpp>

class Control
{
public:
    Control();
    void main();
    void setupStates(std::vector<State*> states, State* initialState);
    
private:
    bool finished = false;
    StateMachine stateMachine;
    std::pair<int, int> screenSize;
    sf::Window window;
};

#endif /* Control_hpp */
