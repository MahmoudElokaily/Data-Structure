//
// Created by M Elokaily on 7/19/2021.
//

#ifndef MAIN_CPP_DOUBLYLINKEDLIST_H
#define MAIN_CPP_DOUBLYLINKEDLIST_H
#include "D:/Data Structure/Doubly LinkedList Node/DoublyNode.h"
#include <iostream>
using namespace std;

template <class t>
class doublyLinkedList {
private:
    int length;
    DoublyNode<t>* front,*back;
public:
    doublyLinkedList();
    void insertFirst(t);
    void insertLast(t);
    void insertAtPos(int,t);
    void Display();
    void removeFirst();
    void removeLast();
    void remove(t);
    void erase(int);
    void clear();
    void displayReverse();
    int size()const;
    bool isEmpty() const;
};

#endif //MAIN_CPP_DOUBLYLINKEDLIST_H
