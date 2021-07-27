//
// Created by M Elokaily on 7/17/2021.
//

#include "Queue.h"
#include <iostream>
using namespace std;

template <class t>
Queue<t>::Queue() {
    length = 0;
    front = rear = nullptr;
}

// Function to push new elements in front
template <class t>
void Queue<t>::push(t newElement) {
    try {
        Node<t> *newNode = new Node<t>;
        newNode->setValue(newElement);
        if (isEmpty()) {
            newNode->setNxt(front);
            front = rear = newNode;
        } else {
            rear->setNxt(newNode);
            newNode->setNxt(NULL);
            rear = newNode;
        }
        ++length;
    }
    catch (exception e){
        throw "Queue is Full";
    }
}

// Function to delete element from front
template <class t>
void Queue<t>::pop() {
    if (isEmpty()){
        throw "Queue is already Empty!";
    }
    else {
        Node<t>* temp = front;
        front = front->getNxt();
        temp->setNxt(NULL);
        delete temp;
        --length;
    }
}

// Function to show all elements in queue
template <class t>
void Queue<t>:: Display(){
    Node<t>* cur = front;
    while (cur != NULL){
        cout<<cur->getValue()<<" ";
        cur = cur->getNxt();
    }
    puts("");
}

// Function to check queue is Empty or not
template <class t>
bool Queue<t>:: isEmpty() const{
    return front == NULL;
}

// Function to know size of queue
template <class t>
int Queue<t>:: size() const{
    return length;
}

// Function to delete all elements in queue
template <class t>
void Queue<t>:: clear(){
    while (front != NULL){
        pop();
    }
}

// Function to know element in queue or not
template <class t>
int Queue<t>:: find(t element){
    Node<t>* cur = front;
    int i=0;
    for (i = 0;cur != NULL && cur->getValue() != element;++i){
        cur = cur->getNxt();
    }
    if (cur == NULL){
        return -1;
    }
    else {
        return i;
    }
}

// Function to return the first element in queue
template <class t>
t& Queue<t>:: getFront() const {
    if (front == NULL) {
        throw "Queue is Empty!";
    } else {
        return front->getValue();
    }
}
