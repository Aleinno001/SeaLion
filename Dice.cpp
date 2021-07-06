//
// Created by davide on 04/07/21.
//

#include "Dice.h"

int Dice::roll(int rolls) const {
    int roll;
    int min = 1;

    unsigned seed;
    seed = time(0);
    srand(seed);

    roll = 0;

    for (int i = 0; i < rolls; i++)
        roll = roll + rand() % (numFaces - min + 1) + min;


    return roll;
}
