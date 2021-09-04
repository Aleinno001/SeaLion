//
// Created by pala on 9/4/21.
//

#ifndef SEALION_LIFEBAR_H
#define SEALION_LIFEBAR_H


#include <SFML/Graphics/Sprite.hpp>
#include "BarInterface.h"
#include "WarShip.h"


class LifeBar: public BarInterface{
private:
    sf::Sprite life;
    sf::Texture textureLife;
    WarShip &subject_;

    bool setUpSprite(std::string textureName);
public:
    LifeBar(WarShip &subject);

    void update(sf::Vector2f &vel, double mx) override;
};


#endif //SEALION_LIFEBAR_H
