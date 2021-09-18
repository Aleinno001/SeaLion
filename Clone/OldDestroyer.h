//
// Created by davide on 18/09/21.
//

#ifndef SEALION_OLDDESTROYER_H
#define SEALION_OLDDESTROYER_H


class c {
private:
    int numTorpedoTubes;
public:
    OldDestroyer(int x, int y, float ac, const float maxVel, int hp, int arm,
              std::string nat, int numL, int numH, int numM, int numAA,
              int le, int wi,
              bool col, ShipType sh, ModelType mo, int torpedo);
    int getNumTorpedoTubes() const;
    void update(bool isDead) override;
    void attach(const std::shared_ptr<Arsenal> &gun) override;
    void detach(const std::shared_ptr<Arsenal> &gun) override;
    void notifyPlanes(sf::Vector2f &vel, double mx) override;
    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void notifyBars(sf::Vector2f &vel, double mx) override;
    void notifyBarsDamage() override;
    void attachBar(const std::shared_ptr<BarInterface> &bar) override;
    void detachBar(const std::shared_ptr<BarInterface> &bar) override;
    //void registerArsenals(std::unique_ptr<Arsenal> observer) override;
    //void removeArsenals(std::unique_ptr<Arsenal> observer) override;
    void notifyArsenals(sf::Vector2f &vel,double mx) override;
    ~Destroyer() override;
    bool setUpSprite(std::string textureName) override;
    //bool canEngage(std::_List_iterator<std::unique_ptr<WarShip>> target) override;
};


#endif //SEALION_OLDDESTROYER_H
