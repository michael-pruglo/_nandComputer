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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mickl\ClionProjects\NandComputer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug

# Include any dependencies generated for this target.
include google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/depend.make

# Include the progress variables for this target.
include google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/progress.make

# Include the compile flags for this target's objects.
include google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/flags.make

google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.obj: google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/flags.make
google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.obj: google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/includes_CXX.rsp
google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.obj: ../google_tests_and_benchmarks/hardware_benchmarks/BasicGatesBenchmark.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\google_tests_and_benchmarks && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_benchmark_run.dir\hardware_benchmarks\BasicGatesBenchmark.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\google_tests_and_benchmarks\hardware_benchmarks\BasicGatesBenchmark.cpp

google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\google_tests_and_benchmarks && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\google_tests_and_benchmarks\hardware_benchmarks\BasicGatesBenchmark.cpp > CMakeFiles\google_benchmark_run.dir\hardware_benchmarks\BasicGatesBenchmark.cpp.i

google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\google_tests_and_benchmarks && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\google_tests_and_benchmarks\hardware_benchmarks\BasicGatesBenchmark.cpp -o CMakeFiles\google_benchmark_run.dir\hardware_benchmarks\BasicGatesBenchmark.cpp.s

# Object files for target google_benchmark_run
google_benchmark_run_OBJECTS = \
"CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.obj"

# External object files for target google_benchmark_run
google_benchmark_run_EXTERNAL_OBJECTS =

google_tests_and_benchmarks/google_benchmark_run.exe: google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/hardware_benchmarks/BasicGatesBenchmark.cpp.obj
google_tests_and_benchmarks/google_benchmark_run.exe: google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/build.make
google_tests_and_benchmarks/google_benchmark_run.exe: lib/libgtestd.a
google_tests_and_benchmarks/google_benchmark_run.exe: lib/libgtest_maind.a
google_tests_and_benchmarks/google_benchmark_run.exe: _deps/googlebenchmark-build/src/libbenchmark.a
google_tests_and_benchmarks/google_benchmark_run.exe: lib/libgtestd.a
google_tests_and_benchmarks/google_benchmark_run.exe: google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/linklibs.rsp
google_tests_and_benchmarks/google_benchmark_run.exe: google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/objects1.rsp
google_tests_and_benchmarks/google_benchmark_run.exe: google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable google_benchmark_run.exe"
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\google_tests_and_benchmarks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\google_benchmark_run.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/build: google_tests_and_benchmarks/google_benchmark_run.exe

.PHONY : google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/build

google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/clean:
	cd /d C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\google_tests_and_benchmarks && $(CMAKE_COMMAND) -P CMakeFiles\google_benchmark_run.dir\cmake_clean.cmake
.PHONY : google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/clean

google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mickl\ClionProjects\NandComputer C:\Users\mickl\ClionProjects\NandComputer\google_tests_and_benchmarks C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\google_tests_and_benchmarks C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\google_tests_and_benchmarks\CMakeFiles\google_benchmark_run.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : google_tests_and_benchmarks/CMakeFiles/google_benchmark_run.dir/depend
