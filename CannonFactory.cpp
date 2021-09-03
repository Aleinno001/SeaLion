//
// Created by davide on 02/07/21.
//

#include "CannonFactory.h"


std::unique_ptr<Arsenal> CannonFactory::createLight(int posX, int posY, WarShip &subject) const {

    std::shared_ptr<Bullet> b (new Bullet("explosiveBullet",5,8,1.50,0.75,0.75));

    std::unique_ptr<LightCannon> lightCannon(
            new LightCannon(250, 3, 20, std::move(b), 200, 200, posX + 2, posY + 3, 6, 4, "LightCannon",subject));
    return std::move(lightCannon);
}

std::unique_ptr<Arsenal> CannonFactory::createMedium(int posX, int posY, WarShip &subject) const {

    std::shared_ptr<Bullet> b (new Bullet("standardBullet",3,7,1,1,1));
    std::unique_ptr<MediumCannnon> mediumCannnon(
            new MediumCannnon(350, 6, 28, std::move(b), 400, 140, posX + 3, posY + 7, 14, 7, "MediumCannon",subject));
    return std::move(mediumCannnon);
}

std::unique_ptr<Arsenal> CannonFactory::createHeavly(int posX, int posY, WarShip &subject) const {

    std::shared_ptr<Bullet> b (new Bullet("piercingBullet",3,7,0.50,1.25,1.25));
    std::unique_ptr<HeavlyCannon> heavlyCannon(
            new HeavlyCannon(450, 9, 36, std::move(b), 800, 80, posX + 7, posY + 14, 28, 15, "HeavlyCannon",subject));
    return std::move(heavlyCannon);
}
