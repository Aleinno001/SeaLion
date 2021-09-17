//
// Created by pala on 8/23/21.
//


#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>

namespace Collision {
    bool PixelPerfectTest(const sf::Sprite& Object1 ,const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
    bool CreateTextureAndBitmask(sf::Texture &LoadInto, const std::string& Filename);
    bool CircleTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
    bool BoundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
}

#endif	/* COLLISION_H */
