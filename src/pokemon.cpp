//
// Created by npolo on 14/09/2026.
//

#include "../inc/pokemon.h"
#include <string>
#include <iostream>

using std::string;

int pokemon::nextId = 0;

// The constructor of the pokemon needs a name, the two types of the pokemon, its maximum hit points, attack, defense, sp attack, sp defense, speed, generation and if its a legendary pokemon.
// The ID of the pokemon is determined by the global nextId, incremented for each pokemon.
pokemon::pokemon(
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
            const bool& legendary) :
            id(nextId), name(name), type_1(type_1), type_2(type_2), hitPointsMax(hitPointsMax), attack(attack), defense(defense),
            sp_attack(sp_attack), sp_defense(sp_defense), speed(speed), generation(generation), legendary(legendary) {
                hitPoints = hitPointsMax;
                nextId = nextId + 1;
            }

pokemon::pokemon(const pokemon& copiedPokemon) :
id(nextId), name(copiedPokemon.name), type_1(copiedPokemon.type_1), type_2(copiedPokemon.type_2), hitPointsMax(copiedPokemon.hitPointsMax), attack(copiedPokemon.attack), defense(copiedPokemon.defense),
sp_attack(copiedPokemon.sp_attack), sp_defense(copiedPokemon.sp_defense), speed(copiedPokemon.speed), generation(copiedPokemon.generation), legendary(copiedPokemon.legendary) {
    hitPoints = copiedPokemon.hitPointsMax;
    nextId = nextId + 1;
}

pokemon::~pokemon() = default;

int pokemon::getId() const { return id; }
string pokemon::getName() const { return name; }
string pokemon::getType1() const { return type_1; }
string pokemon::getType2() const { return type_2; }
double pokemon::getHitPointsMax() const { return hitPointsMax; }
double pokemon::getHitPoints() const { return hitPoints; }
double pokemon::getAttack() const { return attack; }
double pokemon::getDefense() const { return defense; }
double pokemon::getSpAttack() const { return sp_attack; }
double pokemon::getSpDefense() const { return sp_defense; }
double pokemon::getSpeed() const { return speed; }
int pokemon::getGeneration() const { return generation; }
bool pokemon::getLegendary() const { return legendary; }

// This method display the ID and the name of the pokemon.
void pokemon::displayName() const {
    std::cout << "ID : " << id << " Name : " << name << std::endl;
}

// This method display the all information of the pokemon.
void pokemon::displayInfo() const {
    std::cout << "****Pokemon : " << name << "****" << std::endl;
    std::cout << "Type 1 : " << type_1 << std::endl;
    std::cout << "Type 2 : " << type_2 << std::endl;
    std::cout << "hitPointsMax : " << hitPointsMax << std::endl;
    std::cout << "actual hitPoints : " << hitPoints << std::endl;
    std::cout << "attack : " << attack << std::endl;
    std::cout << "defense : " << defense << std::endl;
    std::cout << "sp. attack : " << sp_attack << std::endl;
    std::cout << "sp .defense : " << sp_defense << std::endl;
    std::cout << "speed : " << speed << std::endl;
    std::cout << "generation : " << generation << std::endl;
}

// The method takeDamage reduce the current hit points of the pokemon with damage.
// If the pokemon have no hit points left, the pokemon is "dead".
void pokemon::takeDamage(const double damage) {
    if (hitPoints > damage) {
        hitPoints = hitPoints - damage;
        std::cout << name << " have " << hitPoints << " hit point left" << std::endl;
    }
    else {
        hitPoints = 0;
        std::cout << name << " is dead" << std::endl;
    }
}

// The method attackAnotherPokemon compare the attack of the pokemon with the defense of the other pokemon.
// If the attack is greater than the defense, the attacked pokemon take damage with takeDamage method.
void pokemon::attackAnotherPokemon(pokemon& anotherPokemon) const {
    if (const double damage = attack - anotherPokemon.getDefense(); damage > 0) {
        std::cout << name << " attack is effective" << std::endl;
        anotherPokemon.takeDamage(damage);
    }
    else {
        std::cout << name << " attack is not effective" << std::endl;
    }
}
