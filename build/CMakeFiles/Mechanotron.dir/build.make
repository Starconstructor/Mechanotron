# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/starconstructor/Code/Mechanotron

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/starconstructor/Code/Mechanotron/build

# Include any dependencies generated for this target.
include CMakeFiles/Mechanotron.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Mechanotron.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Mechanotron.dir/flags.make

CMakeFiles/Mechanotron.dir/Mechanotron.c.o: CMakeFiles/Mechanotron.dir/flags.make
CMakeFiles/Mechanotron.dir/Mechanotron.c.o: ../Mechanotron.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/starconstructor/Code/Mechanotron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Mechanotron.dir/Mechanotron.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Mechanotron.dir/Mechanotron.c.o   -c /home/starconstructor/Code/Mechanotron/Mechanotron.c

CMakeFiles/Mechanotron.dir/Mechanotron.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Mechanotron.dir/Mechanotron.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/starconstructor/Code/Mechanotron/Mechanotron.c > CMakeFiles/Mechanotron.dir/Mechanotron.c.i

CMakeFiles/Mechanotron.dir/Mechanotron.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Mechanotron.dir/Mechanotron.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/starconstructor/Code/Mechanotron/Mechanotron.c -o CMakeFiles/Mechanotron.dir/Mechanotron.c.s

# Object files for target Mechanotron
Mechanotron_OBJECTS = \
"CMakeFiles/Mechanotron.dir/Mechanotron.c.o"

# External object files for target Mechanotron
Mechanotron_EXTERNAL_OBJECTS =

Mechanotron: CMakeFiles/Mechanotron.dir/Mechanotron.c.o
Mechanotron: CMakeFiles/Mechanotron.dir/build.make
Mechanotron: CMakeFiles/Mechanotron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/starconstructor/Code/Mechanotron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Mechanotron"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Mechanotron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Mechanotron.dir/build: Mechanotron

.PHONY : CMakeFiles/Mechanotron.dir/build

CMakeFiles/Mechanotron.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Mechanotron.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Mechanotron.dir/clean

CMakeFiles/Mechanotron.dir/depend:
	cd /home/starconstructor/Code/Mechanotron/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/starconstructor/Code/Mechanotron /home/starconstructor/Code/Mechanotron /home/starconstructor/Code/Mechanotron/build /home/starconstructor/Code/Mechanotron/build /home/starconstructor/Code/Mechanotron/build/CMakeFiles/Mechanotron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Mechanotron.dir/depend
