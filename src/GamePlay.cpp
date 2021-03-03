#include "GamePlay.hpp"

#include <SFML/Window/Event.hpp>

#include <stdlib.h>
#include <time.h>
#include <cmath> 



GamePlay::GamePlay(std::shared_ptr<Context> &context) 
: m_context(context), m_snakeDirection(16.f, 0.f), m_deltaTime(sf::Time::Zero)
{
    srand(time(nullptr));
}

GamePlay::~GamePlay() {

}

void GamePlay::init()
{
    m_context->m_assets->addTexture(GRASS, "assets/grass.png", true);
    m_context->m_assets->addTexture(FOOD, "assets/food.png");
    m_context->m_assets->addTexture(SNAKE, "assets/snake.png");
    m_context->m_assets->addTexture(WALL, "assets/wall.png", true);

    m_grass.setTexture(m_context->m_assets->getTexture(GRASS));
    m_grass.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));

    for(auto& wall : m_walls){
        wall.setTexture(m_context->m_assets->getTexture(WALL));
    }
    
    m_walls[0].setTextureRect({0, 0, m_context->m_window->getSize().x, 16});
    m_walls[1].setTextureRect({0, 0, m_context->m_window->getSize().x, 16});
    m_walls[1].setPosition(0, m_context->m_window->getSize().y - 16);
    

    m_walls[2].setTextureRect({0, 0, 16, m_context->m_window->getSize().y});
    m_walls[3].setTextureRect({0, 0, 16, m_context->m_window->getSize().y});
    m_walls[3].setPosition(m_context->m_window->getSize().x - 16, 0);

    m_food.setTexture(m_context->m_assets->getTexture(FOOD));
    m_food.setPosition(m_context->m_window->getSize().x /2, m_context->m_window->getSize().y /2);

    m_snake.init(m_context->m_assets->getTexture(SNAKE));
}
void GamePlay::processInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_context->m_window->close();
        else if(event.type == sf::Event::KeyPressed){
            sf::Vector2f newDirection = m_snakeDirection;
            switch (event.key.code)
            {
            case sf::Keyboard::Right:
                newDirection = {16.f, 0.f};
                break;
            case sf::Keyboard::Left:
                newDirection = {-16.f, 0.f};
                break;
            case sf::Keyboard::Up:
                newDirection = {0.f, -16.f};
                break;
            case sf::Keyboard::Down:
                newDirection = {0.f, 16.f};
                break;
            default:
                break;
            }
            if (std::abs(m_snakeDirection.x) != std::abs(newDirection.x) ||
                std::abs(m_snakeDirection.y) != std::abs(newDirection.y))
            {
                m_snakeDirection = newDirection;
            }
        }
    }
}
void GamePlay::update(sf::Time deltaTime)
{
    m_deltaTime += deltaTime;
    if(m_deltaTime.asSeconds() > 0.1){

        for(auto& wall : m_walls){
            if(m_snake.isOn(wall)){
                // Game Over
                break;
            }
        }

        if(m_snake.isOn(m_food)){
            m_snake.grow(m_snakeDirection);
            int w = m_context->m_window->getSize().x / 16 - 2;
            int h = m_context->m_window->getSize().y / 16 - 2;
            int x = (rand() % w) * 16 + 16;
            int y = (rand() % h) * 16 + 16;
            m_food.setPosition(x, y);
            
        }
        else{
            m_snake.move(m_snakeDirection);
        }


        m_deltaTime = sf::Time::Zero;
    }
}
void GamePlay::draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_grass);

    for(auto& wall : m_walls){
        m_context->m_window->draw(wall);
    }
    m_context->m_window->draw(m_food);
    m_context->m_window->draw(m_snake);
    m_context->m_window->display();
}

void GamePlay::pause()
{

}
void GamePlay::start()
{

}