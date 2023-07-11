//
// Created by Софiя Покотило on 13.11.21.
//


#include "Cell.h"

using namespace std;

Cell ::Cell() : clear(1), ship(0), hit(0) {}

void Cell::set_initial_cell() {
    clear = true;
    ship = false;
    hit = false;
}

bool Cell :: getS() const
{
    return ship;
}

bool Cell :: getC() const
{
    return clear;
}

bool Cell :: getH() const
{
    return hit;
}

void Cell :: setS (bool b)
{
    ship = b;
}

void Cell :: setC (bool b)
{
    clear = b;
}

void Cell :: setH (bool b)
{
    hit = b;
}

int Cell::getShipId() const {
    return ship_id;
}

void Cell::setShipId(int sId) {
    ship_id = sId;
}

ostream& operator<< (ostream &out, const Cell &cell){
    setlocale (LC_ALL,"");
    char32_t k = 164;
    if(cell.hit && cell.clear)
        out<<"☆";
    else if(cell.clear && cell.ship)
        out<<"〰";
    else if(cell.ship && cell.hit)
        out<<"Ⓧ";//★⋘
    else if(cell.ship)
        out<<"⎈";//⎈
    else if(cell.clear)
        out<<"〰";
    else
        out<<"★";
    return out;
}