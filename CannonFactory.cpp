//
// Created by davide on 02/07/21.
//

#include "CannonFactory.h"

std::unique_ptr<Arsenal> CannonFactory::createLight(int posX, int posY,WarShip &subject) const {
    std::shared_ptr<Bullet> b(new StandardBullet("standardBullet", 3, 7));

    std::unique_ptr<LightCannon> lightCannon(
            new LightCannon(250, 3, 5, std::move(b), 50, 200, posX + 2, posY + 3, 6, 4, "LightCannon",subject));
    return std::move(lightCannon);
}

std::unique_ptr<Arsenal> CannonFactory::createMedium(int posX, int posY,WarShip &subject) const {
    std::shared_ptr<Bullet> b(new StandardBullet("standardBullet", 3, 7));
    std::unique_ptr<MediumCannnon> mediumCannnon(
            new MediumCannnon(350, 6, 7, std::move(b), 100, 140, posX + 3, posY + 7, 14, 7, "MediumCannon",subject));
    return std::move(mediumCannnon);
}

std::unique_ptr<Arsenal> CannonFactory::createHeavly(int posX, int posY,WarShip &subject) const {
    std::shared_ptr<Bullet> b(new StandardBullet("standardBullet", 3, 7));
    std::unique_ptr<HeavlyCannon> heavlyCannon(
            new HeavlyCannon(450, 9, 9, std::move(b), 200, 80, posX + 7, posY + 14, 28, 15, "HeavlyCannon",subject));
    return std::move(heavlyCannon);
}
