//
// Created by gabriele on 7/1/21.
//
#ifndef SEALION_WARSHIP_H
#define SEALION_WARSHIP_H
#include <string>
#include <utility>
#include <vector>
#include <list>
#include "Vehicle.h"
#include "Arsenal.h"
#include "GameTile.h"
#include "BarInterface.h"
#include <math.h>
#include <memory>
enum class ShipType {
    Battleship,Cruiser,AircraftCarrier,Destroyer,Submarine
};
enum class ModelType {
    Yamato,Musashi,Kongo,ISE,Takao,IsuzuNagara,Ijn,Akizuki,Fubuki,Yukikaze,Hiryu,Tahio,I400,typeb1,VittorioVeneto,
    AndreaDoria,ImperatoreAugusto,MichelangeloBuonarroti,AlbertoDiGiussano,Trento,Gorizia,Impavido,Leone,PaoloEmilio,
    GiuseppeGaribaldi,Cavour,DaVinci,Papa,Dreadnought,IronDuke,Hood,Lion,Danae,Belfast,Tiger59,Campbelltown,Gallant,
    Jutland,ArkRoyal,Indomitable,Triton,Trenchant,NewYork,Arizona,NorthCarolina,Montana,StLouis,NewOrleans,Alaska,Mahan,
    Sims,Fletcher,Midway,Gato,Narwhal,FranklinDRoosevelt
};
class WarShip : public Vehicle {
protected:
    float dmX;
    ShipType shipType;
    ModelType modelType;
    const int armour;
    const int numLCannons;
    const int numMCannons;
    const int numHCannons;
    const int numAntiAircraft;
    bool concealed;
    bool selected {false};
    std::list<std::shared_ptr<Arsenal>> arsenalList;
    std::list<std::shared_ptr<BarInterface>> bars;
    std::list<std::shared_ptr<WarShip>> enemyList;
    sf::Vector2f targetCoordinates;
    bool setUpSprite(const std::string &textureName) override;
public:
    WarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string nat,ShipType shipType, ModelType modelType,int armour, std::string name,int numLCannons,int numMCannons, int numHCannons,int numAntiAircraft) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat,name),shipType(shipType), modelType(modelType),armour(armour),numLCannons(numLCannons), numMCannons(numMCannons),numHCannons(numHCannons),numAntiAircraft(numAntiAircraft), dmX(0) {}
    virtual void notifyArsenals() const = 0;//Metodi per design pattern observer
    virtual void attach(std::shared_ptr<Arsenal> gun) = 0;//Metodi per design pattern observer
    virtual void detach(std::shared_ptr<Arsenal> gun) = 0;//Metodi per design pattern observer
    virtual void notifyBars() const =0; //Metodo design pattern observer tra BarInterface e Warship
    virtual void notifyBarsDamage() const =0;
    virtual void attachBar(std::shared_ptr<BarInterface> bar)=0;//Metodo design pattern observer tra BarInterface e Warship
    ShipType getShipType() const {return shipType;}
    int getArmour() const {return armour;}
    bool isConcealed() const {return concealed;}
    void setConcealed(bool concealed) {WarShip::concealed = concealed;}
    float getDmX() const {return dmX;}
    bool isSelected() const {return selected;}
    void setSelected(bool selected) {WarShip::selected = selected;}
    std::list<std::shared_ptr<Arsenal>> &getArsenalList(){return arsenalList;}
    std::list<std::shared_ptr<BarInterface>> &getBars() {return bars;}
    void setTargetCoordinates(const sf::Vector2f &targetCoordinates) {WarShip::targetCoordinates = targetCoordinates;}
    const std::list<std::shared_ptr<WarShip>> &getEnemyList() const {return enemyList;}
    void setEnemyList(const std::list<std::shared_ptr<WarShip>> &enemyList) {WarShip::enemyList = enemyList;}
    ~WarShip()=default;
};
#endif //SEALION_WARSHIP_H
