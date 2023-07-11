//
// Created by Софiя Покотило on 13.11.21.
//


#ifndef GAME_SEABATTLE_GAME_H
#define GAME_SEABATTLE_GAME_H
#include "Player_human.h"
#include "Sea_Monster.h"
#include <iostream>
#include <vector>

using namespace std;

class Game {
private:
    Player computer;
    Player_human user;
    Sea_Monster sea_monster;
    vector<string> rules;
    string Statistic;
    bool winner;
public:

    Game();

    void prepare_players(bool auto_config);

    void change_Statistic();

    void battle();

    void end_the_game();

    bool isWinner() const;

    const vector<string> &getRules() const;

    void setRules();

    string &getStatistic() ;

    void setStatistic();

    void check_attack(int &ship_size, int &id, int &size, int &h, int &w, Coordinate &coord, List &list, const bool &b,
                      Player &player, Player &player2);
    void clear_Statistic();
};


#endif //GAME_SEABATTLE_GAME_H

