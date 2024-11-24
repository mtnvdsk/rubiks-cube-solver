cmake_minimum_required(VERSION 3.30)
project(rubiks_cube_solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(rubiks_cube_solver
        Models/RubiksCube.cpp
        Models/RubiksCube.h
        main.cpp)
