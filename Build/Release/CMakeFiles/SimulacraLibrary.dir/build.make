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
include CMakeFiles\SimulacraLibrary.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\SimulacraLibrary.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\SimulacraLibrary.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\SimulacraLibrary.dir\flags.make

CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp
CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/Renderer/Backend/Vulkan/Private/VulkanRHI.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/Renderer/Backend/Vulkan/Private/VulkanRHI.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/Renderer/Backend/Vulkan/Private/VulkanRHI.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/Renderer/Backend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/Renderer/Backend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/Renderer/Backend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

# Object files for target SimulacraLibrary
SimulacraLibrary_OBJECTS = \
"CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj"

# External object files for target SimulacraLibrary
SimulacraLibrary_EXTERNAL_OBJECTS =

SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Private\VulkanRHI.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\Renderer\Backend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\build.make
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library SimulacraLibrary.lib"
	$(CMAKE_COMMAND) -P CMakeFiles\SimulacraLibrary.dir\cmake_clean_target.cmake
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1440~1.338\bin\Hostx64\x64\lib.exe /nologo /machine:x64 /out:SimulacraLibrary.lib @CMakeFiles\SimulacraLibrary.dir\objects1.rsp 

# Rule to build all files generated by this target.
CMakeFiles\SimulacraLibrary.dir\build: SimulacraLibrary.lib
.PHONY : CMakeFiles\SimulacraLibrary.dir\build

CMakeFiles\SimulacraLibrary.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SimulacraLibrary.dir\cmake_clean.cmake
.PHONY : CMakeFiles\SimulacraLibrary.dir\clean

CMakeFiles\SimulacraLibrary.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\avsom\CLionProjects\SimulacraEngine C:\Users\avsom\CLionProjects\SimulacraEngine C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Release\CMakeFiles\SimulacraLibrary.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles\SimulacraLibrary.dir\depend

