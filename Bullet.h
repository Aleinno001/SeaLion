//
// Created by davide on 18/07/21.
//

#ifndef SEALION_BULLET_H
#define SEALION_BULLET_H

#include <string>
#include <stdexcept>
#include "SFML/Graphics.hpp"
#include "math.h"
#include "ToolBox.h" 


class Bullet {
public:
    Bullet(std::string bulletName, int width, int length, float dmgMult,float penetrationMult,float speedStart);
    void reachTarget ();
private:
    bool arrived {true};
    sf::Vector2f targetPoint;
    sf::Vector2f startPoint;
    float currentSpeed;
    float speed {100};
    float damage{};
    float deceleration{1.3};
    float dmgMult{1};
    float speedMult{1};
    float penetrationMult{1};
    sf::Sprite sprite;
    sf::Texture texture;
    std::string bulletName;
    int width;
    int length;
    bool setUpSprite(const std::string& textureName);
    void resetOrigin();
public:
    const sf::Sprite &getSprite() const;
    const sf::Vector2f &getTargetPoint() const;
    bool isArrived() const;
    void setArrived(bool isArrived);
    void hit();
    float getCurrentSpeed() const;
    float getSpeed() const;
    float getDmgMult() const;
    float getSpeedMult() const;
    float getPenetrationMult() const;
    void initializeBullet(sf::Vector2f startPoint, sf::Vector2f target);
    void drawEquipment(sf::RenderWindow &window);
    ~Bullet()=default;
};



#endif //SEALION_BULLET_H
