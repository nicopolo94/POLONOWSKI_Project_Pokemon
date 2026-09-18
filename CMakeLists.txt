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
        src/pokemon_attack.cpp
        inc/pokemon_attack.h
)

target_include_directories(TP PRIVATE inc)

target_compile_definitions(TP PRIVATE DATA_DIR="${CMAKE_SOURCE_DIR}/data")

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

target_link_libraries(TP
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)