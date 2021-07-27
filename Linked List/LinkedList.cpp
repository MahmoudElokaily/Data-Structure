//
// Created by M Elokaily on 7/19/2021.
//

#include "LinkedList.h"
template <class t>
LinkedList<t>:: LinkedList(){
    length = 0;
    front = back = nullptr;
}

// Function to insert in begin
template <class t>
void LinkedList<t>::insertAtBegin(t newItem){
    try {
        Node<t> *newNode = new Node<t>;
        newNode->setValue(newItem);
        if (front == nullptr) {
            newNode->setNxt(nullptr);
            front = back = newNode;
        } else {
            newNode->setNxt(front);
            front = newNode;
        }
        ++length;
    }
    catch (exception e){
        throw "LinkedList is Full!";
    }
}

// Function to insert in begin
template <class t>
void LinkedList<t>::insertAtEnd(t newItem){
    try {
        Node<t> *newNode = new Node<t>;
        newNode->setValue(newItem);
        if (front == nullptr) {
            newNode->setNxt(nullptr);
            front = back = newNode;
        } else {
            back->setNxt(newNode);
            newNode->setNxt(nullptr);
            back = newNode;
        }
        ++length;
    }
    catch (exception e){
        throw "LinkedList is Full!";
    }
}

// Function to insert item in position
template <class t>
void LinkedList<t>::insertAtPos(int pos,t newItem){
    if (pos > length || pos < 0){
        throw "out of range";
    }
    else {
        if (pos == 0){
            insertAtBegin(newItem);
        }
        else if (pos == length){
            insertAtEnd(newItem);
        }
        else {
            Node<t>* newNode = new Node<t>;
            newNode->setValue(newItem);
            Node<t>* cur = front;
            for (int i=1;i<pos;++i){
                cur = cur->getNxt();
            }
            newNode->setNxt(cur->getNxt());
            cur->setNxt(newNode);
            ++length;
        }
    }
}

// Function to delete element from begin
template <class t>
void LinkedList<t>:: removeFromBegin(){
    if(isEmpty()){
        throw "Linked List is already Empty!";
    }
    else if (length == 1){
        front = back = nullptr;
        --length;
    }
    else {
        Node<t>*temp = front;
        front = front->getNxt();
        temp->setNxt(nullptr);
        delete temp;
        --length;
    }
}

// Function to remove from last
template <class t>
void LinkedList<t>:: removeFromLast(){
    if (isEmpty()){
        throw "LinKed List is already Empty!";
    }
    else if (length == 1){
        front = back = nullptr;
        --length;
    }
    else {
        Node<t>*cur = front->getNxt(),*prev = front;
        while (cur != back){
            prev = cur;
            cur = cur->getNxt();
        }
        prev->setNxt(nullptr);
        back = prev;
        delete cur;
        --length;
    }
}

// Function to remove element at position
template <class t>
void LinkedList<t>:: erase(int index){
    if (index < 0 || index > length){
        throw "out of Range";
    }
    else {
        if (index == 0){
            removeFromBegin();
        }
        else if (index == length){
            removeFromLast();
        }
        else {
            Node<t>* cur = front->getNxt(),*prev = front;
            for (int i=1;i<index;++i) prev = cur,cur = cur->getNxt();
            prev->setNxt(cur->getNxt());
            delete cur;
            --length;
        }
    }
}

// Function to know size of Linked List
template <class t>
int LinkedList<t>:: size() const{
    return length;
}

// Function to check if Linked List have elements or not
template <class t>
bool LinkedList<t>::isEmpty() const{
    return front == nullptr;
}

// Function to Display all items in LinkedList
template <class t>
void LinkedList<t>::Display(){
    Node<t>* cur = front;
    while (cur != nullptr){
        cout<<cur->getValue()<<" ";
        cur = cur->getNxt();
    }
    puts("");
}

// Function to delete all Elements in Linked List
template <class t>
void LinkedList<t>::clear(){
    while (front != nullptr){
        removeFromBegin();
    }
}

// Function to tell us the elment in Linked List or not
template <class t>
int LinkedList<t>:: find(t element){
    Node<t>* cur = front;
    int i;
    for (i=0;i<length;++i){
        if (cur->getValue() == element){
            return i;
        }
        cur = cur->getNxt();
    }
    return -1;
}

// Function to reverse all elements
template <class t>
void LinkedList<t>:: reverse() {
    Node<t> *cur = front, *pre = nullptr, *next = front->getNxt();
    while (next != nullptr) {
        next = cur->getNxt();
        cur->setNxt(pre);
        pre = cur;
        cur = next;
    }
    back = front;
    front = pre;
}