//
// Created by M Elokaily on 7/19/2021.
//

#ifndef MAIN_CPP_LINKEDLIST_H
#define MAIN_CPP_LINKEDLIST_H
#include "D:/Data Structure/Node/Node.h"
#include <iostream>
using namespace std;
template <class t>
class LinkedList {
private:
    Node<t>* front,*back;
    int length;
public:
    LinkedList();
    void insertAtBegin(t);
    void insertAtEnd(t);
    void insertAtPos(int,t);
    void removeFromBegin();
    void removeFromLast();
    void erase(int);
    void Display();
    void clear();
    int find(t);
    void reverse();
    int size() const;
    bool isEmpty()const;
};

#endif //MAIN_CPP_LINKEDLIST_H
