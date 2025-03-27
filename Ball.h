//
// Created by 36495 on 9/30/2024.
//

#ifndef BALL_H
#define BALL_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Ball:public sf::Drawable
{
private:
    int p1score = 0, p2score = 0;
    sf::CircleShape circle;
    sf::Vector2f velocity;
    sf::Vector2u windowSize;
public:
    Ball(float radius, sf::Vector2f velocity, sf::Vector2u windowSize);
    Ball();

    void bounce();
    void bounce(const sf::FloatRect &obj1, const sf::FloatRect &obj2);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void stop();
    int getScoreR();
    int getScoreL();
};



#endif //BALL_H
