//
// Created by pala on 9/4/21.
//

#include "LifeBar.h"
#include "Collision.h"


bool LifeBar::setUpSprite(std::string textureName) {
    std::string currentDir = CurrentDir::GetCurrentWorkingDir();
    std::string unitTestingPath = "UnitTesting";
    std::size_t found = currentDir.find(unitTestingPath);
    if (found != std::string::npos) {
        currentDir.erase(found);
        currentDir.pop_back();
    }
    textureName = currentDir + "/../Res/Tiles/" + textureName;
    if (!Collision::CreateTextureAndBitmask(textureLife,textureName)) {
        throw std::runtime_error("Path to tile filename invalid!!");
    }
    textureLife.setSmooth(true);
    life.setTexture(textureLife);
    life.setTextureRect(sf::IntRect(0, 0, 10, 20));
    return true;
}


LifeBar::LifeBar(WarShip &subject):subject_(subject),r(36),g(189),b(36) {
    //subject_.attachBar(this); TODO CONCLUDERE
    setUpSprite("lifeBar");
    life.setPosition(subject_.getSprite().getPosition().x+0.50*subject_.getWidth(),subject_.getSprite().getPosition().y+0.50*subject_.getLength());

    life.setColor(sf::Color(r,g,b));

}


void LifeBar::updateBars(sf::Vector2f &vel, double mx) {
    life.setPosition(life.getPosition() + vel);
    life.setRotation(life.getRotation() + mx);
    sf::Transform rotation;
    rotation.rotate(mx, subject_.getSprite().getPosition());
    sf::Vector2f newPosition = rotation.transformPoint(life.getPosition());
    life.setPosition(newPosition);
    double percentageLife = (subject_.getHp()*subject_.getMaxHp())/100;
    double damageReceived = abs(subject_.getMaxHp()-subject_.getHp());
    double percentageDamage = (damageReceived*subject_.getMaxHp())/100;
    double fifty= ((subject_.getMaxHp()/2)*subject_.getMaxHp())/100;

    if(percentageLife>fifty){
        r=r+r*percentageDamage;
        life.setColor(sf::Color(r,g,b));
    }else{
        g=g-g*percentageDamage;
        life.setColor(sf::Color(r,g,b));

    }




}
