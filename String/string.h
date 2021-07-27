//
// Created by M Elokaily on 7/17/2021.
//

#ifndef MAIN_CPP_STRING_H
#define MAIN_CPP_STRING_H

class String {
private:
    int length,max;
    char str[];
public:
    String();
    void push_back(char);
    void pop_back();
    bool isEmpty() const;
    int size()const;
    void swapString();
    void swap(int,int);
    char back() const;
    char front() const;
    void substr(int,int);
    void Display();
};

#endif //MAIN_CPP_STRING_H
