//
// Created by Софiя Покотило on 13.11.21.
//


#ifndef GAME_SEABATTLE_PLAYER_H
#define GAME_SEABATTLE_PLAYER_H
#include "Battlefield_player.h"
#include "Battlefield_enemy.h"
#include "List.h"

class Player {
protected:
    Battlefield_player my_battlefield;
    Battlefield_enemy enemy_battlefield;
    bool killed_all_ships;
public:
    Player();
    virtual void attack_ships(Battlefield_player &, int &, int &, int &, Coordinate &coord, Coordinate &c, List &list);
    void set_killed_all_ships(bool);
    bool get_killed_all_ships() const;
    Battlefield_player &get_battlefield_player();
    Battlefield_enemy &get_battlefield_enemy();
};


#endif //GAME_SEABATTLE_PLAYER_H

