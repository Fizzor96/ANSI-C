# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/dominik/Prog/AnsiC/ANSI-C/quadratic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dominik/Prog/AnsiC/ANSI-C/quadratic/build

# Include any dependencies generated for this target.
include CMakeFiles/quadraticapp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/quadraticapp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/quadraticapp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quadraticapp.dir/flags.make

CMakeFiles/quadraticapp.dir/main.c.o: CMakeFiles/quadraticapp.dir/flags.make
CMakeFiles/quadraticapp.dir/main.c.o: ../main.c
CMakeFiles/quadraticapp.dir/main.c.o: CMakeFiles/quadraticapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dominik/Prog/AnsiC/ANSI-C/quadratic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/quadraticapp.dir/main.c.o"
	/usr/bin/x86_64-pc-linux-gnu-gcc-11.1.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/quadraticapp.dir/main.c.o -MF CMakeFiles/quadraticapp.dir/main.c.o.d -o CMakeFiles/quadraticapp.dir/main.c.o -c /home/dominik/Prog/AnsiC/ANSI-C/quadratic/main.c

CMakeFiles/quadraticapp.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/quadraticapp.dir/main.c.i"
	/usr/bin/x86_64-pc-linux-gnu-gcc-11.1.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dominik/Prog/AnsiC/ANSI-C/quadratic/main.c > CMakeFiles/quadraticapp.dir/main.c.i

CMakeFiles/quadraticapp.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/quadraticapp.dir/main.c.s"
	/usr/bin/x86_64-pc-linux-gnu-gcc-11.1.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dominik/Prog/AnsiC/ANSI-C/quadratic/main.c -o CMakeFiles/quadraticapp.dir/main.c.s

CMakeFiles/quadraticapp.dir/quadratic.c.o: CMakeFiles/quadraticapp.dir/flags.make
CMakeFiles/quadraticapp.dir/quadratic.c.o: ../quadratic.c
CMakeFiles/quadraticapp.dir/quadratic.c.o: CMakeFiles/quadraticapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dominik/Prog/AnsiC/ANSI-C/quadratic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/quadraticapp.dir/quadratic.c.o"
	/usr/bin/x86_64-pc-linux-gnu-gcc-11.1.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/quadraticapp.dir/quadratic.c.o -MF CMakeFiles/quadraticapp.dir/quadratic.c.o.d -o CMakeFiles/quadraticapp.dir/quadratic.c.o -c /home/dominik/Prog/AnsiC/ANSI-C/quadratic/quadratic.c

CMakeFiles/quadraticapp.dir/quadratic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/quadraticapp.dir/quadratic.c.i"
	/usr/bin/x86_64-pc-linux-gnu-gcc-11.1.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dominik/Prog/AnsiC/ANSI-C/quadratic/quadratic.c > CMakeFiles/quadraticapp.dir/quadratic.c.i

CMakeFiles/quadraticapp.dir/quadratic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/quadraticapp.dir/quadratic.c.s"
	/usr/bin/x86_64-pc-linux-gnu-gcc-11.1.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dominik/Prog/AnsiC/ANSI-C/quadratic/quadratic.c -o CMakeFiles/quadraticapp.dir/quadratic.c.s

# Object files for target quadraticapp
quadraticapp_OBJECTS = \
"CMakeFiles/quadraticapp.dir/main.c.o" \
"CMakeFiles/quadraticapp.dir/quadratic.c.o"

# External object files for target quadraticapp
quadraticapp_EXTERNAL_OBJECTS =

quadraticapp: CMakeFiles/quadraticapp.dir/main.c.o
quadraticapp: CMakeFiles/quadraticapp.dir/quadratic.c.o
quadraticapp: CMakeFiles/quadraticapp.dir/build.make
quadraticapp: CMakeFiles/quadraticapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dominik/Prog/AnsiC/ANSI-C/quadratic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable quadraticapp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quadraticapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quadraticapp.dir/build: quadraticapp
.PHONY : CMakeFiles/quadraticapp.dir/build

CMakeFiles/quadraticapp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quadraticapp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quadraticapp.dir/clean

CMakeFiles/quadraticapp.dir/depend:
	cd /home/dominik/Prog/AnsiC/ANSI-C/quadratic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dominik/Prog/AnsiC/ANSI-C/quadratic /home/dominik/Prog/AnsiC/ANSI-C/quadratic /home/dominik/Prog/AnsiC/ANSI-C/quadratic/build /home/dominik/Prog/AnsiC/ANSI-C/quadratic/build /home/dominik/Prog/AnsiC/ANSI-C/quadratic/build/CMakeFiles/quadraticapp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quadraticapp.dir/depend

