//
// Created by pala on 9/18/21.
//
#ifndef SEALION_CONCRETEARSENAL_H
#define SEALION_CONCRETEARSENAL_H
#include "Arsenal.h"
#include "WarShip.h"

class ConcreteArsenal: public Arsenal {
public:
    ConcreteArsenal(float range, float reload, int maxDispersion, std::shared_ptr<Bullet> &ammo, int firepower, int le,int wi, std::string texName, WarShip &subject, float posX, float posY);
    std::shared_ptr<Bullet> getAmmoType() override;
    void update() override;
    void searchTarget(float elapsedTime) override;
    bool setUpSprite(std::string textureName) override;
    void removeMeFromTheList() override;
    float getRangeOfFire() const override;
    int getReloadTime() const override;
    int getAmmoSpeed() const override;
    int getMaximumDispersion() const override;
    std::shared_ptr<Bullet> getAmmoType() const override;
    int getFirepower() const override;
    void setAmmoType(std::shared_ptr<Bullet> ammoType) override;
    sf::Sprite &getSprite() override;
    const std::string &getTextureName() override;
    int getLength() const override;
    int getWidth() const override;
    float getCountdown() const override;
    void setCountdown(float countdown) override;
    virtual void drawEquipment(sf::RenderWindow &window) override;
    ~ConcreteArsenal()=default;
protected:
    void rotate(sf::Vector2f &coord) override;
    float attack(sf::Vector2f &coord,float elapsedTime) override;
    bool engage(sf::Vector2f &coord,bool concealed) override;
private:
    WarShip &subject_;
};
#endif //SEALION_CONCRETEARSENAL_H
