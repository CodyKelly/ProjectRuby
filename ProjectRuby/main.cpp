#include <vector>

#include "Control.hpp"
#include "States.hpp"

int main()
{
    Control control;
    
    std::vector<State*> states = { new MainMenu(), new TestState() };
    
    control.setupStates(states, states[0]);
    
    control.main();
    
    for (auto s : states)
    {
        delete s;
    }
    
    return 0;
}
