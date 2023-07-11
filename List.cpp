//
// Created by Софiя Покотило on 21.11.21.
//


#include "List.h"

List::List() {
    Head = NULL;
}

List::~List() {
    while (Head != NULL) {
        node* temp = Head->next;
        delete Head;
        Head = temp;
    }
}

void List::add(Coordinate x) {
    node* temp = new node;
    temp->val = x;
    temp->next = NULL;
    if (Head == NULL) {
        Head = temp;
    } else {
        node* tempNew = Head;
        while (tempNew-> next != NULL) {
            tempNew = tempNew->next;
        }
        tempNew->next = temp;
    }
}

Coordinate List::elemByPos(int pos) {
    node* temp = Head;
    if (pos == 1) {
        return temp->val;
    } else {
        node* del;
        int count = 1;
        while (Head != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        del = temp->next;
        temp->next = del->next;
        return del->val;
    }
}

void List::delByVal(Coordinate value) {
    node* temp = Head;
    node* del = Head->next;
    if (temp->val == value) {
        Head = Head->next;
        delete temp;
    } else {
        while (del != NULL) {
            if (del->val == value) {
                break;
            } else {
                temp = del;
                del = del->next;
            }
        }
        if (del == NULL) {} else {
            temp->next = del->next;
            delete del;
        }
    }
}


int List::size() {
    node* temp = Head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void List::print() {
    node* temp = Head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}