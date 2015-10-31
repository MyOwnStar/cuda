# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/star/Github/cuda/matrix-multiplication/cpu-mult

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/star/Github/cuda/matrix-multiplication/cpu-mult/build

# Include any dependencies generated for this target.
include CMakeFiles/CPUTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPUTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPUTest.dir/flags.make

CMakeFiles/CPUTest.dir/main.cpp.o: CMakeFiles/CPUTest.dir/flags.make
CMakeFiles/CPUTest.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/star/Github/cuda/matrix-multiplication/cpu-mult/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/CPUTest.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CPUTest.dir/main.cpp.o -c /home/star/Github/cuda/matrix-multiplication/cpu-mult/main.cpp

CMakeFiles/CPUTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPUTest.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/star/Github/cuda/matrix-multiplication/cpu-mult/main.cpp > CMakeFiles/CPUTest.dir/main.cpp.i

CMakeFiles/CPUTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPUTest.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/star/Github/cuda/matrix-multiplication/cpu-mult/main.cpp -o CMakeFiles/CPUTest.dir/main.cpp.s

CMakeFiles/CPUTest.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/CPUTest.dir/main.cpp.o.requires

CMakeFiles/CPUTest.dir/main.cpp.o.provides: CMakeFiles/CPUTest.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPUTest.dir/build.make CMakeFiles/CPUTest.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CPUTest.dir/main.cpp.o.provides

CMakeFiles/CPUTest.dir/main.cpp.o.provides.build: CMakeFiles/CPUTest.dir/main.cpp.o

CMakeFiles/CPUTest.dir/cpumult.cpp.o: CMakeFiles/CPUTest.dir/flags.make
CMakeFiles/CPUTest.dir/cpumult.cpp.o: ../cpumult.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/star/Github/cuda/matrix-multiplication/cpu-mult/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/CPUTest.dir/cpumult.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CPUTest.dir/cpumult.cpp.o -c /home/star/Github/cuda/matrix-multiplication/cpu-mult/cpumult.cpp

CMakeFiles/CPUTest.dir/cpumult.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPUTest.dir/cpumult.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/star/Github/cuda/matrix-multiplication/cpu-mult/cpumult.cpp > CMakeFiles/CPUTest.dir/cpumult.cpp.i

CMakeFiles/CPUTest.dir/cpumult.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPUTest.dir/cpumult.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/star/Github/cuda/matrix-multiplication/cpu-mult/cpumult.cpp -o CMakeFiles/CPUTest.dir/cpumult.cpp.s

CMakeFiles/CPUTest.dir/cpumult.cpp.o.requires:
.PHONY : CMakeFiles/CPUTest.dir/cpumult.cpp.o.requires

CMakeFiles/CPUTest.dir/cpumult.cpp.o.provides: CMakeFiles/CPUTest.dir/cpumult.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPUTest.dir/build.make CMakeFiles/CPUTest.dir/cpumult.cpp.o.provides.build
.PHONY : CMakeFiles/CPUTest.dir/cpumult.cpp.o.provides

CMakeFiles/CPUTest.dir/cpumult.cpp.o.provides.build: CMakeFiles/CPUTest.dir/cpumult.cpp.o

CMakeFiles/CPUTest.dir/utils/tools.cpp.o: CMakeFiles/CPUTest.dir/flags.make
CMakeFiles/CPUTest.dir/utils/tools.cpp.o: ../utils/tools.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/star/Github/cuda/matrix-multiplication/cpu-mult/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/CPUTest.dir/utils/tools.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CPUTest.dir/utils/tools.cpp.o -c /home/star/Github/cuda/matrix-multiplication/cpu-mult/utils/tools.cpp

CMakeFiles/CPUTest.dir/utils/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPUTest.dir/utils/tools.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/star/Github/cuda/matrix-multiplication/cpu-mult/utils/tools.cpp > CMakeFiles/CPUTest.dir/utils/tools.cpp.i

CMakeFiles/CPUTest.dir/utils/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPUTest.dir/utils/tools.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/star/Github/cuda/matrix-multiplication/cpu-mult/utils/tools.cpp -o CMakeFiles/CPUTest.dir/utils/tools.cpp.s

CMakeFiles/CPUTest.dir/utils/tools.cpp.o.requires:
.PHONY : CMakeFiles/CPUTest.dir/utils/tools.cpp.o.requires

CMakeFiles/CPUTest.dir/utils/tools.cpp.o.provides: CMakeFiles/CPUTest.dir/utils/tools.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPUTest.dir/build.make CMakeFiles/CPUTest.dir/utils/tools.cpp.o.provides.build
.PHONY : CMakeFiles/CPUTest.dir/utils/tools.cpp.o.provides

CMakeFiles/CPUTest.dir/utils/tools.cpp.o.provides.build: CMakeFiles/CPUTest.dir/utils/tools.cpp.o

# Object files for target CPUTest
CPUTest_OBJECTS = \
"CMakeFiles/CPUTest.dir/main.cpp.o" \
"CMakeFiles/CPUTest.dir/cpumult.cpp.o" \
"CMakeFiles/CPUTest.dir/utils/tools.cpp.o"

# External object files for target CPUTest
CPUTest_EXTERNAL_OBJECTS =

CPUTest: CMakeFiles/CPUTest.dir/main.cpp.o
CPUTest: CMakeFiles/CPUTest.dir/cpumult.cpp.o
CPUTest: CMakeFiles/CPUTest.dir/utils/tools.cpp.o
CPUTest: CMakeFiles/CPUTest.dir/build.make
CPUTest: CMakeFiles/CPUTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable CPUTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPUTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPUTest.dir/build: CPUTest
.PHONY : CMakeFiles/CPUTest.dir/build

CMakeFiles/CPUTest.dir/requires: CMakeFiles/CPUTest.dir/main.cpp.o.requires
CMakeFiles/CPUTest.dir/requires: CMakeFiles/CPUTest.dir/cpumult.cpp.o.requires
CMakeFiles/CPUTest.dir/requires: CMakeFiles/CPUTest.dir/utils/tools.cpp.o.requires
.PHONY : CMakeFiles/CPUTest.dir/requires

CMakeFiles/CPUTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPUTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPUTest.dir/clean

CMakeFiles/CPUTest.dir/depend:
	cd /home/star/Github/cuda/matrix-multiplication/cpu-mult/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/star/Github/cuda/matrix-multiplication/cpu-mult /home/star/Github/cuda/matrix-multiplication/cpu-mult /home/star/Github/cuda/matrix-multiplication/cpu-mult/build /home/star/Github/cuda/matrix-multiplication/cpu-mult/build /home/star/Github/cuda/matrix-multiplication/cpu-mult/build/CMakeFiles/CPUTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPUTest.dir/depend

