//
// Created by Софiя Покотило on 13.11.21.
//


#include "Battlefield.h"

Battlefield::Battlefield(): num_of_ships(10), field_height(10), field_width(10){
    set_max_size_of_ship();
    ships = new Ship[num_of_ships];
    cell = new Cell*[field_height];
    for (int i = 0; i < field_height; ++i)
        cell[i] = new Cell[field_width];
    for (int i = 0; i < field_height; ++i) {
        for (int j = 0; j < field_width; ++j) {
            cell[i][j].set_initial_cell();
        }
    }
    for (int i = 0, j = 0, k = 1; i < num_of_ships; ++i) {
        if (!k) {
            ++j;
            k = j + 1;
        }
        ships[i].setSize(max_size_of_ship - j);
        --k;
    }
}

Battlefield::~Battlefield() {
    for(int i = 0; i < field_height; ++i)
        delete[] cell[i];
    delete[] cell;

    delete[] ships;
}

Battlefield::Battlefield(int f_h, int f_w): num_of_ships(10), field_height(f_h), field_width(f_w) {
    set_max_size_of_ship();
    ships = new Ship[num_of_ships];
    cell = new Cell*[field_height];
    for (int i = 0; i < field_height; ++i)
        cell[i] = new Cell[field_width];
    for (int i = 0; i < field_height; ++i) {
        for (int j = 0; j < field_width; ++j) {
            cell[i][j].set_initial_cell();
        }
    }
    for (int i = 0, j = 0, k = 1; i < num_of_ships; ++i) {
        if (!k) {
            ++j;
            k = j + 1;
        }
        ships[i].setSize(max_size_of_ship - j);
        --k;
    }
}

void Battlefield::set_max_size_of_ship() {
    int i = 1;
    for(int j = num_of_ships; j>0;++i){
        j -= i;
    }
    max_size_of_ship = --i;
}

int Battlefield::getFieldHeight() const {
    return field_height;
}

int Battlefield::getFieldWidth() const {
    return field_width;
}

Cell **Battlefield::getField() const {
    return cell;
}

Ship *Battlefield::getShips() const {
    return ships;
}

int Battlefield::getNumOfShips() const {
    return num_of_ships;
}


ostream& operator<< (ostream &out, const Battlefield &field){
    out<<"    ";
    for(char i = 65; i <= 74; ++i) {
        if ((i % 2)) out << " ";
        out << i << "   ";
    }
    out<<endl;
    for(int i = 0; i < field.field_height; ++i){
        for (int j = 0; j < field.field_width; ++j) {
            if(j == 0){
                out<<i+1<<"  ";
                if(i!=9)
                    out<<" ";
            }
            out<<field.cell[i][j]<<"   ";
        }
        out<<endl;
    }

    return out;
}
