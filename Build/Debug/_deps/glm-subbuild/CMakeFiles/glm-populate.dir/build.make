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
CMAKE_SOURCE_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

# Utility rule file for glm-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles\glm-populate.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\glm-populate.dir\progress.make

CMakeFiles\glm-populate: CMakeFiles\glm-populate-complete

CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-install
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-mkdir
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-download
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-update
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-patch
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-configure
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-build
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-install
CMakeFiles\glm-populate-complete: glm-populate-prefix\src\glm-populate-stamp\glm-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'glm-populate'"
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E make_directory C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/CMakeFiles
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/CMakeFiles/glm-populate-complete
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-done

glm-populate-prefix\src\glm-populate-stamp\glm-populate-update:
.PHONY : glm-populate-prefix\src\glm-populate-stamp\glm-populate-update

glm-populate-prefix\src\glm-populate-stamp\glm-populate-build: glm-populate-prefix\src\glm-populate-stamp\glm-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'glm-populate'"
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-build
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-build
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

glm-populate-prefix\src\glm-populate-stamp\glm-populate-configure: glm-populate-prefix\tmp\glm-populate-cfgcmd.txt
glm-populate-prefix\src\glm-populate-stamp\glm-populate-configure: glm-populate-prefix\src\glm-populate-stamp\glm-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'glm-populate'"
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-build
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-configure
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

glm-populate-prefix\src\glm-populate-stamp\glm-populate-download: glm-populate-prefix\src\glm-populate-stamp\glm-populate-gitinfo.txt
glm-populate-prefix\src\glm-populate-stamp\glm-populate-download: glm-populate-prefix\src\glm-populate-stamp\glm-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'glm-populate'"
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -P C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/tmp/glm-populate-gitclone.cmake
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-download
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

glm-populate-prefix\src\glm-populate-stamp\glm-populate-install: glm-populate-prefix\src\glm-populate-stamp\glm-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'glm-populate'"
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-build
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-install
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

glm-populate-prefix\src\glm-populate-stamp\glm-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'glm-populate'"
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -Dcfgdir= -P C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/tmp/glm-populate-mkdirs.cmake
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-mkdir

glm-populate-prefix\src\glm-populate-stamp\glm-populate-patch: glm-populate-prefix\src\glm-populate-stamp\glm-populate-patch-info.txt
glm-populate-prefix\src\glm-populate-stamp\glm-populate-patch: glm-populate-prefix\src\glm-populate-stamp\glm-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'glm-populate'"
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-patch

glm-populate-prefix\src\glm-populate-stamp\glm-populate-update:
.PHONY : glm-populate-prefix\src\glm-populate-stamp\glm-populate-update

glm-populate-prefix\src\glm-populate-stamp\glm-populate-test: glm-populate-prefix\src\glm-populate-stamp\glm-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'glm-populate'"
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-build
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/glm-populate-test
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

glm-populate-prefix\src\glm-populate-stamp\glm-populate-update: glm-populate-prefix\tmp\glm-populate-gitupdate.cmake
glm-populate-prefix\src\glm-populate-stamp\glm-populate-update: glm-populate-prefix\src\glm-populate-stamp\glm-populate-update-info.txt
glm-populate-prefix\src\glm-populate-stamp\glm-populate-update: glm-populate-prefix\src\glm-populate-stamp\glm-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'glm-populate'"
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-src
	echo >nul && "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -Dcan_fetch=YES -P C:/Users/avsom/CLionProjects/SimulacraEngine/Build/Debug/_deps/glm-subbuild/glm-populate-prefix/tmp/glm-populate-gitupdate.cmake
	cd C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild

glm-populate: CMakeFiles\glm-populate
glm-populate: CMakeFiles\glm-populate-complete
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-build
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-configure
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-download
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-install
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-mkdir
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-patch
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-test
glm-populate: glm-populate-prefix\src\glm-populate-stamp\glm-populate-update
glm-populate: CMakeFiles\glm-populate.dir\build.make
.PHONY : glm-populate

# Rule to build all files generated by this target.
CMakeFiles\glm-populate.dir\build: glm-populate
.PHONY : CMakeFiles\glm-populate.dir\build

CMakeFiles\glm-populate.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\glm-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles\glm-populate.dir\clean

CMakeFiles\glm-populate.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild C:\Users\avsom\CLionProjects\SimulacraEngine\Build\Debug\_deps\glm-subbuild\CMakeFiles\glm-populate.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles\glm-populate.dir\depend

