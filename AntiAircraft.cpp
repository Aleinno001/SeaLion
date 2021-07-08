//
// Created by alessandro on 02/07/21.
//

#include "AntiAircraft.h"

AntiAircraft::AntiAircraft(const float range1, const int reload1, const int rate1, int speed1, int dispersion1,
                           std::string type1, float decelleration1, int power1, int num1, int x1, int y1,
                           sf::Texture tex, sf::Sprite sp, int le, int wi, bool col, std::string texName,
                           const float range, const int reload, const int rate, int speed, int dispersion,
                           std::string type, float decelleration, int power, int num, double x, double y)
        : Arsenal(range1, reload1, rate1, speed1, dispersion1, type1, decelleration1, power1, num1, x1, y1, tex, sp, le,
                  wi, col, texName) {

}

AntiAircraft::~AntiAircraft() {

}

bool AntiAircraft::airStrafe() {
    return false;
}

void AntiAircraft::openFire(Vehicle enemy) {
    Arsenal::openFire(enemy);
}

void AntiAircraft::update(int posX, int posY) {
    Arsenal::update(posX, posY);
}

void AntiAircraft::attach() {
    Arsenal::attach();
}

void AntiAircraft::detach() {
    Arsenal::detach();
}

bool AntiAircraft::engage(Vehicle enemy) {
    return Arsenal::engage(enemy);
}

void AntiAircraft::rotate() {
    Arsenal::rotate();
}
