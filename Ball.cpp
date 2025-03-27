//
// Created by 36495 on 9/30/2024.
//

#include "Ball.h"
#include "collision.h"

Ball::Ball(float radius, sf::Vector2f velocity, sf::Vector2u windowSize)
: velocity(velocity), windowSize(windowSize)
{
    circle.setRadius(radius);
    circle.setFillColor(sf::Color(50,120,200));
    circle.setPosition(250, 250);
}
Ball::Ball()
{
    circle.setRadius(25.f);
    circle.setFillColor(sf::Color(50,120,200));
    circle.setPosition(250, 250);
}
void Ball::bounce() {
    if(circle.getPosition().x >= windowSize.x - (2 * circle.getRadius()) || circle.getPosition().x <= 0)
    {//x <= 0,
        velocity.x = -velocity.x;
        if(circle.getPosition().x <= 0)
        {
            circle.setPosition(250, 250);
            p1score++;
        }
        else if(circle.getPosition().x >= windowSize.x - (2 * circle.getRadius()))
        {
            circle.setPosition(250, 250);
            p2score++;
        }
    }
    else if(circle.getPosition().y >= windowSize.y - (2 * circle.getRadius()) || circle.getPosition().y <= 0)
    {
        velocity.y = -velocity.y;
    }
    circle.move(velocity);
}

void Ball::bounce(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    sf::Vector2f position = circle.getPosition();
    if(collision::hasCollided(obj1, circle.getGlobalBounds()) || collision::hasCollided(obj2, circle.getGlobalBounds()))
    {
        velocity.x = -velocity.x;
    }
}

void Ball::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(circle);
}

void Ball::stop()
{ velocity = sf::Vector2f(0,0); }

int Ball::getScoreR()
{ return p1score; }

int Ball::getScoreL()
{ return p2score; }