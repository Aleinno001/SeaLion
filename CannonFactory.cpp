//
// Created by davide on 02/07/21.
//

#include "CannonFactory.h"


std::unique_ptr<ConcreteArsenal> CannonFactory::createLight(int posX, int posY, WarShip &subject){
    std::shared_ptr<Bullet> b (new Bullet("explosiveBullet",5,8,1.50,0.75,0.75));
    std::unique_ptr<ConcreteArsenal> lightCannon(new ConcreteArsenal(250, 3, 20, b, 200, 6, 4, "LightCannon", subject, posX, posY));
    return std::move(lightCannon);
}
std::unique_ptr<ConcreteArsenal> CannonFactory::createMedium(int posX, int posY, WarShip &subject){
    std::shared_ptr<Bullet> b(new Bullet("standardBullet", 3, 7, 1, 1, 1));
    std::unique_ptr<ConcreteArsenal> mediumCannon(new ConcreteArsenal(350, 6, 28, b, 200, 14, 7,"MediumCannon", subject, posX, posY));

    return std::move(mediumCannon);
}
std::unique_ptr<ConcreteArsenal> CannonFactory::createHeavly(int posX, int posY, WarShip &subject){
    std::shared_ptr<Bullet> b(new Bullet("piercingBullet", 3, 7, 0.50, 1.25, 1.25));
    std::unique_ptr<ConcreteArsenal> heavlyCannon(new ConcreteArsenal(450, 9, 36, b, 800, 28, 15,"HeavlyCannon", subject, posX, posY));
    return std::move(heavlyCannon);
}
