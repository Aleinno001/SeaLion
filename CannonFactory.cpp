//
// Created by alessandro on 02/07/21.
//

#include "CannonFactory.h"

std::unique_ptr<Arsenal> CannonFactory::createLight(int posX, int posY) const {
    StandardBullet b;
    std::unique_ptr<LightCannon> lightCannon(
            new LightCannon(250, 3, 250, 5, b, 0.3, 50, 200, posX, posY, 4, 4, "lightCannon"));
    return std::move(lightCannon);
}

std::unique_ptr<Arsenal> CannonFactory::createMedium(int posX, int posY) const {
    StandardBullet b;
    std::unique_ptr<MediumCannnon> mediumCannnon(
            new MediumCannnon(250, 3, 250, 5, b, 0.3, 50, 200, posX, posY, 4, 4, "lightCannon"));
    return std::move(mediumCannnon);
}

std::unique_ptr<Arsenal> CannonFactory::createHeavly(int posX, int posY) const {
    StandardBullet b;
    std::unique_ptr<HeavlyCannon> heavlyCannon(
            new HeavlyCannon(250, 3, 250, 5, b, 0.3, 50, 200, posX, posY, 4, 4, "lightCannon"));
    return std::move(heavlyCannon);
}
