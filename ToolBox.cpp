//
// Created by pala on 9/16/21.
//

#include <valarray>
#include "ToolBox.h"
float ToolBox::calculateDistance(sf::Vector2f &first, sf::Vector2f &second) {
    return sqrt(pow(first.y - second.y, 2) + pow(first.x - second.x, 2));
}
float ToolBox::calculateMx(float dx,float dy) {  //Calcola l'angolo da raggiungere (già tradotto secondo la logica della SFML)
    float mx = 0;mx = 90 + atan2(dy, dx) * 180 / M_PI;
    if (mx < 0) {
        mx = 360 + mx;
    }
    return mx;
}
std::string ToolBox::GetCurrentWorkingDir() {
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}
