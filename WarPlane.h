//
// Created by pala on 9/16/21.
//
#ifndef SEALION_WARPLANE_H
#define SEALION_WARPLANE_H

#include "WarShip.h"

class WarPlane : public Vehicle {
protected:
    float currentCoolDown{0};
    const float coolDown{6};
    int numAmmo;
    int ammoDamage;
    std::shared_ptr<WarShip> target;
    bool setUpSprite(const std::string &textureName) override {
        std::string currentDir = ToolBox::GetCurrentWorkingDir();
        std::string unitTestingPath = "UnitTesting";
        std::size_t found = currentDir.find(unitTestingPath);
        if (found != std::string::npos) {
            currentDir.erase(found);
            currentDir.pop_back();
        }
        std::string textPath;
        textPath = currentDir + "/../Res/"+nationality+"/WarPlane/" + textureName + ".png";
        if (!Collision::CreateTextureAndBitmask(texture, textPath)) {
            throw std::runtime_error("Path to tile filename invalid!!");
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, width, length));
        return true;
    }
public:
    WarPlane(float x, float y, float ac, float maxVel, int hp, int le, int wi, bool col, std::string nat, int numAmmo, int ammoDamage,std::string name) : Vehicle(x, y, ac, maxVel, hp, le, wi,col, nat,name),currentCoolDown(currentCoolDown),coolDown(coolDown), numAmmo(numAmmo),ammoDamage(ammoDamage){};
    void setTarget(const std::shared_ptr<WarShip> &tar) {WarPlane::target = tar;}
    virtual void update()=0; //Metodo per design pattern observer tra planes and Warship
    ~WarPlane()=default;
};
#endif //SEALION_WARPLANE_H
