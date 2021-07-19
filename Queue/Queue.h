//
// Created by M Elokaily on 7/17/2021.
//

#ifndef MAIN_CPP_QUEUE_H
#define MAIN_CPP_QUEUE_H
#include <iostream>
#include "D:/Data Structure/Node/Node.h"

template <class t>
class Queue {
private:
    int length;
    Node<t>* front,*rear;
public:
    Queue();
    void push(t);
    void pop();
    void Display();
    void clear();
    bool isEmpty() const;
    int find(t);
    int size() const;
    t& getFront() const;
};

#endif //MAIN_CPP_QUEUE_H
