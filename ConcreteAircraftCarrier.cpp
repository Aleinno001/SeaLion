//
// Created by alessandro on 19/09/21.
//

#include "ConcreteAircraftCarrier.h"
ConcreteAircraftCarrier::ConcreteAircraftCarrier(float x, float y, float ac, float maxVel, int hp, int le, int wi,bool col, std::string &nat, ShipType shipType, ModelType modelType,int armour, const std::string &name, int numLCannons, int numMCannons,int numHCannons, int numAntiAircraft, int numPlanes) : AircraftCarrier(x, y, ac, maxVel, hp, le, wi, col, nat, shipType, modelType, armour, name, numLCannons, numMCannons,numHCannons, numAntiAircraft, numPlanes) {}
void ConcreteAircraftCarrier::notifyMvcObserver() {
    for (auto &it: listMvcObservers)
        it->updateMvcObserver();
}
void ConcreteAircraftCarrier::addMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.push_back(o);
}
void ConcreteAircraftCarrier::removeMvcObserver(std::shared_ptr<MvcObserver> o) {
    listMvcObservers.remove(o);
}
void ConcreteAircraftCarrier::notifyPlanes() {
    for(auto &itPlanes : planes){
        itPlanes->update();
    }
}
void ConcreteAircraftCarrier::attachPlanes(const std::shared_ptr<WarPlane> &warPlane) {
    planes.push_back(warPlane);
}
void ConcreteAircraftCarrier::detachPlanes(const std::shared_ptr<WarPlane> &warPlane) {
    planes.remove(warPlane);
}
void ConcreteAircraftCarrier::planesAttack() {
    for(auto &itPlanes : planes){
        itPlanes->searchTarget();
    }
}
ConcreteAircraftCarrier::~ConcreteAircraftCarrier() = default;
void ConcreteAircraftCarrier::attack() {
    for(auto &iterArsenal : arsenalList){
        iterArsenal->searchTarget();
    }
}
void ConcreteAircraftCarrier::move() {
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

        if (auto* pAircraftCarrier = dynamic_cast<ConcreteAircraftCarrier*>(this))   //FIXME controllare che gli aerei non stiano volando
            pAircraftCarrier->notifyPlanes();
        else
        {
            //TODO Detach Airplanes Observers
        }
    }
}
void ConcreteAircraftCarrier::notifyArsenals() const {
    for(auto &iterArsenal : arsenalList){
        iterArsenal->update();
    }
}
void ConcreteAircraftCarrier::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}
void ConcreteAircraftCarrier::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);
}
void ConcreteAircraftCarrier::notifyBars() const {
    for(auto &iterBars : bars){
        iterBars->updateBars();
    }
}
void ConcreteAircraftCarrier::notifyBarsDamage() const {
    for(auto &iterBars : bars){
        iterBars->updateBarsDamage();
    }
}
void ConcreteAircraftCarrier::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void ConcreteAircraftCarrier::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);
}
bool ConcreteAircraftCarrier::searchTarget() {
    move();
    if(canEngage())
        attack();
}
float ConcreteAircraftCarrier::rotate(float mx, float rotatingInPlaceMult) {
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
bool ConcreteAircraftCarrier::canEngage() {    //Controlla se nessun cannone può ingaggiare
    bool result = true;
    if(death || concealed){
        result= false;
    }
    return result;
}