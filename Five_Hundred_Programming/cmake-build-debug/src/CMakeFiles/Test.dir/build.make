# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lshm/Documents/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lshm/Documents/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Test.dir/flags.make

src/CMakeFiles/Test.dir/Test.cpp.o: src/CMakeFiles/Test.dir/flags.make
src/CMakeFiles/Test.dir/Test.cpp.o: ../src/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Test.dir/Test.cpp.o"
	cd /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/Test.cpp.o -c /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/src/Test.cpp

src/CMakeFiles/Test.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/Test.cpp.i"
	cd /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/src/Test.cpp > CMakeFiles/Test.dir/Test.cpp.i

src/CMakeFiles/Test.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/Test.cpp.s"
	cd /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/src/Test.cpp -o CMakeFiles/Test.dir/Test.cpp.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/Test.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

src/Test: src/CMakeFiles/Test.dir/Test.cpp.o
src/Test: src/CMakeFiles/Test.dir/build.make
src/Test: /usr/local/lib/libgtest.a
src/Test: /usr/local/lib/libgtest_main.a
src/Test: /usr/local/lib/libgtest.a
src/Test: src/CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test"
	cd /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Test.dir/build: src/Test

.PHONY : src/CMakeFiles/Test.dir/build

src/CMakeFiles/Test.dir/clean:
	cd /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Test.dir/clean

src/CMakeFiles/Test.dir/depend:
	cd /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/src /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/src /home/lshm/CLionProjects/Train_Coding/Five_Hundred_Programming/cmake-build-debug/src/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Test.dir/depend

