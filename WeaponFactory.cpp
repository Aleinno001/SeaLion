//
// Created by davide on 02/07/21.
//

#include "WeaponFactory.h"


std::unique_ptr<Arsenal> WeaponFactory::createSpecialWeapon(WeaponType type,WarShip &subject) const {
    std::shared_ptr<Bullet> b(new StandardBullet("standardBullet", 3, 7));          //FIXME deve sparare siluri
    if (type == WeaponType::antiAir) {
        std::unique_ptr<AntiAircraft> specialCannon(
                new AntiAircraft(250, 3, 5, b, 50, 200, 4, 4,
                                 "AntiAircraft",subject));  //TODO sistemare i valori di danno etc
        return std::move(specialCannon);
    } else {
        std::unique_ptr<TorpedoTube> specialCannon(
                new TorpedoTube(250, 3, 5, b,  50, 200, 4, 4, "TorpedoTube",subject));
        return std::move(specialCannon);
    }
}
