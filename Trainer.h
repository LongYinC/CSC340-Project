#ifndef TRAINER_H
#define TRAINER_H
#include "Buildings.h"
#include "Pokemon.h"
#include <string>
#include <iostream>
#include <fstream>

class Trainer {
   private:
      int teamSize;
      Buildings* team;
      std::string name;
   public:
      int size()const;
      Buildings* getTeam()const;
      std::string getName();
      void addPokemon(Pokemon* pokemon);
      void removePokemon(Pokemon* pokemon);
      Trainer();
      Trainer(Pokemon* pokemon);
      ~Trainer();
      Trainer& operator>(Trainer& other);
      Trainer& operator<(Trainer& other);

      virtual void someAbstractMethod() = 0; //give gym badge, give coins,

#endif
