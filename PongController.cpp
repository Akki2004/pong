//
// Created by 36495 on 11/12/2024.
//

#include "PongController.h"

#include <iostream>
#include "Ball.h"

PongController::PongController(Counter &model, Ball &ball)
    : model(model), ball(ball)
{}


void PongController::eventHandler(sf::RenderWindow& window, sf::Event event)
{

}

void PongController::setType(std::string Ctype)
{
    if(Ctype == "left")
        type = LEFT;

    if(Ctype == "right")
        type = RIGHT;
}

void PongController::updateScore()
{
    if(type == RIGHT)
        model.assign(std::to_string(ball.getScoreR()));
    if(type == LEFT)
        model.assign(std::to_string(ball.getScoreL()));

    if(ball.getScoreR() == 10 && type == RIGHT)
    {
        model.assign("P1 WINS");
        ball.stop();
    }

    if(ball.getScoreL() == 10 && type == LEFT)
    {
        model.assign("P2 WINS");
        ball.stop();
    }

    if(ball.getScoreR() == 10 && type == LEFT)
        model.assign("");

    if(ball.getScoreL() == 10 && type == RIGHT)
        model.assign("");
}