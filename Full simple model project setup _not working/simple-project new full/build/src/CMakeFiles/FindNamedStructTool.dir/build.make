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
CMAKE_SOURCE_DIR = "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/FindNamedStructTool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/FindNamedStructTool.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/FindNamedStructTool.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/FindNamedStructTool.dir/flags.make

src/CMakeFiles/FindNamedStructTool.dir/main.cpp.o: src/CMakeFiles/FindNamedStructTool.dir/flags.make
src/CMakeFiles/FindNamedStructTool.dir/main.cpp.o: /home/nawsher/Desktop/File\ that\ worked/Not\ working\ yet\ (full)/simple-project\ new\ full/src/main.cpp
src/CMakeFiles/FindNamedStructTool.dir/main.cpp.o: src/CMakeFiles/FindNamedStructTool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/FindNamedStructTool.dir/main.cpp.o"
	cd "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/FindNamedStructTool.dir/main.cpp.o -MF CMakeFiles/FindNamedStructTool.dir/main.cpp.o.d -o CMakeFiles/FindNamedStructTool.dir/main.cpp.o -c "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/src/main.cpp"

src/CMakeFiles/FindNamedStructTool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FindNamedStructTool.dir/main.cpp.i"
	cd "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/src/main.cpp" > CMakeFiles/FindNamedStructTool.dir/main.cpp.i

src/CMakeFiles/FindNamedStructTool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FindNamedStructTool.dir/main.cpp.s"
	cd "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/src/main.cpp" -o CMakeFiles/FindNamedStructTool.dir/main.cpp.s

# Object files for target FindNamedStructTool
FindNamedStructTool_OBJECTS = \
"CMakeFiles/FindNamedStructTool.dir/main.cpp.o"

# External object files for target FindNamedStructTool
FindNamedStructTool_EXTERNAL_OBJECTS =

src/FindNamedStructTool: src/CMakeFiles/FindNamedStructTool.dir/main.cpp.o
src/FindNamedStructTool: src/CMakeFiles/FindNamedStructTool.dir/build.make
src/FindNamedStructTool: src/CMakeFiles/FindNamedStructTool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FindNamedStructTool"
	cd "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FindNamedStructTool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/FindNamedStructTool.dir/build: src/FindNamedStructTool
.PHONY : src/CMakeFiles/FindNamedStructTool.dir/build

src/CMakeFiles/FindNamedStructTool.dir/clean:
	cd "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/FindNamedStructTool.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/FindNamedStructTool.dir/clean

src/CMakeFiles/FindNamedStructTool.dir/depend:
	cd "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full" "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/src" "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build" "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/src" "/home/nawsher/Desktop/File that worked/Not working yet (full)/simple-project new full/build/src/CMakeFiles/FindNamedStructTool.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/CMakeFiles/FindNamedStructTool.dir/depend

