#pragma once

#include <vector>

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

    bool isBitHisTail(){
        for(auto& piece : body){
            if(&piece != &body[0] && isOn(piece))
                return true;
        
        }
        return false;
    }
private:
    std::vector<sf::Sprite> body;
};