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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/out

# Include any dependencies generated for this target.
include CMakeFiles/class2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/class2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/class2.dir/flags.make

CMakeFiles/class2.dir/main.cpp.o: CMakeFiles/class2.dir/flags.make
CMakeFiles/class2.dir/main.cpp.o: /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vaavaav/MIEI/3ano/2semestre/cg/fp2/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/class2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/class2.dir/main.cpp.o -c /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/src/main.cpp

CMakeFiles/class2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/class2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/src/main.cpp > CMakeFiles/class2.dir/main.cpp.i

CMakeFiles/class2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/class2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/src/main.cpp -o CMakeFiles/class2.dir/main.cpp.s

# Object files for target class2
class2_OBJECTS = \
"CMakeFiles/class2.dir/main.cpp.o"

# External object files for target class2
class2_EXTERNAL_OBJECTS =

class2: CMakeFiles/class2.dir/main.cpp.o
class2: CMakeFiles/class2.dir/build.make
class2: /usr/lib/libGL.so
class2: /usr/lib/libGLU.so
class2: /usr/lib/libglut.so
class2: /usr/lib/libXmu.so
class2: /usr/lib/libXi.so
class2: CMakeFiles/class2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vaavaav/MIEI/3ano/2semestre/cg/fp2/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable class2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/class2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/class2.dir/build: class2

.PHONY : CMakeFiles/class2.dir/build

CMakeFiles/class2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/class2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/class2.dir/clean

CMakeFiles/class2.dir/depend:
	cd /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/src /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/src /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/out /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/out /home/vaavaav/MIEI/3ano/2semestre/cg/fp2/out/CMakeFiles/class2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/class2.dir/depend

