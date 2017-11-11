#include <vector>

#include "Control.hpp"
#include "States.hpp"

int main()
{
    Control control;
    
    std::vector<State*> states = { new MainMenu() };
    
    control.setupStates(states, states[0]);
    
    control.main();
    
    return 0;
}
