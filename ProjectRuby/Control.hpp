#ifndef Control_hpp
#define Control_hpp

#include "StateMachine.hpp"
#include <SFML/Graphics.hpp>

class Control
{
public:
    Control();
    void main();
    void setupStates(std::vector<State*> states, State* initialState);
    
private:
    unsigned int frameRateLimit = 60;
    bool finished = false;
    StateMachine stateMachine;
    std::pair<int, int> screenSize;
    sf::RenderWindow window;
    void renderingThread();
};

#endif /* Control_hpp */
