cmake_minimum_required(VERSION 3.19)
project(SeaLion)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(UnitTesting)
set(SOURCE_FILES WarShip.cpp WarShip.h Arsenal.cpp Arsenal.h Bonus.cpp Bonus.h Destroyer.cpp Destroyer.h Vehicle.h Vehicle.cpp Radar.cpp Radar.h QuickRepair.cpp QuickRepair.h Sonar.cpp Sonar.h FireExtinguisher.cpp FireExtinguisher.h SpeedBoost.cpp SpeedBoost.h SmokeScreen.cpp SmokeScreen.h)
add_executable(SeaLion main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(SeaLion core)