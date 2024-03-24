cmake_minimum_required(VERSION 3.18.0)

project(TP3_5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()

add_executable(TP3_5 main.cpp
     position.hh position.cc
     taille.hh taille.cc
     objet.hh objet.cc
     joueur.hh joueur.cc
     invaders.cc invaders.hh
     projectile.cc projectile.hh)

