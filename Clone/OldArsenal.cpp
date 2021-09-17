#include "OldArsenal.h"

//getter
const float OldArsenal::getRangeOfFire() const {
    return rangeOfFire;
}

const int OldArsenal::getReloadTime() const {
    return reloadTime;
}


int OldArsenal::getMaximumDispersion() const {
    return maximumDispersion;
}


int OldArsenal::getFirepower() const {
    return firepower;
}

OldArsenal::OldArsenal(const float range, const float reload, int dispersion, std::shared_ptr<Bullet> type,
                 int power, int posX, int posY, int le, int wi,
                 std::string texName) : rangeOfFire(range), reloadTime(reload),
                                        maximumDispersion(dispersion),
                                        firepower(power), length(le),
                                        width(wi), textureName(texName), ammoType(type) {

    pos = sf::Vector2f(posX, posY);


}

bool OldArsenal::setUpSprite(std::string textureName) {
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

void OldArsenal::openFire(Vehicle enemy) {

}

std::shared_ptr<Bullet> OldArsenal::getAmmoType() const {
    return ammoType;
}

void OldArsenal::setAmmoType(const std::shared_ptr<Bullet> ammoType) {
    OldArsenal::ammoType = ammoType;
}


bool OldArsenal::engage(Vehicle enemy) {
    return false;
}

void OldArsenal::rotate() {

}

sf::Sprite &OldArsenal::getSprite() {
    return sprite;
}

const std::string &OldArsenal::getTextureName() const {
    return textureName;
}

int OldArsenal::getLength() const {
    return length;
}

int OldArsenal::getWidth() const {
    return width;
}

const sf::Vector2f &OldArsenal::getPos() const {
    return pos;
}

float OldArsenal::getCountdown() const {
    return countdown;
}

void OldArsenal::setCountdown(float countdown) {
    OldArsenal::countdown = countdown;
}

std::shared_ptr<Bullet> OldArsenal::getAmmoType() {
    return ammoType;
}
