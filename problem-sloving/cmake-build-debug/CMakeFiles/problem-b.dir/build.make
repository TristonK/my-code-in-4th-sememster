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
CMAKE_COMMAND = /home/kuangsl/Downloads/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kuangsl/Downloads/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kuangsl/my-code-in-4th-sememster/problem-sloving

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kuangsl/my-code-in-4th-sememster/problem-sloving/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/problem-b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problem-b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problem-b.dir/flags.make

CMakeFiles/problem-b.dir/4-8b.cpp.o: CMakeFiles/problem-b.dir/flags.make
CMakeFiles/problem-b.dir/4-8b.cpp.o: ../4-8b.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kuangsl/my-code-in-4th-sememster/problem-sloving/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problem-b.dir/4-8b.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problem-b.dir/4-8b.cpp.o -c /home/kuangsl/my-code-in-4th-sememster/problem-sloving/4-8b.cpp

CMakeFiles/problem-b.dir/4-8b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem-b.dir/4-8b.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kuangsl/my-code-in-4th-sememster/problem-sloving/4-8b.cpp > CMakeFiles/problem-b.dir/4-8b.cpp.i

CMakeFiles/problem-b.dir/4-8b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem-b.dir/4-8b.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kuangsl/my-code-in-4th-sememster/problem-sloving/4-8b.cpp -o CMakeFiles/problem-b.dir/4-8b.cpp.s

# Object files for target problem-b
problem__b_OBJECTS = \
"CMakeFiles/problem-b.dir/4-8b.cpp.o"

# External object files for target problem-b
problem__b_EXTERNAL_OBJECTS =

problem-b: CMakeFiles/problem-b.dir/4-8b.cpp.o
problem-b: CMakeFiles/problem-b.dir/build.make
problem-b: CMakeFiles/problem-b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kuangsl/my-code-in-4th-sememster/problem-sloving/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problem-b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problem-b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problem-b.dir/build: problem-b

.PHONY : CMakeFiles/problem-b.dir/build

CMakeFiles/problem-b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/problem-b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/problem-b.dir/clean

CMakeFiles/problem-b.dir/depend:
	cd /home/kuangsl/my-code-in-4th-sememster/problem-sloving/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kuangsl/my-code-in-4th-sememster/problem-sloving /home/kuangsl/my-code-in-4th-sememster/problem-sloving /home/kuangsl/my-code-in-4th-sememster/problem-sloving/cmake-build-debug /home/kuangsl/my-code-in-4th-sememster/problem-sloving/cmake-build-debug /home/kuangsl/my-code-in-4th-sememster/problem-sloving/cmake-build-debug/CMakeFiles/problem-b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/problem-b.dir/depend

