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

void WarShip::move(sf::Vector2<double> coordinates, double dt) {

    double mx;
    double dy = coordinates.y - sprite.getPosition().y;
    double dx = coordinates.x - sprite.getPosition().x;
    float rotatingInPlaceMult = 1;
    double deltaMx;

    mx = 90 + atan2(dy, dx) * 180 / M_PI;

    if (mx < 0) {
        mx = 360 + mx;
    }

    if (currentSpeed <= maxSpeed) {
        currentSpeed = currentSpeed + acceleration / 100;
    }
    sf::Vector2f vel;
    if (!(abs(coordinates.x - sprite.getPosition().x) < 1 && abs(coordinates.y - sprite.getPosition().y) < 1)) {
        if (abs(sprite.getRotation() - mx) >= 25) {
            rotatingInPlaceMult = 3;
            if (currentSpeed > maxSpeed / 4)
                currentSpeed = currentSpeed - acceleration / 100;
        }
        if ((abs(coordinates.x - sprite.getPosition().x) < sprite.getTextureRect().height / 2 &&
             abs(coordinates.y - sprite.getPosition().y) < sprite.getTextureRect().height / 2)) {
            if (currentSpeed > acceleration / 100) {
                currentSpeed = currentSpeed - acceleration / 100;
            }
        }
        vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
        vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
        sprite.setPosition(sprite.getPosition() + vel);
        if (abs(sprite.getRotation() - mx) >= 1.5) {
            if (((mx - sprite.getRotation()) <= 180) && (mx - sprite.getRotation()) > 0) {
                deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 4000;
                sprite.rotate(deltaMx);
            } else if (sprite.getRotation() > 180 && mx < 180) {
                deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 4000;
                sprite.rotate(deltaMx);
            } else {
                deltaMx = - currentSpeed * acceleration * rotatingInPlaceMult / 4000;
                sprite.rotate(deltaMx);
            }
        }
    } else {
        currentSpeed = 0;
    }

    notifyArsenals(vel, deltaMx);
}

const int WarShip::getNumAntiAircraft() const {
    return numAntiAircraft;
}

bool WarShip::canEngage(std::_List_iterator<std::unique_ptr<WarShip>> target) {
    return false;
}

std::_List_iterator<std::unique_ptr<WarShip>> WarShip::searchTarget(std::_List_iterator<std::unique_ptr<WarShip>> enemyListStart, std::_List_iterator<std::unique_ptr<WarShip>> enemyListEnd) {
    if(numHCannons != 0){
        auto iter = arsenalList.begin();
        for(int i = 0; i < numHCannons; i++, ++iter){
            float side;
            side = sqrt(2 * pow(iter -> get()->getRangeOfFire(), 2));
            sf::IntRect rect (iter -> get()->getSprite().getPosition().x - side/2, iter -> get()->getSprite().getPosition().y - side/2, side, side);
            for(int j = 1; j <= 360; j++){
                for(auto enemyIter = enemyListStart; enemyIter != enemyListEnd; ++enemyIter){
                    if (rect.intersects(enemyIter->get()->getSprite().getTextureRect())) {
                        if (canEngage(enemyIter)) {}
                    }//TODO completare
                }

            }
        }
    }

}
