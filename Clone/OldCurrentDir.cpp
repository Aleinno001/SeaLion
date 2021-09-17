//
// Created by alessandro on 17/09/21.
//

#include "OldCurrentDir.h"

std::string CurrentDir::GetCurrentWorkingDir() {
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
}
