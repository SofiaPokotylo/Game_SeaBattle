//
// Created by Софiя Покотило on 14.11.21.
//

#include "Sea_Monster.h"

Sea_Monster::Sea_Monster():num_of_hits(5) {}

bool Sea_Monster::attack_player_ships(Battlefield_player &b, Battlefield_enemy &b2, int &id, List &list, const bool &human) {
    Coordinate c;
    for(int i = b.getNumOfShips()-1, h = 0, w = 0; b.getShips()[i].getSize() == 1; --i){
        c = b.getShips()[i].getFirstCoordinate();
        h = c.getVertical()-1;
        w = c.getHorizontal() - 65;
        if(!b.getField()[h][w].getH()) {
            id = i;
            b.getField()[h][w].setH(true);
            b2.getField()[h][w].setH(true);
            b2.getField()[h][w].setS(true);
            b2.getField()[h][w].setC(false);

            if(human)
                list.delByVal(c);
            return true;
        }
    }
    return false;
}

int Sea_Monster::get_num_of_hits() const {
    return num_of_hits;
}