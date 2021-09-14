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
#include <math.h>
#include <memory>

enum class ShipType {
    Battleship,
    Cruiser,
    AircraftCarrier,
    Destroyer,
    Submarine
};
enum class ModelType {
    Yamato,
    Musashi,
    Kongo,
    ISE,
    Takao,
    IsuzuNagara,
    Ijn,
    Akizuki,
    Fubuki,
    Yukikaze,
    Hiryu,
    Tahio,
    I400,
    typeb1,
    VittorioVeneto,
    AndreaDoria,
    ImperatoreAugusto,
    MichelangeloBuonarroti,
    AlbertoDiGiussano,
    Trento,
    Gorizia,
    Impavido,
    Leone,
    PaoloEmilio,
    GiuseppeGaribaldi,
    Cavour,
    DaVinci,
    Papa,
    Dreadnought,
    IronDuke,
    Hood,
    Lion,
    Danae,
    Belfast,
    Tiger59,
    Campbelltown,
    Gallant,
    Jutland,
    ArkRoyal,
    Indomitable,
    Triton,
    Trenchant,
    NewYork,
    Arizona,
    NorthCarolina,
    Montana,
    StLouis,
    NewOrleans,
    Alaska,
    Mahan,
    Sims,
    Fletcher,
    Ranger,
    Midway,
    Gato,
    Narwhal,
    FranklinDRoosevelt
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

    WarShip(int x, int y, float ac, const float maxVel, int hp, int arm,
            std::string nat, int numL, int numH, int numM, int numAA,
            int le, int wi,
            bool col, ShipType sh, ModelType mo);

    virtual ~WarShip() = default;

    virtual void
    move(sf::Vector2<double> coordinates, double dt);  //Raggiunge il punto desiderato tramite rotazioni e spostamenti

    bool searchTarget(std::_List_iterator<std::unique_ptr<WarShip>> enemyListStart,
                      std::_List_iterator<std::unique_ptr<WarShip>> enemyListEnd,
                      const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector,
                      float dt);  //Cerca un bersaglio nel raggio d'azione se possibile

    //Metodi relativi all'observer

    virtual void notifyArsenals(sf::Vector2f &vel, double mx) = 0;//    Metodi per design pattern observer

    virtual void attach(const std::shared_ptr<Arsenal> &gun) = 0;//    Metodi per design pattern observer

    virtual void detach(const std::shared_ptr<Arsenal> &gun) = 0;//    Metodi per design pattern observer

    virtual void notifyPlanes(sf::Vector2f &vel, double mx) = 0;//    Metodi per design pattern observer

    virtual void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) = 0;//    Metodi per design pattern observer

    virtual void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes)=0;//    Metodi per design pattern observer

    virtual void notifyBars(sf::Vector2f &vel,double mx)=0; //Metodo design pattern observer tra BarInterface e Warship

    virtual void notifyBarsDamage()=0;

    virtual void attachBar(const std::shared_ptr<BarInterface> &bar)=0; //Metodo design pattern observer tra BarInterface e Warship

    virtual void detachBar(const std::shared_ptr<BarInterface> &bar)=0; //Metodo design pattern observer tra BarInterface e Warship

    //Getter

    bool isAir() const;

    void setAir(bool air);

    const int getNumAntiAircraft() const;

    const int getArmour() const;

    const std::string &getName() const;

    const std::string &getNationality() const;

    const int getNumLCannons() const;

    const int getNumMCannons() const;

    const int getNumHCannons() const;

    std::list<std::shared_ptr<BarInterface>> &getBars();

    bool isSelected() const;

    ShipType getShipType() const;

    ModelType getModelType() const;

    bool isConcealed() const;

    std::list<std::shared_ptr<Arsenal>> &getArsenalList();

    const std::list<std::shared_ptr<Vehicle>> &getVehicleList() const;

    const std::string getNationality() {
        return nationality;
    }

    const std::string getName() {
        return name;
    }

    //Setter

    void setConcealed(bool isConcealed);




    void setSelected(bool selected);

protected:

    virtual bool
    canEngage(std::_List_iterator<std::shared_ptr<Arsenal>> iter, std::_List_iterator<std::unique_ptr<WarShip>> target,
              const std::vector<std::vector<std::unique_ptr<GameTile>>> &tileVector);  //Verifica la possibilità di sparare alle navi nemiche

    virtual void
    attack(std::_List_iterator<std::unique_ptr<WarShip>> target, std::_List_iterator<std::shared_ptr<Arsenal>> iter,
           float dt);  //Si occupa di ruotare a sparare alle navi target
};


#endif //SEALION_WARSHIP_H
