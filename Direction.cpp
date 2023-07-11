//
// Created by Софiя Покотило on 14.11.21.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "Simplify"
#include "Direction.h"

Direction::Direction(): up(false), down(false), left(false), right(false), num_of_directions(4) {}

Direction::Direction(const bool &u, const bool &d, const bool &l, const bool &r): up(u), down(d),
                                                                                  left(l), right(r), num_of_directions(4) {}

void Direction::set_direction(const bool &u, const bool &d, const bool &l, const bool &r){
    up = u;
    down = d;
    left = l;
    right = r;
}

int Direction::getNumOfDirections() const {
    return num_of_directions;
}

void Direction::num_to_direct(const int &i, const bool &one_direction) {
    switch (i) {
        case 0:
            if(one_direction) set_direction(1,0,0,0);
            else up = true;
            break;
        case 1:
            if(one_direction) set_direction(0,1,0,0);
            else down = true;
            break;
        case 2:
            if(one_direction) set_direction(0,0,1,0);
            else left = true;
            break;
        case 3:
            if(one_direction) set_direction(0,0,0,1);
            else right = true;
    }
}

void Direction::direct_to_num(int &i) {
    if(up)
        i = 0;
    else if(down)
        i = 1;
    else if(left)
        i = 2;
    else if(right)
        i = 3;
}

bool Direction::num_to_direct_is_set(const int &i) {
    switch (i) {
        case 0:
            if(up)
                return true;
            break;
        case 1:
            if(down)
                return true;
            break;
        case 2:
            if(left)
                return true;
            break;
        case 3:
            if(right)
                return true;
    }
    return false;
}

ostream& operator<< (ostream &out, const Direction &d){
    if(d.up)
        out<<"\nup\n"<<d.up<<endl;
    if(d.down)
        out<<"\ndown\n"<<d.down<<endl;
    if(d.left)
        out<<"\nleft\n"<<d.left<<endl;
    if(d.right)
        out<<"\nright\n"<<d.right<<endl;
    return out;
}
#pragma clang diagnostic pop