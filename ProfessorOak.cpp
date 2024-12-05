#include <iostream>
#include "ProfessorOak.h"
using namespace std;

ProfessorOak::ProfessorOak(){}

int ProfessorOak::getMenuOption(){
    int userInput;
    cout << "(" << PRINT_TEAM << ") Display team" << endl;
    cout << "(" << PRINT_NURSERY << ") Display nursery" << endl;
    cout << "(" << PRINT_CENTER << ") Display center" << endl;
    cout << "(" << ADD_TEAM << ") Add pokemon to team" << endl;
    cout << "(" << ADD_NURSERY << ") Add pokemon to nursery" << endl;
    cout << "(" << ADD_CENTER << ") Add pokemon to center" << endl;
    cout << "(" << REMOVE_TEAM << ") Remove pokemon to team" << endl;
    cout << "(" << REMOVE_NURSERY << ") Remove pokemon to nursery" << endl;
    cout << "(" << REMOVE_CENTER << ") Remove pokemon to center" << endl;
    cout << "(" << CATCH << ") Catch pokemon" << endl;
    cout << "Please enter your choice: ";
    cin >> userInput;
    return userInput;
}

void ProfessorOak::printTeam(){}

void ProfessorOak::printNursery(){}

void ProfessorOak::printCenter(){}

void ProfessorOak::addTeam(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::addNursery(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::addCenter(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::removeTeam(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::removeNursery(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::removeCenter(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::catchPokemon(){}



