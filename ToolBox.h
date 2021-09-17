//
// Created by pala on 9/16/21.
//
#ifndef SEALION_TOOLBOX_H
#define SEALION_TOOLBOX_H
#include <SFML/System/Vector2.hpp>
#include <string>
#include <stdio.h>
#include <unistd.h>

#define GetCurrentDir getcwd

namespace ToolBox {
   float calculateDistance(sf::Vector2f &first, sf::Vector2f &second);
   float calculateMx(float dx, float dy);
   std::string GetCurrentWorkingDir();  //Speciale metodo per ottenere la working directory attuale
};


#endif //SEALION_TOOLBOX_H
