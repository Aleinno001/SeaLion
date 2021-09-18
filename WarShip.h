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
#include "WarPlane.h"
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
    Sims,Fletcher,Ranger,Midway,Gato,Narwhal,FranklinDRoosevelt
};
class WarShip : public Vehicle {
protected:
    ShipType shipType;
    ModelType modelType;
    const int armour;
    const std::string name;
    const int numLCannons;
    const int numMCannons;
    const int numHCannons;
    const int numAntiAircraft;
    bool concealed;
    bool selected {false};
    std::list<std::shared_ptr<Arsenal>> arsenalList;
    std::list<std::shared_ptr<WarPlane>> planeList;
    std::list<std::shared_ptr<BarInterface>> bars;
    std::list<std::shared_ptr<WarShip>> enemyList;
    sf::Vector2f targetCoordinates;
public:
    WarShip(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string &nat,ShipType shipType, ModelType modelType, const int armour, std::string name, const int numLCannons,const int numMCannons, const int numHCannons, const int numAntiAircraft, bool concealed, bool selected,bool air, std::list<std::shared_ptr<Arsenal>> &arsenalList,std::list<std::shared_ptr<WarPlane>> &plaList,std::list<std::shared_ptr<BarInterface>> &bars) : Vehicle(x, y, ac, maxVel, hp, le, wi, col, nat),shipType(shipType), modelType(modelType),armour(armour), name(std::move(name)),numLCannons(numLCannons), numMCannons(numMCannons),numHCannons(numHCannons),numAntiAircraft(numAntiAircraft),concealed(concealed), selected(selected),arsenalList(arsenalList),planeList(plaList),bars(bars) {}
    virtual void notifyArsenals() const = 0;//Metodi per design pattern observer
    virtual void attach(const std::shared_ptr<Arsenal> &gun) = 0;//Metodi per design pattern observer
    virtual void detach(const std::shared_ptr<Arsenal> &gun) = 0;//Metodi per design pattern observer
    virtual void notifyPlanes() const = 0;//Metodi per design pattern observer
    virtual void attachPlanes(const std::shared_ptr<WarPlane> &warPlanes) = 0;//Metodi per design pattern observer
    virtual void detachPlanes(const std::shared_ptr<WarPlane> &warPlanes) = 0;//Metodi per design pattern observer
    virtual void notifyBars() const =0; //Metodo design pattern observer tra BarInterface e Warship
    virtual void notifyBarsDamage() const =0;
    virtual void attachBar(const std::shared_ptr<BarInterface> &bar)=0;//Metodo design pattern observer tra BarInterface e Warship
    virtual void detachBar(const std::shared_ptr<BarInterface> &bar)=0;//Metodo design pattern observer tra BarInterface e Warship
    ShipType getShipType() const {return shipType;}
    void setShipType(ShipType type) { WarShip::shipType = type;}
    ModelType getModelType() const {return modelType;}
    void setModelType(ModelType modelType) {WarShip::modelType = modelType;}
    int getArmour() const {return armour;}
    const std::string &getName() const {return name;}
    int getNumLCannons() const {return numLCannons;}
    int getNumMCannons() const {return numMCannons;}
    int getNumHCannons() const {return numHCannons;}
    int getNumAntiAircraft() const {return numAntiAircraft;}
    bool isConcealed() const {return concealed;}
    void setConcealed(bool concealed) {WarShip::concealed = concealed;}
    bool isSelected() const {return selected;}
    void setSelected(bool selected) {WarShip::selected = selected;}
    const std::list<std::shared_ptr<Arsenal>> &getArsenalList() const {return arsenalList;}
    void setArsenalList(const std::list<std::shared_ptr<Arsenal>> &arsenalList) {WarShip::arsenalList = arsenalList;}
    const std::list<std::shared_ptr<WarPlane>> &getPlaneList() const {return planeList;}
    void setVehicleList(const std::list<std::shared_ptr<WarPlane>> &plaList) {WarShip::planeList = plaList;}
    const std::list<std::shared_ptr<BarInterface>> &getBars() const {return bars;}
    void setBars(const std::list<std::shared_ptr<BarInterface>> &bars) {WarShip::bars = bars;}
    const sf::Vector2f &getTargetCoordinates() const {return targetCoordinates;}
    void setTargetCoordinates(const sf::Vector2f &targetCoordinates) {WarShip::targetCoordinates = targetCoordinates;}
    virtual ~WarShip() = 0;
};
#endif //SEALION_WARSHIP_H
