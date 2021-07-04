//
// Created by pala on 7/2/21.
//

#ifndef SEALION_ABSTRACTSHIPFACTORY_H
#define SEALION_ABSTRACTSHIPFACTORY_H


#include "WarShip.h"

enum class ModelType {
    Yamato,
    Musashi,
    Kongo,
    ISE,
    Takao,
    IsuzuNagara,
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
    Papa
}; //TODO Concludere l'aggiunta dei tipi di modelli navali!!

class AbstractShipFactory {
public:
    virtual std::unique_ptr<WarShip> createSubmarine(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createAircraftCarrier(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createCruiser(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createBattleship(ModelType type) = 0;

    virtual std::unique_ptr<WarShip> createDestroyer(ModelType type) = 0;
};


#endif //SEALION_ABSTRACTSHIPFACTORY_H
