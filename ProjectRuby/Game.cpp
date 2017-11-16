#include "Game.hpp"

void Game::on_enter()
{
    worldNoise.SetNoiseType(FastNoise::Perlin);
}

void Game::update(std::vector<sf::Event> events)
{
    
}

void Game::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::White);
}
