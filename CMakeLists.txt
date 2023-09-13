cmake_minimum_required(VERSION 3.25)
project(SimulacraEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimulacraEngine main.cpp Source/vec3.h Source/color.h Source/ray.h Source/hittable.h)

