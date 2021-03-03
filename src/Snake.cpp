#include "Snake.hpp"

Snake::Snake()
{
}

Snake::~Snake() {

}

void Snake::init(const sf::Texture& texture)
{
    float x = 16.0f * 7.f;
    for(auto i = 0 ; i < 4 ; i++){
        sf::Sprite sp;
        sp.setTexture(texture);
        sp.setPosition({x, 16.f});
        body.push_back(sp);
        x -= 16.f;
    }
}
void Snake::move(const sf::Vector2f& direction)
{   
    for (auto i = body.size()-1; i > 0; i--)
    {
        body[i].setPosition(body[i-1].getPosition());
    }
    
    body[0].setPosition(body[0].getPosition() + direction);
}
bool Snake::isOn(const sf::Sprite& other) const
{
    return other.getGlobalBounds().intersects(body.front().getGlobalBounds());
}
void Snake::grow(const sf::Vector2f& direction)
{
    sf::Sprite newPiece;
    newPiece.setTexture(*body[0].getTexture());
    newPiece.setPosition(body[0].getPosition() + direction);
    body.push_back(newPiece);
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    for(auto& piece : body){
        target.draw(piece);
    }
}