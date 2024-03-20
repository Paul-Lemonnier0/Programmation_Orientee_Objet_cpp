cmake_minimum_required(VERSION 3.18.0)

project(TP4_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
add_compile_options(-Wall -Wpedantic)
endif()

add_executable(TP4_2 main.cpp
    document.cpp document.h
    bibliotheque.cpp bibliotheque.h)
