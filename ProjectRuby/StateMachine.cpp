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
            switchState();
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

void StateMachine::draw(sf::RenderWindow &window)
{
    try
    {
        currentState -> draw(window);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception thrown: " << e.what() << std::endl;
    }
}

void StateMachine::switchState()
{
    std::string nextState = currentState->get_next();
    
    for (auto state : states)
    {
        if (state->get_name() == nextState)
        {
            // Set next state to current and move game data to
            // the now-current state
            GameData persistantData = currentState->get_gameData();
            currentState = state;
            currentState->set_gameData(persistantData);
        }
    }
}
