cmake_minimum_required(VERSION 3.29)
project(project)

set(CMAKE_CXX_STANDARD 20)

add_executable(project main.cpp
        binom_line_reader.cpp
        binom_line_reader.hpp
        trash.cpp)
