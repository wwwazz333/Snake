#include "Game.hpp"
#include "MainMenu.hpp"

Game::Game(): m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(640, 360), "SFML works!", sf::Style::Close);
    // TODO
    m_context->m_states->add(std::make_unique<MainMenu>(m_context));
}

Game::~Game() {

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > FPS)
        {
            timeSinceLastFrame -= FPS;

            m_context->m_states->precessStateChange();
            m_context->m_states->getCurrent()->processInput();
            m_context->m_states->getCurrent()->update(FPS);
            m_context->m_states->getCurrent()->draw();
        }
    }
}