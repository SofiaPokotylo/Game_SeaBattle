//
// Created by Софiя Покотило on 14.11.21.
//


#ifndef GAME_SEABATTLE_BATTLEFIELD_PLAYER_H
#define GAME_SEABATTLE_BATTLEFIELD_PLAYER_H


#include "Battlefield.h"

class Battlefield_player: public Battlefield {
private:
    bool previous_hit = false;
    bool direction_is_set = false;
    Direction direction;
public:
    Battlefield_player();
    void set_rand_cell(int &h, int &w, List &list);
    bool check_h_w(const int &h, const int &w, const bool &);
    bool check_h_w_list(const int &h, const int &w);
    void set_field_ships();
    bool isPreviousHit() const;
    void setPreviousHit(bool previousHit);
    bool isDirectionIsSet() const;
    void setDirectionIsSet(bool directionIsSet);
    void cell_direct(const int &, int &, int &);
    void other_direct(int &);
    const Direction &getDirection() const;
    void setDirection(const Direction &direction);
    void set_rand_direction(bool &direction_not_set, int &last_direct);
    void set_rand_direction(int &last_direct);
    void hit_around(int &h, int &w, Coordinate &coord, const int &i, int &last_direct, List &list);
    void hit_around_user(int &h, int &w, Coordinate &coord, const int &i, int &last_direct);
};


#endif //GAME_SEABATTLE_BATTLEFIELD_PLAYER_H
