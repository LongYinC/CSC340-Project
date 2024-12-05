#ifndef BUILDINGS_H
#define BUILDINGS_H
#include "Pokemon.h"
#include <string>
#include <iostream>
#include <fstream>


struct Buildings{
   private:
      int listSize;
      Pokemon* head;
      Pokemon* tail;
      std::string name;
   public:
      int size()const;
      Pokemon* getHead()const;
      Pokemon* getTail()const;
      void setHead(Pokemon* head);
      void setTail(Pokemon* tail);
      Pokemon* deleteWord(Pokemon* pokemon);
      Pokemon* insert_before(std::string newWord, Pokemon* knownPokemon);
      void push_back(std::string word);
      void push_back(Pokemon* newWordPokemon);
      void loadFile(std::string fileName);
      void print();
      void printReverse();
      Buildings();
      Buildings(std::string name);
      Buildings(std::string name, std::string word);
      ~Buildings();
      Buildings& operator+=(Buildings& other);
      void mergeDicts(Buildings* listB);
      void mergeSort();
      void mergeSort(Buildings* topListPtr);
};
#endif
