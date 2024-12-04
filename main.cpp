#include <iostream>
#include "LinkedList.h"
#include "ProfessorOak.cpp"
using namespace std;

enum Actions {PRINT_TEAM, PRINT_NURSERY, PRINT_CENTER, ADD_TEAM, ADD_NURSERY, ADD_CENTER, CATCH}


int main(){
    ProfessorOak oak = new ProfessorOak();
    int userInput = oak.getMenuOption();
    bool active = true;
    while(active == true){
        switch(userInput){
            case PRINT_TEAM:
                break;
            case PRINT_NURSERY:
                break;
            case PRINT_CENTER:
                break;
            case ADD_TEAM:
                break;
            case ADD_NURSERY:
                break;
            case ADD_CENTER:
                break;
            case CATCH:
                break;
            default:
                active = false;
                break;
        }
    }
    return 0;
}
