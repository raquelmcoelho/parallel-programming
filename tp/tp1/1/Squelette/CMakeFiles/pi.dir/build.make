# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette

# Include any dependencies generated for this target.
include CMakeFiles/pi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pi.dir/flags.make

CMakeFiles/pi.dir/src/pi.c.o: CMakeFiles/pi.dir/flags.make
CMakeFiles/pi.dir/src/pi.c.o: src/pi.c
CMakeFiles/pi.dir/src/pi.c.o: CMakeFiles/pi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pi.dir/src/pi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pi.dir/src/pi.c.o -MF CMakeFiles/pi.dir/src/pi.c.o.d -o CMakeFiles/pi.dir/src/pi.c.o -c /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette/src/pi.c

CMakeFiles/pi.dir/src/pi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pi.dir/src/pi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette/src/pi.c > CMakeFiles/pi.dir/src/pi.c.i

CMakeFiles/pi.dir/src/pi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pi.dir/src/pi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette/src/pi.c -o CMakeFiles/pi.dir/src/pi.c.s

# Object files for target pi
pi_OBJECTS = \
"CMakeFiles/pi.dir/src/pi.c.o"

# External object files for target pi
pi_EXTERNAL_OBJECTS =

bin/pi: CMakeFiles/pi.dir/src/pi.c.o
bin/pi: CMakeFiles/pi.dir/build.make
bin/pi: CMakeFiles/pi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/pi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pi.dir/build: bin/pi
.PHONY : CMakeFiles/pi.dir/build

CMakeFiles/pi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pi.dir/clean

CMakeFiles/pi.dir/depend:
	cd /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette /home/raquel/Documents/2Semester/parallele/tp/tp1/1/Squelette/CMakeFiles/pi.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pi.dir/depend

