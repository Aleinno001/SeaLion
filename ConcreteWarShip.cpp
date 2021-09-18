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
    if (collision && !death) {   //verifica morte e incagliamento
        double mx;
        double dy = targetCoordinates.y - sprite.getPosition().y;
        double dx = targetCoordinates.x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;
        double deltaMx = 0;

        mx = ToolBox::calculateMx(dx, dy);

        if (currentSpeed <= maxSpeed) {
            currentSpeed = currentSpeed + acceleration / 100;
        }
        sf::Vector2f vel;
        if (!(abs(targetCoordinates.x - sprite.getPosition().x) < 2 &&
              abs(targetCoordinates.y - sprite.getPosition().y) < 2)) {  //controlla se la nave ha raggiunto la destinazine
            if (abs(sprite.getRotation() - mx) >=
                25) {  //Se la rotazione da effettuare è elevata allora ruota più velocemente
                rotatingInPlaceMult = 3;
                if (currentSpeed > maxSpeed / 4)
                    currentSpeed = currentSpeed - acceleration / 100;
            }
            if ((abs(targetCoordinates.x - sprite.getPosition().x) < sprite.getTextureRect().height / 2 &&
                 abs(targetCoordinates.y - sprite.getPosition().y) < sprite.getTextureRect().height /
                                                               2)) {   //Se il punto da raggiungere è vicino la nave avanza lentamente
                if (currentSpeed > acceleration / 100) {
                    currentSpeed = currentSpeed - acceleration / 100;
                }
            }
            vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * ToolBox::dt.getElapsedTime().asSeconds() * acceleration / 10;
            vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * ToolBox::dt.getElapsedTime().asSeconds() * acceleration / 10;
            sprite.setPosition(sprite.getPosition() + vel);
            deltaMx = rotate(mx, rotatingInPlaceMult);
        } else {
            currentSpeed = 0;
        }

        notifyArsenals();
        notifyBars();

        if (shipType == ShipType::AircraftCarrier && !air)
            notifyPlanes(vel, deltaMx);
        else
        {
            //TODO Detach Airplanes Observers
        }
    }
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
    if (abs(sprite.getRotation() - mx) >=1.5) {  // Verifica che la rotazione da effettuare sia sufficiebntemente grande (risolve un glitch grafico)
        if (((mx - sprite.getRotation()) <= 180) && (mx - sprite.getRotation()) >0) {  //Analizza le casistiche e di conseguenza ruota incrementando/decrementando l'angolo
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
    bool result = false;
    float y, x;
    if (!target->get()->isConcealed() ||concealed) {  //Non può sparare se il nemico è nascosto, almeno che non lo siano entrambi
        result = true;
        int i, j;
        float mx;
        x = iter->get()->getSprite().getPosition().x;
        y = iter->get()->getSprite().getPosition().y;
        double dy = target->get()->getSprite().getPosition().y - iter->get()->getSprite().getPosition().y;
        double dx = target->get()->getSprite().getPosition().x - iter->get()->getSprite().getPosition().x;
        mx = calculateMx(dx, dy);
        while (abs(target->get()->getSprite().getPosition().x - x) >= 1 ||abs(target->get()->getSprite().getPosition().y - y) >= 1) {x = x + sinf((M_PI / 180.f) * mx) * 2;y = y - cosf((M_PI / 180.f) * mx) * 2;
            i = y / 30;
            j = x / 30;
            if ((tileVector[i][j]->getSprite().getPosition().x < x &&(tileVector[i][j]->getSprite().getPosition().x +tileVector[i][j]->getSprite().getTextureRect().width) > x) &&(tileVector[i][j]->getSprite().getPosition().y < y &&(tileVector[i][j]->getSprite().getPosition().y +tileVector[i][j]->getSprite().getTextureRect().width) > y)) {
                if (!tileVector[i][j]->isPassable) {    //Controlla se nella linea di tiro è presente una casella di terra
                    result = false;
                    return result;
                }
            }
        }
    }
    return result;
}