#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <string>
#include <SFML/Window.hpp>
#include <vector>

class State
{
private:
    bool done = false;
    bool exit = false;
    State* next = nullptr;
    std::string name;
public:
    State(std::string);
    virtual void update(std::vector<sf::Event>) = 0;
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
    std::vector<State*> states;
    
public:
    void update(std::vector<sf::Event>);
    void draw();
    bool get_done() { return done; }
    void setupStates(std::vector<State*> states, State* initialState);
};

#endif /* StateMachine_hpp */
