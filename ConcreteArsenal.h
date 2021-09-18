//
// Created by pala on 9/18/21.
//
#ifndef SEALION_CONCRETEARSENAL_H
#define SEALION_CONCRETEARSENAL_H
#include "Arsenal.h"
#include "WarShip.h"
class ConcreteArsenal: public Arsenal {
public:
    ConcreteArsenal(float range, float reload, float countdown, int maxDispersion, std::shared_ptr<Bullet> ammo,int firepower, int le, int wi, std::string texName, sf::Sprite spr, WarShip &sub): Arsenal(range, reload, countdown, maxDispersion, ammo, firepower, le, wi, texName, spr),subject_(sub) { setUpSprite(texName);}
    std::shared_ptr<Bullet> getAmmoType() override;
    ~ConcreteArsenal() override;
    void update() override;
    void searchTarget() override;
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
protected:
    void rotate() override;
    void attack() override;
    bool engage() override;
private:
    WarShip &subject_;
};
#endif //SEALION_CONCRETEARSENAL_H
