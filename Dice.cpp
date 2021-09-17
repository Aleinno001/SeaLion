//
// Created by alessandro on 04/07/21.
//

#include "Dice.h"

int Dice::roll(int rolls) const {
    int roll;
    int min = 1;
    roll = 0;
    for (int i = 0; i < rolls; i++)
        roll = roll + rand() % (numFaces - min + 1) + min;
    return roll;
}
Dice::Dice(int num, int seedMult) {
    unsigned seed;
    numFaces = num;
    seed = time(nullptr);
    srand(seedMult * seed);
}
