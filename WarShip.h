//
// Created by gabriele on 7/1/21.
//
#ifndef SEALION_WARSHIP_H
#define SEALION_WARSHIP_H
#include <string>
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
    bool air{false};
    std::list<std::shared_ptr<Arsenal>> arsenalList;
    std::list<std::shared_ptr<Vehicle>> vehicleList;
    std::list<std::shared_ptr<BarInterface>> bars;
public:
    virtual const void notifyArsenals() const = 0;//Metodi per design pattern observer
    virtual const void attach(const std::shared_ptr<Arsenal> &gun) = 0;//Metodi per design pattern observer
    virtual const void detach(const std::shared_ptr<Arsenal> &gun) = 0;//Metodi per design pattern observer
    virtual const void notifyPlanes() const = 0;//Metodi per design pattern observer
    virtual const void attachPlanes(const std::shared_ptr<WarPlane> &warPlanes) = 0;//Metodi per design pattern observer
    virtual const void detachPlanes(const std::shared_ptr<WarPlane> &warPlanes) =0;//Metodi per design pattern observer
    virtual const void notifyBars() const=0; //Metodo design pattern observer tra BarInterface e Warship
    virtual const void notifyBarsDamage() const=0;
    virtual const void attachBar(const std::shared_ptr<BarInterface> &bar)=0;//Metodo design pattern observer tra BarInterface e Warship
    virtual const void detachBar(const std::shared_ptr<BarInterface> &bar)=0;//Metodo design pattern observer tra BarInterface e Warship
    virtual const bool isAir() const = 0;
    virtual const void setAir(bool air)=0;
    virtual const int getNumAntiAircraft() const=0;
    virtual const int getArmour() const=0;
    virtual const std::string &getName() const=0;
    virtual const int getNumLCannons() const=0;
    virtual const int getNumMCannons() const=0;
    virtual const int getNumHCannons() const=0;
    virtual const std::list<std::shared_ptr<BarInterface>> &getBars() const=0;
    virtual const bool isSelected() const=0;
    virtual const ShipType getShipType() const=0;
    virtual const ModelType getModelType() const=0;
    virtual const bool isConcealed() const=0;
    virtual std::list<std::shared_ptr<Arsenal>> &getArsenalList() const=0;
    virtual std::list<std::shared_ptr<Vehicle>> &getVehicleList() const=0;
    virtual const void setConcealed(bool isConcealed)=0;
    virtual ~WarShip() = 0;
};
#endif //SEALION_WARSHIP_H
