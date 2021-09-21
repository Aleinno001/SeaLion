//
// Created by davide on 11/09/21.
//
#ifndef SEALION_MVCVIEW_H
#define SEALION_MVCVIEW_H
#include "MvcObserver.h"
#include "MvcController.h"
#include "Button.h"
template <typename T>
class MvcView : public MvcObserver {
private:

    T &model;
    MvcController<T> &controller;
    sf::Window &window;
    sf::Texture tx;
    bool buttonClickAbility;
public:
    MvcView(T& model, MvcController<T> &controller, sf::Window &window): model(model), controller(controller), window(window),buttonClickAbility(false) {
        model.addMvcObserver(std::shared_ptr<MvcObserver>(this));
    };
    T &getModel() const{
        return model;
    };
    void click(std::shared_ptr<T> &target,double dt){
        controller.startUpEngine(target,dt);
    };
     void updateMvcObserver() override {
        buttonClickAbility = false;
    };
    virtual ~MvcView() = default;
    bool isButtonClickable() const{
        return isButtonClickable;
    };
    MvcView *getInstance(){
        return this;
    };
    bool checkButtonClick(sf::Vector2f clickPos, Button &b) {
        bool result = false;
        if (b.getSprite().getGlobalBounds().contains(clickPos)) {
            result = true;
        }
        return result;
    };
};
#endif //SEALION_MVCVIEW_H
