//
// Created by Софiя Покотило on 14.11.21.
//

#ifndef GAME_SEABATTLE_DIRECTION_H
#define GAME_SEABATTLE_DIRECTION_H
#include <iostream>
using namespace std;

class Direction {
private:
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    int num_of_directions = 4;
public:

    Direction();
    Direction(const bool &u, const bool &d, const bool &l, const bool &r);

    void set_direction(const bool &u, const bool &d, const bool &l, const bool &r);

    int getNumOfDirections() const;

    void num_to_direct(const int &, const bool &);

    void direct_to_num(int &) ;

    bool num_to_direct_is_set(const int &);

    friend ostream& operator<< (ostream &out, const Direction &);

};


#endif //GAME_SEABATTLE_DIRECTION_H
