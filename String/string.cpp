//
// Created by M Elokaily on 7/17/2021.
//

#include "string.h"
#include <iostream>
using namespace std;

const int max = 1e5;
// Function to delete char from end
String::String() {
    length = -1;
    str[max];
}

// Function to add char in string
void String ::push_back(char s) {
    if (length > max){
        throw "string is Full!";
    }
    str[++length] = s;
}

void String :: pop_back(){
    if (isEmpty()){
        throw "string is already Empty!";
    }
    else {
        --length;
    }
}

// Function to know string is empty or not
bool String:: isEmpty() const{
    return length < 0;
}

// Function to Know size of string
int String::size() const{
    return length + 1;
}

// Function to swap 2 char in string
// Function work with 0 based
void String::swap(int f,int e) {
    if (f > length || e > length || f < 0 || e < 0){
        throw "out of range";
    }
    else {
        char temp = str[f];
        str[f] = str[e];
        str[e] = temp;
    }
}

// Function to swap all string
void String:: swapString() {
    for (int i = 0, j = length; i < j; ++i, --j) {
        swap(i,j);
    }
}


// Function to get last element
char String:: back() const{
    if (isEmpty()){
        throw "String is Empty";
    }
    return str[length];
}

// Function to get first element
char String:: front() const{
    if (isEmpty()){
        throw "String is Empty";
    }
    return str[0];
}

// Function to get sub strung from string
void String:: substr(int l,int r){
    if (l > length || r > length || l > r || l < 0 || r < 0){
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
void String:: Display(){
    for (int i=0;i<=length;++i){
        cout<<str[i];
    }
    puts("");
}
