//
// Created by pala on 9/18/21.
//
#include "ConcreteArsenal.h"
std::shared_ptr<Bullet> ConcreteArsenal::getAmmoType() {
    return ammoType;
}
ConcreteArsenal::~ConcreteArsenal()=default;
void ConcreteArsenal::update() {
    sprite.setPosition(sprite.getPosition() + subject_.getMovement());
    sprite.setRotation(subject_.getSprite().getRotation());
    sf::Transform rotation;
    rotation.rotate(sprite.getRotation(), subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}
void ConcreteArsenal::searchTarget() {
 //FIXME SearchTarget
}
bool ConcreteArsenal::setUpSprite(std::string textureName) {
    std::string currentDir = ToolBox::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    std::string textPath;
    textPath = currentDir + "/../Res/Buttons/" + textureName + ".png";
    if (!Collision::CreateTextureAndBitmask(texture, textPath)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, length));
    return true;
}
void ConcreteArsenal::removeMeFromTheList() {
    subject_.detach(std::shared_ptr<Arsenal>(this));
}
float ConcreteArsenal::getRangeOfFire() const {
    return rangeOfFire;
}
int ConcreteArsenal::getReloadTime() const {
    return reloadTime;
}
int ConcreteArsenal::getAmmoSpeed() const {
    return ammoType->getSpeed();
}
int ConcreteArsenal::getMaximumDispersion() const {
    return maximumDispersion;
}
std::shared_ptr<Bullet> ConcreteArsenal::getAmmoType() const {
    return ammoType;
}
int ConcreteArsenal::getFirepower() const {
    return firepower;
}
void ConcreteArsenal::setAmmoType(std::shared_ptr<Bullet> ammoType) {
    this->ammoType=ammoType;
}
sf::Sprite &ConcreteArsenal::getSprite(){
    return sprite;
}
const std::string &ConcreteArsenal::getTextureName() {
    return textureName;
}
int ConcreteArsenal::getLength() const {
    return length;
}
int ConcreteArsenal::getWidth() const {
    return width;
}
float ConcreteArsenal::getCountdown() const {
    return countdown;
}
void ConcreteArsenal::setCountdown(float countdown) {
    this->countdown=countdown;
}
void ConcreteArsenal::rotate() {
    //FIXME IMPLEMENTA
}
void ConcreteArsenal::attack() {
    //FIXME ATTACK
}
bool ConcreteArsenal::engage() {
    return 0;//FIXME ENGAGE
}
