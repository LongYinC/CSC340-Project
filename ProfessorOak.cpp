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
    cout << "(" << CATCH << ") Catch pokemon" << endl;
    cin >> userInput;
    return userInput;
}



