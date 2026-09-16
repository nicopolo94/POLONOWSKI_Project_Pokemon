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
    const int id;
    const string name;
    const string type_1;
    const string type_2;
    double hitPointsMax;
    double hitPoints;
    double attack;
    double defense;
    double sp_attack;
    double sp_defense;
    double speed;
    const int generation;
    const bool legendary;
public:
    // The global nextId give each pokemon an unique ID.
    static int nextId;

    // Constructors for pokemon
    pokemon() = delete;
    pokemon(
        const string& name,
        const string& type_1,
        const string& type_2,
        const double& hitPointsMax,
        const double& attack,
        const double& defense,
        const double& sp_attack,
        const double& sp_defense,
        const double& speed,
        const int& generation,
        const bool& legendary
    );
    pokemon(const pokemon& copiedPokemon);

    ~pokemon();

    // Getters
    [[nodiscard]] int getId() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] string getType1() const;
    [[nodiscard]] string getType2() const;
    [[nodiscard]] double getHitPointsMax() const;
    [[nodiscard]] double getHitPoints() const;
    [[nodiscard]] double getAttack() const;
    [[nodiscard]] double getDefense() const;
    [[nodiscard]] double getSpAttack() const;
    [[nodiscard]] double getSpDefense() const;
    [[nodiscard]] double getSpeed() const;
    [[nodiscard]] int getGeneration() const;
    [[nodiscard]] bool getLegendary() const;

    // Methods for pokemon
    void displayName() const;
    void displayInfo() const;
    void takeDamage(double damage);
    void attackAnotherPokemon(pokemon& anotherPokemon) const;
};

#endif //TP_POKEMON_H
