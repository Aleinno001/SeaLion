//
// Created by pala on 9/4/21.
//

#include "LifeBar.h"
#include "Collision.h"


LifeBar::LifeBar(WarShip &subject) : BarInterface(), subject_(subject), r(0), g(255), b(0) {
    life.setPosition(subject_.getSprite().getPosition().x + 0.50 * subject_.getWidth(),
                     subject_.getSprite().getPosition().y + 0.50 * subject_.getLength());
    life.setColor(sf::Color(r, g, b));
}
void LifeBar::updateBars(sf::Vector2f &vel, double mx) {
    life.setPosition(subject_.getSprite().getPosition());
    life.move(0.50 * subject_.getWidth(), 0);
    life.setPosition(life.getPosition() + vel);
    life.setRotation(life.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(life.getPosition());
    life.setPosition(newPosition);
}
void LifeBar::updateBarsDamage() {
    double percentageLife = (subject_.getHp() * 100) / subject_.getMaxHp();
    if (percentageLife >= 50) {
        r = 255 - percentageLife * 255 * 2 / 100;
    } else {
        r = 255;
        g = percentageLife * 2 * 255 / 100;
        if (percentageLife < 1) {
            g = 0;
        }
    }
    life.setColor(sf::Color(r, g, b));
}


