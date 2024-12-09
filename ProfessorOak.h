#ifndef PROFESSOROAK_H
#define PROFESSOROAK_H
#include <string>
#include <iostream>
#include <fstream>
#include "Buildings.h"
#include "Pokemon.h"

enum Actions {QUIT, PRINT_TEAM, PRINT_NURSERY, PRINT_CENTER, ADD_TEAM, ADD_NURSERY, ADD_CENTER, CATCH};

struct ProfessorOak{
    ProfessorOak();
    int getMenuOption();
    void printTeam(Buildings* building);
    void printNursery(Buildings* building);
    void printCenter(Buildings* building);
    void addTeam(Buildings* building, Pokemon* pokemon);
    void addNursery(Buildings* building, Pokemon* pokemon);
    void addCenter(Buildings* building, Pokemon* pokemon);
    Pokemon* removeTeam(Buildings* building, Pokemon* pokemon);
    Pokemon* removeNursery(Buildings* building, Pokemon* pokemon);
    Pokemon* removeCenter(Buildings* building, Pokemon* pokemon);
    void catchPokemon(Buildings* team ,Buildings* center);
    void sortTeam(Buildings* team);
    void handleAddToTeam(Buildings* team, Buildings* center);
    void handleAddToNursery(Buildings* team, Buildings* nursery);
    void handleAddToCenter(Buildings* team, Buildings* center);
    void runPokemonManager();
};
#endif
