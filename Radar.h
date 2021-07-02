//
// Created by davide on 02/07/21.
//

#ifndef SEALION_RADAR_H
#define SEALION_RADAR_H

#include "Bonus.h"

class Radar : public Bonus {

private:
    float radius;
    float duration;
public:
    Radar(WarShip *model, float c, float r, float d) : Bonus(model, c), radius(r), duration(d) {};

    ~Radar() override;

    float getRadius() const;

    float getDuration() const;

    void activate() override;
};


#endif //SEALION_RADAR_H
