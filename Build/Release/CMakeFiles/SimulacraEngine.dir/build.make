﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release

# Include any dependencies generated for this target.
include CMakeFiles\SimulacraEngine.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\SimulacraEngine.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\SimulacraEngine.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\SimulacraEngine.dir\flags.make

CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.obj: CMakeFiles\SimulacraEngine.dir\flags.make
CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Launcher\Win_Main.cpp
CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.obj: CMakeFiles\SimulacraEngine.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimulacraEngine.dir/Source/Core/Launcher/Win_Main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.obj /FdCMakeFiles\SimulacraEngine.dir\ /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Launcher\Win_Main.cpp
<<

CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraEngine.dir/Source/Core/Launcher/Win_Main.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Launcher\Win_Main.cpp
<<

CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraEngine.dir/Source/Core/Launcher/Win_Main.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Launcher\Win_Main.cpp
<<

CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: CMakeFiles\SimulacraEngine.dir\flags.make
CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: CMakeFiles\SimulacraEngine.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimulacraEngine.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj /FdCMakeFiles\SimulacraEngine.dir\ /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraEngine.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraEngine.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

# Object files for target SimulacraEngine
SimulacraEngine_OBJECTS = \
"CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.obj" \
"CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj"

# External object files for target SimulacraEngine
SimulacraEngine_EXTERNAL_OBJECTS =

SimulacraEngine.exe: CMakeFiles\SimulacraEngine.dir\Source\Core\Launcher\Win_Main.cpp.obj
SimulacraEngine.exe: CMakeFiles\SimulacraEngine.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj
SimulacraEngine.exe: CMakeFiles\SimulacraEngine.dir\build.make
SimulacraEngine.exe: SimulacraLibrary.lib
SimulacraEngine.exe: C:\VulkanSDK\1.3.261.1\Lib\vulkan-1.lib
SimulacraEngine.exe: CMakeFiles\SimulacraEngine.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SimulacraEngine.exe"
	"C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\SimulacraEngine.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\mt.exe --manifests -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\SimulacraEngine.dir\objects1.rsp @<<
 /out:SimulacraEngine.exe /implib:SimulacraEngine.lib /pdb:C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\SimulacraEngine.pdb /version:0.0 /machine:x64 /INCREMENTAL:NO /subsystem:windows  SimulacraLibrary.lib C:\VulkanSDK\1.3.261.1\Lib\vulkan-1.lib d3d12.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\SimulacraEngine.dir\build: SimulacraEngine.exe
.PHONY : CMakeFiles\SimulacraEngine.dir\build

CMakeFiles\SimulacraEngine.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SimulacraEngine.dir\cmake_clean.cmake
.PHONY : CMakeFiles\SimulacraEngine.dir\clean

CMakeFiles\SimulacraEngine.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\avsom\CLionProjects\SimulacraEngine C:\Users\avsom\CLionProjects\SimulacraEngine C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles\SimulacraEngine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles\SimulacraEngine.dir\depend
