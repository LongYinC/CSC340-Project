#ifndef Pokemon_H
#define Pokemon_H
#include <string>

struct Pokemon{
   private:
      std::string word;
      Pokemon* next;
      Pokemon* prev;
   public:
      Pokemon();
      Pokemon(std::string word);
      std::string getWord()const;
      Pokemon* getNext()const;
      Pokemon* getPrev()const;
      void setWord(std::string word);
      void setNext(Pokemon* nextPokemon);
      void setPrev(Pokemon* prevPokemon);
      friend bool operator==(const Pokemon& lhs, const Pokemon& rhs);
      friend bool operator!=(const Pokemon& lhs, const Pokemon& rhs);
      friend bool operator>(const Pokemon& lhs, const Pokemon& rhs);
      friend bool operator<(const Pokemon& lhs, const Pokemon& rhs);
      friend bool operator<=(const Pokemon& lhs, const Pokemon& rhs);
      friend bool operator>=(const Pokemon& lhs, const Pokemon& rhs);

};
#endif
