//
// Created by gabriele on 7/1/21.
//

#include "WarShip.h"

const int WarShip::getArmour() const {
    return armour;
}

const std::string &WarShip::getName() const {
    return name;
}

const std::string &WarShip::getNationality() const {
    return nationality;
}

const int WarShip::getNumLCannons() const {
    return numLCannons;
}

const int WarShip::getNumMCannons() const {
    return numMCannons;
}

const int WarShip::getNumHCannons() const {
    return numHCannons;
}
WarShip::WarShip(int x, int y, float ac, const float maxVel, int hp, int arm,
                 std::string nat, int numL, int numH, int numM, int numAA,
                 std::list<std::unique_ptr<Vehicle>> &vehicle, int le, int wi,
                 bool col, ShipType sh, ModelType mo) : Vehicle(x, y, ac, maxVel, hp,
                                                                le, wi, col, nat),
                                                        armour(arm),
                                                        numLCannons(numL),
                                                        numHCannons(numH), numMCannons(numM), numAntiAircraft(numAA),
                                                        shipType(sh), modelType(mo) {
    /*for (auto const& itArsenal : arsenal) {
         arsenalList=itArsenal;
     }*/


}

ShipType WarShip::getShipType() const {
    return shipType;
}

ModelType WarShip::getModelType() const {
    return modelType;
}

std::list<std::shared_ptr<Arsenal>> &WarShip::getArsenalList() {
    return arsenalList;
}

std::list<std::unique_ptr<Vehicle>> &WarShip::getVehicleList() {
    return vehicleList;
}

void WarShip::move(sf::Vector2<double> coordinates) {

double mx;
double dy = coordinates.y - sprite.getPosition().y;
double dx = coordinates.x - sprite.getPosition().x;
sf::Vector2f newPos;
float deltaTime;
mx = 90 + atan2(dy,dx)*180/M_PI;
/*deltaTime = sqrt((2*(sqrt(dx^2 + dy^2)))/acceleration);

currentSpeed += acceleration/60;

newPos.x = sprite.getPosition().x + cosf(sprite.getRotation()*M_PI/180) * deltaTime * currentSpeed;
newPos.y = sprite.getPosition().y + sinf(sprite.getRotation()*M_PI/180) * deltaTime * currentSpeed;

std::cerr << deltaTime << std::endl;
sprite.setPosition(newPos);
*/



if(mx<0){
    mx=360+mx;
}

if(sprite.getRotation() != mx){
    if(mx - sprite.getRotation() <= 180 && (mx - sprite.getRotation()) > 0){
    sprite.rotate(0.1);


}else{
    sprite.rotate(-0.1);
}

}
    if(sprite.getPosition().x < coordinates.x + 1 && sprite.getPosition().x > coordinates.x - 1 &&  sprite.getPosition().y < coordinates.y + 1 && sprite.getPosition().y > coordinates.y - 1){
        sprite.setPosition(coordinates.x, coordinates.y);
    }else{
        sprite.move(cosf64x(sprite.getRotation()*180/M_PI)*(-0.3), sinf64x(sprite.getRotation()*180/M_PI)*0.3);
    }



}

const int WarShip::getNumAntiAircraft() const {
    return numAntiAircraft;
}
