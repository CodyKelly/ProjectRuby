#include <iostream>

#include "Control.hpp"

void Control::main()
{
    while (!finished)
    {
        stateMachine.update();
        
        finished = stateMachine.get_done();
    }
}
