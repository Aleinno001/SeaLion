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
    WarShip &subject_;
    int r,g,b;
public:
    explicit LifeBar(WarShip &subject);
    void updateBars() override;
    void updateBarsDamage() override;
    void drawEquipment(sf::RenderWindow &window) override;
    ~LifeBar()=default;

    void repositionBar(sf::Vector2f v) override;
};


#endif //SEALION_LIFEBAR_H
