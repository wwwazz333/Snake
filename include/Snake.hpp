#pragma once

#include <list>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


class Snake  : public sf::Drawable
{
public:
    Snake();
    ~Snake();

    void init(const sf::Texture& texture);
    void move(const sf::Vector2f& direction);
    bool isOn(const sf::Sprite& other) const;
    void grow(const sf::Vector2f& direction);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    std::list<sf::Sprite> m_body;
    std::list<sf::Sprite>::iterator m_head;
    std::list<sf::Sprite>::iterator m_tail;
    
};