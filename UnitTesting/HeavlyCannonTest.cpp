//
// Created by pala on 8/30/21.
//
#include "gtest/gtest.h"
#include "../HeavlyCannon.h"
#include "../AircraftCarrier.h"
#include "../CannonFactory.h"
#include "../Battleship.h"

TEST(HeavlyCannon, Constructor) {
    StandardBullet b;
    std::list<std::unique_ptr<Vehicle>> v;
    int posX = 700;
    int posY = 700;
    sf::Vector2i coordinates;
    coordinates.x = 1000;
    coordinates.y = 1000;
    int shipWidth = 44;
    int shipHeight = 180;
    int numAntiAir = 15;




    std::unique_ptr<Battleship> ironDuke(
            new Battleship(coordinates.x, coordinates.y, 1, 39, 29500, 826,
                           "Uk", 0, 5, 0, numAntiAir,   shipHeight, shipWidth, true,
                           ShipType::Battleship,
                           ModelType::IronDuke, 0));


    std::unique_ptr<HeavlyCannon> heavlyCannon(
            new HeavlyCannon(450, 9, 150, 9, b, 0.5, 200, 80, posX + 7, posY + 14, 28, 15, "HeavlyCannon",*ironDuke));

    ASSERT_EQ(heavlyCannon->getRangeOfFire(),450);
    ASSERT_EQ(heavlyCannon->getReloadTime(),9);
    ASSERT_EQ(heavlyCannon->getAmmoSpeed(),150);
    ASSERT_EQ(heavlyCannon->getMaximumDispersion(),9);
    ASSERT_EQ(heavlyCannon->getAmmoDeceleration(),static_cast<float>(0.5));
    ASSERT_EQ(heavlyCannon->getFirepower(),200);
    ASSERT_EQ(heavlyCannon->getNumAmmo(),80);
    ASSERT_EQ(heavlyCannon->getPos().x,posX+7);
    ASSERT_EQ(heavlyCannon->getPos().y,posY+14);
    ASSERT_EQ(heavlyCannon->getLength(),28);
    ASSERT_EQ( heavlyCannon->getWidth(),15);
    ASSERT_EQ( heavlyCannon->getTextureName(),"HeavlyCannon");












}
