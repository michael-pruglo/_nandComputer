# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mickl\ClionProjects\NandComputer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug

# Include any dependencies generated for this target.
include _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/depend.make

# Include the progress variables for this target.
include _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/flags.make

_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.obj: _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/flags.make
_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.obj: _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/includes_CXX.rsp
_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.obj: _deps/googlebenchmark-src/test/user_counters_tabular_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.obj"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-build\test && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\user_counters_tabular_test.dir\user_counters_tabular_test.cc.obj -c C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-src\test\user_counters_tabular_test.cc

_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.i"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-build\test && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-src\test\user_counters_tabular_test.cc > CMakeFiles\user_counters_tabular_test.dir\user_counters_tabular_test.cc.i

_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.s"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-build\test && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-src\test\user_counters_tabular_test.cc -o CMakeFiles\user_counters_tabular_test.dir\user_counters_tabular_test.cc.s

# Object files for target user_counters_tabular_test
user_counters_tabular_test_OBJECTS = \
"CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.obj"

# External object files for target user_counters_tabular_test
user_counters_tabular_test_EXTERNAL_OBJECTS =

_deps/googlebenchmark-build/test/user_counters_tabular_test.exe: _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/user_counters_tabular_test.cc.obj
_deps/googlebenchmark-build/test/user_counters_tabular_test.exe: _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/build.make
_deps/googlebenchmark-build/test/user_counters_tabular_test.exe: _deps/googlebenchmark-build/test/liboutput_test_helper.a
_deps/googlebenchmark-build/test/user_counters_tabular_test.exe: _deps/googlebenchmark-build/src/libbenchmark.a
_deps/googlebenchmark-build/test/user_counters_tabular_test.exe: _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/linklibs.rsp
_deps/googlebenchmark-build/test/user_counters_tabular_test.exe: _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/objects1.rsp
_deps/googlebenchmark-build/test/user_counters_tabular_test.exe: _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable user_counters_tabular_test.exe"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\user_counters_tabular_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/build: _deps/googlebenchmark-build/test/user_counters_tabular_test.exe

.PHONY : _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/build

_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/clean:
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-build\test && $(CMAKE_COMMAND) -P CMakeFiles\user_counters_tabular_test.dir\cmake_clean.cmake
.PHONY : _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/clean

_deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mickl\ClionProjects\NandComputer C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-src\test C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-build\test C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\_deps\googlebenchmark-build\test\CMakeFiles\user_counters_tabular_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/googlebenchmark-build/test/CMakeFiles/user_counters_tabular_test.dir/depend

