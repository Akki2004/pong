//
// Created by 36495 on 10/1/2024.
//

#include "Paddle.h"

Paddle::Paddle()
{}

void Paddle::setKeys(const sf::Keyboard::Key& up, const sf::Keyboard::Key& down)
{
    Paddle::upKey = up;
    Paddle::downKey = down;
}

void Paddle::setSpeed(float speed)
{
    Paddle::speed = speed;
}

void Paddle::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
    if(sf::Keyboard::isKeyPressed(upKey))
        move({0,-speed});
    if(sf::Keyboard::isKeyPressed(downKey))
        move({0,speed});
}