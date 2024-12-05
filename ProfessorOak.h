#ifndef PROFESSOROAK_H
#define PROFESSOROAK_H
#include <string>
#include <iostream>
#include <fstream>
#include "Buildings.h"

enum Actions {QUIT, PRINT_TEAM, PRINT_NURSERY, PRINT_CENTER, ADD_TEAM, ADD_NURSERY, ADD_CENTER, REMOVE_TEAM, REMOVE_NURSERY, REMOVE_CENTER, CATCH};

struct ProfessorOak{
    ProfessorOak();
    int getMenuOption();
    void printTeam();
    void printNursery();
    void printCenter();
    void addTeam(Buildings* building, Pokemon* pokemon);
    void addNursery(Buildings* building, Pokemon* pokemon);
    void addCenter(Buildings* building, Pokemon* pokemon);
    void removeTeam(Buildings* building, Pokemon* pokemon);
    void removeNursery(Buildings* building, Pokemon* pokemon);
    void removeCenter(Buildings* building, Pokemon* pokemon);
    void catchPokemon();
};
#endif
