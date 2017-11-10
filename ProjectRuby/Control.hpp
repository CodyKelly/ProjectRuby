#ifndef Control_hpp
#define Control_hpp

#include "StateMachine.hpp"

class Control
{
public:
    void main();
    
private:
    bool finished = false;
    StateMachine stateMachine;
};

#endif /* Control_hpp */
