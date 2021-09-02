//
// Created by gabriele on 7/2/21.
//


#include "Arsenal.h"

//getter
const float Arsenal::getRangeOfFire() const {
    return rangeOfFire;
}

const int Arsenal::getReloadTime() const {
    return reloadTime;
}


int Arsenal::getMaximumDispersion() const {
    return maximumDispersion;
}


int Arsenal::getFirepower() const {
    return firepower;
}

int Arsenal::getNumAmmo() const {
    return numAmmo;
}

Arsenal::Arsenal(const float range, const float reload, int dispersion, std::shared_ptr<Bullet> type,
                 int power, int num, int posX, int posY, int le, int wi,
                 std::string texName) : rangeOfFire(range), reloadTime(reload),
                                        maximumDispersion(dispersion),
                                        firepower(power), numAmmo(num), length(le),
                                        width(wi), textureName(texName), ammoType(type) {

    pos = sf::Vector2f(posX, posY);


}

bool Arsenal::setUpSprite(std::string textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    std::string textPath;
    textPath = currentDir + "/../Res/Weaponry/" + textureName + ".png";
    if (!texture.loadFromFile(textPath)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, length));
    return true;
}

void Arsenal::openFire(Vehicle enemy) {

}

std::shared_ptr<Bullet> Arsenal::getAmmoType() const {
    return ammoType;
}

void Arsenal::setAmmoType(const std::shared_ptr<Bullet> ammoType) {
    Arsenal::ammoType = ammoType;
}


bool Arsenal::engage(Vehicle enemy) {
    return false;
}

void Arsenal::rotate() {

}

sf::Sprite &Arsenal::getSprite() {
    return sprite;
}

const std::string &Arsenal::getTextureName() const {
    return textureName;
}

int Arsenal::getLength() const {
    return length;
}

int Arsenal::getWidth() const {
    return width;
}

const sf::Vector2f &Arsenal::getPos() const {
    return pos;
}

float Arsenal::getCountdown() const {
    return countdown;
}

void Arsenal::setCountdown(float countdown) {
    Arsenal::countdown = countdown;
}

void Arsenal::setNumAmmo(int numAmmo) {
    Arsenal::numAmmo = numAmmo;
}






