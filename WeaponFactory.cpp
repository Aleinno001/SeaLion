//
// Created by davide on 02/07/21.
//

#include "WeaponFactory.h"


std::unique_ptr<Arsenal> WeaponFactory::createSpecialWeapon(WeaponType type,WarShip &subject) const {
    std::shared_ptr<Bullet> b(new Bullet("standardBullet", 3, 7,1,1,1));          //FIXME deve sparare siluri
    if (type == WeaponType::antiAir) {
        std::unique_ptr<AntiAircraft> specialCannon(
                new AntiAircraft(200, 0, 10, b, 1, 4, 4,
                                 "AntiAircraft", subject));
        return std::move(specialCannon);
    } else {
        std::unique_ptr<TorpedoTube> specialCannon(
                new TorpedoTube(250, 3, 5, b, 50, 4, 4, "TorpedoTube", subject));   //TODO sistemare i valori di danno etc
        return std::move(specialCannon);
    }
}
