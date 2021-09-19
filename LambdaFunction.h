//
// Created by davide on 19/09/21.
//

#ifndef SEALION_LAMBDAFUNCTION_H
#define SEALION_LAMBDAFUNCTION_H

#include "GameWorld.h"
#include <SFML/Graphics/RenderWindow.hpp>

namespace LambdaFunction {
    auto searchAirplane = [](sf::RenderWindow &window, GameWorld &gameWorld) {
        while (window.isOpen()) {
            float distance;
            for (auto &iter: gameWorld.getAlliedFleet()) {
                for (auto &iterEnemy: gameWorld.getEnemyFleet()) {
                    if (iter->getShipType() == ShipType::AircraftCarrier) {
                        for (auto &iterPlane: iterEnemy->getVehicleList()) {
                            distance = sqrt(
                                    pow(iterPlane->getSprite().getPosition().x - iter->getSprite().getPosition().x, 2) +
                                    pow(iterPlane->getSprite().getPosition().y - iter->getSprite().getPosition().y, 2));
                            for (auto &iterAntiAir: iter.get()->getArsenalList()) {
                                std::cerr << distance << std::endl;
                                if (iterAntiAir->getTextureName() == "AntiAircraft" &&
                                    distance <= iterAntiAir->getRangeOfFire()) {
                                    iter.get()->antiAirAttack(iterPlane, iterAntiAir);
                                }
                            }
                            if (iterPlane.get()->getHp() <= 0) {
                                iterPlane.get()->setDeath(true);
                                iter.get()->detachPlanes(iterPlane);
                            }
                        }
                    }
                }
            }
        }
    };
    //FIXME da sistemare il sistema di incaglio delle navi e il danno da speronamento + se una barca muore l'altra non si può muovere
    auto f = [](std::list<iteratorPositions> fullNavyCollision, GameWorld &gameWorld, int tileDim,
                sf::RenderWindow &window) { //Scorre la lista di iteratori che puntano ad ogni nave di gioco e ogni sprite di ogni nave verrà controllata con ogni sprite di nave tranne se stessa per verificare l'avvenuta collisione
        while (window.isOpen()) {
            for (auto iter = fullNavyCollision.begin(); iter != fullNavyCollision.end(); ++iter) {
                for (auto &iterSecond: fullNavyCollision) {
                    if (iter->it->get() != iterSecond.it->get()) {
                        if (Collision::PixelPerfectTest(iter->it->get()->getSprite(), iterSecond.it->get()->getSprite()) &&
                            !(iter->it->get()->isDeath() || iterSecond.it->get()->isDeath())) {
                            iter->it->get()->setCollision(false);
                            iterSecond.it->get()->setCollision(false);
                        }
                    }
                }
                //controlla le eventuali collisioni ai bordi della finestra di gioco
                if (((iter->it->get()->getSprite().getPosition().x -
                      iter->it->get()->getSprite().getLocalBounds().width / 2) < 0) ||
                    ((iter->it->get()->getSprite().getPosition().y -
                      iter->it->get()->getSprite().getLocalBounds().height / 2) < 0) ||
                    ((iter->it->get()->getSprite().getPosition().x +
                      iter->it->get()->getSprite().getLocalBounds().width / 2) > window.getSize().x) ||
                    ((iter->it->get()->getSprite().getPosition().y +
                      iter->it->get()->getSprite().getLocalBounds().height / 2) > window.getSize().y)) {
                    iter->it->get()->setCollision(false);
                }
            }
            //controllo cllisioni con blocchi di terra
            for (auto &iterNavy: fullNavyCollision) {
                for (int row = 0; row < (gameWorld.getMapHeight() / tileDim); row++) {
                    for (int column = 0; column < (gameWorld.getMapWidth() / tileDim); column++) {
                        if (gameWorld.tiles[row][column]->getTileType() == TileType::Dirt &&
                            Collision::PixelPerfectTest(iterNavy.it->get()->getSprite(),
                                                        gameWorld.tiles[row][column]->getSprite())) {//Se il blocco è di terra e se avviene la collisione
                            iterNavy.it->get()->setCollision(false);
                            gameWorld.tiles[row][column]->setIsPassable(false);
                        }
                    }
                }
            }
        }
    };
    auto tilesCheckAndDeath = [](sf::RenderWindow &window, GameWorld &gameWorld,
                                 std::list<iteratorPositions> &fullNavyCollision,
                                 int tileDim) { //thread per il controllo e l'applicazione degli effetti tiles
        bool enteredFog = false;
        while (window.isOpen()) {
            for (auto &itNaval: fullNavyCollision) {
                enteredFog = false;
                if (itNaval.it->get()->getHp() > 0) {
                    for (int row = 0; row < (gameWorld.getMapHeight() / tileDim); row++)
                        for (int column = 0; column < (gameWorld.getMapWidth() / tileDim); column++) {
                            if (gameWorld.tiles[row][column]->getTileType() == TileType::Wave &&
                                //applica i relativi effetti se la tile è di mare mosso
                                Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                            gameWorld.tiles[row][column]->getSprite())) {
                                itNaval.it->get()->setConcealed(false);
                                itNaval.it->get()->setCurrentSpeed(itNaval.it->get()->getMaxSpeed() * 0.80);
                            } else if (gameWorld.tiles[row][column]->getTileType() == TileType::Whirlpool &&
                                       //applica i seguenti effetti se la tile è di tipo muninello
                                       Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                                   gameWorld.tiles[row][column]->getSprite())) {
                                itNaval.it->get()->setConcealed(false);
                                itNaval.it->get()->setDamage(itNaval.it->get()->getHp() * 0.00003);
                                itNaval.it->get()->notifyBarsDamage();
                            } else if (gameWorld.tiles[row][column]->getTileType() == TileType::Fog &&
                                       //applica i seguenti effetti se la tile è di nebbia
                                       Collision::PixelPerfectTest(itNaval.it->get()->getSprite(),
                                                                   gameWorld.tiles[row][column]->getSprite())) {
                                itNaval.it->get()->setConcealed(true);
                                enteredFog = true;
                            }
                        }
                } else {                                                //controlla se la nave è distrutta e applica i relativi effetti
                    itNaval.it->get()->setCollision(true);
                    itNaval.it->get()->setDeath(true);
                    for (auto &itCannons: itNaval.it->get()->getArsenalList()) {
                        itCannons->getAmmoType()->setArrived(true);
                        //FIXME itCannons->removeMeFromTheList();
                    }
                }
                if (!enteredFog) {
                    itNaval.it->get()->setConcealed(
                            false); //effetti contrari alla nebbia applicati se la nave non si trova sulla nebbia
                }
            }
        }

    };
    auto checkHit = [](std::list<iteratorPositions> &fullNavy, sf::Window &window) {
        while (window.isOpen()) {
            for (auto &iteratorNavy: fullNavy) {
                for (auto &iteratorTarget: fullNavy) {
                    if (iteratorNavy.it != iteratorTarget.it) {
                        for (auto &iteratorCannons: iteratorNavy.it->get()->getArsenalList()) { // controlla le collisoni tra i proiettili e tutte le navi permettendo il fuoco amico
                            if (iteratorCannons->getTextureName() != "AntiAircraft" &&
                                iteratorCannons->getTextureName() != "TorpedoTube" &&
                                !iteratorCannons->getAmmoType()->isArrived()) {
                                if (Collision::PixelPerfectTest(iteratorCannons->getAmmoType()->getSprite(),
                                                                iteratorTarget.it->get()->getSprite()) &&
                                    !iteratorTarget.it->get()->isDeath()) {
                                    double directDamage = 0;
                                    Dice critical(3, iteratorCannons->getAmmoType()->getSprite().getPosition().y);
                                    if (iteratorCannons->getTextureName() ==
                                        "HeavlyCannon") {        //Applica gli effetti del cannone pesante se la nave spara col cannone pesante
                                        if (((critical.roll(1) - 1) *
                                             ((800 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                              //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                              ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                               (iteratorCannons->getAmmoType()->getSpeed() *
                                                iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                            iteratorTarget.it->get()->getArmour()) {
                                            directDamage =
                                                    (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                    iteratorCannons->getFirepower();
                                        }
                                    } else if (iteratorCannons->getTextureName() ==
                                               "MediumCannon") { //Applica gli effetti del cannone pesante se la nave spara col cannone medio
                                        if (((critical.roll(1) - 1) *
                                             ((400 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                              //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                              ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                               (iteratorCannons->getAmmoType()->getSpeed() *
                                                iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                            iteratorTarget.it->get()->getArmour()) {
                                            directDamage =
                                                    (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                    iteratorCannons->getFirepower();
                                        }
                                    } else {  //Applica gli effetti del cannone pesante se la nave spara col cannone leggero
                                        if (((critical.roll(1) - 1) *
                                             ((200 * iteratorCannons->getAmmoType()->getPenetrationMult()) *
                                              //calcolo del livello di prenetrazione armatura e dinamica casualità con tiro di dado
                                              ((iteratorCannons->getAmmoType()->getCurrentSpeed()) /
                                               (iteratorCannons->getAmmoType()->getSpeed() *
                                                iteratorCannons->getAmmoType()->getSpeedMult())))) >
                                            iteratorTarget.it->get()->getArmour()) {
                                            directDamage =
                                                    (critical.roll(1) - 1) * iteratorCannons->getAmmoType()->getDmgMult() *
                                                    iteratorCannons->getFirepower();
                                        }
                                    }
                                    iteratorCannons->getAmmoType()->hit();
                                    iteratorTarget.it->get()->setDamage(directDamage);
                                    iteratorTarget.it->get()->notifyBarsDamage();
                                }
                            }
                        }
                    }
                }
            }
        }
    };
};


#endif //SEALION_LAMBDAFUNCTION_H
