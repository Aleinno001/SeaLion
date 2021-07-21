//
// Created by davide on 02/07/21.
//

#include "CannonFactory.h"

std::unique_ptr<Arsenal> CannonFactory::createLight(int posX, int posY) const {
    StandardBullet b;
    std::unique_ptr<LightCannon> lightCannon(
            new LightCannon(250, 3, 250, 5, b, 0.3, 50, 200, posX, posY, 6, 4, "LightCannon"));
    return std::move(lightCannon);
}

std::unique_ptr<Arsenal> CannonFactory::createMedium(int posX, int posY) const {
    StandardBullet b;
    std::unique_ptr<MediumCannnon> mediumCannnon(
            new MediumCannnon(350, 6, 200, 7, b, 0.4, 100, 140, posX, posY, 14, 7, "MediumCannon"));
    return std::move(mediumCannnon);
}

std::unique_ptr<Arsenal> CannonFactory::createHeavly(int posX, int posY) const {
    StandardBullet b;
    std::unique_ptr<HeavlyCannon> heavlyCannon(
            new HeavlyCannon(450, 9, 150, 9, b, 0.5, 200, 80, posX, posY, 28, 15, "lightCannon"));
    return std::move(heavlyCannon);
}
