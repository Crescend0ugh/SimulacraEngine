# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release

# Include any dependencies generated for this target.
include C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/compiler_depend.make

# Include the progress variables for this target.
include C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/flags.make

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/flags.make
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/includes_C.rsp
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.obj: C:/glfw-3.3.8/tests/windows.c
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.obj"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.obj -MF CMakeFiles\windows.dir\windows.c.obj.d -o CMakeFiles\windows.dir\windows.c.obj -c C:\glfw-3.3.8\tests\windows.c

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\glfw-3.3.8\tests\windows.c > CMakeFiles\windows.dir\windows.c.i

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\glfw-3.3.8\tests\windows.c -o CMakeFiles\windows.dir\windows.c.s

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/flags.make
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/includes_C.rsp
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj: C:/glfw-3.3.8/deps/getopt.c
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj -MF CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\getopt.c.obj.d -o CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\getopt.c.obj -c C:\glfw-3.3.8\deps\getopt.c

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.i"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\glfw-3.3.8\deps\getopt.c > CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\getopt.c.i

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.s"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\glfw-3.3.8\deps\getopt.c -o CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\getopt.c.s

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/flags.make
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/includes_C.rsp
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj: C:/glfw-3.3.8/deps/glad_gl.c
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj -MF CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\glad_gl.c.obj.d -o CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\glad_gl.c.obj -c C:\glfw-3.3.8\deps\glad_gl.c

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.i"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\glfw-3.3.8\deps\glad_gl.c > CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\glad_gl.c.i

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.s"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\glfw-3.3.8\deps\glad_gl.c -o CMakeFiles\windows.dir\C_\glfw-3.3.8\deps\glad_gl.c.s

# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.obj" \
"CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj" \
"CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/windows.c.obj
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/getopt.c.obj
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/C_/glfw-3.3.8/deps/glad_gl.c.obj
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/build.make
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/src/libglfw3.a
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/linkLibs.rsp
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/objects1.rsp
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable windows.exe"
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\windows.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/build: C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/windows.exe
.PHONY : C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/build

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/clean:
	cd /d C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests && $(CMAKE_COMMAND) -P CMakeFiles\windows.dir\cmake_clean.cmake
.PHONY : C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/clean

C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\avsom\CLionProjects\SimulacraEngine C:\glfw-3.3.8\tests C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests C:\Users\avsom\CLionProjects\SimulacraEngine\Binaries\tests\CMakeFiles\windows.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : C:/Users/avsom/CLionProjects/SimulacraEngine/Binaries/tests/CMakeFiles/windows.dir/depend

