//
// Created by davide on 02/07/21.
//

#include "CannonFactory.h"

std::unique_ptr<Arsenal> CannonFactory::createLight(int posX, int posY, WarShip &subject) const {
    StandardBullet b;
    std::unique_ptr<LightCannon> lightCannon(
            new LightCannon(250, 3, 250, 5, b, 0.3, 50, 200, posX + 2, posY + 3, 6, 4, "LightCannon", subject));
    return std::move(lightCannon);
}

std::unique_ptr<Arsenal> CannonFactory::createMedium(int posX, int posY, WarShip &subject) const {
    StandardBullet b;
    std::unique_ptr<MediumCannnon> mediumCannnon(
            new MediumCannnon(350, 6, 200, 7, b, 0.4, 100, 140, posX + 3, posY + 7, 14, 7, "MediumCannon", subject));
    return std::move(mediumCannnon);
}

std::unique_ptr<Arsenal> CannonFactory::createHeavly(int posX, int posY, WarShip &subject) const {
    StandardBullet b;
    std::unique_ptr<HeavlyCannon> heavlyCannon(
            new HeavlyCannon(450, 9, 150, 9, b, 0.5, 200, 80, posX + 7, posY + 14, 28, 15, "HeavlyCannon", subject));
    return std::move(heavlyCannon);
}
