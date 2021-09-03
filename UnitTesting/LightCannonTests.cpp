//
// Created by pala on 8/24/21.
//

#include "gtest/gtest.h"
#include "../LightCannon.h"
#include "../AircraftCarrier.h"
#include "../CannonFactory.h"

TEST(LightCannon, Constructor) {


    int posX = 700;
    int posY = 700;
    sf::Vector2i coordinates;
    coordinates.x = 1000;
    coordinates.y = 1000;
    int shipWidth = 44;
    int shipHeight = 180;
    CannonFactory factory;



    std::unique_ptr<AircraftCarrier> GiuseppeGaribaldi(
            new AircraftCarrier(coordinates.x, coordinates.y, 1, 56, 14150, 114, "Italy", 3, 0, 0, 0, shipHeight,
                                shipWidth,
                                true,
                                ShipType::AircraftCarrier, ModelType::GiuseppeGaribaldi, 6));




    std::shared_ptr<Bullet> b(new StandardBullet("standardBullet", 3, 7));

    std::unique_ptr<LightCannon> lightCannon(
            new LightCannon(250, 3, 20, std::move(b), 50, 200, posX + 2, posY + 3, 6, 4, "LightCannon",*GiuseppeGaribaldi));

    ASSERT_EQ(lightCannon->getRangeOfFire(),250);
    ASSERT_EQ(lightCannon->getReloadTime(),3);
    ASSERT_EQ(lightCannon->getAmmoSpeed(),20);
    ASSERT_EQ(lightCannon->getAmmoType(),b);
    ASSERT_EQ(lightCannon->getMaximumDispersion(),5);
    ASSERT_EQ(lightCannon->getAmmoDeceleration(),static_cast<float>(0.3));
    ASSERT_EQ(lightCannon->getFirepower(),50);
    ASSERT_EQ(lightCannon->getNumAmmo(),200);
    ASSERT_EQ(lightCannon->getPos().x,posX+2);
    ASSERT_EQ(lightCannon->getPos().y,posY+3);
    ASSERT_EQ(lightCannon->getLength(),6);
    ASSERT_EQ( lightCannon->getWidth(),4);
    ASSERT_EQ( lightCannon->getTextureName(),"LightCannon");












}
