//
// Created by Софiя Покотило on 13.11.21.
//


#ifndef GAME_SEABATTLE_BATTLEFIELD_H
#define GAME_SEABATTLE_BATTLEFIELD_H
#include <iostream>
#include "Cell.h"
#include "Ship.h"
#include "List.h"

using namespace std;

class Battlefield {
protected:
    int field_height = 10;
    int field_width = 10;
    Cell **cell = nullptr;
    Ship *ships = nullptr;
    int num_of_ships = 10;
    int max_size_of_ship = 4;
public:
    Battlefield();

    ~Battlefield();

    Battlefield(int f_h, int f_w);

    void set_max_size_of_ship();

    int getFieldHeight() const;

    int getFieldWidth() const;

    Cell **getField() const;

    Ship *getShips() const;

    int getNumOfShips() const;

    friend ostream& operator<< (ostream &out, const Battlefield &);

};


#endif //GAME_SEABATTLE_BATTLEFIELD_H
