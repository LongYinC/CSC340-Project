#include "Nursery.h"
#include <iostream>

Nursery::Nursery(){
  (*this).name = "Nursery";
}

Nursery::~Nursery(){
  delete (*this).name;
  delete (*this).head;
  delete (*this).tail;
}

void Nursery::napTime(){
  Pokemon* temp = new Pokemon()
  (*this).
}
