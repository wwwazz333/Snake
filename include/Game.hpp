#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetMan.hpp"
#include "StateMan.hpp"

#include <memory>

struct Context
{
    std::unique_ptr<Engine::AssetMan> m_assets;
    std::unique_ptr<Engine::StateMan> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    {
        m_assets = std::make_unique<Engine::AssetMan>();
        m_states = std::make_unique<Engine::StateMan>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};


class Game {

public:
    Game();
    ~Game();

    void run();
private:
    std::shared_ptr<Context> m_context;
    const sf::Time FPS = sf::seconds(1.0f/60.0f);
};