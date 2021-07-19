//
// Created by alessandro on 02/07/21.
//

#include "WeaponFactory.h"


std::unique_ptr<Arsenal> WeaponFactory::createSpecialWeapon(WeaponType type) const {
    StandardBullet b;
    if (type == WeaponType::antiAir) {
        std::unique_ptr<AntiAircraft> specialCannon(
                new AntiAircraft(250, 3, 250, 5, b, 0.3, 50, 200, 4, 4, "AntiAircraft"));
        return std::move(specialCannon);
    } else {
        std::unique_ptr<TorpedoTube> specialCannon(
                new TorpedoTube(250, 3, 250, 5, b, 0.3, 50, 200, 4, 4, "TorpedoTube"));
        return std::move(specialCannon);
    }
}
