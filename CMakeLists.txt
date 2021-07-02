cmake_minimum_required(VERSION 3.19)
project(SeaLion)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(UnitTesting)
set(SOURCE_FILES WarShip.cpp WarShip.h Arsenal.cpp Arsenal.h Bonus.cpp Bonus.h Vehicle.h Vehicle.cpp Submarine.cpp Submarine.h Map.cpp Map.h Battleship.cpp Battleship.h Cruiser.cpp Cruiser.h Destroyer.cpp Destroyer.h AircraftCarrier.cpp AircraftCarrier.h ShipFactory.cpp ShipFactory.h AbstractShipFactory.h LightCannon.cpp LightCannon.h MediumCannon.cpp MediumCannon.h HeavlyCannon.cpp HeavlyCannon.h TorpedoTube.cpp TorpedoTube.h AntiAircraft.cpp AntiAircraft.h ArsenalFactory.h CannonFactory.cpp CannonFactory.h SpecialWeaponFactory.h WeaponFactory.cpp WeaponFactory.h)
add_executable(SeaLion main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(SeaLion core)