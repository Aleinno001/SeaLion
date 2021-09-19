//
// Created by pala on 9/18/21.
//

#ifndef SEALION_ANTIAIRCRAFT_H
#define SEALION_ANTIAIRCRAFT_H




class AntiAircraft : public Arsenal {
public:
    //TODO implementare
    AntiAircraft(float range, int reload, int dispersion, std::shared_ptr<Bullet> type,
                 int power, int le, int wi, std::string texName, WarShip &sub);
    ~AntiAircraft() override;
private:
    WarShip &subject_;
    bool airStrafe();
    void openFire(Vehicle enemy) override;
    void update(sf::Vector2f &vel,double mx) override;
    void removeMeFromTheList() {
        subject_.detach(std::shared_ptr<Arsenal>(this));
    }
    bool engage(Vehicle enemy) override;
    void rotate() override;
    bool setUpSprite(std::string textureName) override;
    void resetOrigin() override;
};

#endif //SEALION_ANTIAIRCRAFT_H