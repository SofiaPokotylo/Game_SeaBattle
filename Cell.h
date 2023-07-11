//
// Created by Софiя Покотило on 13.11.21.
//


#ifndef GAME_SEABATTLE_CELL_H
#define GAME_SEABATTLE_CELL_H
#include "Coordinate.h"
#include <iostream>
using namespace std;

class Cell {
private:
    bool ship;
    bool clear;
    bool hit;
    int ship_id;
public:
    Cell();

    void set_initial_cell();

    int getShipId() const;

    void setShipId(int shipId);

    bool getS() const;
    bool getC() const;
    bool getH() const;

    void setS(bool);
    void setC(bool);
    void setH(bool);


    friend ostream& operator<< (ostream &out, const Cell &);
};


#endif //GAME_SEABATTLE_CELL_H
