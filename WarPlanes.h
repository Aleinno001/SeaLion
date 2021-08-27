//
// Created by pala on 8/27/21.
//

#ifndef SEALION_WARPLANES_H
#define SEALION_WARPLANES_H


#include <SFML/System/Vector2.hpp>

class WarPlanes {
public:
    virtual ~WarPlanes()=default;
    virtual void updatePlanes(sf::Vector2f &vel,double mx)=0;
};


#endif //SEALION_WARPLANES_H
