//
// Created by pala on 02/07/21.
//

#ifndef SEALION_TORPEDOTUBE_H
#define SEALION_TORPEDOTUBE_H

#include "Arsenal.h"

class TorpedoTube : public Arsenal {
public:
    //TODO implementare



    TorpedoTube(const float range, const int reload, int speed, int dispersion, Bullet type,
                float decelleration, int power, int num, int posX, int posY, int le, int wi, std::string texName);

    ~TorpedoTube() override;

private:
    bool accuracy();

    void openFire(Vehicle enemy) override;

    void update(std::unique_ptr<WarShip> theChangedSubject) override;

    void attach() override;

    void detach() override;

    bool engage(Vehicle enemy) override;

    void rotate() override;
};


#endif //SEALION_TORPEDOTUBE_H
