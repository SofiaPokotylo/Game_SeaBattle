//
// Created by Софiя Покотило on 21.11.21.
//


#ifndef GAME_SEABATTLE_LIST_H
#define GAME_SEABATTLE_LIST_H
#include "Coordinate.h"
#include <iostream>

using namespace std;

struct node {
    Coordinate val;
    node* next;
};

class List {
    node* Head;
public:
    List();
    ~List();

    void add(Coordinate x);
    Coordinate elemByPos(int pos);
    void delByVal(Coordinate value);
    int size();
    void print();
};



#endif //GAME_SEABATTLE_LIST_H
