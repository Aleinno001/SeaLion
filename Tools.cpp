//
// Created by alessandro on 21/09/21.
//

#include "Tools.h"
float Tools::getElapsedTime() {
    return dt.getElapsedTime().asSeconds();
}

void Tools::reset() {

    dt.restart();

}
