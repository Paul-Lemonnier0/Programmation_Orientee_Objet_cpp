cmake_minimum_required(VERSION 3.18.0)

project(TP6_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
add_compile_options(-Wall -Wpedantic)
endif()

add_executable(TP6_2 main.cpp
    resultat.cpp resultat.h
    resultatexception.cpp resultatexception.h
    date.cpp date.h)
