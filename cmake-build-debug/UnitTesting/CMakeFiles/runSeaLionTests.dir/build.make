# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/162/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/162/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pala/CLionProjects/Projects/SeaLion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug

# Include any dependencies generated for this target.
include UnitTesting/CMakeFiles/runSeaLionTests.dir/depend.make
# Include the progress variables for this target.
include UnitTesting/CMakeFiles/runSeaLionTests.dir/progress.make

# Include the compile flags for this target's objects.
include UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make

UnitTesting/CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.o: ../UnitTesting/runAllTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/runAllTests.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/runAllTests.cpp > CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/runAllTests.cpp -o CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.o: ../UnitTesting/GameWorldFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameWorldFixture.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameWorldFixture.cpp > CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameWorldFixture.cpp -o CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.o: ../UnitTesting/GameTileTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameTileTest.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameTileTest.cpp > CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameTileTest.cpp -o CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.o: ../UnitTesting/GameTileFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameTileFixture.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameTileFixture.cpp > CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/GameTileFixture.cpp -o CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.o: ../UnitTesting/BattleshipFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/BattleshipFixture.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/BattleshipFixture.cpp > CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/BattleshipFixture.cpp -o CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.o: ../UnitTesting/DestroyerFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/DestroyerFixture.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/DestroyerFixture.cpp > CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/DestroyerFixture.cpp -o CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.o: ../UnitTesting/SubmarineFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/SubmarineFixture.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/SubmarineFixture.cpp > CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/SubmarineFixture.cpp -o CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.o: ../UnitTesting/BattleshipTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/BattleshipTest.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/BattleshipTest.cpp > CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/BattleshipTest.cpp -o CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.o: ../UnitTesting/DestroyerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/DestroyerTest.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/DestroyerTest.cpp > CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/DestroyerTest.cpp -o CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.o: ../UnitTesting/SubmarineTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/SubmarineTest.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/SubmarineTest.cpp > CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/SubmarineTest.cpp -o CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.o: ../UnitTesting/CruiserFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/CruiserFixture.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/CruiserFixture.cpp > CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/CruiserFixture.cpp -o CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.o: ../UnitTesting/CruiserTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/CruiserTest.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/CruiserTest.cpp > CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/CruiserTest.cpp -o CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.o: ../UnitTesting/AircraftCarrierFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/AircraftCarrierFixture.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/AircraftCarrierFixture.cpp > CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/AircraftCarrierFixture.cpp -o CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.s

UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.o: UnitTesting/CMakeFiles/runSeaLionTests.dir/flags.make
UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.o: ../UnitTesting/AircraftCarrierTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.o"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/AircraftCarrierTest.cpp

UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.i"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/AircraftCarrierTest.cpp > CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.i

UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.s"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/UnitTesting/AircraftCarrierTest.cpp -o CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.s

# Object files for target runSeaLionTests
runSeaLionTests_OBJECTS = \
"CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.o" \
"CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.o"

# External object files for target runSeaLionTests
runSeaLionTests_EXTERNAL_OBJECTS =

UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/runAllTests.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/GameWorldFixture.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileTest.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/GameTileFixture.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipFixture.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerFixture.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineFixture.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/BattleshipTest.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/DestroyerTest.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/SubmarineTest.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserFixture.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/CruiserTest.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierFixture.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/AircraftCarrierTest.cpp.o
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/build.make
UnitTesting/runSeaLionTests: lib/libgtestd.a
UnitTesting/runSeaLionTests: lib/libgtest_maind.a
UnitTesting/runSeaLionTests: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
UnitTesting/runSeaLionTests: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
UnitTesting/runSeaLionTests: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
UnitTesting/runSeaLionTests: libcore.a
UnitTesting/runSeaLionTests: lib/libgtestd.a
UnitTesting/runSeaLionTests: UnitTesting/CMakeFiles/runSeaLionTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable runSeaLionTests"
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runSeaLionTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
UnitTesting/CMakeFiles/runSeaLionTests.dir/build: UnitTesting/runSeaLionTests
.PHONY : UnitTesting/CMakeFiles/runSeaLionTests.dir/build

UnitTesting/CMakeFiles/runSeaLionTests.dir/clean:
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting && $(CMAKE_COMMAND) -P CMakeFiles/runSeaLionTests.dir/cmake_clean.cmake
.PHONY : UnitTesting/CMakeFiles/runSeaLionTests.dir/clean

UnitTesting/CMakeFiles/runSeaLionTests.dir/depend:
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pala/CLionProjects/Projects/SeaLion /home/pala/CLionProjects/Projects/SeaLion/UnitTesting /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/UnitTesting/CMakeFiles/runSeaLionTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : UnitTesting/CMakeFiles/runSeaLionTests.dir/depend

