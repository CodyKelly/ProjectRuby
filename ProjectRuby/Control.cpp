#include <iostream>
#include <vector>

#include "Control.hpp"

void Control::renderingThread()
{
    // We can skip drawing if the program is done
    while (!finished)
    {
        window.clear();
        stateMachine.draw(window);
        window.display();
    }
}

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
    
    window.setActive(false);
    
    sf::Thread thread(&Control::renderingThread, this);
    
    thread.launch();
    
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
    }
}
