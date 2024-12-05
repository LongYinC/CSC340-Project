#include "Pokemon.h"
#include <string>
using namespace std;

Pokemon::Pokemon(){
   (*this).word = "";
   (*this).next = nullptr;
   (*this).prev = nullptr;
}

Pokemon::Pokemon(string word){
   (*this).word = word;
   (*this).next = nullptr;
   (*this).prev = nullptr;
}

string Pokemon::getWord()const{
   return (*this).word;   
}

void Pokemon::setWord(string word){
   (*this).word = word;   
}

Pokemon* Pokemon::getNext()const{
   return (*this).next;   
}

Pokemon* Pokemon::getPrev()const{
   return (*this).prev;   
}

void Pokemon::setNext(Pokemon* nextPokemon){
   (*this).next = nextPokemon;   
}

void Pokemon::setPrev(Pokemon* prevPokemon){
   (*this).prev = prevPokemon;   
}

bool operator==(const Pokemon& lhs, const Pokemon& rhs){
   return lhs.getWord() == rhs.getWord();   
}

bool operator!=(const Pokemon& lhs, const Pokemon& rhs){
   return lhs.getWord() != rhs.getWord();   
}

bool operator>(const Pokemon& lhs, const Pokemon& rhs){
   return lhs.getWord() > rhs.getWord();   
}

bool operator>=(const Pokemon& lhs, const Pokemon& rhs){
   return lhs.getWord() >= rhs.getWord();   
}

bool operator<(const Pokemon& lhs, const Pokemon& rhs){
   return lhs.getWord() < rhs.getWord();   
}

bool operator<=(const Pokemon& lhs, const Pokemon& rhs){
   return lhs.getWord() <= rhs.getWord();   
}
