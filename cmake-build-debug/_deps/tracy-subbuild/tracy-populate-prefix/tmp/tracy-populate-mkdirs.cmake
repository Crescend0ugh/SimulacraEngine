# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-src"
  "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-build"
  "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-subbuild/tracy-populate-prefix"
  "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-subbuild/tracy-populate-prefix/tmp"
  "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-subbuild/tracy-populate-prefix/src/tracy-populate-stamp"
  "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-subbuild/tracy-populate-prefix/src"
  "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-subbuild/tracy-populate-prefix/src/tracy-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-subbuild/tracy-populate-prefix/src/tracy-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/avsom/CLionProjects/SimulacraEngine/cmake-build-debug/_deps/tracy-subbuild/tracy-populate-prefix/src/tracy-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
