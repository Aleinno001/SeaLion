//
// Created by alessandro on 04/09/21.
//

#ifndef SEALION_EXPLOSION_H
#define SEALION_EXPLOSION_H


#include <SFML/Graphics.hpp>
#include "CurrentDir.h"

class Explosion {
private:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Explosion(sf::Vector2f pos);

private:
    bool setUpSprite();

    void resetOrigin();

public:

    void setFrame(int numFrame, sf::Vector2f pos);

    const sf::Sprite &getSprite() const;
};


#endif //SEALION_EXPLOSION_H
