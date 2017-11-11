#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <string>

class State
{
private:
    bool done = false;
    bool exit = false;
    State* next = nullptr;
    std::string name;
public:
    virtual void update() = 0;
    virtual void draw() = 0;
    bool get_done() { return done; }
    bool get_exit() { return exit; }
    State* get_next() { return next; }
};

class StateMachine
{
private:
    State* currentState;
    bool done = false;
    
public:
    void update();
    void draw();
    bool get_done() { return done; }
};

#endif /* StateMachine_hpp */
