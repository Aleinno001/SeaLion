//
// Created by pala on 7/2/21.
//

#ifndef SEALION_CRUISER_H
#define SEALION_CRUISER_H


#include "WarShip.h"

class Cruiser : public WarShip {
private:
    int numPlanes;
public:
    Cruiser(int x, int y, float ac, const float maxVel, int hp, int length, int arm, std::string na,
            std::string nat, int numL, int numH, int numM, std::vector<std::unique_ptr<Arsenal>> &arsenalList,
            std::vector<std::unique_ptr<Vehicle>> &vehicleList, const sf::Texture &tex, sf::Sprite sp, int le, int wi,
            bool col, std::string textureName, ShipType sh, ModelType mo, int planes) : WarShip(x, y, ac, maxVel, hp,
                                                                                                length, arm, na, nat,
                                                                                                numL, numH, numM,
                                                                                                arsenalList,
                                                                                                vehicleList, tex, sp,
                                                                                                le, wi, col,
                                                                                                textureName, sh, mo),
                                                                                        numPlanes(planes) {}

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

    ~Cruiser() override;

protected:
    void rotate() override;

    bool canEngage(Vehicle target) override;
};


#endif //SEALION_CRUISER_H
