cmake_minimum_required(VERSION 4.0)
project(18_function)

set(CMAKE_CXX_STANDARD 20)

add_executable(18_function main.cpp
        multiply.h
        multiply.cpp
        event_system.cpp
        event_system.h)
