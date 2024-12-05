#include <iostream>
#include "LinkedList.h"
#include "ProfessorOak.h"
#include "ProfessorOak.cpp"
using namespace std;


/*enum Actions {QUIT, PRINT_TEAM, PRINT_NURSERY, PRINT_CENTER, ADD_TEAM, ADD_NURSERY, ADD_CENTER, CATCH};

int getMenuOption(){
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
*/



int main(){
    ProfessorOak* oak = new ProfessorOak();
    int userInput = oak->getMenuOption();
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
