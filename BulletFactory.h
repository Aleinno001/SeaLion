//
// Created by davide on 02/09/21.
//

#ifndef SEALION_BULLETFACTORY_H
#define SEALION_BULLETFACTORY_H


#include <memory>
#include "Bullet.h"

class BulletFactory {
public:
    std::shared_ptr<Bullet> createBullet (const std::string& bulletName);
};


#endif //SEALION_BULLETFACTORY_H
