set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
cmake_minimum_required(VERSION 3.5)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES runAllTests.cpp GameWorldFixture.cpp GameTileTest.cpp GameTileFixture.cpp BattleshipFixture.cpp DestroyerFixture.cpp SubmarineFixture.cpp BattleshipTest.cpp DestroyerTest.cpp SubmarineTest.cpp CruiserFixture.cpp CruiserTest.cpp AircraftCarrierFixture.cpp AircraftCarrierTest.cpp ../Collision.cpp ../Collision.h LightCannonFixture.cpp LightCannonTests.cpp MediumCannonFixture.cpp MediumCannonTests.cpp HeavlyCannonFixture.cpp HeavlyCannonTest.cpp BomberFixture.cpp BomberTest.cpp FighterFixture.cpp FighterTest.cpp TorpedoBomberFixture.cpp TorpedoBomberTest.cpp MvcControllerFixture.cpp MvcControllerTest.cpp MvcViewFixture.cpp MvcViewTest.cpp ../WarPlane.h ../ConcreteWarPlane.cpp ../ConcreteWarPlane.h)
add_executable(runSeaLionTests ${TEST_SOURCE_FILES})
target_link_libraries(runSeaLionTests gtest gtest_main sfml-graphics sfml-window sfml-system core)


