# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/augustin/Documents/code/cppBinarySearchTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/augustin/Documents/code/cppBinarySearchTree/build

# Include any dependencies generated for this target.
include CMakeFiles/cppBinarySearchTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cppBinarySearchTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppBinarySearchTree.dir/flags.make

CMakeFiles/cppBinarySearchTree.dir/main.cpp.o: CMakeFiles/cppBinarySearchTree.dir/flags.make
CMakeFiles/cppBinarySearchTree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/augustin/Documents/code/cppBinarySearchTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppBinarySearchTree.dir/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppBinarySearchTree.dir/main.cpp.o -c /home/augustin/Documents/code/cppBinarySearchTree/main.cpp

CMakeFiles/cppBinarySearchTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppBinarySearchTree.dir/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/augustin/Documents/code/cppBinarySearchTree/main.cpp > CMakeFiles/cppBinarySearchTree.dir/main.cpp.i

CMakeFiles/cppBinarySearchTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppBinarySearchTree.dir/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/augustin/Documents/code/cppBinarySearchTree/main.cpp -o CMakeFiles/cppBinarySearchTree.dir/main.cpp.s

# Object files for target cppBinarySearchTree
cppBinarySearchTree_OBJECTS = \
"CMakeFiles/cppBinarySearchTree.dir/main.cpp.o"

# External object files for target cppBinarySearchTree
cppBinarySearchTree_EXTERNAL_OBJECTS =

cppBinarySearchTree: CMakeFiles/cppBinarySearchTree.dir/main.cpp.o
cppBinarySearchTree: CMakeFiles/cppBinarySearchTree.dir/build.make
cppBinarySearchTree: CMakeFiles/cppBinarySearchTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/augustin/Documents/code/cppBinarySearchTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cppBinarySearchTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppBinarySearchTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppBinarySearchTree.dir/build: cppBinarySearchTree

.PHONY : CMakeFiles/cppBinarySearchTree.dir/build

CMakeFiles/cppBinarySearchTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppBinarySearchTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppBinarySearchTree.dir/clean

CMakeFiles/cppBinarySearchTree.dir/depend:
	cd /home/augustin/Documents/code/cppBinarySearchTree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/augustin/Documents/code/cppBinarySearchTree /home/augustin/Documents/code/cppBinarySearchTree /home/augustin/Documents/code/cppBinarySearchTree/build /home/augustin/Documents/code/cppBinarySearchTree/build /home/augustin/Documents/code/cppBinarySearchTree/build/CMakeFiles/cppBinarySearchTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppBinarySearchTree.dir/depend
