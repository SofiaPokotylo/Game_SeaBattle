//
// Created by Софiя Покотило on 13.11.21.
//


#include "Ship.h"
#include <ctime>

Ship::Ship(): size(0), is_set(false){
    direction.set_direction(0,0,0,0);
    first_coordinate.set_Coordinate(1, 'A');
    last_coordinate.set_Coordinate(10,'J');
}

void Ship::set_direction(bool u, bool d, bool l, bool r) {
    direction.set_direction(u,d,l,r);
}

Direction Ship::get_direction() const {
    return direction;
}

void Ship::set_rand_direction(bool &direction_not_set, int &last_direct) {
    int a = 0;
    if(clock()%2)
        a = clock()%(direction.getNumOfDirections()-2);
    else
        a = clock()%(direction.getNumOfDirections()-2) + 2;
    int t = direction.getNumOfDirections();
    if(direction.num_to_direct_is_set(a)) {
        if(clock()%2) {
            for (int i = a; i < t ; ++i) {
                if (direction.num_to_direct_is_set(i) == false) {
                    direction.num_to_direct(i, false);
                    last_direct = i;
                    direction_not_set = false;
                    break;
                }
                if (i == t - 1)
                    direction_not_set = true;
            }
        } else{
            for (int i = t-1; i >= 0 ; --i) {
                if (direction.num_to_direct_is_set(i) == false) {
                    direction.num_to_direct(i, false);
                    last_direct = i;
                    direction_not_set = false;
                    break;
                }
                if (i == 0)
                    direction_not_set = true;
            }
        }
    }
    else {
        direction.num_to_direct(a, false);
        last_direct = a;
        direction_not_set = false;
    }
}

int Ship::getSize() const {
    return size;
}

void Ship::setSize(int s) {
    size = s;
}

const Coordinate &Ship::getFirstCoordinate() const {
    return first_coordinate;
}

void Ship::setFirstCoordinate(const Coordinate &firstCoordinate) {
    first_coordinate = firstCoordinate;
}

const Coordinate &Ship::getLastCoordinate() const {
    return last_coordinate;
}

void Ship::setLastCoordinate(const Coordinate &lastCoordinate) {
    last_coordinate = lastCoordinate;
}

bool Ship::isSet() const {
    return is_set;
}

void Ship::setIsSet(bool isSet) {
    is_set = isSet;
}

void Ship::set_direction(const Direction &d) {
    direction = d;
}

ostream& operator<< (ostream &out, const Ship &s){
    out<<"size = "<<s.size<<endl;
    return out;
}