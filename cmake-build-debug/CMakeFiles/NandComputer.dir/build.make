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
include CMakeFiles/NandComputer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NandComputer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NandComputer.dir/flags.make

CMakeFiles/NandComputer.dir/main.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NandComputer.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\main.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\main.cpp

CMakeFiles/NandComputer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\main.cpp > CMakeFiles\NandComputer.dir\main.cpp.i

CMakeFiles/NandComputer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\main.cpp -o CMakeFiles\NandComputer.dir\main.cpp.s

CMakeFiles/NandComputer.dir/tests/Timer.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/tests/Timer.cpp.obj: ../tests/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NandComputer.dir/tests/Timer.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\tests\Timer.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\tests\Timer.cpp

CMakeFiles/NandComputer.dir/tests/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/tests/Timer.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\tests\Timer.cpp > CMakeFiles\NandComputer.dir\tests\Timer.cpp.i

CMakeFiles/NandComputer.dir/tests/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/tests/Timer.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\tests\Timer.cpp -o CMakeFiles\NandComputer.dir\tests\Timer.cpp.s

CMakeFiles/NandComputer.dir/tests/Random.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/tests/Random.cpp.obj: ../tests/Random.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NandComputer.dir/tests/Random.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\tests\Random.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\tests\Random.cpp

CMakeFiles/NandComputer.dir/tests/Random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/tests/Random.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\tests\Random.cpp > CMakeFiles\NandComputer.dir\tests\Random.cpp.i

CMakeFiles/NandComputer.dir/tests/Random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/tests/Random.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\tests\Random.cpp -o CMakeFiles\NandComputer.dir\tests\Random.cpp.s

CMakeFiles/NandComputer.dir/hardware/Adders.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/hardware/Adders.cpp.obj: ../hardware/Adders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NandComputer.dir/hardware/Adders.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\hardware\Adders.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\hardware\Adders.cpp

CMakeFiles/NandComputer.dir/hardware/Adders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/hardware/Adders.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\hardware\Adders.cpp > CMakeFiles\NandComputer.dir\hardware\Adders.cpp.i

CMakeFiles/NandComputer.dir/hardware/Adders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/hardware/Adders.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\hardware\Adders.cpp -o CMakeFiles\NandComputer.dir\hardware\Adders.cpp.s

CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.obj: ../hardware/BasicGates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\hardware\BasicGates.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\hardware\BasicGates.cpp

CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\hardware\BasicGates.cpp > CMakeFiles\NandComputer.dir\hardware\BasicGates.cpp.i

CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\hardware\BasicGates.cpp -o CMakeFiles\NandComputer.dir\hardware\BasicGates.cpp.s

CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.obj: ../tests/TestBasicGates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\tests\TestBasicGates.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\tests\TestBasicGates.cpp

CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\tests\TestBasicGates.cpp > CMakeFiles\NandComputer.dir\tests\TestBasicGates.cpp.i

CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\tests\TestBasicGates.cpp -o CMakeFiles\NandComputer.dir\tests\TestBasicGates.cpp.s

CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.obj: ../tests/TestAdders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\tests\TestAdders.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\tests\TestAdders.cpp

CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\tests\TestAdders.cpp > CMakeFiles\NandComputer.dir\tests\TestAdders.cpp.i

CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\tests\TestAdders.cpp -o CMakeFiles\NandComputer.dir\tests\TestAdders.cpp.s

CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.obj: CMakeFiles/NandComputer.dir/flags.make
CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.obj: ../tests/TestHardware.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NandComputer.dir\tests\TestHardware.cpp.obj -c C:\Users\mickl\ClionProjects\NandComputer\tests\TestHardware.cpp

CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\NandComputer\tests\TestHardware.cpp > CMakeFiles\NandComputer.dir\tests\TestHardware.cpp.i

CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\NandComputer\tests\TestHardware.cpp -o CMakeFiles\NandComputer.dir\tests\TestHardware.cpp.s

# Object files for target NandComputer
NandComputer_OBJECTS = \
"CMakeFiles/NandComputer.dir/main.cpp.obj" \
"CMakeFiles/NandComputer.dir/tests/Timer.cpp.obj" \
"CMakeFiles/NandComputer.dir/tests/Random.cpp.obj" \
"CMakeFiles/NandComputer.dir/hardware/Adders.cpp.obj" \
"CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.obj" \
"CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.obj" \
"CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.obj" \
"CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.obj"

# External object files for target NandComputer
NandComputer_EXTERNAL_OBJECTS =

NandComputer.exe: CMakeFiles/NandComputer.dir/main.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/tests/Timer.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/tests/Random.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/hardware/Adders.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/hardware/BasicGates.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/tests/TestBasicGates.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/tests/TestAdders.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/tests/TestHardware.cpp.obj
NandComputer.exe: CMakeFiles/NandComputer.dir/build.make
NandComputer.exe: CMakeFiles/NandComputer.dir/linklibs.rsp
NandComputer.exe: CMakeFiles/NandComputer.dir/objects1.rsp
NandComputer.exe: CMakeFiles/NandComputer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable NandComputer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NandComputer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NandComputer.dir/build: NandComputer.exe

.PHONY : CMakeFiles/NandComputer.dir/build

CMakeFiles/NandComputer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NandComputer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NandComputer.dir/clean

CMakeFiles/NandComputer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mickl\ClionProjects\NandComputer C:\Users\mickl\ClionProjects\NandComputer C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug C:\Users\mickl\ClionProjects\NandComputer\cmake-build-debug\CMakeFiles\NandComputer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NandComputer.dir/depend

