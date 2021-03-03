#pragma once

#include "State.hpp"
#include "Snake.hpp"
#include <memory>
#include <array>
#include "Game.hpp"

#include <SFML/Graphics/Sprite.hpp>

class GamePlay : public Engine::State
{
public:
    GamePlay(std::shared_ptr<Context> &context);
    ~GamePlay();

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;

    void pause() override;
    void start() override;
private:
    std::shared_ptr<Context> m_context;

    sf::Sprite m_grass;
    sf::Sprite m_food;

    std::array<sf::Sprite, 4> m_walls;

    Snake m_snake;
    sf::Vector2f m_snakeDirection;

    sf::Time m_deltaTime;
};