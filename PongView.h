//
// Created by 36495 on 11/12/2024.
//

#ifndef PONGVIEW_H
#define PONGVIEW_H



#include "Counter.h"
#include <SFML/Graphics.hpp>

class PongView : public sf::Drawable
{
    Counter &model;
    sf::Text text;
    sf::Font font;

public:
    PongView(Counter& model);
    void setCounterPos(float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};



#endif //PONGVIEW_H
