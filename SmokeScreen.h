//
// Created by alessandro on 02/07/21.
//

#ifndef SEALION_SMOKESCREEN_H
#define SEALION_SMOKESCREEN_H

#include "Bonus.h"

class SmokeScreen : public Bonus {

private:
    int uses;
    float duration;
    int posX;
    int posY;
    float diameter;

public:
    //TODO implementare i metodi
    SmokeScreen(WarShip *m, float c, int u, float d, int pX, int pY, float diam) : Bonus(m, c), uses(u),
                                                                                   duration(d), posX(pX),
                                                                                   posY(pY), diameter(diam) {};

    ~SmokeScreen() override;

    int getUses() const;

    float getDuration() const;

    double getPosX() const;

    double getPosY() const;

    float getDiameter() const;

    void activate() override;
};


#endif //SEALION_SMOKESCREEN_H
