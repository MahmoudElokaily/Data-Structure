//
// Created by M Elokaily on 7/17/2021.
//

#include "PriorityQueue.h"
#include <algorithm>
using namespace std;

template <class t>
PriorityQueue<t>:: PriorityQueue(){
    length = -1;
    max = 1e5;
    PQ[max];
}

// Function to Know PriorityQueue is empty or not
template <class t>
bool PriorityQueue<t>:: isEmpty() const{
    return length <  0;
}

// Function to add element in PriorityQueue
template <class t>
void PriorityQueue<t>:: insert(t newItem){
    if (length >= max){
        throw "PriorityQueue is Full";
    }
    PQ[length++] = newItem;
    sort(PQ,PQ+length,greater<>());
}


//Function to delete element in PriorityQueue
template <class t>
#include <algorithm>
void PriorityQueue<t>:: remove(){
    if (isEmpty()){
        throw "PriorityQueue is already Empty!";
    }
    else {
        PQ[0] = 0;
        sort(PQ,PQ+length,greater<>());
        --length;
    }
}


//Function to Display all elements in PriorityQueue
template <class t>
void PriorityQueue<t>:: Display(){
    for (int i=0;i<length;++i){
        cout<<PQ[i]<<" ";
    }
    puts("");
}

// Function to know size of PriorityQueue
template <class t>
int PriorityQueue<t>:: size() const{
    return length + 1;
}

// Function to retun top element in PriorityQueue
template <class t>
t PriorityQueue<t>:: top() const{
    if (isEmpty()){
        throw "PriorityQueue is Empty";
    }
    else {
        return PQ[0];
    }
}

// Function to clear PriorityQueue
template <class t>
void PriorityQueue<t>:: clear(){
    length = -1;
}