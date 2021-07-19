//
// Created by M Elokaily on 7/17/2021.
//

#include "Node.h"
Node<t>::Node() {
    nxt = nullptr;
}

template<class t>
Node<t>::Node(t v) {
    value = v;
    nxt = nullptr;
}

template <class t>
void Node <t> :: setValue(t x){
    value = x;
}

template <class t>
t& Node <t>:: getValue()const{
    return value;
}

template <class t>
void Node <t> :: setNxt(Node* node){
    nxt = node;
}

template <class t>
Node<t>* Node <t>:: getNxt() const{
    return nxt;
}