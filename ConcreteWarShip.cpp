//
// Created by alessandro on 17/09/21.
//

#include "ConcreteWarShip.h"
ConcreteWarShip::ConcreteWarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col,std::string &nat, ShipType shipType, ModelType modelType, const int armour,const std::string &name, const int numLCannons, const int numMCannons,const int numHCannons, const int numAntiAircraft, bool concealed, bool selected,bool air, std::list<std::shared_ptr<Arsenal>> &arsenalList,std::list<std::shared_ptr<WarPlane>> &plaList,std::list<std::shared_ptr<BarInterface>> &bars) : WarShip(x, y, ac, maxVel, hp, le, wi,col, nat, shipType,modelType, armour, name,numLCannons, numMCannons,numHCannons, numAntiAircraft,concealed, selected, air,arsenalList, plaList,bars) {
    setUpSprite(name);
    sprite.setOrigin(width/2,length/2);
    sprite.setPosition(posX,posY);
}
void ConcreteWarShip::attack() {
    return;
}
void ConcreteWarShip::move() {
    return;
}
void ConcreteWarShip::notifyArsenals() const {
    return;
}
void ConcreteWarShip::attach(const std::shared_ptr<Arsenal> &gun) {
    return;
}
void ConcreteWarShip::detach(const std::shared_ptr<Arsenal> &gun) {
    return;
}
void ConcreteWarShip::notifyPlanes() const {
    return;
}
void ConcreteWarShip::attachPlanes(const std::shared_ptr<WarPlane> &warPlanes) {
    planeList.push_back(warPlanes);
}
void ConcreteWarShip::detachPlanes(const std::shared_ptr<WarPlane> &warPlanes) {
    planeList.remove(warPlanes);
}
void ConcreteWarShip::notifyBars() const {
    return;
}
void ConcreteWarShip::notifyBarsDamage() const {
    return;
}
void ConcreteWarShip::attachBar(const std::shared_ptr<BarInterface> &bar) {
    return;
}
void ConcreteWarShip::detachBar(const std::shared_ptr<BarInterface> &bar) {
    return;
}
bool ConcreteWarShip::searchTarget() {
    return 0;
}
float ConcreteWarShip::rotate(float mx, float rotatingInPlaceMult) {
    float deltaMx = 0;
    if (abs(sprite.getRotation() - mx) >=
        1.5) {  // Verifica che la rotazione da effettuare sia sufficiebntemente grande (risolve un glitch grafico)
        if (((mx - sprite.getRotation()) <= 180) && (mx - sprite.getRotation()) >
                                                    0) {  //Analizza le casistiche e di conseguenza ruota incrementando/decrementando l'angolo
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 4000;
            sprite.rotate(deltaMx);
        } else if (sprite.getRotation() > 180 && mx < 180) {
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 4000;
            sprite.rotate(deltaMx);
        } else {
            deltaMx = -currentSpeed * acceleration * rotatingInPlaceMult / 4000;
            sprite.rotate(deltaMx);
        }
    }
    return deltaMx;
}
bool ConcreteWarShip::canEngage() const {
    return 0;
}