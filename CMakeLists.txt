cmake_minimum_required(VERSION 3.27)
project(TP)

set(CMAKE_CXX_STANDARD 20)

add_executable(TP src/main.cpp
        src/pokemon.cpp
        inc/pokemon.h
        src/pokemon_vector.cpp
        inc/pokemon_vector.h
        src/pokedex.cpp
        inc/pokedex.h
)