cmake_minimum_required(VERSION 4.3)
project(TP)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(TP src/main.cpp
        src/pokemon.cpp
        inc/pokemon.h
        src/pokemon_vector.cpp
        inc/pokemon_vector.h
        src/pokedex.cpp
        inc/pokedex.h
)

target_link_libraries(TP PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

configure_file(
        ${CMAKE_SOURCE_DIR}/data/pokedex.csv
        ${CMAKE_BINARY_DIR}/pokedex.csv
        COPYONLY
)
