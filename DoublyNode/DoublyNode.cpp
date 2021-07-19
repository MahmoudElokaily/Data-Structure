//
// Created by M Elokaily on 7/19/2021.
//

#include "DoublyNode.h"

template <class t>
DoublyNode<t> :: DoublyNode(){
    nxt = pre = nullptr;
}

template <class t>
void DoublyNode<t> :: setPre(DoublyNode<t>* node){
    pre = node;
}

template <class t>
void DoublyNode<t> :: setNxt(DoublyNode<t>* node){
    nxt = node;
}

template <class t>
DoublyNode<t>* DoublyNode<t> :: getPre() const{
    return pre;
}

template <class t>
DoublyNode<t>* DoublyNode<t> :: getNxt() const{
    return nxt;
}

template <class t>
void DoublyNode<t> ::setValue(t x) {
    value = x;
}

template <class t>
t& DoublyNode<t> ::getValue(){
    return value;
}