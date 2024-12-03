#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Pokemon {
    private:
        int level;
        string name;
        string type;

    public:
        virtual void attack();
        virtual void evolve();
        virtual void info();

        virtual void getLevel();
        virtual void getName();
        virtual void getType();
        virtual void setLevel(int lvl);
        virtual void setName(string n);
        virtual void setType(string t);
};

#endif