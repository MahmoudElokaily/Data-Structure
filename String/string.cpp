//
// Created by M Elokaily on 7/17/2021.
//

#include "string.h"

#include <iostream>


// Function to delete char from end
string::string() {
    length = 0;
    max = 1e5;
    str[max];
}

// Function to add char in string
void string ::push_back(char s) {
    if (length > max){
        throw "string is Full!";
    }
    str[length++] = s;
}

void string :: pop_back(){
    if (isEmpty()){
        throw "string is already Empty!";
    }
    else {
        --length;
    }
}

// Function to know string is empty or not
bool string:: isEmpty() const{
    return length < 0;
}

// Function to Know size of string
int string::size() const{
    return length + 1;
}

// Function to swap 2 char in string
void string::swap(int f,int e) {
    --f,--e;
    if (f > length || e > length){
        throw "out of range";
    }
    else {
        char temp = str[f];
        str[f] = str[e];
        str[e] = temp;
    }
}

// Function to swap all string
void string:: swapString() {
    if (isEmpty()) {
        throw "String is Empty";
    }
    for (int i = 1, j = length; i <= j; ++i, j--) {
        swap(i, j);
        if (!isEmpty()) {
            for (int i = 1, j = length; i <= j; ++i, j--) {
                swap(i, j);
            }
        }
    }
}


    // Function to get last element
    char string:: back() const{
        if (isEmpty()){
            throw "String is Empty";
        }
        return str[length];
    }

    // Function to get first element
    char string:: front() const{
        if (isEmpty()){
            throw "String is Empty";
        }
        return str[0];
    }

    // Function to get sub strung from string
    void string:: substr(int l,int r){
        --l,--r;
        if (l > length || r > length || l > r){
            throw "Erorr!";
        }
        else {
            for (int i=l;i<=r;++i){
                std::cout<<str[i];
            }
            puts("");
        }
    }

    // Function to display string
    void string:: Display(){
        for (int i=0;i<length;++i){
            std::cout<<str[i];
        }
        puts("");
    }