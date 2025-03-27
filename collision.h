//
// Created by 36495 on 10/22/2024.
//

#ifndef COLLISION_H
#define COLLISION_H

#include <SFML\Graphics.hpp>

class collision
{
public:
    static bool hasCollided(const sf::FloatRect &obj1, const sf::FloatRect &obj2);
};



#endif //COLLISION_H
