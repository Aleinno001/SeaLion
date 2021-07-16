//
// Created by alessandro on 04/07/21.
//

#ifndef SEALION_DICE_H
#define SEALION_DICE_H

#include <ctime>
#include <math.h>


class Dice {
private:
    int numFaces;
public:
    Dice(int num);

    ~Dice() = default;

    int roll(int rolls) const;
};


#endif //SEALION_DICE_H
