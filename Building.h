#ifndef BUILDING_H
#define BUILDING_H
#include <string>
#include <iostream>
#include <stream>
#include "LinkedList.cpp"

using namespace std;

class Building {
    private:
        string name;
        LinkedList* list;

    public:
        Building();
        virtual ~Building();
        virtual string getName();
        virtual LinkedList* getList();
        virtual void setName();
        virtual void addPokemon();
        virtual void removePokemon();
};

#endif
