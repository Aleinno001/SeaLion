//
// Created by davide on 02/07/21.
//

#ifndef SEALION_TORPEDOTUBE_H
#define SEALION_TORPEDOTUBE_H

#include "Arsenal.h"
#include "WarShip.h"
class TorpedoTube : public Arsenal {
public:
    //TODO implementare
    TorpedoTube(const float range, const int reload, int dispersion, std::shared_ptr<Bullet> type,
                int power, int le, int wi, std::string texName, WarShip &sub);
    ~TorpedoTube() override;
private:
    WarShip &subject_;
    bool accuracy();
    void openFire(Vehicle enemy) override;
    void update(sf::Vector2f &vel,double mx) override;
    void removeMeFromTheList() {
        subject_.detach(std::shared_ptr<Arsenal>(this));
    }
    bool engage(Vehicle enemy) override;
    void rotate() override;
    void resetOrigin() override;
};


#endif //SEALION_TORPEDOTUBE_H

