#include <exception>
#include <iostream>

#include "StateMachine.hpp"

void StateMachine::update()
{
    while (!done)
    {
        try
        {
            currentState -> update();
            
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
}
