//
// Created by alessandro on 20/07/21.
//

#include "CurrentDir.h"

std::string CurrentDir::GetCurrentWorkingDir() {
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}
