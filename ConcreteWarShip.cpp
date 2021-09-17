//
// Created by alessandro on 17/09/21.
//

#include "ConcreteWarShip.h"
ConcreteWarShip::ConcreteWarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col,
                                 std::string &nat, ShipType shipType, ModelType modelType, const int armour,
                                 const std::string &name, const int numLCannons, const int numMCannons,
                                 const int numHCannons, const int numAntiAircraft, bool concealed, bool selected,
                                 bool air, std::list<std::shared_ptr<Arsenal>> &arsenalList,
                                 std::list<std::shared_ptr<Vehicle>> &vehicleList,
                                 std::list<std::shared_ptr<BarInterface>> &bars) : WarShip(x, y, ac, maxVel, hp, le, wi,
                                                                                           col, nat, shipType,
                                                                                           modelType, armour, name,
                                                                                           numLCannons, numMCannons,
                                                                                           numHCannons, numAntiAircraft,
                                                                                           concealed, selected, air,
                                                                                           arsenalList, vehicleList,
                                                                                           bars) {
    setUpSprite(name);
    sprite.setOrigin(width/2,length/2);
    sprite.setPosition(posX,posY);
}
const void ConcreteWarShip::attack() {
    return;
}
const void ConcreteWarShip::move() {
    return;
}
const void ConcreteWarShip::notifyArsenals() const {
    return;
}
const void ConcreteWarShip::attach(const std::shared_ptr<Arsenal> &gun) {
    return;
}
const void ConcreteWarShip::detach(const std::shared_ptr<Arsenal> &gun) {
    return;
}
const void ConcreteWarShip::notifyPlanes() const {
    return;
}
const void ConcreteWarShip::attachPlanes(const std::shared_ptr<WarPlane> &warPlanes) {
    return;
}
const void ConcreteWarShip::detachPlanes(const std::shared_ptr<WarPlane> &warPlanes) {
    return;
}
const void ConcreteWarShip::notifyBars() const {
    return;
}
const void ConcreteWarShip::notifyBarsDamage() const {
    return;
}
const void ConcreteWarShip::attachBar(const std::shared_ptr<BarInterface> &bar) {
    return;
}
const void ConcreteWarShip::detachBar(const std::shared_ptr<BarInterface> &bar) {
    return;
}
const bool ConcreteWarShip::searchTarget() {
    return 0;
}
const float ConcreteWarShip::rotate() {
    return 0;
}
const bool ConcreteWarShip::canEngage() const {
    return 0;
}