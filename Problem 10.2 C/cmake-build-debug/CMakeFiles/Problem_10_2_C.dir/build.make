# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Problem_10_2_C.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Problem_10_2_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Problem_10_2_C.dir/flags.make

CMakeFiles/Problem_10_2_C.dir/main.c.obj: CMakeFiles/Problem_10_2_C.dir/flags.make
CMakeFiles/Problem_10_2_C.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Problem_10_2_C.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Problem_10_2_C.dir\main.c.obj -c "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\main.c"

CMakeFiles/Problem_10_2_C.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Problem_10_2_C.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\main.c" > CMakeFiles\Problem_10_2_C.dir\main.c.i

CMakeFiles/Problem_10_2_C.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Problem_10_2_C.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\main.c" -o CMakeFiles\Problem_10_2_C.dir\main.c.s

# Object files for target Problem_10_2_C
Problem_10_2_C_OBJECTS = \
"CMakeFiles/Problem_10_2_C.dir/main.c.obj"

# External object files for target Problem_10_2_C
Problem_10_2_C_EXTERNAL_OBJECTS =

Problem_10_2_C.exe: CMakeFiles/Problem_10_2_C.dir/main.c.obj
Problem_10_2_C.exe: CMakeFiles/Problem_10_2_C.dir/build.make
Problem_10_2_C.exe: CMakeFiles/Problem_10_2_C.dir/linklibs.rsp
Problem_10_2_C.exe: CMakeFiles/Problem_10_2_C.dir/objects1.rsp
Problem_10_2_C.exe: CMakeFiles/Problem_10_2_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Problem_10_2_C.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Problem_10_2_C.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Problem_10_2_C.dir/build: Problem_10_2_C.exe
.PHONY : CMakeFiles/Problem_10_2_C.dir/build

CMakeFiles/Problem_10_2_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Problem_10_2_C.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Problem_10_2_C.dir/clean

CMakeFiles/Problem_10_2_C.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\cmake-build-debug" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\cmake-build-debug" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\Problem 10.2 C\cmake-build-debug\CMakeFiles\Problem_10_2_C.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Problem_10_2_C.dir/depend
