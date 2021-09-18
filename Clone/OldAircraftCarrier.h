//
// Created by davide on 18/09/21.
//

#ifndef SEALION_OLDAIRCRAFTCARRIER_H
#define SEALION_OLDAIRCRAFTCARRIER_H


class OldAircraftCarrier {
private:
    int numPlanes;
    std::list<std::shared_ptr<MvcObserver>> listMvcObservers; //Lista di Viste per design pattern MVC
public:
    int getNumPlanes() const;
public:
    OldAircraftCarrier(int x, int y, float ac, const float maxVel, int hp, int arm,
                    std::string nat, int numL, int numH, int numM, int numAA,
                    int le, int wi,
                    bool col, ShipType sh, ModelType mo, int planes);
    void update(bool isDead) override;
    void attach(const std::shared_ptr<Arsenal> &gun) override;
    void detach(const std::shared_ptr<Arsenal> &gun) override;
    void notifyArsenals(sf::Vector2f &vel,double mx) override;
    void notifyPlanes(sf::Vector2f &vel, double mx) override;
    void attachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void detachPlanes(const std::shared_ptr<Vehicle> &warPlanes) override;
    void notifyBars(sf::Vector2f &vel, double mx) override;
    void notifyBarsDamage() override;
    void attachBar(const std::shared_ptr<BarInterface> &bar) override;
    void detachBar(const std::shared_ptr<BarInterface> &bar) override;
    OldAircraftCarrier& getInstance();
    void notifyMvcObserver() override;
    void addMvcObserver(std::shared_ptr<MvcObserver> o) override;
    void removeMvcObserver(std::shared_ptr<MvcObserver> o) override;
    void searchAndHuntDownEnemyTargets(std::_List_iterator<std::unique_ptr<WarShip>> &target,double dt);
    int HowManyGuns() {
        return arsenalList.size();
    }
    std::list<std::shared_ptr<MvcObserver>> getListMvcObservers();
    ~OldAircraftCarrier() override;
};


#endif //SEALION_OLDAIRCRAFTCARRIER_H
