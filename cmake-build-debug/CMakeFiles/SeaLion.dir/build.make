# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/158/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/158/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pala/CLionProjects/Projects/SeaLion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SeaLion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SeaLion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SeaLion.dir/flags.make

CMakeFiles/SeaLion.dir/main.cpp.o: CMakeFiles/SeaLion.dir/flags.make
CMakeFiles/SeaLion.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SeaLion.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SeaLion.dir/main.cpp.o -c /home/pala/CLionProjects/Projects/SeaLion/main.cpp

CMakeFiles/SeaLion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SeaLion.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pala/CLionProjects/Projects/SeaLion/main.cpp > CMakeFiles/SeaLion.dir/main.cpp.i

CMakeFiles/SeaLion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SeaLion.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pala/CLionProjects/Projects/SeaLion/main.cpp -o CMakeFiles/SeaLion.dir/main.cpp.s

# Object files for target SeaLion
SeaLion_OBJECTS = \
"CMakeFiles/SeaLion.dir/main.cpp.o"

# External object files for target SeaLion
SeaLion_EXTERNAL_OBJECTS =

SeaLion: CMakeFiles/SeaLion.dir/main.cpp.o
SeaLion: CMakeFiles/SeaLion.dir/build.make
SeaLion: libcore.a
SeaLion: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
SeaLion: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
SeaLion: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
SeaLion: CMakeFiles/SeaLion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SeaLion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SeaLion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SeaLion.dir/build: SeaLion

.PHONY : CMakeFiles/SeaLion.dir/build

CMakeFiles/SeaLion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SeaLion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SeaLion.dir/clean

CMakeFiles/SeaLion.dir/depend:
	cd /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pala/CLionProjects/Projects/SeaLion /home/pala/CLionProjects/Projects/SeaLion /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug /home/pala/CLionProjects/Projects/SeaLion/cmake-build-debug/CMakeFiles/SeaLion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SeaLion.dir/depend

