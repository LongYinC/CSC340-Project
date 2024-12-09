#include <iostream>
#include "Buildings.h"
#include "Nursery.h"
#include "Center.h"
#include "ProfessorOak.h"
#include "ProfessorOak.cpp"
using namespace std;


int main() {
    ProfessorOak* oak = new ProfessorOak();
    oak->runPokemonManager();
    delete oak;
    return 0;
}

