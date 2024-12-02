#ifndef NODE_H
#define NODE_H
#include <string>

struct Node{
   private:
      std::string word;
      Node* next;
      Node* prev;
   public:
      Node();
      Node(std::string word);
      std::string getWord()const;
      Node* getNext()const;
      Node* getPrev()const;
      void setWord(std::string word);
      void setNext(Node* nextNode);
      void setPrev(Node* prevNode);
      friend bool operator==(const Node& lhs, const Node& rhs);
      friend bool operator!=(const Node& lhs, const Node& rhs);
      friend bool operator>(const Node& lhs, const Node& rhs);
      friend bool operator<(const Node& lhs, const Node& rhs);
      friend bool operator<=(const Node& lhs, const Node& rhs);
      friend bool operator>=(const Node& lhs, const Node& rhs);

};
#endif
