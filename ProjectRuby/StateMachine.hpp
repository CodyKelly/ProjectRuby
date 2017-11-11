#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Tools.hpp"

class State
{
protected:
    bool done = false;
    bool exit = false;
private:
    std::string next;
    std::string name;
    GameData gameData;
public:
    State(std::string);
    virtual void update(std::vector<sf::Event>) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
    bool get_done() const { return done; }
    bool get_exit() const { return exit; }
    std::string get_next() const { return next; }
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
