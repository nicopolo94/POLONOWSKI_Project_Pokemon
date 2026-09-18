#include "pokedex.h"
#include "pokemon_party.h"

#include <SFML/Graphics.hpp>
#include <exception>
#include <iostream>
#include <string>

int main() {
    try {
        // Named rather than a literal: GCC flags a reference returned from a call that received a
        // temporary string as possibly dangling, even though the singleton outlives it.
        const std::string pokedex_path = std::string(DATA_DIR) + "/pokedex.csv";
        const pokedex& dex = pokedex::get_instance(pokedex_path);
        std::cout << dex.size() << " pokemon in the Pokedex" << std::endl;

        pokemon_party party;
        party.add_pokemon(dex.copy_pokemon("Pikachu"));
        party.add_pokemon(dex.copy_pokemon("Bulbasaur"));
        party.add_pokemon(dex.copy_pokemon("Pikachu"));

        std::cout << "\nParty :" << std::endl;
        party.display();

        party.get_by_index(0).attackAnotherPokemon(party.get_by_index(1));

        const std::unique_ptr<pokemon> extracted = party.extract_pokemon("Bulbasaur");
        std::cout << "\nExtracted :" << std::endl;
        extracted->displayInfo();

        std::cout << "\nParty after extraction :" << std::endl;
        party.display();
    }
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
        return 1;
    }
    return 0;
}