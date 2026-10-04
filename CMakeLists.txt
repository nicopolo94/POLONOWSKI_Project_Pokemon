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
        src/pokemon_attack.cpp
        src/texture_cache.cpp
        src/selection_layout.cpp
        src/selection_screen.cpp
        inc/game_state.h
        inc/game_engine.h
        src/game_engine.cpp
        inc/state_title.h
        src/state_title.cpp
        inc/state_exploration.h
        src/state_exploration.cpp
        inc/state_team_selection.h
        src/state_team_selection.cpp
        inc/state_combat.h
        src/state_combat.cpp
        inc/state_game_over.h
        src/state_game_over.cpp
)

target_include_directories(TP PRIVATE inc)
target_compile_definitions(TP PRIVATE DATA_DIR="${CMAKE_SOURCE_DIR}/data")

# Cherche le SFML 2 que tu viens d'installer via apt-get
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

# On utilise les noms en minuscules pour la version Linux de SFML 2
target_link_libraries(TP
        PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

target_compile_options(TP PUBLIC -Wall -Wextra -Wpedantic)
target_compile_definitions(TP PUBLIC DATA_DIR="${CMAKE_SOURCE_DIR}/data")