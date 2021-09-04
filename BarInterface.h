//
// Created by pala on 9/4/21.
//

#ifndef SEALION_BARINTERFACE_H
#define SEALION_BARINTERFACE_H


#include <SFML/System/Vector2.hpp>

class BarInterface {
public:
    virtual ~BarInterface()= default;;
    virtual void update(sf::Vector2f &vel, double mx)=0;


};


#endif //SEALION_BARINTERFACE_H
