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
    Explosion();

private:
    bool setUpSprite();

    void resetOrigin();

public:

    void setFrame(int numFrame, sf::Vector2f pos);
};


#endif //SEALION_EXPLOSION_H
