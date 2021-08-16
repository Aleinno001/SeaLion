//
// Created by gabriele on 7/1/21.
//

#include "WarShip.h"

const int WarShip::getArmour() const {
    return armour;
}

const std::string &WarShip::getName() const {
    return name;
}

const std::string &WarShip::getNationality() const {
    return nationality;
}

const int WarShip::getNumLCannons() const {
    return numLCannons;
}

const int WarShip::getNumMCannons() const {
    return numMCannons;
}

const int WarShip::getNumHCannons() const {
    return numHCannons;
}


WarShip::WarShip(int x, int y, float ac, const float maxVel, int hp, int arm,
                 std::string nat, int numL, int numH, int numM, int numAA,
                 std::list<std::unique_ptr<Vehicle>> &vehicle, int le, int wi,
                 bool col, ShipType sh, ModelType mo) : Vehicle(x, y, ac, maxVel, hp,
                                                                le, wi, col, nat),
                                                        armour(arm),
                                                        numLCannons(numL),
                                                        numHCannons(numH), numMCannons(numM), numAntiAircraft(numAA),
                                                        shipType(sh), modelType(mo) {
    /*for (auto const& itArsenal : arsenal) {
         arsenalList=itArsenal;
     }*/


}

ShipType WarShip::getShipType() const {
    return shipType;
}

ModelType WarShip::getModelType() const {
    return modelType;
}

std::list<std::shared_ptr<Arsenal>> &WarShip::getArsenalList() {
    return arsenalList;
}

std::list<std::unique_ptr<Vehicle>> &WarShip::getVehicleList() {
    return vehicleList;
}

void WarShip::move(sf::Vector2i coordinates) {
/*
    //TODO implementare lo spostamento
    //sprite.setPosition(coordinates.x,coordinates.y);


    float dx =   coordinates.x-posX ;
    float dy =   coordinates.y-posY ;

    float rotation = (-atan2(dx,dy)) * 180 / M_PI;





    sprite.rotate((rotation+180)/60);

    //sprite.setPosition(coordinates.x,coordinates.y);

    //
    // sprite.move(0.0008*(dx/sqrt((2*maxSpeed/acceleration)))/60,0.0008*(dy/sqrt((2*maxSpeed/acceleration))));
    sf::Vector2f nextPos;

    nextPos = std::(sprite.getPosition(),coordinates,maxSpeed/60);
    */
double mx;
    if(coordinates.x < sprite.getPosition().x){
        if(coordinates.y< sprite.getPosition().y){
            //secondo quadrante


        }else{
            //terzo quadrante


        }
    }else if(coordinates.y<sprite.getPosition().y){
        //primo quandrante
        mx = (coordinates.y-sprite.getPosition().y)/(coordinates.x -sprite.getPosition().x);
        mx = atan(mx);
        mx = 90 - mx;



    }else{
        //quarto quadrante
    }

}


