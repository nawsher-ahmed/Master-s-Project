# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = "/home/nawsher/Desktop/Project Intermediate/Server"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/nawsher/Desktop/Project Intermediate/Server/build"

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/server.c.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/server.c.o: /home/nawsher/Desktop/Project\ Intermediate/Server/server.c
CMakeFiles/Server.dir/server.c.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/nawsher/Desktop/Project Intermediate/Server/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Server.dir/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Server.dir/server.c.o -MF CMakeFiles/Server.dir/server.c.o.d -o CMakeFiles/Server.dir/server.c.o -c "/home/nawsher/Desktop/Project Intermediate/Server/server.c"

CMakeFiles/Server.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Server.dir/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/nawsher/Desktop/Project Intermediate/Server/server.c" > CMakeFiles/Server.dir/server.c.i

CMakeFiles/Server.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Server.dir/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/nawsher/Desktop/Project Intermediate/Server/server.c" -o CMakeFiles/Server.dir/server.c.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/server.c.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/server.c.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/nawsher/Desktop/Project Intermediate/Server/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server
.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd "/home/nawsher/Desktop/Project Intermediate/Server/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/nawsher/Desktop/Project Intermediate/Server" "/home/nawsher/Desktop/Project Intermediate/Server" "/home/nawsher/Desktop/Project Intermediate/Server/build" "/home/nawsher/Desktop/Project Intermediate/Server/build" "/home/nawsher/Desktop/Project Intermediate/Server/build/CMakeFiles/Server.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Server.dir/depend

