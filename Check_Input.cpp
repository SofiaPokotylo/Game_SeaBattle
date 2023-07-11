//
// Created by Софiя Покотило on 05.12.21.
//

#include "Check_Input.h"

Check_Input::Check_Input() {
    text = "\n\nError! Incorrect Input!\n\n";
}

Check_Input::Check_Input(string _text): text(_text) {}

string Check_Input::what() {
    return text;
}