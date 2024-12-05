#include <iostream>
#include "LinkedList.h"
#include "ProfessorOak.h"
#include "ProfessorOak.cpp"
using namespace std;

int main(){
    ProfessorOak* oak = new ProfessorOak();
    int userInput = oak->getMenuOption();
    bool active = true;
    while(active == true){
        switch(userInput){
            case PRINT_TEAM:
                userInput = oak->getMenuOption();
                break;
            case PRINT_NURSERY:
                userInput = oak->getMenuOption();
                break;
            case PRINT_CENTER:
                userInput = oak->getMenuOption();
                break;
            case ADD_TEAM:
                userInput = oak->getMenuOption();
                break;
            case ADD_NURSERY:
                userInput = oak->getMenuOption();
                break;
            case ADD_CENTER:
                userInput = oak->getMenuOption();
                break;
            case CATCH:
                userInput = oak->getMenuOption();
                break;
            default:
                active = false;
                break;
        }
    }
    return 0;
}
