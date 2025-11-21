cmake_minimum_required(VERSION 4.0)
project(20_derive)

set(CMAKE_CXX_STANDARD 20)

add_executable(20_derive main.cpp
        Derived.cpp
        Derived.h)
