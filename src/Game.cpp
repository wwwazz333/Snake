#include "Game.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Game::Game(): m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close);
    // TODO
    // add first state to m_states here;
}

Game::~Game() {

}

void Game::run()
{
    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > FPS)
        {
            timeSinceLastFrame -= FPS;

            // m_context->m_states->precessStateChange();
            // m_context->m_states->getCurrent()->processInput();
            // m_context->m_states->getCurrent()->update(FPS);
            // m_context->m_states->getCurrent()->draw();
        
            sf::Event event;
            while (m_context->m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_context->m_window->close();
            }

            m_context->m_window->clear();
            m_context->m_window->draw(shape);
            m_context->m_window->display();
        }
    }
}