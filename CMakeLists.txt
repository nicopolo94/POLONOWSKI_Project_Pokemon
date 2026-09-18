cmake_minimum_required(VERSION 3.21)
project(TP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP
        src/main.cpp
        src/pokemon.cpp
        src/pokemon_vector.cpp
        src/pokedex.cpp
        src/pokemon_party.cpp
        inc/pokemon_party.h
)

target_include_directories(TP PRIVATE inc)