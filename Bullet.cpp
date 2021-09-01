//
// Created by davide on 18/07/21.
//


#include "Bullet.h"


Bullet::Bullet(
               const std::string &bulletName, int width, int length) :
                                                bulletName(bulletName), width(width), length(length){
    setUpSprite(bulletName);
    resetOrigin();
}

bool Bullet::setUpSprite(std::string textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    std::string textPath;
    textPath = currentDir + "/../Res/Bullet/" + textureName + ".png";
    if (!texture.loadFromFile(textPath)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, length));
    return true;
}

void Bullet::resetOrigin() {
    sprite.setOrigin(width + 1 / 2, length / 2);
}

void Bullet::reachTarget() {
    float mx;
    sf::Vector2f vel;

    double dy = targetPoint.y - startPoint.y;
    double dx = targetPoint.x - startPoint.x;
    mx = 90 + atan2(dy, dx) * 180 / M_PI;

    if (mx < 0) {
        mx = 360 + mx;
    }

    if(currentSpeed == 0){
        currentSpeed = speed;
    }
    vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * speedMult / 10;
    vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * speedMult / 10;

    currentSpeed = currentSpeed - deceleration;

    sprite.setPosition(sprite.getPosition() + vel);
    sprite.setRotation(sprite.getRotation() + mx);
}

void Bullet::setTargetPoint(const sf::Vector2f &targetPoint) {
    Bullet::targetPoint = targetPoint;
}

void Bullet::setStartPoint(const sf::Vector2f &startPoint) {
    Bullet::startPoint = startPoint;
}

const sf::Sprite &Bullet::getSprite() const {
    return sprite;
}

const sf::Vector2f &Bullet::getTargetPoint() const {
    return targetPoint;
}

bool Bullet::isArrived() const {
    return arrived;
}

void Bullet::setArrived(bool isArrived) {
    Bullet::arrived = isArrived;
}
