#include "GymLeader.h"
#include <iostream>

GymLeader::GymLeader(){
  (*this).name = "GymLeader0";
}

GymLeader::~GymLeader(){
  delete (*this).name;
  delete (*this).team;
  delete (*this).teamSize;
}

GymLeader::GymLeader(std::string name, Pokemon* pokemon){
  (*this).name = name;
  (*this).team->push_back(pokemon);
}

void GymLeader::someAbstractMethod(){
  cout << "Congratulations for defeating me! Here is the gym badge." << endl;
}
