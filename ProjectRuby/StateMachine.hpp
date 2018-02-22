/*
 FILE: StateMachine
*/

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Tools.hpp"
#include "State.hpp"

class StateMachine
{
private:
    State* currentState;
    bool done = false;
    std::vector<State*> states;
    void switchState();
    
public:
    void update(std::vector<sf::Event>);
    void draw(sf::RenderWindow&);
    bool get_done() const { return done; }
    void setupStates(std::vector<State*> states, State* initialState);
};

#endif /* StateMachine_hpp */
