# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/farm/Documents/CG/lessons/first

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/farm/Documents/CG/lessons/first/build

# Include any dependencies generated for this target.
include external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/flags.make

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o: external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o: ../external/glfw-3.1.2/tests/sharing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/farm/Documents/CG/lessons/first/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o"
	cd /home/farm/Documents/CG/lessons/first/build/external/glfw-3.1.2/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sharing.dir/sharing.c.o   -c /home/farm/Documents/CG/lessons/first/external/glfw-3.1.2/tests/sharing.c

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/sharing.c.i"
	cd /home/farm/Documents/CG/lessons/first/build/external/glfw-3.1.2/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/farm/Documents/CG/lessons/first/external/glfw-3.1.2/tests/sharing.c > CMakeFiles/sharing.dir/sharing.c.i

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/sharing.c.s"
	cd /home/farm/Documents/CG/lessons/first/build/external/glfw-3.1.2/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/farm/Documents/CG/lessons/first/external/glfw-3.1.2/tests/sharing.c -o CMakeFiles/sharing.dir/sharing.c.s

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.requires:

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.requires

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.provides: external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.requires
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.provides.build
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.provides

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.provides.build: external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o


# Object files for target sharing
sharing_OBJECTS = \
"CMakeFiles/sharing.dir/sharing.c.o"

# External object files for target sharing
sharing_EXTERNAL_OBJECTS =

external/glfw-3.1.2/tests/sharing: external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o
external/glfw-3.1.2/tests/sharing: external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/build.make
external/glfw-3.1.2/tests/sharing: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/tests/sharing: /usr/lib64/librt.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libm.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libX11.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libXrandr.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libXinerama.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libXi.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libXxf86vm.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libXcursor.so
external/glfw-3.1.2/tests/sharing: /usr/lib64/libGL.so
external/glfw-3.1.2/tests/sharing: external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/farm/Documents/CG/lessons/first/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sharing"
	cd /home/farm/Documents/CG/lessons/first/build/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sharing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/build: external/glfw-3.1.2/tests/sharing

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/build

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/requires: external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/sharing.c.o.requires

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/requires

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/clean:
	cd /home/farm/Documents/CG/lessons/first/build/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/sharing.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/clean

external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/depend:
	cd /home/farm/Documents/CG/lessons/first/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/farm/Documents/CG/lessons/first /home/farm/Documents/CG/lessons/first/external/glfw-3.1.2/tests /home/farm/Documents/CG/lessons/first/build /home/farm/Documents/CG/lessons/first/build/external/glfw-3.1.2/tests /home/farm/Documents/CG/lessons/first/build/external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/depend

