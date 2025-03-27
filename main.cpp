#include <iostream>
#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "Ball.h"

#include "Counter.h"
#include "PongController.h"
#include "PongView.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(720, 420, 32), "Test");
    window.setFramerateLimit(60);

    Counter model1;
    Counter model2;
    PongView view1(model1);
    PongView view2(model2);
    view1.setCounterPos((window.getSize().x / 2) - 30, window.getSize().y - 70.f);
    view2.setCounterPos((window.getSize().x / 2) + 30, window.getSize().y - 70.f);

    Ball ball(25.f, sf::Vector2f{5.0f, 5.0f}, window.getSize());

    PongController controller1(model1, ball);
    PongController controller2(model2, ball);

    controller1.setType("right");
    controller2.setType("left");

    Paddle leftPaddle, rightPaddle;
    leftPaddle.setSize({25,100});
    leftPaddle.setSpeed(10.0);
    leftPaddle.setKeys(sf::Keyboard::W, sf::Keyboard::S);

    rightPaddle.setSize({25,100});
    rightPaddle.setPosition({window.getSize().x - rightPaddle.getSize().x,0});
    rightPaddle.setSpeed(10.0);
    rightPaddle.setKeys(sf::Keyboard::Up, sf::Keyboard::Down);


    while(window.isOpen())
    {
    // event listener, constant polling for each input
        sf::Event event;
        while(window.pollEvent(event)){
            // check event type
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        leftPaddle.eventHandler(window, event);
        rightPaddle.eventHandler(window, event);

        controller1.updateScore();
        controller2.updateScore();
        view1.update();
        view2.update();

        window.clear();
        ball.bounce();
        ball.bounce(rightPaddle.getGlobalBounds(), leftPaddle.getGlobalBounds());
        window.clear(sf::Color::Black);
        ball.draw(window, sf::RenderStates::Default);
        window.draw(leftPaddle);
        window.draw(rightPaddle);

        window.draw(view1);
        window.draw(view2);

        window.display();
    }
    return 0;
}
