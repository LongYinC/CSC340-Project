#include <iostream>
#include "Buildings.h"
#include "Nursery.h"
#include "Center.h"
#include "ProfessorOak.h"
#include "ProfessorOak.cpp"
using namespace std;

int main(){
    ProfessorOak* oak = new ProfessorOak();
    int userInput = oak->getMenuOption();
    bool active = true;
    Buildings * list = new Buildings();
    list->loadFile("pokemonName.txt");
    Buildings * team = new Buildings();
    Buildings * nursery = new Buildings();
    Buildings * center = new Buildings();
    while(active == true){
        switch(userInput){
            case PRINT_TEAM:
                oak->sortTeam(team);
                oak->printTeam(team);
                userInput = oak->getMenuOption();
                break;
            case PRINT_NURSERY:
                oak->printNursery(nursery);
                userInput = oak->getMenuOption();
                break;
            case PRINT_CENTER:
                oak->printCenter(center);
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
            case REMOVE_TEAM:
                userInput = oak->getMenuOption();
                break;
            case REMOVE_NURSERY:
                userInput = oak->getMenuOption();
                break;
            case REMOVE_CENTER:
                userInput = oak->getMenuOption();
                break;
            case CATCH:
                oak->catchPokemon(team, center);
                userInput = oak->getMenuOption();
                break;
            default:
                active = false;
                break;
        }
    }
    return 0;
}
