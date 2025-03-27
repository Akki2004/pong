//
// Created by 36495 on 10/22/2024.
//

#include "collision.h"

bool collision::hasCollided(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    return obj1.intersects(obj2);
}

