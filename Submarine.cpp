//
// Created by alessandro on 19/09/21.
//

#include "Submarine.h"

Submarine::Submarine(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, const int armour, const std::string &name,const int numLCannons, const int numMCannons, const int numHCannons, const int numAntiAircraft): Specialty(x, y, ac, maxVel, hp, le, wi, col, nat, shipType, modelType, armour, name, numLCannons, numMCannons,numHCannons, numAntiAircraft) {}
void Submarine::attack(float elapsedTime) {
    for(auto &iterArsenal : arsenalList){
        iterArsenal->searchTarget(elapsedTime);
    }
}
void Submarine::move(float elapsedTime) {
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
            vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * elapsedTime * acceleration / 10;
            vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * elapsedTime * acceleration / 10;
            sprite.setPosition(sprite.getPosition() + vel);
            rotate(mx, rotatingInPlaceMult);
        } else {
            currentSpeed = 0;
        }

        notifyArsenals();
        notifyBars();
    }
}
void Submarine::notifyArsenals() const {
    for(auto &iterArsenal : arsenalList){
        iterArsenal->update();
    }
}
void Submarine::attach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.push_back(gun);
}
void Submarine::detach(const std::shared_ptr<Arsenal> &gun) {
    arsenalList.remove(gun);
}
void Submarine::notifyBars() const {
    for(auto &iterBars : bars){
        iterBars->updateBars();
    }
}
void Submarine::notifyBarsDamage() const {
    for(auto &iterBars : bars){
        iterBars->updateBarsDamage();
    }
}
void Submarine::attachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.push_back(bar);
}
void Submarine::detachBar(const std::shared_ptr<BarInterface> &bar) {
    bars.remove(bar);
}
bool Submarine::searchTarget(float elapsedTime) {
    move(elapsedTime);
    if(canEngage())
        attack(elapsedTime);
}
float Submarine::rotate(float mx, float rotatingInPlaceMult) {
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
bool Submarine::canEngage() {    //Controlla se nessun cannone può ingaggiare
    bool result = true;
    if(death || concealed){
        result= false;
    }
    return result;
}
void Submarine::setMvcTarget(std::shared_ptr<WarShip> target) {
    //TODO implementare
}

void Submarine::drawEquipment(sf::RenderWindow &window) {
    if (death) {
        sprite.setColor(sf::Color::Transparent);
    } else if (selected) {
        sprite.setColor(sf::Color::Green);
    } else {
        sprite.setColor(sf::Color::White);
    }
    window.draw(sprite);
    for(auto &it : bars){
        it->drawEquipment(window);
    }
    window.draw(sprite);
}
