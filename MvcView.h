//
// Created by davide on 11/09/21.
//
#ifndef SEALION_MVCVIEW_H
#define SEALION_MVCVIEW_H
#include "MvcObserver.h"
#include "MvcController.h"
template <typename T,typename D>
class MvcView : public MvcObserver {
private:
    T &model;
    MvcController<T,D> &controller;
    sf::Window &window;
    sf::Texture tx;
    Button &button;
public:
    MvcView(T& model, MvcController<T,D> &controller, sf::Window &window,Button &b): model(model), controller(controller), window(window), button(b) {
        model.addMvcObserver(std::shared_ptr<MvcObserver>(this));
    };
    T &getModel() const{return model;}
    void click(std::shared_ptr<D> target){controller.startUpEngine(target);};
    void updateMvcObserver() override {};
    ~MvcView() override = default;
    Button &getButton() const {return button;}
    MvcView *getInstance(){return this;};
};
#endif //SEALION_MVCVIEW_H
