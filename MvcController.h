//
// Created by pala on 9/11/21.
//
#ifndef SEALION_MVCCONTROLLER_H
#define SEALION_MVCCONTROLLER_H
#include <utility>
template <typename T>
class MvcController {
public:
    explicit MvcController(T &mod) : model(mod) {};
    void startUpEngine(std::shared_ptr<T> &target){
        model.searchAndHuntDownEnemyTargets(target);
    };
    T &getModel() const{
        return model;
    };
private:
    T &model;
};
#endif //SEALION_MVCCONTROLLER_H
