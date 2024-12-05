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
    cout << "(" << REMOVE_TEAM << ") Remove pokemon from team" << endl;
    cout << "(" << REMOVE_NURSERY << ") Remove pokemon from nursery" << endl;
    cout << "(" << REMOVE_CENTER << ") Remove pokemon from center" << endl;
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
    cout << "Add Pokemon to the Team: " << endl;
    building -> push_back(pokemon);
}

void ProfessorOak::addNursery(Buildings* building, Pokemon* pokemon){
    cout << "Add Pokemon to the Nursery: " << endl;
    building -> push_back(pokemon);
}

void ProfessorOak::addCenter(Buildings* building, Pokemon* pokemon){
    cout << "Add Pokemon to the Center: " << endl;
    building -> push_back(pokemon);
}

void ProfessorOak::removeTeam(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::removeNursery(Buildings* building, Pokemon* pokemon){}

void ProfessorOak::removeCenter(Buildings* building, Pokemon* pokemon){}

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



