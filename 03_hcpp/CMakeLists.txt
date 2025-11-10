cmake_minimum_required(VERSION 4.0)
project(02_scope)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(02_scope
        example.cpp
        example.h
        main.cpp)
