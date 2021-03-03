#include "MainMenu.hpp"
#include <SFML/Window/Event.hpp>

#include "GamePlay.hpp"

MainMenu::MainMenu(std::shared_ptr<Context> &context) : m_context(context), m_currentButton(&m_playButton)
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
    m_playButton.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_playButton.setString("play");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width/2, m_playButton.getLocalBounds().height/2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 25.f);
    // m_playButton.setCharacterSize(20);

    // exitButton
    m_exitButton.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_exitButton.setString("exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width/2, m_exitButton.getLocalBounds().height/2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 + 25.f);
    // m_exitButton.setCharacterSize(20);
}
void MainMenu::processInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_context->m_window->close();
        else if(event.type == sf::Event::KeyPressed){
            switch (event.key.code)
            {
            case sf::Keyboard::Up :
                m_currentButton = &m_playButton;
                break;
            case sf::Keyboard::Down:
                m_currentButton = &m_exitButton;
                break;
            case sf::Keyboard::Return:
                m_btnPressed = true;
                break;
            default:
                break;
            }
        }
    }
}
void MainMenu::update(sf::Time deltaTime)
{
    m_playButton.setFillColor(sf::Color::White);
    m_exitButton.setFillColor(sf::Color::White);
    
    if(m_currentButton != nullptr) {m_currentButton->setFillColor(sf::Color::Yellow);}
    if(m_btnPressed){
        if(isEqual(*m_currentButton, m_playButton)){
            // TODO
            m_context->m_states->add(std::make_unique<GamePlay>(m_context), true);
        }
        else if(isEqual(*m_currentButton, m_exitButton)){
            // TODO
            m_context->m_window->close();
        }
        m_btnPressed = false;
    }
}
void MainMenu::draw()
{
    m_context->m_window->clear(sf::Color(0, 0, 125));
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}