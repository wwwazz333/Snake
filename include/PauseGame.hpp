#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class PauseGame : public Engine::State
{

public:
    PauseGame(std::shared_ptr<Context> &context);
    ~PauseGame();

    void init();
    void processInput();
    void update(sf::Time deltaTime);
    void draw();
private:
    std::shared_ptr<Context> m_context;

    sf::Text m_pauseTitle;
};