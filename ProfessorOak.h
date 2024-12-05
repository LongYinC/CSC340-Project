#ifndef PROFESSOROAK_H
#define PROFESSOROAK_H
#include <string>
#include <iostream>
#include <fstream>

enum Actions {PRINT_TEAM, PRINT_NURSERY, PRINT_CENTER, ADD_TEAM, ADD_NURSERY, ADD_CENTER, CATCH};

struct ProfessorOak{
    ProfessorOak();
    int getMenuOption();
};
#endif
