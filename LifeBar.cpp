//
// Created by pala on 9/4/21.
//

#include "LifeBar.h"
#include "Collision.h"





LifeBar::LifeBar(WarShip &subject):BarInterface(),subject_(subject),r(0),g(255),b(0) {

    life.setPosition(subject_.getSprite().getPosition().x+0.50*subject_.getWidth(),subject_.getSprite().getPosition().y+0.50*subject_.getLength());
    life.setColor(sf::Color(r,g,b));

}


void LifeBar::updateBars(sf::Vector2f &vel, double mx) {
    life.setPosition(subject_.getSprite().getPosition());
    life.move(0.50*subject_.getWidth(),0);
    life.setPosition(life.getPosition() + vel);
    life.setRotation(life.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(life.getPosition());
    life.setPosition(newPosition);

}

void LifeBar::updateBarsDamage() {

    double percentageLife = (subject_.getHp() * subject_.getMaxHp()) / 100;
    double damageReceived = abs(subject_.getMaxHp() - subject_.getHp());
    double percentageDamage = (damageReceived * subject_.getMaxHp()) / 100;

    if (percentageLife > 0.50) {
        if(r<255) {
            r = r + r * percentageDamage;
            life.setColor(sf::Color(r, g, b));
        }
    } else {
        g = g - g * percentageDamage;
        life.setColor(sf::Color(r, g, b));

    }
}


