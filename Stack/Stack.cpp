//
// Created by M Elokaily on 7/19/2021.
//

#include "Stack.h"

template <class t>
Stack<t>::Stack() {
    length = 0;
    top = NULL;
}

template <class t>
void Stack<t>::push(t newItem) {
    try {
        Node<t> *newNode = new Node<t>;
        newNode->setValue(newItem);
        newNode->setNxt(top);
        top = newNode;
        ++length;
    }
    catch (exception e){
        throw "Stack is Full";
    }
}

template <class t>
bool Stack<t>:: isEmpty()const{
    // if answer is 1 this mean the stack have elements otherwise stack is empty
    // you can choose ant one of them , and both are working
//        return !length;
    return top == NULL;
}

template <class t>
void Stack<t>::pop() {
    // delete element from top
    if (isEmpty()){
        throw "Stack is already empty";
    }
    else {
        Node<t>* temp = top;
        top =top->getNxt();
        temp->setNxt(NULL);
        delete temp;
        --length;
    }
}

template <class t>
int Stack<t>:: size() const{
    // return size of stack
    return length;
}

template <class t>
t& Stack<t>:: getTop() const{
    // return elements in top
    if (isEmpty()){
        throw "Stack is Empty!\n";
    }
    else {
        return top->getValue();
    }
}

template <class t>
void Stack<t>:: Display(){
    // to print elements in stack
    Node<t>* cur = top;
    while (cur != NULL){
        cout<<cur->getValue()<<" ";
        cur = cur->getNxt();
    }
    puts("");
}
template <class t>
void Stack<t>:: clear(){
    // to remove all elements in stack
    while (top != NULL){
        pop();
    }
}
template <class t>
int Stack<t>:: find(t element){
    // Function work with 0 based
    // to know this element i search in stack or not
    Node<t>* cur = top;
    int i=0;
    for (i=0;cur != NULL && cur->getValue() != element;++i){
        cur = cur->getNxt();
    }
    if (cur == NULL){
        return -1;
    }
    else {
        return i;
    }
}
