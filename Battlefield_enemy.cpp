//
// Created by Софiя Покотило on 14.11.21.
//


#include "Battlefield_enemy.h"

Battlefield_enemy::Battlefield_enemy(): num_of_misses(0), num_of_killed_ships(0), previous_miss(false){
}

int Battlefield_enemy::get_num_of_misses() const {
    return num_of_misses;
}

void Battlefield_enemy::add_killed_ship() {
    num_of_killed_ships += 1;
}

void Battlefield_enemy::set_num_of_misses(int i) {
    if(i>=0)
        num_of_misses = i;
}

void Battlefield_enemy::set_previous_miss(bool b) {
    previous_miss = b;
}

void Battlefield_enemy::add_miss(int i) {
    if(i>=0)
        num_of_misses += i;
}

bool Battlefield_enemy::get_previous_miss() const {
    return previous_miss;
}

int Battlefield_enemy::get_num_of_killed_ships() const {
    return num_of_killed_ships;
}

void Battlefield_enemy::hit_around(int &h, int &w, Coordinate &coord, const Ship &ship, int &last_direct) {
    Coordinate coord2;
    ship.get_direction().direct_to_num(last_direct);
    int h1 = 0, w1 = 0;
    bool t;
    coord = ship.getFirstCoordinate();
    coord2 = ship.getLastCoordinate();
    if((last_direct+2)%2){
        h = coord.getVertical() - 2;
        w = coord.getHorizontal() - 66;
        h1 = coord2.getVertical();
        w1 = coord2.getHorizontal() - 64;
    }
    else{
        h = coord2.getVertical() - 2;
        w = coord2.getHorizontal() - 66;
        h1 = coord.getVertical();
        w1 = coord.getHorizontal() - 64;
    }
    if((h+1)==(h1-1))
        t = true;
    if((w+1)==(w1-1))
        t = false;
    for (int k = h, k_first = k+1, k_last = h1; k <= k_last; ++k) {
        for (int l = w, l_first = l+1, l_last =  w1; l <= l_last; ++l) {
            if(check_h_w_list(k,l))
                if((t && (k != k_first || l==w || l==w1)) || (!t && (l != l_first) || k==h || k==h1))
                    cell[k][l].setH(true);
        }
    }
}

bool Battlefield_enemy::check_h_w_list(const int &h, const int &w) {
    if(h>=field_height || h<0)
        return false;
    else if(w>=field_width || w<0)
        return false;
    return true;
}

