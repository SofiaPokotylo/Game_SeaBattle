//
// Created by Софiя Покотило on 13.11.21.
//


#include "Coordinate.h"
#include "Check_Input.h"

Coordinate::Coordinate(): vertical(1), horizontal('A'){}
Coordinate::Coordinate(int v, char h): vertical(v), horizontal(h) {}

void Coordinate::set_Coordinate(int v, char h) {
    vertical = v;
    horizontal = h;
}

int Coordinate::getVertical() const {
    return vertical;
}

void Coordinate::setVertical(int vert) {
    vertical = vert;
}

char Coordinate::getHorizontal() const {
    return horizontal;
}

void Coordinate::setHorizontal(char horiz) {
    horizontal = horiz;
}

ostream& operator<< (ostream &out, const Coordinate &c){
    out<<c.vertical<<c.horizontal;
    return out;
}

istream& operator>> (istream &in, Coordinate &c){
    in >> c.vertical;
    if (in.fail())
    {
        in.clear();
        in.ignore(32767,'\n');
        throw Check_Input("\n\bAnother symbol was used instead of integer number!\n");
    }
    in >> c.horizontal;
    if(c.horizontal < 65 || (c.horizontal > 90 && c.horizontal < 97) || c.horizontal > 122) {
        in.clear();
        in.ignore(32767,'\n');
        throw Check_Input("\n\bAnother symbol was used instead of letter\n");
    }

    return in;
}

bool operator==(const Coordinate &a, const Coordinate &b){
    if(a.horizontal==b.horizontal && a.vertical==b.vertical)
        return true;
    return false;
}

bool operator<(const Coordinate &a, const Coordinate &b){
    if(a.vertical<b.vertical)
        return true;
    else if(a.horizontal<b.horizontal)
        return true;
    return false;
}

bool operator>(const Coordinate &a, const Coordinate &b){
    if(a.vertical>b.vertical)
        return true;
    else if(a.horizontal>b.horizontal)
        return true;
    return false;
}

