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
                 int le, int wi,
                 bool col, ShipType sh, ModelType mo) : Vehicle(x, y, ac, maxVel, hp,
                                                                le, wi, col, nat),
                                                        armour(arm),
                                                        numLCannons(numL),
                                                        numHCannons(numH), numMCannons(numM), numAntiAircraft(numAA),
                                                        shipType(sh), modelType(mo), concealed(false) {
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


void WarShip::move(sf::Vector2<double> coordinates, double dt) {
    if (collision && !death) {   //FIXME da rivedere il comportamento post impatto
        double mx;
        double dy = coordinates.y - sprite.getPosition().y;
        double dx = coordinates.x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;
        double deltaMx = 0;

        mx = 90 + atan2(dy, dx) * 180 / M_PI;

        if (mx < 0) {
            mx = 360 + mx;
        }

        if (currentSpeed <= maxSpeed * 10) {  //FIXME togli il *10
            currentSpeed = currentSpeed + acceleration / 100 * 10;
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
                    deltaMx = -currentSpeed * acceleration * rotatingInPlaceMult / 4000;
                    sprite.rotate(deltaMx);
                }
            }
        } else {
            currentSpeed = 0;
        }

        notifyArsenals(vel, deltaMx);

        if (shipType == ShipType::AircraftCarrier)
            notifyPlanes(vel, deltaMx);

    }
}

const int WarShip::getNumAntiAircraft() const {
    return numAntiAircraft;
}

bool WarShip::canEngage(std::_List_iterator<std::shared_ptr<Arsenal>> iter,
                        std::_List_iterator<std::unique_ptr<WarShip>> target,
                        const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector) {
        bool result = false;
        float y, x;
    if (!target->get()->isConcealed() || concealed) {
        result = true;
        int i, j;
        float mx;
        x = iter->get()->getSprite().getPosition().x;
        y = iter->get()->getSprite().getPosition().y;
        double dy = target->get()->getSprite().getPosition().y - iter->get()->getSprite().getPosition().y;
        double dx = target->get()->getSprite().getPosition().x - iter->get()->getSprite().getPosition().x;
        mx = 90 + atan2(dy, dx) * 180 / M_PI;

        if (mx < 0) {
                mx = 360 + mx;
            }
            while (abs(target->get()->getSprite().getPosition().x - x) >= 1 ||
                   abs(target->get()->getSprite().getPosition().y - y) >= 1) {
                x = x + sinf((M_PI / 180.f) * mx) * 2;
                y = y - cosf((M_PI / 180.f) * mx) * 2;
                i = y / 30;
                j = x / 30;
                if ((tileVector[i][j]->getSprite().getPosition().x < x &&
                     (tileVector[i][j]->getSprite().getPosition().x +
                      tileVector[i][j]->getSprite().getTextureRect().width) > x) &&
                    (tileVector[i][j]->getSprite().getPosition().y < y &&
                     (tileVector[i][j]->getSprite().getPosition().y +
                      tileVector[i][j]->getSprite().getTextureRect().width) > y)) {
                    if (!tileVector[i][j]->isPassable) {
                        result = false;
                        return result;
                    }
                }
            }
        }
    return result;
}

void WarShip::attack(std::_List_iterator<std::unique_ptr<WarShip>> target,
                     std::_List_iterator<std::shared_ptr<Arsenal>> iter, float dt) {
    double mx;
    double dy;
    double dx;
    dy = target->get()->getSprite().getPosition().y - iter->get()->getSprite().getPosition().y;
    dx = target->get()->getSprite().getPosition().x - iter->get()->getSprite().getPosition().x;
    mx = -90 + atan2(dy, dx) * 180 / M_PI;

    if (mx < 0) {
        mx = 360 + mx;
    }
    iter->get()->getSprite().setRotation(mx);

        if (abs(iter->get()->getCountdown() - dt) <= dt) {
            sf::Vector2f targetPosition;
            targetPosition = target->get()->getSprite().getPosition();
            Dice dice(11, targetPosition.x);
            float dx = targetPosition.x - iter->get()->getSprite().getPosition().x;
            float dy = targetPosition.y - iter->get()->getSprite().getPosition().y;
            float distance = sqrt(pow(dx, 2) + pow(dy, 2));
            targetPosition.x +=
                    (pow(-1, dice.roll(1))) * (iter->get()->getMaximumDispersion() * (dice.roll(1) - 1) / 10) *
                    distance /
                    iter->get()->getRangeOfFire();
            targetPosition.y +=
                    (pow(-1, dice.roll(1))) * (iter->get()->getMaximumDispersion() * (dice.roll(1) - 1) / 10) *
                    distance /
                    iter->get()->getRangeOfFire();
            iter->get()->setCountdown(iter->get()->getReloadTime());
            iter->get()->getAmmoType()->initializeBullet(iter->get()->getSprite().getPosition(),
                                                         targetPosition);
        } else {
            iter->get()->setCountdown(iter->get()->getCountdown() - dt);
        }
        if ((abs(iter->get()->getAmmoType()->getSprite().getPosition().x -
                 iter->get()->getAmmoType()->getTargetPoint().x) >
             5 ||
             abs(iter->get()->getAmmoType()->getSprite().getPosition().y -
                 iter->get()->getAmmoType()->getTargetPoint().y) >
             5)) {
            iter->get()->getAmmoType()->reachTarget();
        } else {
            iter->get()->getAmmoType()->hit();
        }

}

bool WarShip::searchTarget(std::_List_iterator<std::unique_ptr<WarShip>> enemyListStart,
                           std::_List_iterator<std::unique_ptr<WarShip>> enemyListEnd,
                           const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector, float dt) {
    bool result = false;
    if(!death) {
        float distance = 0;
        result = false;
        auto iter = arsenalList.begin();
        int numIter = numLCannons + numMCannons + numHCannons;

        std::_List_iterator<std::unique_ptr<WarShip>> target;
        float targetDistance = 999999;
        for (int i = 0; i < numIter; i++, ++iter) {
            for (auto enemyIter = enemyListStart; enemyIter != enemyListEnd; ++enemyIter) {

                    distance = sqrt(
                            pow(enemyIter->get()->getSprite().getPosition().y -
                                iter->get()->getSprite().getPosition().y,
                                2) +
                            pow(enemyIter->get()->getSprite().getPosition().x -
                                iter->get()->getSprite().getPosition().x,
                                2));
                    if (distance <= iter->get()->getRangeOfFire() && distance <= targetDistance) {
                        if (canEngage(iter, enemyIter, tileVector)) {
                            target = enemyIter;
                            targetDistance = distance;
                        }
                    }
            }
            if (targetDistance != 999999) {
                if(!target->get()->death) {
                    attack(target, iter, dt);
                    result = true;
                }else{
                    iter->get()->getAmmoType()->reachTarget();
                }
            }
            targetDistance = 999999;
        }
    }


    return result;
}

bool WarShip::isConcealed() const {
    return concealed;
}

void WarShip::setConcealed(bool isConcealed) {
    WarShip::concealed = isConcealed;
}

const std::list<std::shared_ptr<Vehicle>> &WarShip::getVehicleList() const {
    return vehicleList;
}

