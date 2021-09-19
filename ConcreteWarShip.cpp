//
// Created by alessandro on 17/09/21.
//

#include "ConcreteWarShip.h"
ConcreteWarShip::ConcreteWarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col,std::string &nat, ShipType shipType, ModelType modelType, const int armour,const std::string &name, const int numLCannons, const int numMCannons,const int numHCannons, const int numAntiAircraft) : WarShip(x, y, ac, maxVel, hp, le, wi,col, nat, shipType,modelType, armour, name,numLCannons, numMCannons,numHCannons, numAntiAircraft) {
    setUpSprite(name);
    sprite.setOrigin(width/2,length/2);
    sprite.setPosition(posX,posY);
}
void ConcreteWarShip::attack() {
    for(auto &iterArsenal : arsenalList){
        iterArsenal->searchTarget();
    }
}
void ConcreteWarShip::move() {
    if (collision && !death) {   //verifica morte e incagliamento
        double mx;
        double dy = targetCoordinates.y - sprite.getPosition().y;
        double dx = targetCoordinates.x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;

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
            rotate(mx, rotatingInPlaceMult);
        } else {
            currentSpeed = 0;
        }

        notifyArsenals();
        notifyBars();

        if (shipType == ShipType::AircraftCarrier)   //FIXME controllare che gli aerei non stiano volando
            notifyPlanes();
        else
        {
            //TODO Detach Airplanes Observers
        }
    }
}
void ConcreteWarShip::notifyArsenals() const {
    for(auto &iterArsenal : arsenalList){
        iterArsenal->update();
    }
}
void ConcreteWarShip::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}
void ConcreteWarShip::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);
}
void ConcreteWarShip::notifyBars() const {
    for(auto &iterBars : bars){
        iterBars->updateBars();
    }
}
void ConcreteWarShip::notifyBarsDamage() const {
    for(auto &iterBars : bars){
        iterBars->updateBarsDamage();
    }
}
void ConcreteWarShip::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void ConcreteWarShip::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);
}
bool ConcreteWarShip::searchTarget() {
    move();
    if(canEngage())
        attack();
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
bool ConcreteWarShip::canEngage() {    //Controlla se nessun cannone può ingaggiare
    bool result = true;
    if(death || concealed){
        result= false;
    }
    return result;
}