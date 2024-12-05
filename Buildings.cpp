#include "Buildings.h"
#include <string>
using namespace std;

Buildings::Buildings(){
   (*this).listSize = 0;
   (*this).head = nullptr;
   (*this).tail = nullptr;
   (*this).name = "Building";  
}

Buildings::Buildings(string name){
   (*this).listSize = 0;
   (*this).head = nullptr;
   (*this).tail = nullptr;
   (*this).name = name;
}

Buildings::Buildings(string name, string word){
   (*this).listSize = 0;
   (*this).head = nullptr;
   (*this).tail = nullptr;
   (*this).name = name;
   (*this).push_back(word);
}

Buildings::~Buildings(){
   Pokemon* current = (*this).head;
   while(current != nullptr){
      Pokemon* next = current->getNext();
      delete current;
      current = next;
   }
   head = nullptr;
}


void Buildings::push_back(string word){
   Pokemon* temp = new Pokemon(word);
   if((*this).tail){
      (*this).tail->setNext(temp);
      temp->setPrev((*this).tail);
   }
   else{
      (*this).head = temp;   
   }
   (*this).tail = temp;
   (*this).listSize++; 
}

void Buildings::push_back(Pokemon* newWordPokemon){
   if(newWordPokemon == nullptr){
      return;   
   }
   newWordPokemon->setNext(nullptr);
   if(!(*this).head){
      (*this).head = newWordPokemon;
      (*this).tail = newWordPokemon;
   }
   else{
      newWordPokemon->setPrev(tail);
      (*this).tail->setNext(newWordPokemon);
      (*this).tail = newWordPokemon;
   }
   (*this).listSize++;
}

int Buildings::size()const{
   return (*this).listSize;   
}

void Buildings::loadFile(string fileName){
   ifstream inFS;
   inFS.open(fileName);
   if(!inFS.is_open()){
      return;   
   }
   string word;
   while(!inFS.eof()){
      inFS >> word;
      push_back(word);
   }
   inFS.close();
}

Pokemon* Buildings::getHead()const{
   return (*this).head;   
}

void Buildings::setHead(Pokemon* head){
   (*this).head = head;   
}

Pokemon* Buildings::getTail()const{
   return (*this).tail;   
}

void Buildings::setTail(Pokemon* tail){
   (*this).tail = tail;   
}

Pokemon* Buildings::deleteWord(Pokemon* pokemon){
   if(pokemon == nullptr){
      return nullptr;   
   }   
   
   Pokemon* next = pokemon->getNext();
   if(pokemon->getPrev() != nullptr){
      pokemon->getPrev()->setNext(pokemon->getNext());
   }
   else{
      (*this).head = pokemon->getNext();   
   }
   if(pokemon->getNext() != nullptr){
      pokemon->getNext()->setPrev(pokemon->getPrev()); 
   }
   else{
      (*this).tail = pokemon->getPrev();   
   }
   delete pokemon;
   (*this).listSize--; 
   return next;
}

Pokemon* Buildings::insert_before(string newWord, Pokemon* knownPokemon){
   if(knownPokemon == nullptr){
      return nullptr;   
   }   
   Pokemon* pokemon = new Pokemon(newWord);
   
   pokemon->setNext(knownPokemon);
   pokemon->setPrev(knownPokemon->getPrev());
   
   if(knownPokemon->getPrev() != nullptr){
      knownPokemon->getPrev()->setNext(pokemon);   
   }
   else{
      (*this).head = pokemon;   
   }
   
   knownPokemon->setPrev(pokemon);
   (*this).listSize++;
   return pokemon;
}

Buildings& Buildings::operator+=(Buildings& other){
    Pokemon* otherHead = other.getHead();
    Pokemon* otherTail = other.getTail();

    if (!otherHead) return *this;

    if (!(*this).head) {
        (*this).head = otherHead;
        (*this).tail = otherTail;
    } else {
        (*this).tail->setNext(otherHead);
        other.head->setPrev((*this).tail);
        (*this).tail = otherTail;
    }

    (*this).listSize += other.size();

    other.head = nullptr;
    other.tail = nullptr;
    other.listSize = 0; 

    return *this;
}

void Buildings::mergeDicts(Buildings* listB) {
    if (!listB || listB->size() == 0) {
        return;   
    }
    
    if ((*this).head == nullptr) {
        (*this).head = listB->getHead();
        (*this).tail = listB->getTail();
        (*this).listSize = listB->size();
        
        listB->setHead(nullptr);
        listB->setTail(nullptr);
        listB->listSize = 0;
        return;
    }
   
    Pokemon* current = (*this).head;
    Pokemon* current2 = listB->getHead();
    
    while (current2 != nullptr) {
        if (current->getWord() > current2->getWord()) {
            Pokemon* next2 = current2->getNext();
            
            if (current == (*this).head) {
                current2->setNext((*this).head);
                (*this).head->setPrev(current2);
                (*this).head = current2;
            } else {
                current2->setPrev(current->getPrev());
                current->getPrev()->setNext(current2);
                current2->setNext(current);
                current->setPrev(current2);
            }
            (*this).listSize++;
            current2 = next2;
        }
        else if (current->getWord() == current2->getWord()) {
            Pokemon* temp = current2;
            current2 = current2->getNext();
            delete temp;
        }
        else {
            if (current->getNext() != nullptr) {
                current = current->getNext();   
            } else {
                (*this).tail->setNext(current2);
                current2->setPrev((*this).tail);
                (*this).tail = listB->getTail();
                
                Pokemon* countPokemon = current2;
                int remainCount = 0;
                while (countPokemon != nullptr) {
                    remainCount++;
                    countPokemon = countPokemon->getNext();
                }
                (*this).listSize += remainCount;
                
                break;
            }
        }
    }
    
    listB->setHead(nullptr);
    listB->setTail(nullptr);
    listB->listSize = 0;
}

void Buildings::mergeSort() {
    if (listSize <= 1) {
        return;  
    }
    
    Buildings* tempList = new Buildings();
    
    Pokemon* current = head;
    while (current != nullptr) {
        tempList->push_back(current->getWord());
        current = current->getNext();
    }
    
    mergeSort(tempList);
    
    while (head != nullptr) {
        Pokemon* next = head->getNext();
        delete head;
        head = next;
    }
    
    head = tempList->getHead();
    tail = tempList->getTail();
    listSize = tempList->size();
    
    tempList->setHead(nullptr);
    tempList->setTail(nullptr);
    delete tempList;
}

void Buildings::mergeSort(Buildings* topListPtr) {
    if (topListPtr == nullptr || topListPtr->size() <= 1) {
        return;
    }
    
    Buildings* leftList = new Buildings();
    Buildings* rightList = new Buildings();
    
    int mid = topListPtr->size() / 2;
    Pokemon* current = topListPtr->getHead();
    
    for (int i = 0; i < mid && current != nullptr; i++) {
        leftList->push_back(current->getWord());
        current = current->getNext();
    }
    
    while (current != nullptr) {
        rightList->push_back(current->getWord());
        current = current->getNext();
    }
    
    mergeSort(leftList);
    mergeSort(rightList);
    
    while (topListPtr->getHead() != nullptr) {
        Pokemon* next = topListPtr->getHead()->getNext();
        delete topListPtr->getHead();
        topListPtr->setHead(next);
    }
    topListPtr->setHead(nullptr);
    topListPtr->setTail(nullptr);
    
    topListPtr->mergeDicts(leftList);
    topListPtr->mergeDicts(rightList);
    
    delete leftList;
    delete rightList;
}


void Buildings::print(){
   Pokemon* current = (*this).head;
   while(current != nullptr){
      cout << current->getWord() << endl;
      current = current->getNext();
   }
}

void Buildings::printReverse(){
   Pokemon* current = (*this).tail;
   while(current != nullptr){
      cout << current->getWord() << endl;
      current = current->getPrev();
   }
}
