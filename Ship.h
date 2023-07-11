//
// Created by Софiя Покотило on 13.11.21.
//


#ifndef GAME_SEABATTLE_SHIP_H
#define GAME_SEABATTLE_SHIP_H
#include "Direction.h"
#include "Coordinate.h"
#include <iostream>

using namespace std;

class Ship {
private:
    int size;
    Coordinate first_coordinate;
    Coordinate last_coordinate;
    Direction direction;
    bool is_set = false;
public:

    Ship();

    bool isSet() const;

    void setIsSet(bool isSet);

    void set_direction(bool u, bool d, bool l, bool r);
    void set_direction(const Direction &);
    void set_rand_direction(bool &, int &);

    Direction get_direction() const;

    int getSize() const;

    void setSize(int size);

    const Coordinate &getFirstCoordinate() const;

    void setFirstCoordinate(const Coordinate &firstCoordinate);

    const Coordinate &getLastCoordinate() const;

    void setLastCoordinate(const Coordinate &lastCoordinate);

    friend ostream& operator<< (ostream &out, const Ship &);
};


#endif //GAME_SEABATTLE_SHIP_H

