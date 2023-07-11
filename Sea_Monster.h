//
// Created by Софiя Покотило on 14.11.21.
//


#ifndef GAME_SEABATTLE_SEA_MONSTER_H
#define GAME_SEABATTLE_SEA_MONSTER_H
#include "Battlefield_player.h"
#include "Battlefield_enemy.h"

class Sea_Monster {
private:
    int num_of_hits;
public:
    Sea_Monster();
    int get_num_of_hits() const;
    bool attack_player_ships(Battlefield_player &, Battlefield_enemy &, int &id, List&, const bool &);
};


#endif //GAME_SEABATTLE_SEA_MONSTER_H
