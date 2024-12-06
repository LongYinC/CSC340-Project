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
    string input;
    Pokemon * current;
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
                cout << "What pokemon do you want to add to your team?(Please enter full name)" << endl;
                cin >> input;
                current = center->getHead();
                if(team->size() < 6){
                    while(current != nullptr){
                        if(current->getWord() == input){
                            oak->addTeam(team, current);
                            //oak->removeCenter(center, current);
                            break;
                        }
                        current = current->getNext();
                    }
                    if(current == nullptr){
                        cout << "You do not own this pokemon" << endl;
                    }
                }
                else{
                    cout << "Your team has reach it limit" << endl;
                }
                userInput = oak->getMenuOption();
                break;
            case ADD_NURSERY:
                cout << "What pokemon do you want to add to the nursery?(Please enter full name)" << endl;
                cin >> input;
                current = team->getHead();
                while(current != nullptr){
                        if(current->getWord() == input){
                            oak->addNursery(nursery, current);
                            //oak->removeTeam(team, current);
                            break;
                        }
                        current = current->getNext();
                }
                if(current == nullptr){
                    cout << "You do not own this pokemon" << endl;
                }
                userInput = oak->getMenuOption();
                break;
            case ADD_CENTER:
                cout << "What pokemon do you want to add to the center?(Please enter full name)" << endl;
                cin >> input;
                current = team->getHead();
                while(current != nullptr){
                        if(current->getWord() == input){
                            oak->addCenter(center, current);
                            //oak->removeTeam(team, current);
                            break;
                        }
                        current = current->getNext();
                }
                if(current == nullptr){
                    cout << "You do not own this pokemon" << endl;
                }
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
