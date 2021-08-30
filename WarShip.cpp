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



void WarShip::move(sf::Vector2<double> coordinates, double dt) {
    if (collision) {   //FIXME da rivedere il comportamento post impatto
        double mx;
        double dy = coordinates.y - sprite.getPosition().y;
        double dx = coordinates.x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;
        double deltaMx;

        mx = 90 + atan2(dy, dx) * 180 / M_PI;

        if (mx < 0) {
            mx = 360 + mx;
        }

        if (currentSpeed <= maxSpeed * 100) {  //FIXME togli il *10
            currentSpeed = currentSpeed + acceleration / 100 * 100;
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

        if(shipType==ShipType::AircraftCarrier)
            notifyPlanes(vel, deltaMx);

    }
}

const int WarShip::getNumAntiAircraft() const {
    return numAntiAircraft;
}

bool WarShip::canEngage(std::_List_iterator<std::shared_ptr<Arsenal>> iter,
                        std::_List_iterator<std::unique_ptr<WarShip>> target,
                        const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector) {
    bool result = true;
    float m, q, y, x;
    sf::Vector2f coords(x, y);
    if (!target->get()->isConcealed()) {
        for (int i = 0; i < tileVector.size(); i++) {
            for (int j = 0; j < tileVector[i].size(); j++) {
                if (target->get()->getSprite().getPosition().x != iter->get()->getSprite().getPosition().x) {
                    m = (target->get()->getSprite().getPosition().y - iter->get()->getSprite().getPosition().y) /
                        (target->get()->getSprite().getPosition().x - iter->get()->getSprite().getPosition().x);
                    q = iter->get()->getSprite().getPosition().y - m * (iter->get()->getSprite().getPosition().x);
                } else {
                    //TODO caso retta verticale
                }
                x = iter->get()->getSprite().getPosition().x;
                while (static_cast<int>(x) != static_cast<int>(target->get()->getSprite().getPosition().x)) {
                    y = m * x + q;
                    coords.x = x;
                    coords.y = y;
                    if ((tileVector[i][j]->getSprite().getPosition().x < x &&
                         (tileVector[i][j]->getSprite().getPosition().x +
                          tileVector[i][j]->getSprite().getTextureRect().width) > x) &&
                        (tileVector[i][j]->getSprite().getPosition().y < y &&
                         (tileVector[i][j]->getSprite().getPosition().y +
                          tileVector[i][j]->getSprite().getTextureRect().width) > y)) {
                        if (!tileVector[i][j]->isPassable) {
                            return result = false;
                        }
                    }
                    if (x > target->get()->getSprite().getPosition().x) {
                        x--;
                    } else {
                        x++;
                    }
                }
            }
        }
    }
    return result;                //TODO da implementare
}

void WarShip::attack(std::_List_iterator<std::unique_ptr<WarShip>> target) {
    float side;
    double mx;
    double dy;
    double dx;

    for (auto &iter: arsenalList) {
        dy = target->get()->getSprite().getPosition().y - iter.get()->getSprite().getPosition().y;
        dx = target->get()->getSprite().getPosition().x - iter.get()->getSprite().getPosition().x;
        mx = -90 + atan2(dy, dx) * 180 / M_PI;
        //FIXME i cannoni ruotano nel verso sbagliato
        if (mx < 0) {
            mx = 360 + mx;
        }

        float distance = sqrt(
                pow(target->get()->getSprite().getPosition().y - iter.get()->getSprite().getPosition().y, 2) +
                pow(target->get()->getSprite().getPosition().x - iter.get()->getSprite().getPosition().x, 2));
        if (distance <= iter.get()->getRangeOfFire()) {
            std::cerr << "Dovrei ruotare i cannoni" << std::endl;
            /*  //FIXME da sistemare la rotazione dei cannoni
            if(abs(iter->get()->getSprite().getRotation() - mx) >= 1.5) {
                if (((mx - iter->get()->getSprite().getRotation()) <= 180) &&
                    (mx - iter->get()->getSprite().getRotation()) > 0) {
                    std::cerr<<"If n.1"<<std::endl;
                    iter->get()->getSprite().rotate(1);
                } else if (iter->get()->getSprite().getRotation() > 180 && mx < 180) {
                    std::cerr<<"If n.2"<<std::endl;
                    iter->get()->getSprite().rotate(1);
                } else {
                    std::cerr<<"If n.3"<<std::endl;
                    iter->get()->getSprite().rotate(-1);
                }
            }
             */
            iter.get()->getSprite().setRotation(mx);
        }
    }
}

bool WarShip::searchTarget(std::_List_iterator<std::unique_ptr<WarShip>> enemyListStart,
                           std::_List_iterator<std::unique_ptr<WarShip>> enemyListEnd,
                           const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector) {

    bool result = false;
    auto iter = arsenalList.begin();
    int numIter = 0;
    if (numHCannons != 0) {
        numIter = numHCannons;
    } else if (numMCannons != 0) {
        numIter = numMCannons;
    } else if (numLCannons != 0) {
        numIter = numLCannons;
    }
    std::_List_iterator<std::unique_ptr<WarShip>> target;
    float targetDistance = 999999;
    for (int i = 0; i < numIter; i++, ++iter) {
        for (auto enemyIter = enemyListStart; enemyIter != enemyListEnd; ++enemyIter) {
            float distance = sqrt(
                    pow(enemyIter->get()->getSprite().getPosition().y - iter->get()->getSprite().getPosition().y, 2) +
                    pow(enemyIter->get()->getSprite().getPosition().x - iter->get()->getSprite().getPosition().x, 2));
            std::cerr << "Armor: " << armour << std::endl;
            std::cerr << "Coordinata del nemico (y,x): " << enemyIter->get()->getSprite().getPosition().y << ", "
                      << enemyIter->get()->getSprite().getPosition().x << std::endl;
            std::cerr << "Coordinata dei cannoni (y,x): " << iter->get()->getSprite().getPosition().y << ", "
                      << iter->get()->getSprite().getPosition().x << std::endl;
            std::cerr << "Distance: " << distance << std::endl;
            std::cerr << "Range of fire: " << iter->get()->getRangeOfFire() << std::endl;
            /*
            if (targetDistance == -1 && distance <= iter->get()->getRangeOfFire()) {
                targetDistance = distance;
            }
             */
            if (distance <= iter->get()->getRangeOfFire() && distance <= targetDistance) {
                if (canEngage(iter, enemyIter, tileVector)) {
                    target = enemyIter;
                    targetDistance = distance;
                }
            }
        }

    }
    if (targetDistance != 999999) {
        attack(target);
        result = true;
    }
    targetDistance = -1;
    return result;
}

bool WarShip::isConcealed() const {
    return concealed;
}

void WarShip::setConcealed(bool isConcealed) {
    WarShip::concealed = isConcealed;
}
