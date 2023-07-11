//
// Created by Софiя Покотило on 13.11.21.
//


#include "Player.h"
Player::Player(): killed_all_ships(false) {}

void Player::attack_ships(Battlefield_player &b, int &h, int &w, int &last_direct, Coordinate &first_coord, Coordinate &coord, List &list) {
    //Coordinate coord;
    if(!b.isPreviousHit()) {
        b.set_rand_cell(h, w, list);
        b.getField()[h][w].setH(true);
        enemy_battlefield.getField()[h][w].setH(true);
        coord.setVertical(h + 1);
        coord.setHorizontal(w + 65);
        list.delByVal(coord);
        if (b.getField()[h][w].getS() && !b.getField()[h][w].getC()) {
            first_coord.set_Coordinate(coord.getVertical(),coord.getHorizontal());
            b.setPreviousHit(true);
            enemy_battlefield.set_previous_miss(false);
            enemy_battlefield.getField()[h][w].setS(true);
            enemy_battlefield.getField()[h][w].setC(false);
        }
        else {
            b.setPreviousHit(false);
            enemy_battlefield.set_previous_miss(true);
        }
        b.setDirectionIsSet(false);
    }
    else {
        do {
            if (!b.isDirectionIsSet()) {
                do{
                    h = first_coord.getVertical() - 1;
                    w = first_coord.getHorizontal() - 65;
                    b.set_rand_direction(last_direct);
                    b.cell_direct(last_direct, h, w);
                }while(!b.check_h_w(h, w, false));
                b.getField()[h][w].setH(true);
                enemy_battlefield.getField()[h][w].setH(true);
                coord.setVertical(h + 1);
                coord.setHorizontal(w + 65);
                list.delByVal(coord);
                if (b.getField()[h][w].getS() && !b.getField()[h][w].getC()) {
                    //b.setPreviousHit(true);
                    enemy_battlefield.getField()[h][w].setS(true);
                    enemy_battlefield.getField()[h][w].setC(false);
                    enemy_battlefield.set_previous_miss(false);
                    b.setDirectionIsSet(true);
                } else {
                    enemy_battlefield.set_previous_miss(true);
                    b.setDirectionIsSet(false);
                    h = first_coord.getVertical() - 1;
                    w = first_coord.getHorizontal() - 65;
                    break;

                }

            }
            else {
                b.cell_direct(last_direct, h, w);
                if(!b.check_h_w(h, w, false)){
                    h = first_coord.getVertical() - 1;
                    w = first_coord.getHorizontal() - 65;
                    b.other_direct(last_direct);
                    b.cell_direct(last_direct, h, w);
                }
                b.getField()[h][w].setH(true);
                enemy_battlefield.getField()[h][w].setH(true);
                coord.setVertical(h + 1);
                coord.setHorizontal(w + 65);
                list.delByVal(coord);
                if (b.getField()[h][w].getS() && !b.getField()[h][w].getC()) {
                    enemy_battlefield.getField()[h][w].setS(true);
                    enemy_battlefield.getField()[h][w].setC(false);
                    b.setPreviousHit(true);
                    enemy_battlefield.set_previous_miss(false);
                } else {
                    enemy_battlefield.set_previous_miss(true);
                    h = first_coord.getVertical() - 1;
                    w = first_coord.getHorizontal() - 65;
                    b.other_direct(last_direct);
                    break;
                }
            }
        }while(!b.isDirectionIsSet());
    }
}

Battlefield_enemy& Player::get_battlefield_enemy() {
    return enemy_battlefield;
}

Battlefield_player& Player::get_battlefield_player() {
    return my_battlefield;
}

void Player::set_killed_all_ships(bool b) {
    killed_all_ships = b;
}

bool Player::get_killed_all_ships() const {
    return  killed_all_ships;
}