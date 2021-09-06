//
// Created by pala on 9/4/21.
//

#ifndef SEALION_BARINTERFACE_H
#define SEALION_BARINTERFACE_H


#include <SFML/Graphics.hpp>

class BarInterface {
public:
    virtual ~BarInterface()= default;;
    virtual void updateBars(sf::Vector2f &vel, double mx)=0;
    virtual void updateBarsDamage()=0;


};


#endif //SEALION_BARINTERFACE_H
