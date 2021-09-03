//
// Created by davide on 02/09/21.
//

#include "BulletFactory.h"
#include "StandardBullet.h"
#include "ExplosiveBullet.h"
#include "AABullet.h"
#include "Torpedo.h"
#include "PiercingBullet.h"

std::shared_ptr<Bullet> BulletFactory::createBullet(const std::string &bulletName) {

    if (bulletName == "standardBullet") {
        std::shared_ptr<Bullet> b(new StandardBullet("standardBullet", 3, 7));
        return std::move(b);
    } else  if (bulletName == "explosiveBullet") {
        std::shared_ptr<Bullet> b(new ExplosiveBullet("explosiveBullet", 5, 8));
        return std::move(b);
    } else if (bulletName == "AABullet"){
        //std::shared_ptr<Bullet> b(new AABullet("AABullet", 5, 8));
        // return std::move(b);                                 //FIXME da modificare
    } else  if (bulletName == "Torpedo") {
        //std::shared_ptr<Bullet> b(new Torpedo("Torpedo", 5, 8));
        //return std::move(b);
    } else {
        std::shared_ptr<Bullet> b(new PiercingBullet("piercingBullet", 3, 7));
        return std::move(b);
    }
}
