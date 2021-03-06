//
// Created by davide on 18/07/21.
//


#include <iostream>
#include "Bullet.h"
#include "Collision.h"


Bullet::Bullet(std::string bulletName, int width, int length,float dmgMult,float penetrationMult,float speedStart) :
        bulletName(bulletName), width(width), length(length),dmgMult(dmgMult),penetrationMult(penetrationMult),speedMult(speedStart) {
    currentSpeed = 0;
    arrived=true;
    setUpSprite(bulletName);
    sprite.setPosition(0, 0);
    resetOrigin();
}
bool Bullet::setUpSprite(const std::string& textureName) {
    std::string currentDir = ToolBox::GetCurrentWorkingDir();
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
    float mx;
    sf::Vector2f vel;
    double dy = targetPoint.y - startPoint.y;
    double dx = targetPoint.x - startPoint.x;
    mx = ToolBox::calculateMx(dx,dy);
    if (currentSpeed == 0) {
        currentSpeed = speed;
    } else if (currentSpeed < 0) {
        currentSpeed = 0;
        arrived = true;
    }
    sprite.setRotation(mx);
    vel.x = sinf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * speedMult / 10;
    vel.y = -cosf((M_PI / 180.f) * sprite.getRotation()) * currentSpeed * speedMult / 10;
    currentSpeed = currentSpeed - deceleration;
    sprite.setPosition(sprite.getPosition() + vel);
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
    currentSpeed = speed;
    targetPoint = target;
    startPoint = start;
    arrived = false;
    sprite.setPosition(startPoint);
}
float Bullet::getCurrentSpeed() const {
    return currentSpeed;
}
float Bullet::getSpeed() const {
    return speed;
}
float Bullet::getDmgMult() const {
    return dmgMult;
}
float Bullet::getSpeedMult() const {
    return speedMult;
}
float Bullet::getPenetrationMult() const {
    return penetrationMult;
}

void Bullet::drawEquipment(sf::RenderWindow &window) {
    if(!arrived)
        window.draw(sprite);
}




