//
// Created by pala on 9/17/21.
//

#include "OldBomber.h"
//

void OldBomber::bombard(Vehicle &enemy) {

}

void OldBomber::attack(Vehicle target) {
}

void OldBomber::update(bool isDead) {
    Vehicle::update(isDead);
}



OldBomber::~OldBomber() {

}


void OldBomber::updatePlanes(sf::Vector2f &vel,double mx) {
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}

OldBomber::OldBomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col, int numBombs, int damage,std::string nat,WarShip &subject) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat),subject_(subject),bombDamage(damage),numBombs(numBombs) {
    std::string textureName="OldBomber";

    try {
        setUpSprite("WarPlanes/" + textureName);
        sprite.setPosition(pos);
        resetOrigin();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}

void OldBomber::resetOrigin() {
    sprite.setOrigin((width - 1) / 2, (length) / 2);
}

int OldBomber::getNumBombs() const {
    return numBombs;
}

int OldBomber::getBombDamage() const {
    return bombDamage;
}

void OldBomber::planeAttack(std::_List_iterator<std::unique_ptr<Vehicle>> target, float dt) {
    if(actualCooldown <= 0){
        if (WarShip *pTarget = dynamic_cast<WarShip *> (target->get())) {
            pTarget->setDamage(bombDamage);
            pTarget->notifyBarsDamage();                                //notify per Observer Bars
        }
        actualCooldown = cooldown;
    } else {
        actualCooldown -= dt;
    }


}
