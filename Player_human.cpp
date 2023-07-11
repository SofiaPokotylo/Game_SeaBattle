//
// Created by Софiя Покотило on 14.11.21.
//


#include "Player_human.h"
#include <cmath>
#include "Check_Input.h"

Player_human::Player_human(): auto_config(true), num_of_wins(0), num_of_losses(0), num_of_consecutive_wins(0), record(0) {

}

int Player_human::getNumOfWins() const {
    return num_of_wins;
}

void Player_human::setNumOfWins(int numOfWins) {
    num_of_wins = numOfWins;
}

int Player_human::getNumOfLosses() const {
    return num_of_losses;
}

void Player_human::setNumOfLosses(int numOfLosses) {
    num_of_losses = numOfLosses;
}

int Player_human::getNumOfConsecutiveWins() const {
    return num_of_consecutive_wins;
}

void Player_human::setNumOfConsecutiveWins(int numOfConsecutiveWins) {
    num_of_consecutive_wins = numOfConsecutiveWins;
    if(num_of_consecutive_wins>record) record = num_of_consecutive_wins;
}

int Player_human::getRecord() const {
    return record;
}

void Player_human::setRecord(int record) {
    Player_human::record = record;
}

void Player_human::attack_ships(Battlefield_player &b, int &h, int &w, Coordinate &coord) {
    char a;
    do {
        cout<< "\nEnter the integer number from 1 to 10(1 and 10 included) and the letter from A to J(A and J included)\n";
        for (bool i = true; i;) {
            try {
                cin >> coord;
                i = false;
            } catch (Check_Input &c_i) {
                cout<<c_i.what();
            }
        }
    }while(!check_coordinate_attack(coord,b));

    h = coord.getVertical()-1;
    w = coord.getHorizontal()-65;
    b.getField()[h][w].setH(true);
    enemy_battlefield.getField()[h][w].setH(true);
    if(b.getField()[h][w].getS() && !b.getField()[h][w].getC()) {
        b.setPreviousHit(true);
        enemy_battlefield.set_previous_miss(false);
        enemy_battlefield.getField()[h][w].setS(true);
        enemy_battlefield.getField()[h][w].setC(false);
    }
    else {
        b.setDirectionIsSet(false);
        enemy_battlefield.set_previous_miss(true);
    }
}

void Player_human::manual_place_ships(){
    Coordinate coord1;
    Coordinate coord2;
    int h = 0, h1 = 0, w = 0, w1 = 0;
    bool v_or_h = false; // true - h==h1, false - w = w1;
    cout<<"\nPlace all the ships, start from the ship with 4 decks and end with the ship with 1 deck\n";
    for(int i = 0, k = 0; i<my_battlefield.getNumOfShips(); ++i) {
        k = my_battlefield.getShips()[i].getSize();
        cout<<my_battlefield;

        cout<<"\nThe size of ship is equal to \n"<<k;
        if(k==1){
            cout<<"\nPlease, enter only one coordinate\n";
            do {
                cout
                        << "\nEnter the integer number from 1 to 10(1 and 10 included) and the letter from A to J(A and J included)\n";
                for (bool i = true; i;) {
                    try {
                        cin >> coord1;
                        i = false;
                    } catch (Check_Input &c_i) {
                        cout<<c_i.what();
                    }
                }
            }while(!check_coordinate(coord1,true));
            coord2 = coord1;
        }
        else
            do {
                cout << "\nPlease, enter the first and the last coordinates of the ship";
                cout << "(the size of the ship is equal to "<<k<<")\n";
                do {
                    cout<< "\nEnter the integer numbers from 1 to 10(1 and 10 included) and the letters from A to J(A and J included)\n";
                    for (bool i = true; i;) {
                        try {
                            cin >> coord1;
                            cin >> coord2;
                            i = false;
                        } catch (Check_Input &c_i) {
                            cout<<c_i.what();
                        }
                    }
                } while (!check_coordinate(coord1, false) || !check_coordinate(coord2, false));
                low_to_up(coord1);
                low_to_up(coord2);
            }while (!check_coord_ship(coord1,coord2,k,v_or_h));
        if(k == 1)
            my_battlefield.getShips()[i].set_direction(0,0,0,0);
        else define_direct(i,coord1,coord2,false);
        my_battlefield.getShips()[i].setFirstCoordinate(coord1);
        my_battlefield.getShips()[i].setLastCoordinate(coord2);
        around_ship(v_or_h,coord1,coord2,i);

    }

}

void Player_human::around_ship(const bool &v_h, Coordinate &coord, Coordinate &coord2, const int &i) {
    int h = 0, h1 = 0, w = 0, w1 = 0;
    int last_direct = 0;
    my_battlefield.getShips()[i].get_direction().direct_to_num(last_direct);
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
            if(my_battlefield.check_h_w_list(k,l)) {
                my_battlefield.getField()[k][l].setS(true);
                if((v_h && k == k_first && l>w && l<w1) || (!v_h && l == l_first && k>h && k<h1)) {
                    my_battlefield.getField()[k][l].setC(false);
                    my_battlefield.getField()[k][l].setShipId(i);
                    //my_battlefield.getField()[k][l].setCoord();
                }
            }
        }
    }
}

bool Player_human::check_coordinate(Coordinate &c, const bool &cond) {
    // cond: 0(any number not equal to 1 or 2) - place ship(size!=1), 1 - place ship(size=0)
    if(c.getVertical()<1)
        return false;
    if(c.getVertical()>10)
        return false;
    if(!(c.getHorizontal()>=65 && c.getHorizontal()<=74) && !(c.getHorizontal()>=97 && c.getHorizontal()<=106))
        return false;
    if(cond){
        low_to_up(c);
        if(my_battlefield.getField()[c.getVertical()-1][c.getHorizontal()-65].getS())
            return false;
    }
    return true;
}

bool Player_human::check_coordinate_attack(Coordinate &c, Battlefield_player &b) {

    if(c.getVertical()<1)
        return false;
    if(c.getVertical()>10)
        return false;
    if(!(c.getHorizontal()>=65 && c.getHorizontal()<=74) && !(c.getHorizontal()>=97 && c.getHorizontal()<=106))
        return false;
    low_to_up(c);
    if(b.getField()[c.getVertical()-1][c.getHorizontal()-65].getH())
        return false;

    return true;
}

bool Player_human::check_coord_ship(const Coordinate &coord1, const Coordinate &coord2, const int &k, bool &v_h) {
    if(k!=1) {
        if ((coord1.getVertical() == coord2.getVertical()) == (coord1.getHorizontal() == coord2.getHorizontal()))
            return false;
    }
    int h = 0, h1 = 0, w = 0, w1 = 0, first = 0, last = 0;
    h = coord1.getVertical()-1;
    h1 = coord2.getVertical()-1;
    w = coord1.getHorizontal()-65;
    w1 = coord2.getHorizontal()-65;
    if(h==h1){
        if(abs(w-w1) != (k-1))
            return false;
        if(w>w1) {
            first = w1;
            last = w;
        }
        else {
            first = w;
            last = w1;
        }
        for (int a = first; a <= last; ++a)
            if (my_battlefield.getField()[h][a].getS())
                return false;
        v_h = true;
    }
    else{
        if(abs(h-h1) != (k-1))
            return false;
        if(h>h1) {
            first = h1;
            last = h;
        }
        else {
            first = h;
            last = h1;
        }
        for (int a = first; a <= last; ++a)
            if (my_battlefield.getField()[a][w].getS())
                return false;
        v_h = false;
    }
    return true;

}

void Player_human::define_direct(int &i, const Coordinate &coord1, const Coordinate &coord2, bool t) {
    int h = 0, h1 = 0, w = 0, w1 = 0;
    h = coord1.getVertical();
    h1 = coord2.getVertical();
    w = coord1.getHorizontal();
    w1 = coord2.getHorizontal();
    if(h==h1){
        if(w>w1) {
            if (t) i = 2;
            else my_battlefield.getShips()[i].set_direction(0, 0, 1, 0);
        }
        else {
            if(t) i = 3;
            else my_battlefield.getShips()[i].set_direction(0, 0, 0, 1);
        }
    }
    else{
        if(h>h1){
            if(t) i = 0;
            else my_battlefield.getShips()[i].set_direction(1,0,0,0);
        }
        else {
            if(t) i = 1;
            my_battlefield.getShips()[i].set_direction(0, 1, 0, 0);
        }
    }
}

void Player_human::low_to_up(Coordinate &c) {
    if(c.getHorizontal()>=97)
        c.setHorizontal(c.getHorizontal()-32);
}
