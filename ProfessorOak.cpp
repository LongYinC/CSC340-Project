#include <iostream>
#include "ProfessorOak.h"
#include "Buildings.h"
#include "Pokemon.h"
#include "Buildings.cpp"
#include "Pokemon.cpp"
#include <random>
#include <string>
#include <fstream>
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
    cout << "Please enter your choice: ";
    cin >> userInput;
    return userInput;
}

void ProfessorOak::printTeam(Buildings* building){
    cout << "Team: " << endl;
    building->print();
}

void ProfessorOak::printNursery(Buildings* building){
    cout << "Nursery: " << endl;
    building->print();
}

void ProfessorOak::printCenter(Buildings* building){
    cout << "Center: " << endl;
    building->print();
}

void ProfessorOak::addTeam(Buildings* building, Pokemon* pokemon){
    cout << "Add " << pokemon->getWord() << " to the Team" << endl; //CHANGE METHOD LATER TO MAKE SURE THAT THE POKEMON BEING ADDED IS IN EITHER NURSERY OR CENTER
    building -> push_back(pokemon); // USE SEARCH METHOD
}

void ProfessorOak::addNursery(Buildings* building, Pokemon* pokemon){
    cout << "Add " << pokemon->getWord() << " to the Nursery" << endl; //CHANGE METHOD LATER TO MAKE SURE THAT THE POKEMON BEING ADDED IS IN EITHER TEAM OR CENTER
    building -> push_back(pokemon);
}

void ProfessorOak::addCenter(Buildings* building, Pokemon* pokemon){
    cout << "Add " << pokemon->getWord() << " to the Center" << endl; //CHANGE METHOD LATER TO MAKE SURE THAT THE POKEMON BEING ADDED IS IN EITHER NURSERY OR TEAM
    building -> push_back(pokemon);
}

Pokemon* ProfessorOak::removeTeam(Buildings* building, Pokemon* pokemon){
    cout << "Removed " << pokemon->getWord() << " from the Team" << endl; 
    // Detach the Pokemon from the team without deleting it
    if(pokemon == building->getHead()) {
        building->setHead(pokemon->getNext());
        if(building->getHead()) building->getHead()->setPrev(nullptr);
    } else if(pokemon == building->getTail()) {
        building->setTail(pokemon->getPrev());
        if(building->getTail()) building->getTail()->setNext(nullptr);
    } else {
        pokemon->getPrev()->setNext(pokemon->getNext());
        pokemon->getNext()->setPrev(pokemon->getPrev());
    }
    
    // Reset the Pokemon's links
    pokemon->setNext(nullptr);
    pokemon->setPrev(nullptr);
    
    // Decrease the list size
    building->reduceSize();
    
    return pokemon;
}
    
Pokemon* ProfessorOak::removeNursery(Buildings* building, Pokemon* pokemon){
    cout << "Removed " << pokemon->getWord() << " from the Nursery" << endl; 
    // Detach the Pokemon from the team without deleting it
    if(pokemon == building->getHead()) {
        building->setHead(pokemon->getNext());
        if(building->getHead()) building->getHead()->setPrev(nullptr);
    } else if(pokemon == building->getTail()) {
        building->setTail(pokemon->getPrev());
        if(building->getTail()) building->getTail()->setNext(nullptr);
    } else {
        pokemon->getPrev()->setNext(pokemon->getNext());
        pokemon->getNext()->setPrev(pokemon->getPrev());
    }
    
    // Reset the Pokemon's links
    pokemon->setNext(nullptr);
    pokemon->setPrev(nullptr);
    
    // Decrease the list size
    building->reduceSize();
    
    return pokemon;
}

Pokemon* ProfessorOak::removeCenter(Buildings* building, Pokemon* pokemon){
    cout << "Removed " << pokemon->getWord() << " from the Center" << endl; 
    // Detach the Pokemon from the team without deleting it
    if(pokemon == building->getHead()) {
        building->setHead(pokemon->getNext());
        if(building->getHead()) building->getHead()->setPrev(nullptr);
    } else if(pokemon == building->getTail()) {
        building->setTail(pokemon->getPrev());
        if(building->getTail()) building->getTail()->setNext(nullptr);
    } else {
        pokemon->getPrev()->setNext(pokemon->getNext());
        pokemon->getNext()->setPrev(pokemon->getPrev());
    }
    
    // Reset the Pokemon's links
    pokemon->setNext(nullptr);
    pokemon->setPrev(nullptr);
    
    // Decrease the list size
    building->reduceSize();
    
    return pokemon;
}

void ProfessorOak::catchPokemon(Buildings* team, Buildings* center){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 151);

    int random_pokeNum = distrib(gen);

    ifstream file("pokemonName.txt");
    if(!file){
        cout << "Error opening file!" << endl;
    }
    string pokemonName;
    int indexNum = 0;

    while(getline(file, pokemonName)){
        indexNum++;
        if(indexNum == random_pokeNum){
            cout << "You caught " << pokemonName << "!" << endl;
            break;
        }
    }
    file.close();
    if(team->size() >= 6){
        center->push_back(new Pokemon(pokemonName));
        cout << pokemonName << " has been sent to your pokemon center." << endl;
    } else {
        team->push_back(new Pokemon(pokemonName));
        cout << pokemonName << " has been added to your team!" << endl;
    }
}

void ProfessorOak::sortTeam(Buildings* building){
    building->mergeSort();
}

void ProfessorOak::runPokemonManager() {
    Buildings* list = new Buildings();
    list->loadFile("pokemonName.txt");
    Buildings* team = new Buildings();
    Buildings* nursery = new Buildings();
    Buildings* center = new Buildings();
    
    bool active = true;
    int userInput;
    
    while(active) {
        userInput = getMenuOption();
        
        switch(userInput) {
            case PRINT_TEAM:
                sortTeam(team);
                printTeam(team);
                break;
            case PRINT_NURSERY:
                printNursery(nursery);
                break;
            case PRINT_CENTER:
                printCenter(center);
                break;
            case ADD_TEAM:
                handleAddToTeam(team, center);
                break;
            case ADD_NURSERY:
                handleAddToNursery(team, nursery);
                break;
            case ADD_CENTER:
                handleAddToCenter(team, center);
                break;
            case CATCH:
                catchPokemon(team, center);
                break;
            default:
                active = false;
                break;
        }
    }
    
    // Clean up dynamically allocated memory
    delete list;
    delete team;
    delete nursery;
    delete center;
}

void ProfessorOak::handleAddToTeam(Buildings* team, Buildings* center) {
    string input;
    cout << "What pokemon do you want to add to your team?(Please enter full name)" << endl;
    cin >> input;
    Pokemon* current = center->getHead();
    
    if(team->size() < 6) {
        while(current != nullptr) {
            if(current->getWord() == input) {
                removeCenter(center, current);
                addTeam(team, current);                           
                return;
            }
            current = current->getNext();
        }
        cout << "You do not own this pokemon" << endl;
    } else {
        cout << "Your team has reached its limit" << endl;
    }
}

void ProfessorOak::handleAddToNursery(Buildings* team, Buildings* nursery) {
    string input;
    cout << "What pokemon do you want to add to your nursery?(Please enter full name)" << endl;
    cin >> input;
    Pokemon* current = team->getHead();
    
    
    while(current != nullptr) {
        if(current->getWord() == input) {
            removeTeam(team, current);
            addNursery(nursery, current);                           
            return;
        }
        current = current->getNext();
    }
    cout << "You do not own this pokemon" << endl;
}

void ProfessorOak::handleAddToCenter(Buildings* team, Buildings* center) {
    string input;
    cout << "What pokemon do you want to add to your center?(Please enter full name)" << endl;
    cin >> input;
    Pokemon* current = team->getHead();
    
    
    while(current != nullptr) {
        if(current->getWord() == input) {
            removeTeam(team, current);
            addCenter(center, current);                           
            return;
        }
        current = current->getNext();
    }
    cout << "You do not own this pokemon" << endl;
}


