//
// Created by Софiя Покотило on 14.11.21.
//


#include "Battlefield_player.h"
#include <ctime>

Battlefield_player::
Battlefield_player(): direction_is_set(false), previous_hit(false){}

bool Battlefield_player::isPreviousHit() const {
    return previous_hit;
}

void Battlefield_player::setPreviousHit(bool previousHit) {
    previous_hit = previousHit;
}

bool Battlefield_player::isDirectionIsSet() const {
    return direction_is_set;
}

void Battlefield_player::setDirectionIsSet(bool directionIsSet) {
    direction_is_set = directionIsSet;
}

void Battlefield_player::set_field_ships(){
    bool direction_not_set = false;
    int h = 0;
    int w = 0;
    int h1 = 0;
    int w1 = 0;
    Coordinate coord2;
    int last_direct = 0;
    Coordinate coord;
    Direction direct;
    List list;
    for(int i = 0; i<field_height; ++i){
        for (int j = 0; j < field_width; ++j) {
            coord.set_Coordinate(i+1,j+65);
            list.add(coord);
        }
    }

    for (int i = 0, j = 0; i < num_of_ships; ++i) {
        while(!ships[i].isSet()) { // корабель не розміщено
            direction_not_set = false;
            j = ships[i].getSize(); // j - size of ship
            set_rand_cell(h, w, list);
            coord.setVertical(h + 1);// налаштування координати клітинки на полі
            coord.setHorizontal(w + 65);
            ships[i].setFirstCoordinate(coord); // перша коорд корабля
            ships[i].setLastCoordinate(coord); // остання коорд корабля = першій
            cell[h][w].setS(true);
            cell[h][w].setC(false);
            --j;//зменш розмір
            if(!j)//корабель однопалубний
                ships[i].setIsSet(true);//розміщений корабель
            else {
                while(!direction_not_set) {
                    set_rand_direction(direction_not_set, last_direct);
                    if (direction_not_set)
                        break;
                    while(j>0){
                        cell_direct(last_direct,h,w);
                        if (check_h_w(h, w, true)) {
                            cell[h][w].setS(true);
                            cell[h][w].setC(false);
                            coord.setVertical(h + 1);
                            coord.setHorizontal(w + 65);
                            ships[i].setLastCoordinate(coord);
                            --j;
                            if (!j) {
                                cell[h][w].setS(true);
                                cell[h][w].setC(false);
                                ships[i].setIsSet(true);
                                direction_not_set = true;
                            }
                        }
                        else{
                            other_direct(last_direct);
                            if(direction.num_to_direct_is_set(last_direct)) {
                                other_direct(last_direct);
                                direction_not_set = true;
                                break;
                            }
                            else {
                                coord = ships[i].getFirstCoordinate();
                                h = coord.getVertical() - 1;
                                w = coord.getHorizontal() - 65;
                                ships[i].setFirstCoordinate(ships[i].getLastCoordinate());
                            }
                        }

                    }
                }
            }
            if(!ships[i].isSet()){
                coord = ships[i].getFirstCoordinate();
                h = coord.getVertical() - 1;
                w = coord.getHorizontal() - 65;
                coord = ships[i].getLastCoordinate();
                //ships[i].set_direction(0,0,0,0);
                direction.set_direction(0,0,0,0);
                for(int h1 = coord.getVertical()-1, w1 = coord.getHorizontal()-65;h!=h1 || w!=w1;){
                    cell[h][w].setS(false);
                    cell[h][w].setC(true);
                    cell_direct(last_direct,h,w);
                }
                if(h==coord.getVertical()-1 && w==coord.getHorizontal()-65){
                    cell[h][w].setS(false);
                    cell[h][w].setC(true);
                }
            }
        }
        coord = ships[i].getFirstCoordinate();
        h = coord.getVertical() - 1;
        w = coord.getHorizontal() - 65;
        direction.num_to_direct(last_direct, true);
        ships[i].set_direction(direction);
        direction.set_direction(0,0,0,0);
        for (int k = 0; k < ships[i].getSize(); ++k) {
            if(ships[i].getSize()==1)
                ships[i].set_direction(0,0,0,0);
            if(k) cell_direct(last_direct,h,w);
            cell[h][w].setShipId(i);
            coord.setVertical(h+1);
            coord.setHorizontal(w+65);
        }
        coord = ships[i].getFirstCoordinate();
        coord2 = ships[i].getLastCoordinate();
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
        for (int k = h, k_first = k+1, k_last = h1; k <= k_last; ++k) {
            for (int l = w, l_first = l+1, l_last =  w1; l <= l_last; ++l) {
                if(check_h_w_list(k,l)) {
                    coord.setVertical(k+1);
                    coord.setHorizontal(l+65);
                    list.delByVal(coord);
                    if (k != k_first || l != l_first)
                        cell[k][l].setS(true);
                }
            }
        }
    }
}




bool Battlefield_player::check_h_w(const int &h, const int &w, const bool &t) {
    if(h>=field_height || h<0)
        return false;
    else if(w>=field_width || w<0)
        return false;
    else if(t){
        if(cell[h][w].getS())
            return false;
    }
    else if(!t){
        if(cell[h][w].getH())
            return false;
    }
    return true;
}



bool Battlefield_player::check_h_w_list(const int &h, const int &w) {
    if(h>=field_height || h<0)
        return false;
    else if(w>=field_width || w<0)
        return false;
    return true;
}

void Battlefield_player::set_rand_cell(int &h, int &w, List &list){
    Coordinate c;
    int k = clock()%list.size() + 1;
    c = list.elemByPos(k);
    h = c.getVertical()-1;
    w = c.getHorizontal()-65;
}

void Battlefield_player::cell_direct(const int &direct, int &h, int &w) {
    switch (direct) {
        case 0:
            --h;
            break;
        case 1:
            ++h;
            break;
        case 2:
            --w;
            break;
        case 3:
            ++w;
    }
}

void Battlefield_player::other_direct(int &direct) {
    switch (direct) {
        case 0:
            direct = 1;
            break;
        case 1:
            direct = 0;
            break;
        case 2:
            direct = 3;
            break;
        case 3:
            direct = 2;
    }
}

void Battlefield_player::set_rand_direction(bool &direction_not_set, int &last_direct) {
    int a = 0;
    if(clock()%2)
        a = clock()%(direction.getNumOfDirections()-2);
    else
        a = clock()%(direction.getNumOfDirections()-2) + 2;
    int t = direction.getNumOfDirections();
    if(direction.num_to_direct_is_set(a)) {
        if(clock()%2) {
            for (int i = a; i < t ; ++i) {
                if (!direction.num_to_direct_is_set(i)) {
                    direction.num_to_direct(i, false);
                    last_direct = i;
                    direction_not_set = false;
                    break;
                }
                if (i == t - 1)
                    direction_not_set = true;
            }
        } else{
            for (int i = t-1; i >= 0 ; --i) {
                if (!direction.num_to_direct_is_set(i)) {
                    direction.num_to_direct(i, false);
                    last_direct = i;
                    direction_not_set = false;
                    break;
                }
                if (i == 0)
                    direction_not_set = true;
            }
        }
    }
    else {
        direction.num_to_direct(a, false);
        last_direct = a;
        direction_not_set = false;
    }
}


void Battlefield_player::set_rand_direction(int &last_direct) {
    int a = 0;
    if(clock()%2)
        a = clock()%(direction.getNumOfDirections()-2);
    else
        a = clock()%(direction.getNumOfDirections()-2) + 2;
    //int t = direction.getNumOfDirections();
    if(direction.num_to_direct_is_set(a)) {
        int t = direction.getNumOfDirections();
        if(clock()%2) {
            for (int i = 0; i < t ; ++i) {
                if (direction.num_to_direct_is_set(i) == false) {
                    direction.num_to_direct(i, false);
                    last_direct = i;
                    break;
                }
            }
        } else{
            for (int i = t-1; i >= 0 ; --i) {
                if (direction.num_to_direct_is_set(i) == false) {
                    direction.num_to_direct(i, false);
                    last_direct = i;
                    break;
                }
            }
        }
    }
    else {
        direction.num_to_direct(a, false);
        last_direct = a;
    }
}

const Direction &Battlefield_player::getDirection() const {
    return direction;
}

void Battlefield_player::setDirection(const Direction &direction) {
    Battlefield_player::direction = direction;
}

void Battlefield_player::hit_around(int &h, int &w, Coordinate &coord, const int &i, int &last_direct, List &list) {
    Coordinate coord2;
    ships[i].get_direction().direct_to_num(last_direct);
    int h1 = 0, w1 = 0;
    bool t;
    coord = ships[i].getFirstCoordinate();
    coord2 = ships[i].getLastCoordinate();
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
            if(check_h_w(k,l,false)) {
                if((t && (k != k_first || l==w || l==w1)) || (!t && (l != l_first || k==h || k==h1))) {
                    coord.setVertical(k+1);
                    coord.setHorizontal(l+65);
                    list.delByVal(coord);
                    cell[k][l].setH(true); //можливо забрати
                }
            }
        }
    }
}

void Battlefield_player::hit_around_user(int &h, int &w, Coordinate &coord, const int &i, int &last_direct) {
    Coordinate coord2;
    ships[i].get_direction().direct_to_num(last_direct);
    int h1 = 0, w1 = 0;
    bool t;
    coord = ships[i].getFirstCoordinate();
    coord2 = ships[i].getLastCoordinate();
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
            if(check_h_w(k,l,false)) {
                if((t && (k != k_first || l==w || l==w1)) || (!t && (l != l_first) || k==h || k==h1))
                    cell[k][l].setH(true);
            }
        }
    }
}