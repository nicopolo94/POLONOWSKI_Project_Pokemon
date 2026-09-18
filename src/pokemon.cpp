//
// Created by npolo on 14/09/2026.
//

#include "pokemon.h"

#include <iostream>

int pokemon::nextId = 0;

pokemon::pokemon(
    const int number,
    const string& name,
    const string& type_1,
    const string& type_2,
    const double hitPointsMax,
    const double attack,
    const double defense,
    const double sp_attack,
    const double sp_defense,
    const double speed,
    const int generation,
    const bool legendary,
    const int evolution
) :
    id(nextId++), number(number), name(name), type_1(type_1), type_2(type_2), evolution(evolution),
    hitPointsMax(hitPointsMax), hitPoints(hitPointsMax), attack(attack), defense(defense),
    sp_attack(sp_attack), sp_defense(sp_defense), speed(speed), generation(generation), legendary(legendary) {}

pokemon::pokemon(const pokemon& copiedPokemon) :
    id(nextId++), number(copiedPokemon.number), name(copiedPokemon.name), type_1(copiedPokemon.type_1),
    type_2(copiedPokemon.type_2), evolution(copiedPokemon.evolution), hitPointsMax(copiedPokemon.hitPointsMax),
    hitPoints(copiedPokemon.hitPointsMax), attack(copiedPokemon.attack), defense(copiedPokemon.defense),
    sp_attack(copiedPokemon.sp_attack), sp_defense(copiedPokemon.sp_defense), speed(copiedPokemon.speed),
    generation(copiedPokemon.generation), legendary(copiedPokemon.legendary) {}

pokemon::~pokemon() = default;

int pokemon::getId() const { return id; }
int pokemon::getNumber() const { return number; }
const string& pokemon::getName() const { return name; }
const string& pokemon::getType1() const { return type_1; }
const string& pokemon::getType2() const { return type_2; }
int pokemon::getEvolution() const { return evolution; }
double pokemon::getHitPointsMax() const { return hitPointsMax; }
double pokemon::getHitPoints() const { return hitPoints; }
double pokemon::getAttack() const { return attack; }
double pokemon::getDefense() const { return defense; }
double pokemon::getSpAttack() const { return sp_attack; }
double pokemon::getSpDefense() const { return sp_defense; }
double pokemon::getSpeed() const { return speed; }
int pokemon::getGeneration() const { return generation; }
bool pokemon::isLegendary() const { return legendary; }
bool pokemon::isKnockedOut() const { return hitPoints <= 0; }

void pokemon::displayName() const {
    std::cout << "ID : " << id << " | #" << number << " " << name << std::endl;
}

void pokemon::displayInfo() const {
    std::cout << "**** " << name << " (#" << number << ", ID " << id << ") ****" << std::endl;
    std::cout << "Type        : " << type_1 << (type_2.empty() ? "" : " / " + type_2) << std::endl;
    std::cout << "Hit points  : " << hitPoints << " / " << hitPointsMax << std::endl;
    std::cout << "Attack      : " << attack << std::endl;
    std::cout << "Defense     : " << defense << std::endl;
    std::cout << "Sp. attack  : " << sp_attack << std::endl;
    std::cout << "Sp. defense : " << sp_defense << std::endl;
    std::cout << "Speed       : " << speed << std::endl;
    std::cout << "Generation  : " << generation << std::endl;
    std::cout << "Evolution   : " << evolution << std::endl;
    std::cout << "Legendary   : " << (legendary ? "yes" : "no") << std::endl;
}

void pokemon::takeDamage(const double damage) {
    if (damage <= 0) {
        return;
    }
    if (hitPoints > damage) {
        hitPoints -= damage;
        std::cout << name << " has " << hitPoints << " hit points left" << std::endl;
    }
    else {
        hitPoints = 0;
        std::cout << name << " is knocked out" << std::endl;
    }
}

void pokemon::heal() {
    hitPoints = hitPointsMax;
}

void pokemon::attackAnotherPokemon(pokemon& anotherPokemon) const {
    if (const double damage = attack - anotherPokemon.getDefense(); damage > 0) {
        std::cout << name << "'s attack is effective" << std::endl;
        anotherPokemon.takeDamage(damage);
    }
    else {
        std::cout << name << "'s attack is not effective" << std::endl;
    }
}