//
// Created by pala on 9/18/21.
//
#include "ConcreteArsenal.h"
std::shared_ptr<Bullet> ConcreteArsenal::getAmmoType() {
    return ammoType;
}
void ConcreteArsenal::update() {
    sprite.setPosition(sprite.getPosition() + subject_.getMovement());
    sprite.setRotation(subject_.getSprite().getRotation());
    sf::Transform rotation;
    rotation.rotate(subject_.getDmX(), subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(sprite.getPosition());
    sprite.setPosition(newPosition);
}
void ConcreteArsenal::searchTarget(float elapsedTime) {
    std::shared_ptr<WarShip> target;
    float distance;
    float targetDistance = 999999;
    for (auto &enemyIter:subject_.getEnemyList()) {
        if (!enemyIter->isDeath() ||!ammoType->isArrived()) {  //Permette al proiettile di raggiungere il bersaglio anche se la nave bersaglio muore
            distance = ToolBox::calculateDistance(const_cast<sf::Vector2f &>(enemyIter->getSprite().getPosition()),const_cast<sf::Vector2f &>(sprite.getPosition()));
            if ((distance <= rangeOfFire && distance <= targetDistance)) {  //Salva il bersaglio più vicino che è possibile attaccare
                if (engage(const_cast<sf::Vector2f &>(enemyIter->getSprite().getPosition()),enemyIter->isConcealed())) {
                    target = enemyIter;
                    targetDistance = distance;
                }
            }
        }
    }
    if (targetDistance != 999999) {
        if (!target->isDeath()) {
            attack(const_cast<sf::Vector2f &>(target->getSprite().getPosition()),elapsedTime);
        } else {  //Il proiettile può raggiungere il bersaglio anche se chi lo spara muore
            ammoType->reachTarget();
        }
    } else if (!ammoType->isArrived()) {  //Se il proiettile non ha raggiunto il bersaglio continua a viaggiare
        ammoType->reachTarget();
    }
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
    textPath = currentDir + "/../Res/Weaponry/" + textureName + ".png";
    if (!Collision::CreateTextureAndBitmask(texture, textPath)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width, length));
    return true;
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
void ConcreteArsenal::rotate(sf::Vector2f &coord) {
    double mx;
    double dy;
    double dx;
    dy = coord.y - sprite.getPosition().y;
    dx = coord.x - sprite.getPosition().x;
    mx = -180 + ToolBox::calculateMx(dx, dy);
    sprite.setRotation(mx);
}
float ConcreteArsenal::attack(sf::Vector2f &coord,float elapsedTime) {
    rotate(coord);
    if (abs(countdown - elapsedTime) <= elapsedTime) {  //Verifica che il cannone abbia ricaricato e quindi imposta lo stato di sparo
        sf::Vector2f targetPosition;
        targetPosition = coord;
        Dice dice(11, targetPosition.x);
        float dx = targetPosition.x - sprite.getPosition().x;
        float dy = targetPosition.y - sprite.getPosition().y;
        float distance = sqrt(pow(dx, 2) + pow(dy, 2));
        targetPosition.x +=(pow(-1, dice.roll(1))) * (maximumDispersion * (dice.roll(1) - 1) / 10) *distance /rangeOfFire;
        targetPosition.y +=(pow(-1, dice.roll(1))) * (maximumDispersion * (dice.roll(1) - 1) / 10) *distance /rangeOfFire;
        countdown=reloadTime;
        ammoType->initializeBullet(sprite.getPosition(),targetPosition);
    } else {
        countdown=countdown - elapsedTime;
    }
    if ((abs(ammoType->getSprite().getPosition().x -ammoType->getTargetPoint().x) >1 ||abs(ammoType->getSprite().getPosition().y -ammoType->getTargetPoint().y) >1)) { //Controlla se il proiettile ha raggiunto le coordinate prefissatammoType->reachTarget();
    } else {
        ammoType->hit();
    }
}
bool ConcreteArsenal::engage(sf::Vector2f &coord,bool concealed) {
    bool result = false;
    if (!concealed || subject_.isConcealed()) {  //Non può sparare se il nemico è nascosto, almeno che non lo siano entrambi
        result = true;
    }
    return result;
}
ConcreteArsenal::ConcreteArsenal(float range, float reload, int maxDispersion, std::shared_ptr<Bullet> &ammo,int firepower, int le, int wi, std::string texName, WarShip &subject, float posX, float posY): Arsenal(range, reload, maxDispersion, ammo, firepower, le, wi, texName), subject_(subject) {
    setUpSprite(texName);
    sprite.setOrigin(width/2,length/2);
    sprite.setPosition(posX,posY);
}

void ConcreteArsenal::drawEquipment(sf::RenderWindow &window) {
    if (subject_.isDeath()) {
        sprite.setColor(sf::Color::Black);
    } else if (subject_.isSelected()) {
        sprite.setColor(sf::Color::Green);
    } else {
        sprite.setColor(sf::Color::White);
    }
    window.draw(sprite);
    ammoType->drawEquipment(window);
}
