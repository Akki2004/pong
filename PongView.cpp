//
// Created by 36495 on 11/12/2024.
//

#include "PongView.h"

PongView::PongView(Counter& model)
    : model(model)
{
    if(font.loadFromFile("OpenSans-Bold.ttf"))
    {
        text.setFont(font);
        text.setCharacterSize(60);
    }
}

void PongView::setCounterPos(float xpos, float ypos)
{
    text.setPosition(xpos, ypos);
}

void PongView::update()
{
    text.setString(model);
}

void PongView::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(text);
}

