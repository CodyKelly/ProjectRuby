#include <exception>
#include <iostream>

#include "StateMachine.hpp"

State::State(std::string n) : name(n) { }

void StateMachine::setupStates(std::vector<State *> newStates, State *initialState)
{
    states = newStates;
    currentState = initialState;
}

void StateMachine::update(std::vector<sf::Event> events)
{
    try
    {
        currentState -> update(events);
        
        if (currentState -> get_done())
        {
            currentState = currentState -> get_next();
        }
        
        if (currentState -> get_exit())
        {
            done = true;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception thrown: " << e.what() << std::endl;
    }
}
