# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/bash/projects/chameleon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bash/projects/chameleon/build

# Include any dependencies generated for this target.
include chameleon/CMakeFiles/chameleon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include chameleon/CMakeFiles/chameleon.dir/compiler_depend.make

# Include the progress variables for this target.
include chameleon/CMakeFiles/chameleon.dir/progress.make

# Include the compile flags for this target's objects.
include chameleon/CMakeFiles/chameleon.dir/flags.make

chameleon/CMakeFiles/chameleon.dir/http.o: chameleon/CMakeFiles/chameleon.dir/flags.make
chameleon/CMakeFiles/chameleon.dir/http.o: ../chameleon/http.cpp
chameleon/CMakeFiles/chameleon.dir/http.o: chameleon/CMakeFiles/chameleon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bash/projects/chameleon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object chameleon/CMakeFiles/chameleon.dir/http.o"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT chameleon/CMakeFiles/chameleon.dir/http.o -MF CMakeFiles/chameleon.dir/http.o.d -o CMakeFiles/chameleon.dir/http.o -c /home/bash/projects/chameleon/chameleon/http.cpp

chameleon/CMakeFiles/chameleon.dir/http.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chameleon.dir/http.i"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bash/projects/chameleon/chameleon/http.cpp > CMakeFiles/chameleon.dir/http.i

chameleon/CMakeFiles/chameleon.dir/http.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chameleon.dir/http.s"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bash/projects/chameleon/chameleon/http.cpp -o CMakeFiles/chameleon.dir/http.s

chameleon/CMakeFiles/chameleon.dir/urls.o: chameleon/CMakeFiles/chameleon.dir/flags.make
chameleon/CMakeFiles/chameleon.dir/urls.o: ../chameleon/urls.cpp
chameleon/CMakeFiles/chameleon.dir/urls.o: chameleon/CMakeFiles/chameleon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bash/projects/chameleon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object chameleon/CMakeFiles/chameleon.dir/urls.o"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT chameleon/CMakeFiles/chameleon.dir/urls.o -MF CMakeFiles/chameleon.dir/urls.o.d -o CMakeFiles/chameleon.dir/urls.o -c /home/bash/projects/chameleon/chameleon/urls.cpp

chameleon/CMakeFiles/chameleon.dir/urls.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chameleon.dir/urls.i"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bash/projects/chameleon/chameleon/urls.cpp > CMakeFiles/chameleon.dir/urls.i

chameleon/CMakeFiles/chameleon.dir/urls.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chameleon.dir/urls.s"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bash/projects/chameleon/chameleon/urls.cpp -o CMakeFiles/chameleon.dir/urls.s

chameleon/CMakeFiles/chameleon.dir/views.o: chameleon/CMakeFiles/chameleon.dir/flags.make
chameleon/CMakeFiles/chameleon.dir/views.o: ../chameleon/views.cpp
chameleon/CMakeFiles/chameleon.dir/views.o: chameleon/CMakeFiles/chameleon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bash/projects/chameleon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object chameleon/CMakeFiles/chameleon.dir/views.o"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT chameleon/CMakeFiles/chameleon.dir/views.o -MF CMakeFiles/chameleon.dir/views.o.d -o CMakeFiles/chameleon.dir/views.o -c /home/bash/projects/chameleon/chameleon/views.cpp

chameleon/CMakeFiles/chameleon.dir/views.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chameleon.dir/views.i"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bash/projects/chameleon/chameleon/views.cpp > CMakeFiles/chameleon.dir/views.i

chameleon/CMakeFiles/chameleon.dir/views.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chameleon.dir/views.s"
	cd /home/bash/projects/chameleon/build/chameleon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bash/projects/chameleon/chameleon/views.cpp -o CMakeFiles/chameleon.dir/views.s

# Object files for target chameleon
chameleon_OBJECTS = \
"CMakeFiles/chameleon.dir/http.o" \
"CMakeFiles/chameleon.dir/urls.o" \
"CMakeFiles/chameleon.dir/views.o"

# External object files for target chameleon
chameleon_EXTERNAL_OBJECTS =

chameleon/libchameleon.a: chameleon/CMakeFiles/chameleon.dir/http.o
chameleon/libchameleon.a: chameleon/CMakeFiles/chameleon.dir/urls.o
chameleon/libchameleon.a: chameleon/CMakeFiles/chameleon.dir/views.o
chameleon/libchameleon.a: chameleon/CMakeFiles/chameleon.dir/build.make
chameleon/libchameleon.a: chameleon/CMakeFiles/chameleon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bash/projects/chameleon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libchameleon.a"
	cd /home/bash/projects/chameleon/build/chameleon && $(CMAKE_COMMAND) -P CMakeFiles/chameleon.dir/cmake_clean_target.cmake
	cd /home/bash/projects/chameleon/build/chameleon && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chameleon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chameleon/CMakeFiles/chameleon.dir/build: chameleon/libchameleon.a
.PHONY : chameleon/CMakeFiles/chameleon.dir/build

chameleon/CMakeFiles/chameleon.dir/clean:
	cd /home/bash/projects/chameleon/build/chameleon && $(CMAKE_COMMAND) -P CMakeFiles/chameleon.dir/cmake_clean.cmake
.PHONY : chameleon/CMakeFiles/chameleon.dir/clean

chameleon/CMakeFiles/chameleon.dir/depend:
	cd /home/bash/projects/chameleon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bash/projects/chameleon /home/bash/projects/chameleon/chameleon /home/bash/projects/chameleon/build /home/bash/projects/chameleon/build/chameleon /home/bash/projects/chameleon/build/chameleon/CMakeFiles/chameleon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chameleon/CMakeFiles/chameleon.dir/depend

