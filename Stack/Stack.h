//
// Created by M Elokaily on 7/19/2021.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include "D:/Data Structure/Node/Node.h"


#include <iostream>

using namespace std;

template <class t>
class Stack{
private:
    int length;
    Node<t>* top;
public:
    Stack();
    void push(t);
    void pop();
    void clear();
    void Display();
    int find(t);
    t& getTop() const;
    int size() const;
    bool isEmpty() const;
};

#endif //STACK_STACK_H
