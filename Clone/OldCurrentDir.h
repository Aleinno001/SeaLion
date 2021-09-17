//
// Created by alessandro on 17/09/21.
//

#ifndef SEALION_OLDCURRENTDIR_H
#define SEALION_OLDCURRENTDIR_H

#include <stdio.h>
#include <unistd.h>
#include <string>

#define GetCurrentDir getcwd

class CurrentDir {
public:
    static std::string GetCurrentWorkingDir();  //Speciale metodo per ottenere la working directory attuale
};
#endif //SEALION_OLDCURRENTDIR_H
