//
// Created by gabriele on 7/1/21.
//

#include "WarShip.h"


WarShip::WarShip(int x, int y, float ac, const float maxVel, int hp, int arm,
                 std::string nat, int numL, int numH, int numM, int numAA,
                 int le, int wi,
                 bool col, ShipType sh, ModelType mo) : Vehicle(x, y, ac, maxVel, hp,
                                                                le, wi, col, nat),
                                                        armour(arm),
                                                        numLCannons(numL),
                                                        numHCannons(numH), numMCannons(numM), numAntiAircraft(numAA),
                                                        shipType(sh), modelType(mo), concealed(false) {
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

//FIXME da rivedere il comportamento post impatto
void WarShip::move(sf::Vector2f coordinates,
                   double dt) {    //Raggiunge il punto desiderato tramite rotazioni e spostamenti
    if (collision && !death) {   //verifica morte e incagliamento
        double mx;
        double dy = coordinates.y - sprite.getPosition().y;
        double dx = coordinates.x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;
        double deltaMx = 0;

        mx = calculateMx(dx, dy);
        //FIXME togli il *10
        if (currentSpeed <= maxSpeed * 10) {
            currentSpeed = currentSpeed + acceleration / 100 * 10;
        }
        sf::Vector2f vel;
        if (!(abs(coordinates.x - sprite.getPosition().x) < 2 &&
              abs(coordinates.y - sprite.getPosition().y) < 2)) {  //controlla se la nave ha raggiunto la destinazine
            if (abs(sprite.getRotation() - mx) >=
                25) {  //Se la rotazione da effettuare è elevata allora ruota più velocemente
                rotatingInPlaceMult = 3;
                if (currentSpeed > maxSpeed / 4)
                    currentSpeed = currentSpeed - acceleration / 100;
            }
            if ((abs(coordinates.x - sprite.getPosition().x) < sprite.getTextureRect().height / 2 &&
                 abs(coordinates.y - sprite.getPosition().y) < sprite.getTextureRect().height /
                                                               2)) {   //Se il punto da raggiungere è vicino la nave avanza lentamente
                if (currentSpeed > acceleration / 100) {
                    currentSpeed = currentSpeed - acceleration / 100;
                }
            }
            vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
            vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * dt * acceleration / 10;
            sprite.setPosition(sprite.getPosition() + vel);
            deltaMx = rotate(mx, rotatingInPlaceMult);
        } else {
            currentSpeed = 0;
        }

        notifyArsenals(vel, deltaMx);
        notifyBars(vel,deltaMx);

        if (shipType == ShipType::AircraftCarrier && !air)
            notifyPlanes(vel, deltaMx);
        else
        {
            //TODO Detach Airplanes Observers
        }
    }
}

const int WarShip::getNumAntiAircraft() const {
    return numAntiAircraft;
}

bool WarShip::canEngage(std::_List_iterator<std::shared_ptr<Arsenal>> iter,
                        std::_List_iterator<std::unique_ptr<WarShip>> target,
                        const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector) {  //Verifica la possibilità di sparare alle navi nemiche
    bool result = false;
    float y, x;
    if (!target->get()->isConcealed() ||
        concealed) {  //Non può sparare se il nemico è nascosto, almeno che non lo siano entrambi
        result = true;
        int i, j;
        float mx;
        x = iter->get()->getSprite().getPosition().x;
        y = iter->get()->getSprite().getPosition().y;
        double dy = target->get()->getSprite().getPosition().y - iter->get()->getSprite().getPosition().y;
        double dx = target->get()->getSprite().getPosition().x - iter->get()->getSprite().getPosition().x;
        mx = calculateMx(dx, dy);
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
                    if (!tileVector[i][j]->isPassable) {    //Controlla se nella linea di tiro è presente una casella di terra
                        result = false;
                        return result;
                    }
                }
            }
        }
    return result;
}

void WarShip::attack(std::_List_iterator<std::unique_ptr<WarShip>> target,
                     std::_List_iterator<std::shared_ptr<Arsenal>> iter,
                     float dt) {   //Si occupa di ruotare a sparare alle navi target
    double mx;
    double dy;
    double dx;
    dy = target->get()->getSprite().getPosition().y - iter->get()->getSprite().getPosition().y;
    dx = target->get()->getSprite().getPosition().x - iter->get()->getSprite().getPosition().x;
    mx = -180 + calculateMx(dx, dy);
    iter->get()->getSprite().setRotation(mx);

    if (abs(iter->get()->getCountdown() - dt) <=
        dt) {  //Verifica che il cannone abbia ricaricato e quindi imposta lo stato di sparo
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
         1 ||
         abs(iter->get()->getAmmoType()->getSprite().getPosition().y -
             iter->get()->getAmmoType()->getTargetPoint().y) >
         1)) { //Controlla se il proiettile ha raggiunto le coordinate prefissate
        iter->get()->getAmmoType()->reachTarget();
    } else {
        iter->get()->getAmmoType()->hit();
    }

}

bool WarShip::searchTarget(std::_List_iterator<std::unique_ptr<WarShip>> enemyListStart,
                           std::_List_iterator<std::unique_ptr<WarShip>> enemyListEnd,
                           const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector,
                           float dt) {   //Cerca un bersaglio nel raggio d'azione se possibile
    bool result = false;
    if (!death) {
        float distance = 0;
        result = false;
        auto iter = arsenalList.begin();
        int numIter = numLCannons + numMCannons + numHCannons;

        std::_List_iterator<std::unique_ptr<WarShip>> target;
        float targetDistance = 999999;
        for (int i = 0; i < numIter; i++, ++iter) {  //per tutti i cannoni
            for (auto enemyIter = enemyListStart; enemyIter != enemyListEnd; ++enemyIter) {
                if (!enemyIter->get()->death ||
                    !iter->get()->getAmmoType()->isArrived()) {  //Permette al proiettile di raggiungere il bersaglio anche se la nave bersaglio muore
                    distance = calculateDistance(
                            const_cast<sf::Vector2f &>(enemyIter->get()->getSprite().getPosition()),
                            const_cast<sf::Vector2f &>(iter->get()->getSprite().getPosition()));
                    if ((distance <= iter->get()->getRangeOfFire() &&
                         distance <= targetDistance)) {  //Salva il bersaglio più vicino che è possibile attaccare
                        if (canEngage(iter, enemyIter, tileVector)) {
                            target = enemyIter;
                            targetDistance = distance;
                        }
                    }
                }
            }
            if (targetDistance != 999999) {
                if (!target->get()->death) {
                    attack(target, iter, dt);
                    result = true;
                } else {  //Il proiettile può raggiungere il bersaglio anche se chi lo spara muore
                    iter->get()->getAmmoType()->reachTarget();
                }
            } else if (!iter->get()->getAmmoType()->isArrived()) {  //Se il proiettile non ha raggiunto il bersaglio continua a viaggiare
                iter->get()->getAmmoType()->reachTarget();
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

std::list<std::shared_ptr<BarInterface>> &WarShip::getBars(){
    return bars;
}

void WarShip::setSelected(bool selected) {
    WarShip::selected = selected;
}

bool WarShip::isSelected() const {
    return selected;
}

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



bool WarShip::isAir() const {
    return air;
}

void WarShip::setAir(bool air) {
    WarShip::air = air;
}

float WarShip::rotate(float mx, float rotatingInPlaceMult) {
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

