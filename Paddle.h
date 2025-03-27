//
// Created by 36495 on 10/1/2024.
//

#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>


class Paddle : public sf::RectangleShape
{
private:
    sf::Keyboard::Key upKey;
    sf::Keyboard::Key downKey;
    float speed;
public:
    Paddle();
    void setKeys(const sf::Keyboard::Key& up, const sf::Keyboard::Key& down);
    void setSpeed(float speed);
    void eventHandler(sf::RenderWindow& window, sf::Event& event);
};



#endif //PADDLE_H
