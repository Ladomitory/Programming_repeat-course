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
CMAKE_SOURCE_DIR = "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/problem_8_2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/problem_8_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problem_8_2.dir/flags.make

CMakeFiles/problem_8_2.dir/main.cpp.obj: CMakeFiles/problem_8_2.dir/flags.make
CMakeFiles/problem_8_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problem_8_2.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\problem_8_2.dir\main.cpp.obj -c "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\main.cpp"

CMakeFiles/problem_8_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem_8_2.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\main.cpp" > CMakeFiles\problem_8_2.dir\main.cpp.i

CMakeFiles/problem_8_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem_8_2.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\main.cpp" -o CMakeFiles\problem_8_2.dir\main.cpp.s

# Object files for target problem_8_2
problem_8_2_OBJECTS = \
"CMakeFiles/problem_8_2.dir/main.cpp.obj"

# External object files for target problem_8_2
problem_8_2_EXTERNAL_OBJECTS =

problem_8_2.exe: CMakeFiles/problem_8_2.dir/main.cpp.obj
problem_8_2.exe: CMakeFiles/problem_8_2.dir/build.make
problem_8_2.exe: CMakeFiles/problem_8_2.dir/linklibs.rsp
problem_8_2.exe: CMakeFiles/problem_8_2.dir/objects1.rsp
problem_8_2.exe: CMakeFiles/problem_8_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problem_8_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\problem_8_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problem_8_2.dir/build: problem_8_2.exe
.PHONY : CMakeFiles/problem_8_2.dir/build

CMakeFiles/problem_8_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\problem_8_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/problem_8_2.dir/clean

CMakeFiles/problem_8_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\cmake-build-debug" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\cmake-build-debug" "E:\ladomitory\Users\Ladomitory\Informatic\olympic.nsu.ru\Programming_repeat course(trans from ru)\tour 8\problem 8.2\cmake-build-debug\CMakeFiles\problem_8_2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/problem_8_2.dir/depend

