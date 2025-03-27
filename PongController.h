//
// Created by 36495 on 11/12/2024.
//

#ifndef PONGCONTROLLER_H
#define PONGCONTROLLER_H

#include "Counter.h"
#include <SFML/Graphics.hpp>
#include "Ball.h"

class PongController {
enum Type {RIGHT, LEFT};
private:
    Counter &model;
    Ball &ball;
    Type type;
public:
    PongController(Counter &model, Ball &ball);
    void setType(std::string type);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void updateScore();
};



#endif //PONGCONTROLLER_H
