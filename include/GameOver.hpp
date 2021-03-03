#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class GameOver : public Engine::State
{

public:
    GameOver(std::shared_ptr<Context> &context);
    ~GameOver();

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;


private:
    std::shared_ptr<Context> m_context;

    sf::Text m_gameOverTitle;
    sf::Text m_retryButton;
    sf::Text m_exitButton;
    sf::Text* m_currentButton;
    bool m_btnPressed = false;

    bool isEqual(sf::Text a, sf::Text b){
        return a.getString() == b.getString() && a.getCharacterSize() == b.getCharacterSize();
    }
};