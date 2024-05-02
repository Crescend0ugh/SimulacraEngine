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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles\SimulacraLibrary.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\SimulacraLibrary.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\SimulacraLibrary.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\SimulacraLibrary.dir\flags.make

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanDevice.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanDevice.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanDevice.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanExtensions.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanExtensions.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanExtensions.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanInstance.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanInstance.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanInstance.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanPipeline.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanPipeline.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanPipeline.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanQueue.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanQueue.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanQueue.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanRHI.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanRHI.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanRHI.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanSwapchain.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanSwapchain.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanSwapchain.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/Core/Platform/SimulacraWindowsWindow.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\Core\Platform\SimulacraWindowsWindow.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanSurface.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanSurface.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanSurface.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Platforms/Windows/SimulacraVulkanWindowsPlatform.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.obj: CMakeFiles\SimulacraLibrary.dir\flags.make
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.obj: C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp
CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.obj: CMakeFiles\SimulacraLibrary.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanWindow.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.obj.d --working-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.obj /FdCMakeFiles\SimulacraLibrary.dir\SimulacraLibrary.pdb /FS -c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanWindow.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe > CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp
<<

CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimulacraLibrary.dir/Source/RendererBackend/Vulkan/Public/SimulacraVulkanWindow.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.s /c C:\Users\avsom\CLionProjects\SimulacraEngine\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp
<<

# Object files for target SimulacraLibrary
SimulacraLibrary_OBJECTS = \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj" \
"CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.obj"

# External object files for target SimulacraLibrary
SimulacraLibrary_EXTERNAL_OBJECTS =

SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanDevice.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanExtensions.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanInstance.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanPipeline.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanQueue.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanRHI.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSwapchain.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\Core\Platform\SimulacraWindowsWindow.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanSurface.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Platforms\Windows\SimulacraVulkanWindowsPlatform.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\Source\RendererBackend\Vulkan\Public\SimulacraVulkanWindow.cpp.obj
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\build.make
SimulacraLibrary.lib: CMakeFiles\SimulacraLibrary.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX static library SimulacraLibrary.lib"
	$(CMAKE_COMMAND) -P CMakeFiles\SimulacraLibrary.dir\cmake_clean_target.cmake
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1438~1.331\bin\Hostx64\x64\lib.exe /nologo /machine:x64 /out:SimulacraLibrary.lib @CMakeFiles\SimulacraLibrary.dir\objects1.rsp 

# Rule to build all files generated by this target.
CMakeFiles\SimulacraLibrary.dir\build: SimulacraLibrary.lib
.PHONY : CMakeFiles\SimulacraLibrary.dir\build

CMakeFiles\SimulacraLibrary.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SimulacraLibrary.dir\cmake_clean.cmake
.PHONY : CMakeFiles\SimulacraLibrary.dir\clean

CMakeFiles\SimulacraLibrary.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\avsom\CLionProjects\SimulacraEngine C:\Users\avsom\CLionProjects\SimulacraEngine C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release C:\Users\avsom\CLionProjects\SimulacraEngine\cmake-build-release\CMakeFiles\SimulacraLibrary.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles\SimulacraLibrary.dir\depend

