//
// Created by Софiя Покотило on 13.11.21.
//


#ifndef GAME_SEABATTLE_COORDINATE_H
#define GAME_SEABATTLE_COORDINATE_H
#include <iostream>
using namespace std;

class Coordinate {
private:
    int vertical;
    char horizontal;
public:
    Coordinate();
    Coordinate(int v, char h);

    void set_Coordinate(int v, char h);

    int getVertical() const;

    void setVertical(int vertical);

    char getHorizontal() const;

    void setHorizontal(char horizontal);

    friend ostream& operator<< (ostream &out, const Coordinate &);

    friend istream& operator>> (istream &in, Coordinate &);

    friend bool operator==(const Coordinate &, const Coordinate &);

    friend bool operator<(const Coordinate &, const Coordinate &);

    friend bool operator>(const Coordinate &, const Coordinate &);

};


#endif //GAME_SEABATTLE_COORDINATE_H
