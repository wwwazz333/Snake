#include "PauseGame.hpp"
#include <SFML/Window/Event.hpp>

PauseGame::PauseGame(std::shared_ptr<Context> &context) : m_context(context)
{

}

PauseGame::~PauseGame() {

}

void PauseGame::init()
{
    // pauseTitle
    m_context->m_assets->addFont(MAIN_FONT, "assets/arial_narrow_7.ttf");
    m_pauseTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_pauseTitle.setString("Pause");
    m_pauseTitle.setOrigin(m_pauseTitle.getLocalBounds().width/2, m_pauseTitle.getLocalBounds().height/2);
    m_pauseTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 150.0f);
}
void PauseGame::processInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_context->m_window->close();
        else if(event.type == sf::Event::KeyPressed){
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                m_context->m_states->popCurrent();
                break;
            default:
                break;
            }
        }
    }
}
void PauseGame::update(sf::Time deltaTime)
{
    
}
void PauseGame::draw()
{
    m_context->m_window->draw(m_pauseTitle);
    m_context->m_window->display();
}