//
// Created by Софiя Покотило on 14.11.21.
//

#ifndef GAME_SEABATTLE_PLAYER_HUMAN_H
#define GAME_SEABATTLE_PLAYER_HUMAN_H
#include "Player.h"

class Player_human: public Player{
private:
    bool auto_config;
    int num_of_wins;
    int num_of_losses;
    int num_of_consecutive_wins;
    int record;
public:

    Player_human();

    int getNumOfWins() const;

    void setNumOfWins(int numOfWins);

    int getNumOfLosses() const;

    void setNumOfLosses(int numOfLosses);

    int getNumOfConsecutiveWins() const;

    void setNumOfConsecutiveWins(int numOfConsecutiveWins);

    int getRecord() const;

    void setRecord(int record);

    void manual_place_ships();

    bool check_coordinate(Coordinate &, const bool &);

    bool check_coordinate_attack(Coordinate &, Battlefield_player &);

    bool check_coord_ship(const Coordinate &coord1, const Coordinate &coord2, const int &i, bool &);

    void define_direct(int &i, const Coordinate &coord1, const Coordinate &coord2, bool);

    void low_to_up(Coordinate &);

    void around_ship(const bool &v_h, Coordinate &coord, Coordinate &coord2, const int &i);

    void attack_ships(Battlefield_player &b, int &h, int &w, Coordinate &first_coord);



};


#endif //GAME_SEABATTLE_PLAYER_HUMAN_H
