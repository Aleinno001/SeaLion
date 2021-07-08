//
// Created by pala on 7/2/21.
//

#ifndef SEALION_DESTROYER_H
#define SEALION_DESTROYER_H


#include "WarShip.h"

class Destroyer : public WarShip {
private:
    int numTorpedoTubes;
public:

    Destroyer(double x, double y, float ac, const float maxVel, int hp, int length, int arm, std::string na,
              std::string nat, int numL, int numH, int numM,
              std::vector<std::unique_ptr<Arsenal>> &arsenalList,
              std::vector<std::unique_ptr<Vehicle>> &vehicleList, sf::Texture tex, sf::Sprite sp, int le, int wi,
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

    ~Destroyer() override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;
};


#endif //SEALION_DESTROYER_H
