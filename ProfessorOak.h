#ifndef PROFESSOROAK_H
#define PROFESSOROAK_H
#include <string>
#include <iostream>
#include <fstream>
#include "Buildings.h"

enum Actions {QUIT, PRINT_TEAM, PRINT_NURSERY, PRINT_CENTER, ADD_TEAM, ADD_NURSERY, ADD_CENTER, CATCH};

struct ProfessorOak{
    ProfessorOak();
    int getMenuOption();
    void printTeam();
    void printNursery();
    void printCenter();
};
#endif
