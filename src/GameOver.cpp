#include "GameOver.hpp"
#include <SFML/Window/Event.hpp>

#include "GamePlay.hpp"

GameOver::GameOver(std::shared_ptr<Context> &context) : m_context(context), m_currentButton(&m_retryButton)
{

}

GameOver::~GameOver() {

}

void GameOver::init()
{
    // gameOverTitle
    m_context->m_assets->addFont(MAIN_FONT, "assets/arial_narrow_7.ttf");
    m_gameOverTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_gameOverTitle.setString("game Over");
    m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width/2, m_gameOverTitle.getLocalBounds().height/2);
    m_gameOverTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 150.0f);
 
    // retrayButton
    m_retryButton.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_retryButton.setString("retry");
    m_retryButton.setOrigin(m_retryButton.getLocalBounds().width/2, m_retryButton.getLocalBounds().height/2);
    m_retryButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 25.f);
    m_retryButton.setCharacterSize(20);

    // exitButton
    m_exitButton.setFont(m_context->m_assets->getFont(MAIN_FONT));
    m_exitButton.setString("exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width/2, m_exitButton.getLocalBounds().height/2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 + 25.f);
    m_exitButton.setCharacterSize(20);
}
void GameOver::processInput()
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
                m_currentButton = &m_retryButton;
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
void GameOver::update(sf::Time deltaTime)
{
    m_retryButton.setFillColor(sf::Color::White);
    m_exitButton.setFillColor(sf::Color::White);
    
    if(m_currentButton != nullptr) {m_currentButton->setFillColor(sf::Color::Yellow);}
    if(m_btnPressed){
        if(isEqual(*m_currentButton, m_retryButton)){
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
void GameOver::draw()
{
    m_context->m_window->clear(sf::Color(0, 0, 125));
    m_context->m_window->draw(m_gameOverTitle);
    m_context->m_window->draw(m_retryButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}