//
// Created by alessandro on 12/10/21.
//
#include "Specialty.h"
void Specialty::notifyMvcObserver(){
    for (auto &it: listMvcObservers)
    it->updateMvcObserver();
}