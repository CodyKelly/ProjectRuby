#include <vector>

#include "Control.hpp"
#include "MainMenu.hpp"
#include "Game.hpp"

int main()
{
    Control control;
    
    std::vector<State*> states = { new MainMenu(), new Game() };
    
    control.setupStates(states, states[0]);
    
    control.main();
    
    for (auto s : states)
    {
        delete s;
    }
    
    return 0;
}
