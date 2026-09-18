//
// Created by npolo on 14/09/2026.
//

#include "pokedex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

pokedex::pokedex(const string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Can't open the file : " + file_name);
    }

    string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::vector<string> cells;
        string cell;
        while (std::getline(ss, cell, ',')) {
            cells.push_back(cell);
        }

        try {
            add_pokemon(std::make_unique<pokemon>(
                std::stoi(cells.at(0)),
                cells.at(1),
                cells.at(2),
                cells.at(3),
                std::stod(cells.at(5)),
                std::stod(cells.at(6)),
                std::stod(cells.at(7)),
                std::stod(cells.at(8)),
                std::stod(cells.at(9)),
                std::stod(cells.at(10)),
                std::stoi(cells.at(11)),
                cells.at(12) == "True"
            ));
        }
        catch (const std::exception& e) {
            std::cerr << "Ignored line : " << line << " (" << e.what() << ")" << std::endl;
        }
    }
}

pokedex& pokedex::get_instance(const string& file_name) {
    // Function-local static: built on first use, destroyed at the end of the program, no leak.
    static pokedex instance(file_name);
    return instance;
}

std::unique_ptr<pokemon> pokedex::copy_pokemon(const string& pokemon_name) const {
    const std::optional<std::size_t> index = find_pokemon(pokemon_name);
    if (!index) {
        throw std::invalid_argument("Unknown pokemon : " + pokemon_name);
    }
    return copy_pokemon(*index);
}

std::unique_ptr<pokemon> pokedex::copy_pokemon(const std::size_t index) const {
    return std::make_unique<pokemon>(get_by_index(index));
}
