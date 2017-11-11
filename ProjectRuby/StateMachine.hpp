#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Tools.hpp"

class State
{
private:
    bool done = false;
    bool exit = false;
    std::string next;
    std::string name;
    GameData gameData;
public:
    State(std::string);
    virtual void update(std::vector<sf::Event>);
    virtual void draw(sf::RenderWindow&);
    bool get_done() const { return done; }
    void set_done() { done = true; }
    bool get_exit() const { return exit; }
    void set_exit() { exit = true; }
    std::string get_next() const { return next; }
    void set_next(std::string n) { next = n; }
    std::string get_name() const { return name; }
    void set_gameData(GameData data) { gameData = data; }
    GameData get_gameData() const { return gameData; }
};

class StateMachine
{
private:
    State* currentState;
    bool done = false;
    std::vector<State*> states;
    void switchState();
    
public:
    void update(std::vector<sf::Event>);
    void draw(sf::RenderWindow&);
    bool get_done() const { return done; }
    void setupStates(std::vector<State*> states, State* initialState);
};

#endif /* StateMachine_hpp */
