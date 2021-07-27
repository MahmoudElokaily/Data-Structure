//
// Created by M Elokaily on 7/17/2021.
//

#ifndef MAIN_CPP_PRIORITYQUEUE_H
#define MAIN_CPP_PRIORITYQUEUE_H
#include <iostream>
using namespace std;

template <class t>
class PriorityQueue {
private:
    int length;
    int max;
    t PQ[];
public:
    PriorityQueue();
    bool isEmpty() const;
    void insert(t);
    void remove();
    void Display();
    int size() const;
    t top() const;
    void clear();
};
#endif //MAIN_CPP_PRIORITYQUEUE_H