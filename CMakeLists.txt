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
set(SOURCE_FILES  WarShip.h Arsenal.h Vehicle.h ShipFactory.cpp ShipFactory.h AbstractShipFactory.h  ArsenalFactory.h CannonFactory.cpp CannonFactory.h SpecialWeaponFactory.h WeaponFactory.cpp WeaponFactory.h Observer.h Dice.cpp Dice.h AbstractAirplaneFactory.h AirplaneFactory.cpp AirplaneFactory.h GameTile.cpp GameTile.h GameWorld.cpp GameWorld.h Bullet.cpp Bullet.h Collision.cpp Collision.h AABullet.cpp AABullet.h Torpedo.cpp Torpedo.h BarInterface.cpp BarInterface.h LifeBar.cpp LifeBar.h MvcSubject.h MvcObserver.h MvcController.h MvcView.h Button.cpp Button.h ToolBox.cpp ToolBox.h WarPlane.h Clone/OldCurrentDir.cpp Clone/OldCurrentDir.h ConcreteWarShip.cpp ConcreteWarShip.h ConcreteWarPlane.cpp ConcreteWarPlane.h ConcreteArsenal.cpp ConcreteArsenal.h LambdaFunction.cpp LambdaFunction.h AircraftCarrier.cpp AircraftCarrier.h AircraftCarrierSpecialty.h)
add_executable(SeaLion main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(SeaLion core sfml-graphics sfml-window sfml-system)