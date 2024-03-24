cmake_minimum_required(VERSION 3.18.0)

project(TP3_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()

add_executable(TP3_2 main.cpp
    figure.cc figure.hh
    point.cc point.hh
    segment.cc segment.hh
    triangle.cc triangle.hh
    rectangle.cc rectangle.hh)
