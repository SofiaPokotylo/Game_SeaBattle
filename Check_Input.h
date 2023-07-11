//
// Created by Софiя Покотило on 05.12.21.
//


#ifndef GAME_SEABATTLE_CHECK_INPUT_H
#define GAME_SEABATTLE_CHECK_INPUT_H
#include <iostream>
using namespace std;

class Check_Input {
protected:
    string text;
public:
    Check_Input();
    Check_Input(string _text);
    string what();
};


#endif //GAME_SEABATTLE_CHECK_INPUT_H
