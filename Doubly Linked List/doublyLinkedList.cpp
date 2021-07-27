//
// Created by M Elokaily on 7/19/2021.
//

#include "doublyLinkedList.h"

template <class t>
doublyLinkedList<t>::doublyLinkedList() {
    front = back = nullptr;
    length = 0;
}

template <class t>
void doublyLinkedList<t>:: insertFirst(t item)
{
    try {
        DoublyNode<t> *newNode = new DoublyNode<t>;
        newNode->setValue(item);
        if (front == nullptr) {
            front = back = newNode;
            newNode->setNxt(nullptr); newNode->setPre(nullptr);
        } else {
            newNode->setNxt(front);
            newNode->setPre(nullptr);
            front->setPre(newNode);
            front = newNode;
        }
        ++length;
    }
    catch (exception e){
        throw "List is Full";
    }
}

template <class t>
void doublyLinkedList<t>:: insertLast(t newItem) {
    try {
        DoublyNode<t> *newNode = new DoublyNode<t>;
        newNode->setValue(newItem);
        if (front == nullptr) {
            front = back = newNode;
            newNode->setNxt(nullptr); newNode->setPre(NULL);
        } else {
            newNode->setNxt(nullptr);
            newNode->setPre(back);
            back->setNxt(newNode);
            back = newNode;
        }
        ++length;
    }
    catch (exception e){
        throw "List is Full";
    }
}

template <class t>
void doublyLinkedList<t>:: insertAtPos(int pos, t item) {
    if (pos < 0 || pos > length) {
        throw "Out Of Range!";
    } else if (pos == 0) {
        insertFirst(item);
    } else if (pos == length) {
        insertLast(item);
    } else {
        DoublyNode<t> *newNode = new DoublyNode<t>;
        newNode->setValue(item);
        DoublyNode<t> *cur = front;
        for (int i = 1; i < pos; i++) cur = cur->getNxt();

        newNode->setNxt(cur->getNxt());
        newNode->setPre(cur);
        cur->getNxt()->setPre(newNode);
        cur->setNxt(newNode);
        ++length;
    }
}

// Function to print all elements
template <class t>
void doublyLinkedList<t>:: Display(){
    DoublyNode<t>* cur = front;
    while (cur != nullptr){
        cout<<cur->getValue()<<" ";
        cur = cur->getNxt();
    }
    puts("");
}

// Function to remove elements from begin
template <class t>
void doublyLinkedList<t>:: removeFirst()
{
    if (front == nullptr) {
        throw "List is already Empty!";
    }
    else if (length == 1)//first == last
    {
        delete front;
        front = back = nullptr;
        --length;
    }
    else
    {
        DoublyNode<t>* temp = front;
        front = front->getNxt();
        front->setPre(nullptr);
        delete temp;
        --length;
    }
}

// Function to delete item from end
template <class t>
void doublyLinkedList<t>:: removeLast(){
    if (front == nullptr){
        throw "List is already Empty!";
    }
    else if (length == 1)//first == last
    {
        delete front;
        front = back = nullptr;
        --length;
    }
    else
    {
        DoublyNode<t> *temp = back;
        back = back->getPre();
        back->setNxt(nullptr);
        delete temp;
        --length;
    }
}

// Function to erase value by it is value
template <class t>
void doublyLinkedList<t>:: remove(t item){
    if (isEmpty()){
        throw "Empty List!";
    }
    else if (front->getValue() == item){
        removeFirst();
    }
    else {
        DoublyNode<t>*cur = front->getNxt();
        while (cur != NULL && cur->getValue() != item) cur = cur->getNxt();
        if (cur == nullptr) {
            throw "item not Found";
        }
        else if (cur->getNxt() == NULL){
            removeLast();
        }
        else {
            cur->getPre()->setNxt(cur->getNxt());
            cur->getNxt()->setPre(cur->getPre());
            delete cur;
            --length;
        }
    }
}

// Function to erase value by it is index
template <class t>
void doublyLinkedList<t>:: erase(int index){
    if (isEmpty()){
        throw "Empty List!";
    }
    else if (index > length || index < 0){
        throw "Out of range";
    }
    else if (index == 0){
        removeFirst();
    }
    else if (index == length - 1){
        removeLast();
    }
    else {
        DoublyNode<t>*cur = front->getNxt();
        for (int i=1;i<index;++i) cur = cur->getNxt();
        cur->getPre()->setNxt(cur->getNxt());
        cur->getNxt()->setPre(cur->getPre());
        delete cur;
        --length;
    }
}

// Function to know size of list
template <class t>
int doublyLinkedList<t>:: size() const{
    return length;
}

// Function to know List is Empty or no
template <class t>
bool doublyLinkedList<t>:: isEmpty() const{
    return front == NULL;
}

// Function to clear List
template <class  t>
void doublyLinkedList<t>:: clear(){
    if (isEmpty()){
        throw "List is already Empty";
    }
    while (!isEmpty()){
        removeFirst();
    }
}

// Function to reverse list
template <class t>
void doublyLinkedList<t>:: displayReverse(){
    DoublyNode<t>* cur = back;
    while (cur != nullptr){
        cout<<cur->getValue()<<" ";
        cur = cur->getPre();
    }
    puts("");
}