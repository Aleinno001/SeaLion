//
// Created by davide on 02/07/21.
//

#ifndef SEALION_SONAR_H
#define SEALION_SONAR_H

#include "Bonus.h"

class Sonar : public Bonus {

private:
    float radius;
    float duration;

public:
    Sonar(WarShip *m, float c, float r, float d) : Bonus(m, c), radius(r), duration(d) {};

    ~Sonar() override;

    float getRadius() const;

    float getDuration() const;

    void activate() override;
};


#endif //SEALION_SONAR_H
