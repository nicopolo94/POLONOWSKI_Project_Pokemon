//
// Created by npolo on 14/09/2026.
//

/*
 * The class pokemon is used to create Pokemon.
 * A pokemon contains an unique ID, incremented for each new pokemon.
 * A pokemon have a name (string), two types (string),
 * a maximum for its hit points (double), its current hit points (double),
 * a value for its attack (double) and for its defense (double), sp. attack (double),
 * sp. defense (double), speed (double), generation (int) and if its a legendary pokemon (bool)
 *
 * The pokemon constructor needs a name, the two types, the evolution of the pokemon, its maximum hit points,
 * its attack and defense, sp_attack, sp_defense, speed, generation and if its a legendary pokemon.
 * The current hit points is initialized with the maximum hit points.
*/

#ifndef TP_POKEMON_H
#define TP_POKEMON_H

#include <string>

using std::string;

class pokemon {
private:
    // id is unique per instance (two Pikachu get two ids); number is the Pokedex number shared by
    // every copy and by alternate forms (Mega evolutions have the same number as their base form).
    const int id;
    const int number;
    const string name;
    const string type_1;
    const string type_2;
    int evolution;
    double hitPointsMax;
    double hitPoints;
    double attack;
    double defense;
    double sp_attack;
    double sp_defense;
    double speed;
    const int generation;
    const bool legendary;

    static int nextId;

public:
    pokemon() = delete;
    pokemon(
        int number,
        const string& name,
        const string& type_1,
        const string& type_2,
        double hitPointsMax,
        double attack,
        double defense,
        double sp_attack,
        double sp_defense,
        double speed,
        int generation,
        bool legendary,
        int evolution = 0
    );
    // A copy is a new individual: it gets its own id and starts with full hit points.
    pokemon(const pokemon& copiedPokemon);
    pokemon& operator=(const pokemon&) = delete;
    ~pokemon();

    [[nodiscard]] int getId() const;
    [[nodiscard]] int getNumber() const;
    [[nodiscard]] const string& getName() const;
    [[nodiscard]] const string& getType1() const;
    [[nodiscard]] const string& getType2() const;
    [[nodiscard]] int getEvolution() const;
    [[nodiscard]] double getHitPointsMax() const;
    [[nodiscard]] double getHitPoints() const;
    [[nodiscard]] double getAttack() const;
    [[nodiscard]] double getDefense() const;
    [[nodiscard]] double getSpAttack() const;
    [[nodiscard]] double getSpDefense() const;
    [[nodiscard]] double getSpeed() const;
    [[nodiscard]] int getGeneration() const;
    [[nodiscard]] bool isLegendary() const;
    [[nodiscard]] bool isKnockedOut() const;

    void displayName() const;
    void displayInfo() const;
    void takeDamage(double damage);
    void heal();
    void attackAnotherPokemon(pokemon& anotherPokemon) const;
};

#endif //TP_POKEMON_H
