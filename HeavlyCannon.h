//
// Created by davide on 02/07/21.
//

#ifndef SEALION_HEAVLYCANNON_H
#define SEALION_HEAVLYCANNON_H


#include "Arsenal.h"
#include "Bullet.h"

class HeavlyCannon : public Arsenal {
public:
    //TODO implementare


    HeavlyCannon(const float range, const int reload, int speed, int dispersion, Bullet type,
                 float decelleration, int power, int num, int posX, int posY, int le, int wi, std::string texName);

    ~HeavlyCannon() override;

private:
    bool shoreBombardment();

    void openFire(Vehicle enemy) override;

    void update(std::unique_ptr<WarShip> theChangedSubject) override;

    void attach() override;

    void detach() override;

    bool engage(Vehicle enemy) override;

    void rotate() override;

    void resetOrigin() override;
};


#endif //SEALION_HEAVLYCANNON_H
