#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine::State
{

public:
    MainMenu(std::shared_ptr<Context> &context);
    ~MainMenu();

    void init() override;
    void processInput() override;
    void update(sf::Time deltaTime) override;
    void draw() override;


private:
    std::shared_ptr<Context> m_context;

    sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;
    sf::Text* m_currentButton;
    bool m_btnPressed = false;

    bool isEqual(sf::Text a, sf::Text b){
        return a.getString() == b.getString() && a.getCharacterSize() == b.getCharacterSize();
    }
};