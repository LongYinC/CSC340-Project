#include "LinkedList.h"
#include <string>
using namespace std;

LinkedList::LinkedList(){
   (*this).listSize = 0;
   (*this).head = nullptr;
   (*this).tail = nullptr;   
}

LinkedList::LinkedList(string word){
   (*this).listSize = 0;
   (*this).head = nullptr;
   (*this).tail = nullptr;
   (*this).push_back(word);
}

LinkedList::~LinkedList(){
   Node* current = (*this).head;
   while(current != nullptr){
      Node* next = current->getNext();
      delete current;
      current = next;
   }
   head = nullptr;
}


void LinkedList::push_back(string word){
   Node* temp = new Node(word);
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

void LinkedList::push_back(Node* newWordNode){
   if(newWordNode == nullptr){
      return;   
   }
   newWordNode->setNext(nullptr);
   if(!(*this).head){
      (*this).head = newWordNode;
      (*this).tail = newWordNode;
   }
   else{
      newWordNode->setPrev(tail);
      (*this).tail->setNext(newWordNode);
      (*this).tail = newWordNode;
   }
   (*this).listSize++;
}

int LinkedList::size()const{
   return (*this).listSize;   
}

void LinkedList::loadFile(string fileName){
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

Node* LinkedList::getHead()const{
   return (*this).head;   
}

void LinkedList::setHead(Node* head){
   (*this).head = head;   
}

Node* LinkedList::getTail()const{
   return (*this).tail;   
}

void LinkedList::setTail(Node* tail){
   (*this).tail = tail;   
}

Node* LinkedList::deleteWord(Node* node){
   if(node == nullptr){
      return nullptr;   
   }   
   
   Node* next = node->getNext();
   if(node->getPrev() != nullptr){
      node->getPrev()->setNext(node->getNext());
   }
   else{
      (*this).head = node->getNext();   
   }
   if(node->getNext() != nullptr){
      node->getNext()->setPrev(node->getPrev()); 
   }
   else{
      (*this).tail = node->getPrev();   
   }
   delete node;
   (*this).listSize--; 
   return next;
}

Node* LinkedList::insert_before(string newWord, Node* knownNode){
   if(knownNode == nullptr){
      return nullptr;   
   }   
   Node* node = new Node(newWord);
   
   node->setNext(knownNode);
   node->setPrev(knownNode->getPrev());
   
   if(knownNode->getPrev() != nullptr){
      knownNode->getPrev()->setNext(node);   
   }
   else{
      (*this).head = node;   
   }
   
   knownNode->setPrev(node);
   (*this).listSize++;
   return node;
}

LinkedList& LinkedList::operator+=(LinkedList& other){
    Node* otherHead = other.getHead();
    Node* otherTail = other.getTail();

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

void LinkedList::mergeDicts(LinkedList* listB) {
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
   
    Node* current = (*this).head;
    Node* current2 = listB->getHead();
    
    while (current2 != nullptr) {
        if (current->getWord() > current2->getWord()) {
            Node* next2 = current2->getNext();
            
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
            Node* temp = current2;
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
                
                Node* countNode = current2;
                int remainCount = 0;
                while (countNode != nullptr) {
                    remainCount++;
                    countNode = countNode->getNext();
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

void LinkedList::mergeSort() {
    if (listSize <= 1) {
        return;  
    }
    
    LinkedList* tempList = new LinkedList();
    
    Node* current = head;
    while (current != nullptr) {
        tempList->push_back(current->getWord());
        current = current->getNext();
    }
    
    mergeSort(tempList);
    
    while (head != nullptr) {
        Node* next = head->getNext();
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

void LinkedList::mergeSort(LinkedList* topListPtr) {
    if (topListPtr == nullptr || topListPtr->size() <= 1) {
        return;
    }
    
    LinkedList* leftList = new LinkedList();
    LinkedList* rightList = new LinkedList();
    
    int mid = topListPtr->size() / 2;
    Node* current = topListPtr->getHead();
    
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
        Node* next = topListPtr->getHead()->getNext();
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


void LinkedList::print(){
   Node* current = (*this).head;
   while(current != nullptr){
      cout << current->getWord() << endl;
      current = current->getNext();
   }
}

void LinkedList::printReverse(){
   Node* current = (*this).tail;
   while(current != nullptr){
      cout << current->getWord() << endl;
      current = current->getPrev();
   }
}
