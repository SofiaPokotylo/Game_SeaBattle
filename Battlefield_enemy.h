//
// Created by Софiя Покотило on 14.11.21.
//


#ifndef GAME_SEABATTLE_BATTLEFIELD_ENEMY_H
#define GAME_SEABATTLE_BATTLEFIELD_ENEMY_H
#include "Battlefield.h"

class Battlefield_enemy: public Battlefield{
private:
    int num_of_misses;
    int num_of_killed_ships;
    bool previous_miss;
public:
    Battlefield_enemy();
    bool get_previous_miss() const;
    void set_previous_miss(bool);
    int get_num_of_misses() const;
    void set_num_of_misses(int);
    void add_miss(int);
    int get_num_of_killed_ships() const;
    void add_killed_ship();
    void hit_around(int &h, int &w, Coordinate &coord, const Ship &ship, int &last_direct);
    bool check_h_w_list(const int &h, const int &w);
};


#endif //GAME_SEABATTLE_BATTLEFIELD_ENEMY_H
