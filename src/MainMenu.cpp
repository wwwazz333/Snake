#include "MainMenu.hpp"
#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context> &context) : m_context(context)
{

}

MainMenu::~MainMenu() {

}

void MainMenu::init()
{
    // gameTitle
    m_context->m_assets->addFont(MAIN_FONT, "assets/arial_narrow_7.ttf");
    m_gameTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_gameTitle.setString("snake game");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width/2, m_gameTitle.getLocalBounds().height/2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 150.0f);
 
    // playButton
    m_context->m_assets->addFont(MAIN_FONT, "assets/arial_narrow_7.ttf");
    m_playButton.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_playButton.setString("snake game");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width/2, m_playButton.getLocalBounds().height/2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 25.f);
    m_playButton.setCharacterSize(20);

    // exitButton
    m_context->m_assets->addFont(MAIN_FONT, "assets/arial_narrow_7.ttf");
    m_exitButton.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_exitButton.setString("snake game");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width/2, m_exitButton.getLocalBounds().height/2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 + 25.f);
    m_exitButton.setCharacterSize(20);
}
void MainMenu::processInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_context->m_window->close();
    }
}
void MainMenu::update(sf::Time deltaTime)
{

}
void MainMenu::draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->display();
}