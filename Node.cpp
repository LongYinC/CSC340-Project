#include "Node.h"
#include <string>
using namespace std;

Node::Node(){
   (*this).word = "";
   (*this).next = nullptr;
   (*this).prev = nullptr;
}

Node::Node(string word){
   (*this).word = word;
   (*this).next = nullptr;
   (*this).prev = nullptr;
}

string Node::getWord()const{
   return (*this).word;   
}

void Node::setWord(string word){
   (*this).word = word;   
}

Node* Node::getNext()const{
   return (*this).next;   
}

Node* Node::getPrev()const{
   return (*this).prev;   
}

void Node::setNext(Node* nextNode){
   (*this).next = nextNode;   
}

void Node::setPrev(Node* prevNode){
   (*this).prev = prevNode;   
}

bool operator==(const Node& lhs, const Node& rhs){
   return lhs.getWord() == rhs.getWord();   
}

bool operator!=(const Node& lhs, const Node& rhs){
   return lhs.getWord() != rhs.getWord();   
}

bool operator>(const Node& lhs, const Node& rhs){
   return lhs.getWord() > rhs.getWord();   
}

bool operator>=(const Node& lhs, const Node& rhs){
   return lhs.getWord() >= rhs.getWord();   
}

bool operator<(const Node& lhs, const Node& rhs){
   return lhs.getWord() < rhs.getWord();   
}

bool operator<=(const Node& lhs, const Node& rhs){
   return lhs.getWord() <= rhs.getWord();   
}
