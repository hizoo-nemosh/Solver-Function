cmake_minimum_required(VERSION 3.12)
project(SolverFunctionEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solver-app SolverFunction-OOP.cpp)
