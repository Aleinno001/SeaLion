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
    Bullet(const std::string bulletName, int width, int length, float dmgMult,float penetrationMult,float speedStart);
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
    void setTargetPoint(const sf::Vector2f &targetPoint);
    void setStartPoint(const sf::Vector2f &startPoint);
    const sf::Sprite &getSprite() const;
    const sf::Vector2f &getTargetPoint() const;
    bool isArrived() const;
    void setArrived(bool isArrived);
    void hit();
    const sf::Vector2f &getStartPoint() const;
    float getCurrentSpeed() const;
    float getSpeed() const;
    float getDamage() const;
    float getDmgMult() const;
    float getSpeedMult() const;
    float getPenetrationMult() const;
    float getDeceleration() const;
    const sf::Texture &getTexture() const;
    const std::string &getBulletName() const;
    int getWidth() const;
    int getLength() const;
    void initializeBullet(sf::Vector2f startPoint, sf::Vector2f target);
};



#endif //SEALION_BULLET_H
