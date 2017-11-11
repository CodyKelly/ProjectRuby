#include <iostream>
#include <vector>

#include "Control.hpp"

Control::Control()
{
    screenSize = std::pair<int, int>(800, 600);
    window.create(sf::VideoMode(screenSize.first, screenSize.second), "Project Ruby");
}

void Control::setupStates(std::vector<State *> states, State *initialState)
{
    stateMachine.setupStates(states, initialState);
}

void Control::main()
{
    window.setFramerateLimit(frameRateLimit);
    
    while (!finished)
    {
        // Create vector to hold events
        std::vector<sf::Event> events;
        sf::Event event;
        
        // Populate event vector
        while(window.pollEvent(event))
        {
            events.push_back(event);
        }
        
        stateMachine.update(events);
        
        finished = stateMachine.get_done();
        
        for (auto e : events)
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
                finished = true;
            }
        }
        
        // We can skip drawing if the program is done
        if (!finished)
        {
            stateMachine.draw(window);
        }
    }
}
