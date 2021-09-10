//
// Created by pala on 8/24/21.
//
#include "gtest/gtest.h"
#include "../MediumCannon.h"

#include "../Cruiser.h"
#include "../CannonFactory.h"
TEST(MediumCannon, Constructor) {


    std::list<std::unique_ptr<Vehicle>> v;
    int posX = 700;
    int posY = 700;
    sf::Vector2i coordinates;
    coordinates.x = 1000;
    coordinates.y = 1000;
    int shipWidth = 44;
    int shipHeight = 180;
    CannonFactory factory;
    int antiAir = 10;


   

    std::unique_ptr<Cruiser> takao(new Cruiser(coordinates.x, coordinates.y, 3, 66, 15500, 237,
                                               "Japan", 4, 0, 5, antiAir, shipHeight, shipWidth, true,
                                               ShipType::Cruiser,
                                               ModelType::Takao, 2));


    std::shared_ptr<Bullet> b(new Bullet("Bullet", 3, 7,1,1,1));

    std::unique_ptr<MediumCannnon> mediumCannon(
            new MediumCannnon(350, 6, 28, std::move(b), 140, posX + 3, posY + 7, 14, 7, "MediumCannon",*takao));
    
    ASSERT_EQ(mediumCannon->getRangeOfFire(),350);
    ASSERT_EQ(mediumCannon->getReloadTime(),6);
    ASSERT_EQ(mediumCannon->getMaximumDispersion(),28);
    ASSERT_EQ(mediumCannon->getAmmoType(),b);
    ASSERT_EQ(mediumCannon->getFirepower(),100);

    ASSERT_EQ(mediumCannon->getPos().x,posX+3);
    ASSERT_EQ(mediumCannon->getPos().y,posY+7);
    ASSERT_EQ(mediumCannon->getLength(),14);
    ASSERT_EQ( mediumCannon->getWidth(),7);
    ASSERT_EQ( mediumCannon->getTextureName(),"MediumCannon");

}