//
// Created by davide on 04/07/21.
//

#include "OldFTorpedoBomber.h"

OldFTorpedoBomber::OldFTorpedoBomber(int x, int y, float ac, float maxVel, int hp, int le, int wi, bool col,
                             int numTorpedos, int damage,std::string nat,WarShip &subject) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat),subject_(subject),numTorpedos(numTorpedos),torpedoDamage(damage)  {

    std::string textureName="OldFTorpedoBomber";

    try {
        setUpSprite("WarPlanes/" + textureName);
        sprite.setPosition(pos);
        resetOrigin();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Wrong texture name" << std::endl;
    }
}

void OldFTorpedoBomber::launchTorpedo(Vehicle &enemy) {

}

void OldFTorpedoBomber::attack(Vehicle target) {

}

void OldFTorpedoBomber::update(bool isDead) {
    Vehicle::update(isDead);
}



OldFTorpedoBomber::~OldFTorpedoBomber() {

}

void OldFTorpedoBomber::updatePlanes(sf::Vector2f &vel,double mx) {
    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}

void OldFTorpedoBomber::resetOrigin() {
    sprite.setOrigin((width - 1) / 2, (length - 1) / 2);
}

int OldFTorpedoBomber::getNumTorpedos() const {
    return numTorpedos;
}

int OldFTorpedoBomber::getTorpedoDamage() const {
    return torpedoDamage;
}

void OldFTorpedoBomber::planeAttack(std::_List_iterator<std::unique_ptr<Vehicle>> target, float dt) {
    if (actualCooldown <= 0) {
        if (WarShip *pTarget = dynamic_cast<WarShip *> (target->get())) {
            pTarget->setDamage(torpedoDamage);
            pTarget->notifyBarsDamage();                                //notify per Observer Bars
        }
        actualCooldown = cooldown;
    } else {
        actualCooldown -= dt;
    }
}
