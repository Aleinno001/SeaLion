//
// Created by pala on 9/17/21.
//
#include "ConcreteWarPlane.h"

void ConcreteWarPlane::attack(float elapsedTime) {
    if(currentCoolDown <= 0){
        target->setDamage(ammoDamage);
        target->notifyBarsDamage();//notify per Observer Bars
        currentCoolDown = coolDown;
    } else {
        currentCoolDown -= elapsedTime;
    }
}
void ConcreteWarPlane::update() {
    if(target.get() == nullptr) {
        sprite.setPosition(sprite.getPosition() + subject_.getMovement());
        sprite.setRotation(subject_.getSprite().getRotation());
        sf::Transform rotation;
        rotation.rotate(subject_.getDmX(), subject_.getSprite().getPosition());
        sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
        sprite.setPosition(newPosition);
    }
}
void ConcreteWarPlane::searchTarget(float elapsedTime) {
    if(target.get() != nullptr && !target->isConcealed()) {
        move(elapsedTime);
        if (canEngage())
            attack(elapsedTime);
    }
}
float ConcreteWarPlane::rotate(float mx, float rotatingInPlaceMult) {
    float deltaMx = 0;
    if (abs(sprite.getRotation() - mx) >=
        1.5) {  // Verifica che la rotazione da effettuare sia sufficientemente grande (risolve un glitch grafico)
        if (((mx - sprite.getRotation()) <= 180) && (mx - sprite.getRotation()) >
                                                    0) {  //Analizza le casistiche e di conseguenza ruota incrementando/decrementando l'angolo
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 1000;
            sprite.rotate(deltaMx);
        } else if (sprite.getRotation() > 180 && mx < 180) {
            deltaMx = currentSpeed * acceleration * rotatingInPlaceMult / 1000;
            sprite.rotate(deltaMx);
        } else {
            deltaMx = -currentSpeed * acceleration * rotatingInPlaceMult / 1000;
            sprite.rotate(deltaMx);
        }
    }
    return deltaMx;
}
bool ConcreteWarPlane::canEngage() {
    if(abs(target->getSprite().getPosition().x - sprite.getPosition().x) < 90 && abs(target->getSprite().getPosition().y - sprite.getPosition().y) < 90)
        return true;
    else
        return false;
}
void ConcreteWarPlane::move(float elapsedTime) {
    if (!death && target) {   //verifica morte e se il target non ?? ancora stato assegnato
        double mx;
        double dy = target->getSprite().getPosition().y - sprite.getPosition().y;
        double dx = target->getSprite().getPosition().x - sprite.getPosition().x;
        float rotatingInPlaceMult = 1;
        mx = ToolBox::calculateMx(dx, dy);
        if (currentSpeed <= maxSpeed * 2) {
            currentSpeed = currentSpeed + acceleration / 100 * 2;
        }
        if (abs(sprite.getRotation() - mx) >=
            25) {  //Se la rotazione da effettuare ?? elevata allora ruota pi?? velocemente
            rotatingInPlaceMult = 3;
            if (currentSpeed > maxSpeed / 4)
                currentSpeed = currentSpeed - acceleration / 100;
        }
        if ((abs(target->getSprite().getPosition().y - sprite.getPosition().x) < sprite.getTextureRect().height / 2 &&
             abs(target->getSprite().getPosition().x - sprite.getPosition().y) < sprite.getTextureRect().height /
                                                           2)) {   //Se il punto da raggiungere ?? vicino la nave avanza lentamente
            if (currentSpeed > acceleration / 100) {
                currentSpeed = currentSpeed - acceleration / 100;
            }
        }
        movement.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed *elapsedTime* acceleration / 10;
        movement.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed *elapsedTime* acceleration / 10;
        sprite.setPosition(sprite.getPosition() + movement);
        rotate(mx, rotatingInPlaceMult);
    }
}
void ConcreteWarPlane::drawEquipment(sf::RenderWindow &window) {
    if (subject_.isDeath()) {
        sprite.setColor(sf::Color(0,0,0,160));
    } else if (subject_.isSelected()) {
        sprite.setColor(sf::Color::Green);
    } else if(subject_.isConcealed()){
        sprite.setColor(sf::Color(255,255,255,130));
    }else{
        sprite.setColor(sf::Color::White);
    }
    window.draw(sprite);
}