//
// Created by npolo on 14/09/2026.
//

#include "../inc/pokedex.h"
#include "../inc/pokemon.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using std::string;

pokedex * pokedex::pokedex_instance;

pokedex::pokedex(const string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Can't open the file : " << file_name << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Dont use the first line.

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        try {
            std::vector<std::string> dataLine;
            std::string cell;
            while (std::getline(ss, cell, ',')) {
                dataLine.push_back(cell);
            }

            list_of_pokemon.push_back(new pokemon(
                dataLine.at(1),
                dataLine.at(2),
                dataLine.at(3),
                std::stod(dataLine.at(5)),
                std::stod(dataLine.at(6)),
                std::stod(dataLine.at(7)),
                std::stod(dataLine.at(8)),
                std::stod(dataLine.at(9)),
                std::stod(dataLine.at(10)),
                std::stoi(dataLine.at(11)),
                dataLine.at(12) == "True"
            ));
        }
        catch (const std::exception& e) {
            std::cerr << "Error at line : " << line << std::endl;
            std::cerr << "Error : " << e.what() << std::endl;
        }
    }
    file.close();
}

pokedex *pokedex::get_instance(const string &file_name) {
    if (!pokedex_instance) {
        pokedex_instance = new pokedex(file_name);
    }
    return pokedex_instance;
}

