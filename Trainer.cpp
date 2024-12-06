#include "Trainer.h"
#include <iostream>
#include <string>

using namespace std;

Trainer::Trainer(){
  (*this).name = "NoName";
}

Trainer::Trainer(Pokemon* pokemon){
  (*this).name = "NoName";
  (*this).team->push_back(pokemon);
  (*this).teamSize = 1;
}

Trainer::~Trainer(){
  delete (*this).name;
  delete (*this).team;
  delete (*this).teamSize;
}

int Trainer::size(){
  return (*this).teamSize;
}

Buildings* Trainer::getTeam()const {
  return(*this).team;
}

string Trainer::getName(){
  return (*this).name;
}

void Trainer::addPokemon(Pokemon* pokemon){
  (*this).team->push_back(pokemon);
}

void Trainer::removePokemon(Pokemon* pokemon){
  (*this).team->deleteWord(pokemon);
}

Trainer& Trainer::operator>(Trainer& other){
  //BATTLE WHO WON
}

Trainer& Trainer::operator<(Trainer& other){
  //BATTLE WHO WON
}

void someAbstractMethod(){
  cout << "You won 1000 coins?";
}
