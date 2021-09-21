//
// Created by pala on 9/4/21.
//

#ifndef SEALION_BARINTERFACE_H
#define SEALION_BARINTERFACE_H


#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "ToolBox.h"

class BarInterface {
private:
    bool setUpSprite(std::string textureName);
protected:
    sf::Sprite life;
    sf::Texture textureLife;
public:
    BarInterface();
    virtual ~BarInterface()= default;
    virtual void updateBars()=0;
    virtual void updateBarsDamage() = 0;
    void resetOrigin();
    sf::Sprite getSprite() const;
    virtual void drawEquipment(sf::RenderWindow &window)=0;
};


#endif //SEALION_BARINTERFACE_H
