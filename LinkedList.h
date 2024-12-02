#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>


struct LinkedList{
   private:
      int listSize;
      Node* head;
      Node* tail;
   public:
      int size()const;
      Node* getHead()const;
      Node* getTail()const;
      void setHead(Node* head);
      void setTail(Node* tail);
      Node* deleteWord(Node* node);
      Node* insert_before(std::string newWord, Node* knownNode);
      void push_back(std::string word);
      void push_back(Node* newWordNode);
      void loadFile(std::string fileName);
      void print();
      void printReverse();
      LinkedList();
      LinkedList(std::string word);
      ~LinkedList();
      LinkedList& operator+=(LinkedList& other);
      void mergeDicts(LinkedList* listB);
      void mergeSort();
      void mergeSort(LinkedList* topListPtr);
};
#endif
