//
// Created by pala on 02/07/21.
//

#include "WeaponFactory.h"


std::unique_ptr<Arsenal> WeaponFactory::createSpecialWeapon(WeaponType type, int posX, int posY) const {
    StandardBullet b;
    if (type == WeaponType::antiAir) {
        std::unique_ptr<AntiAircraft> specialCannon(
                new AntiAircraft(250, 3, 250, 5, b, 0.3, 50, 200, posX, posY, 4, 4, "lightCannon"));
        return std::move(specialCannon);
    } else {
        std::unique_ptr<TorpedoTube> specialCannon(
                new TorpedoTube(250, 3, 250, 5, b, 0.3, 50, 200, posX, posY, 4, 4, "lightCannon"));
        return std::move(specialCannon);
    }
}
