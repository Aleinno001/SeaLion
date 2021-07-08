//
// Created by pala on 7/2/21.
//

#ifndef SEALION_BATTLESHIP_H
#define SEALION_BATTLESHIP_H


#include "WarShip.h"

class Battleship : public WarShip {
private:
    int numInterceptors;


public:

    Battleship(double x1, double y1, float ac1, const float maxVel1, int hp1, int length1, int arm1,
               std::string na1, std::string nat1, int numL1, int numH1, int numM1,
               std::vector<std::unique_ptr<Arsenal>> &arsenalList1,
               std::vector<std::unique_ptr<Vehicle>> &vehicleList1, double x, double y, float ac,
               const float maxVel, int hp, int length, int arm, std::string na, std::string nat, int numL,
               int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
               std::vector<std::unique_ptr<Vehicle>> &vehicleList, int numInter, sf::Texture tex, sf::Sprite sp, int le,
               int wi,
               bool col, std::string textureName);

    //float calcSpeed() override;

    void attack(Vehicle target) override;

    void calculateDistance(Vehicle target) override;

    void update(bool isDead) override;

    void attach() override;

    void detach() override;

    void stopMove() override;

    void ceaseFire() override;

    void registerArsenals() override;

    void removeArsenals() override;

    void notifyArsenals() override;

    ~Battleship() override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;

public:

};


#endif //SEALION_BATTLESHIP_H
