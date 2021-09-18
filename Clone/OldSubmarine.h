//
// Created by davide on 18/09/21.
//

#ifndef SEALION_OLDSUBMARINE_H
#define SEALION_OLDSUBMARINE_H


class OldSubmarine {
private:
    bool isSubmerged{false};
    int numTorpedoTubes;
public:
    OldSubmarine(int x, int y, float ac, const float maxVel, int hp, int arm,
              std::string nat, int numL, int numH, int numM, int numAA,
              int le, int wi,
              bool col, ShipType sh, ModelType mo, int numTor, bool isSub);
    void submerge();
    bool isSubmerged1() const {
        return isSubmerged;
    }
    int getNumTorpedoTubes() const {
        return numTorpedoTubes;
    }
    void update(bool isDead) override;
    void attach(const std::shared_ptr<Arsenal> &gun) override;
    void detach(const std::shared_ptr<Arsenal> &gun) override;
    void notifyPlanes(sf::Vector2f &vel, double mx) override;
    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void notifyBars(sf::Vector2f &vel, double mx) override;
    void attachBar(const std::shared_ptr<BarInterface> &bar) override;
    void detachBar(const std::shared_ptr<BarInterface> &bar) override;
    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void notifyBarsDamage() override;
    ~OldSubmarine() override{
    };
    // void registerArsenals(std::unique_ptr<Arsenal> observer) override;
    //void removeArsenals(std::unique_ptr<Arsenal> observer) override;
    void notifyArsenals(sf::Vector2f &vel,double mx) override;
    //bool canEngage(std::_List_iterator<std::unique_ptr<WarShip>> target) override;
};


#endif //SEALION_OLDSUBMARINE_H
