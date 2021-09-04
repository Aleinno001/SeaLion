cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
project(SeaLion)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if (SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif ()

add_subdirectory(UnitTesting)
set(SOURCE_FILES WarShip.cpp WarShip.h Arsenal.cpp Arsenal.h Bonus.cpp Bonus.h Vehicle.h Vehicle.cpp Submarine.cpp Submarine.h Battleship.cpp Battleship.h Cruiser.cpp Cruiser.h Destroyer.cpp Destroyer.h AircraftCarrier.cpp AircraftCarrier.h ShipFactory.cpp ShipFactory.h AbstractShipFactory.h LightCannon.cpp LightCannon.h MediumCannon.cpp MediumCannon.h HeavlyCannon.cpp HeavlyCannon.h TorpedoTube.cpp TorpedoTube.h AntiAircraft.cpp AntiAircraft.h ArsenalFactory.h CannonFactory.cpp CannonFactory.h SpecialWeaponFactory.h WeaponFactory.cpp WeaponFactory.h Radar.cpp Radar.h QuickRepair.cpp QuickRepair.h Sonar.cpp Sonar.h FireExtinguisher.cpp FireExtinguisher.h SpeedBoost.cpp SpeedBoost.h SmokeScreen.cpp SmokeScreen.h View.cpp View.h Observer.h AbstractBonusFactory.h BonusFactory.cpp BonusFactory.h Dice.cpp Dice.h Bomber.cpp Bomber.h Fighter.cpp Fighter.h TorpedoBomber.cpp TorpedoBomber.h AbstractAirplaneFactory.h AirplaneFactory.cpp AirplaneFactory.h GameTile.cpp GameTile.h GameWorld.cpp GameWorld.h Bullet.cpp Bullet.h CurrentDir.cpp CurrentDir.h Collision.cpp Collision.h AABullet.cpp AABullet.h Torpedo.cpp Torpedo.h BarInterface.cpp BarInterface.h LifeBar.cpp LifeBar.h Explosion.cpp Explosion.h)
add_executable(SeaLion main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(SeaLion core sfml-graphics sfml-window sfml-system)