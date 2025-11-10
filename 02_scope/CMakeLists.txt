cmake_minimum_required(VERSION 4.0)
project(02_scope.md)

set(CMAKE_CXX_STANDARD 20)

#设置编译选项，保存临时文件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -save-temps=obj")

add_executable(03_hcpp main.cpp)
