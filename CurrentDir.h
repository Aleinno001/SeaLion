//
// Created by alessandro on 20/07/21.
//

#ifndef SEALION_CURRENTDIR_H
#define SEALION_CURRENTDIR_H

#include <stdio.h>
#include <unistd.h>
#include <string>

#define GetCurrentDir getcwd

class CurrentDir {
public:
    static std::string GetCurrentWorkingDir();
};


#endif //SEALION_CURRENTDIR_H