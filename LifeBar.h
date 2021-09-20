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
    void removeMe(){
        subject_.detachBar(std::shared_ptr<BarInterface>(this));
    }
};


#endif //SEALION_LIFEBAR_H
