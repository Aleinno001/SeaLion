//
// Created by davide on 18/07/21.
//


#include <iostream>
#include "Bullet.h"
#include "Collision.h"


Bullet::Bullet(
        const std::string &bulletName, int width, int length) :
        bulletName(bulletName), width(width), length(length) {
    currentSpeed = 0;
    setUpSprite(bulletName);
    sprite.setPosition(0, 0);
    resetOrigin();
}

bool Bullet::setUpSprite(const std::string& textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    std::string textPath;
    textPath = currentDir + "/../Res/Bullet/" + textureName + ".png";
    if (!Collision::CreateTextureAndBitmask(texture,textPath)) {
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
    std::cerr << "Sono nella reache target quella vera " << std::endl;
    float mx;
    sf::Vector2f vel;

    double dy = targetPoint.y - startPoint.y;
    double dx = targetPoint.x - startPoint.x;
    mx = 90 + atan2(dy, dx) * 180 / M_PI;

    if (mx < 0) {
        mx = 360 + mx;
    }

    if (currentSpeed == 0) {
        currentSpeed = speed;
    }
    sprite.setRotation(mx);
    vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * speedMult / 10;
    vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * speedMult / 10;

    std::cerr << "vel.x: " << vel.x << std::endl;
    std::cerr << "vel.y: " << vel.y << std::endl;

    currentSpeed = currentSpeed - deceleration;

    sprite.setPosition(sprite.getPosition() + vel);

}

void Bullet::setTargetPoint(const sf::Vector2f &targetPoint) {
    Bullet::targetPoint = targetPoint;
}

void Bullet::setStartPoint(const sf::Vector2f &startPoint) {
    Bullet::startPoint = startPoint;
    sprite.setPosition(startPoint);
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

void Bullet::hit() {
    arrived = true;
    currentSpeed = 0;
}

void Bullet::initializeBullet(sf::Vector2f start, sf::Vector2f target) {
    targetPoint = target;
    startPoint = start;
    arrived = false;
    sprite.setPosition(startPoint);
}


