/*
 FILE: State.hpp
 PROVIDES: A class for a game state to be used in a state machine. Has functions
 to control what the state does on enter and what state, if any, will be loaded
 when the current state is finished.
 

 CONSTRUCTOR for the state class:
 State(
    const std::string n
 )
 
    Postcondition:
 
*/

#ifndef State_hpp
#define State_hpp

#include <string>
#include <SFML/Graphics.hpp>
#include "Tools.hpp"

class State
{
private:
    bool done = false;
    bool exit = false;
    std::string next;
    const std::string name;
    GameData gameData;
protected:
    virtual void on_enter() { }
    virtual void on_exit() { }
public:
    inline State(const std::string n) : name(n) { }
    friend class StateMachine;
    inline virtual void update(std::vector<sf::Event>) { }
    inline virtual void draw(sf::RenderWindow& w) { w.clear(sf::Color::White); }
    inline bool get_done() const { return done; }
    inline void set_done() { done = true; }
    inline bool get_exit() const { return exit; }
    inline void set_exit() { exit = true; }
    inline std::string get_next() const { return next; }
    inline void set_next(std::string n) { next = n; }
    inline std::string get_name() const { return name; }
    inline void set_gameData(GameData data) { gameData = data; }
    inline GameData get_gameData() const { return gameData; }
};

#endif /* State_hpp */
