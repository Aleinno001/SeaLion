//
// Created by alessandro on 21/09/21.
//

#ifndef SEALION_TOOLS_H
#define SEALION_TOOLS_H

#include "SFML/Graphics.hpp"

class Tools {
public:
    static sf::Clock dt;
public:
    static float getElapsedTime();
    static void reset();
};

#endif //SEALION_TOOLS_H
